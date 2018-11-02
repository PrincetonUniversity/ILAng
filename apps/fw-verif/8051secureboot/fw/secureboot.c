/*
 * Copyright (c) 1999-2001 Tony Givargis.  Permission to copy is granted
 * provided that this header remains intact.  This software is provided
 * with no warranties.
 *
 * Version : 2.9
 */

/*---------------------------------------------------------------------------*/
#include "seahorn/seahorn.h"

/*---------------------------------------------------------------------------*/
#include "rsa.h"
#ifdef C
#ifndef CBMC
#include <stdio.h>
#endif
#else
//#include <reg51.h> FIXME
#endif

XDATA_ARR(0x0000, MAX_PRG_SIZE, unsigned char, program);
XDATA_ARR(0x5000, MAX_IM_SIZE, unsigned char, boot);

XDATA_ARR(0xC000, MAX_IM_SIZE+0x40, unsigned char, sha_in);
XDATA_ARR(0xE100, H, unsigned char, sha_out);
XDATA_ARR(0xE200, N, unsigned char, rsa_out);

/*---------------------------------------------------------------------------*/
#define PACK(var, size) unsigned char var[size]

struct modules{
    unsigned int addr;
    PACK(p0,2);  // add extra bytes to account for different type sizes
    unsigned int size;
    PACK(p1,2);
    unsigned char hash[H];
};
struct image{
    unsigned char sig[N];  // signature of header
    unsigned char exp[N];
    unsigned char mod[N];  // n in modexp
    unsigned int num;      // total number of blocks
    PACK(p0, 2);
    struct modules module[1];
};

enum status{
    UNDET,
    FAIL,
    PASS
};

//public key hash
CODE unsigned char pkhash[20] = {0x37, 0x34, 0xA6, 0x83, 
                                   0x5F, 0xFC, 0xE0, 0x2B, 
                                   0xC6, 0xEE, 0xCB, 0x81, 
                                   0x6C, 0x92, 0x6C, 0x7C, 
                                   0xBA, 0x79, 0xCB, 0x8F};

#ifndef C
void quit() {
    /* FIXME
    P0 = P1 = P2 = P3 = 0xDE;
    P0 = P1 = P2 = P3 = 0xAD;
    P0 = P1 = P2 = P3 = 0x00;
    while(1);
    */
    return;
}
#endif

//void fail(unsigned char* failmes) {
void fail() {
#ifdef C
#ifndef CBMC
  //printf("%s\n", failmes);
#endif
#else
  //(void)failmes;
  // P0 = 0; FIXME
  quit();
#endif
}

#ifdef CBMC
void meminit(struct image* image)
{
    int i;
    image->sig[nondet_uint()%N] = nondet_uchar();
    image->exp[nondet_uint()%N] = nondet_uchar();
    image->mod[nondet_uint()%N] = nondet_uchar();
    image->num = nondet_uint();
    for(i=0; i<2; i++){
        image->module[0].addr = nondet_uint();
        image->module[0].size = nondet_uint();
        image->module[0].hash[nondet_uint()%H] = nondet_uchar();
    }
}
#endif

int main() {
    // assumptions on memory mapped address. 
    assume (&sha_ptr == (struct sha_reg_struct*)0xFE00);
    assume (&memwr_ptr == (struct acc_regs*)0xF9F0);
    //assume (&rsa_ptr == (struct RSA_regs*)0xFA00);
    assume (&rsa_ptr == (struct RSA_regs*)(0xFD00-48));
    assume (sha_ptr.state == 0);
    assume (rsa_ptr.state == 0);

    /*
    program = (unsigned char*)0x0000;
    boot = (unsigned char*)0x5000;
    sha_in = (unsigned char*)0xC000;
    sha_out = (unsigned char*)0xE100;
    rsa_out = (unsigned char*)0xE200;
    */
    assume (program == (unsigned char*)0x0000);
    assume (boot == (unsigned char*)0x5000);
    assume (sha_in == (unsigned char*)0xC000);
    assume (sha_out == (unsigned char*)0xE100);
    assume (rsa_out == (unsigned char*)0xE200);

    unsigned int i, j;
    unsigned int num;   // total number of blocks
    struct image* im;
    struct modules* block; // current block
    unsigned int size;
    unsigned char* moddata;
    unsigned int ldaddr = 0;
    enum status pass = UNDET;
#ifdef C
    int pages[5];
#endif
#ifdef CBMC
    // unsigned char before, after;
    unsigned int compind;
    // is the image valid?
    unsigned char key_val = nondet_uchar();
    unsigned char sig_val = nondet_uchar();
    unsigned char addr_val = 1;
#endif

    //sassert (pass != FAIL);
    int stage = 0;

    // STAGE 0: set up
    pt_init();
#ifdef C
    // put new arrays in mem
    boot = mem_add(MAX_IM_SIZE);
    program = mem_add(MAX_PRG_SIZE);
    sha_in = mem_add(MAX_IM_SIZE+0x40);
    sha_out = mem_add(H);
    rsa_out = mem_add(N);
    // put new arrays into pt
    pages[BOOT] = pt_add(boot, MAX_IM_SIZE);
    pages[PRG] = pt_add(program, MAX_PRG_SIZE);
    pages[SHAI] = pt_add(sha_in, MAX_IM_SIZE+0x40);
    pages[SHAO] = pt_add(sha_out, H);
    pages[RSAO] = pt_add(rsa_out, N);
#endif

    // set SHA read and write addresses
    unlock(SHA, (unsigned char*)&sha_regs.rd_addr, (unsigned char*)(&sha_regs.wr_addr+1));
    writeptr(SHA, &sha_regs.rd_addr, sha_in);
    writeptr(SHA, &sha_regs.wr_addr, sha_out);
    lock(SHA, (unsigned char*)&sha_regs.rd_addr, (unsigned char*)(&sha_regs.wr_addr+1));
    //sassert (sha_regs.rd_addr == sha_in);
    //sassert (sha_regs.wr_addr == sha_out);
    // unlock memwr registers
    unlock(MEMWR, (unsigned char*)&memwr_regs.start, (unsigned char*)(&memwr_regs+1));
    // set up RSA
    unlock(RSA, (unsigned char*)&rsa_regs.opaddr, (unsigned char*)(&rsa_regs.opaddr+1));
    writeptr(RSA, &rsa_regs.opaddr, rsa_out);  // set up address to write to
    lock(RSA, (unsigned char*)&rsa_regs.opaddr, (unsigned char*)(&rsa_regs.opaddr+1));

    if(!RSAinit(rsa_out, sha_in, sha_out)){
        pass = FAIL;
        //fail("invalid input/output addresses");
        return 0;
    }

    //sassert (stage == 0);
    stage = 1;
    // STAGE 1: read image into RAM  
    unlock(pages[BOOT], boot, boot+MAX_IM_SIZE);
#ifndef CBMC  // for CBMC just use initialized values
    load(0, MAX_IM_SIZE, boot, 1);
#else
    meminit((struct image*)boot);
/*
    compind = nondet_uint() % MAX_IM_SIZE;  // checking image locking
    before = boot[compind[0]];
    // something might break the image here
    if(nondet_uint())
        writec(nondet_int(), nondet_ptr(), nondet_uchar(), 0);
*/
#endif
    // image is loaded.
    // now we need to lock boot to boot + MAX_IM_SIZE
    lock(pages[BOOT], boot, boot+MAX_IM_SIZE);
    //sassert (pass != FAIL);

    //sassert (stage == 1);
    stage = 2;
    // STAGE 2: check that key matches hash
    im  = (struct image*) boot;
    // set signature key
    unlock(RSA_KEYS, rsa_regs.exp, rsa_regs.exp+N);
    writecarr(RSA_KEYS, rsa_regs.exp, im->exp, N);
    lock(RSA_KEYS, rsa_regs.exp, rsa_regs.exp+N);
    // set signature modulus
    unlock(RSA_KEYS, rsa_regs.n, rsa_regs.n+N);
    writecarr(RSA_KEYS, rsa_regs.n, im->mod, N);
    lock(RSA_KEYS, rsa_regs.n, rsa_regs.n+N);
    // check the hashes
    //sassert (sha_regs.state == 0);
    sha1(rsa_regs.exp, 2*N);
    //sassert (sha_regs.state == 0);
    //sassert (0);
#ifndef CBMC
    /*
    for(i=0; i<H; i++){
        if(sha_out[i] != pkhash[i]){
            pass = FAIL;  // FAIL: key hash mismatch
            //fail("key hash mismatch");
            return 0;
        }
    }
    */
    if (nd()) {
        pass = FAIL;
        return 0;
    }
#else
    // key in image was incorrect, or image has been compromised
    if(!key_val || !pt_valid(pages[BOOT]) ||
       !pt_valid(RSA_KEYS)) // keys copied incorrectly
    {
        pass = FAIL;
        return 0;
    }
#endif
    //sassert (0);
    //sassert (pass != FAIL);

//#ifdef CBMC
//    assert(size <= MAX_IM_SIZE);
//    __CPROVER_assume(size <= MAX_IM_SIZE);
//#endif

    //sassert (stage == 2);
    stage = 3;
    // STAGE 3: verify signature in boot
    num = im->num & 0xFFFF;  // number of modules

    // sizeof image struct includes extra signature and first module
    size = sizeof(struct image) - (im->exp -(unsigned char*)im) + sizeof(struct modules) * (num-1);

    if(size > MAX_IM_SIZE)
    {
        pass = FAIL; // FAIL: image too large
        //fail("header too large");
        return 0;
    }
/*
#ifdef CBMC
    if(nondet_uint())
        writec(nondet_int(), nondet_ptr(), nondet_uint(), 0);
#endif
*/
    if(!verifySignature(im->exp, size, im->sig))
    {
        pass = FAIL;  // FAIL: signature mismatch
        //fail("signature mismatch");
        return 0;
    }

    //sassert (pass != FAIL);

    //sassert (stage == 3);
    stage = 4;
    // STAGE 4: load blocks
    if(num == 0){  // no blocks to load, done
        pass = PASS;
        return 0;
    }

    unlock(pages[PRG], program, program + MAX_PRG_SIZE);  // unlock memory space for program
    block = im->module;  // block data in header
    moddata = (unsigned char*)(block + num); // program data of this module
    size = 0;

    for(i=0; i<num; i++)
    {
/*
#ifdef CBMC
        unsigned int ldaddr2 = ldaddr;  // checking program loading
        unsigned int size2 = size;
#endif
*/
        // check that size and address are valid
        size = block->size & 0xFFFF;     // size of current module
        ldaddr = block->addr;   // address to load this module into
//      __CPROVER_assume(size!=0);  // checking program loading
        // the data does not fit inside the image
        if(moddata + size > boot + MAX_IM_SIZE ||
           moddata + size < moddata)  // overflow
        {
            //addr_val = 0;
            pass = FAIL;
            //fail("data does not fit in image");
            return 0;
        }
        // the data does not fit in memory range allocated for it
        if(size + ldaddr > MAX_PRG_SIZE ||
           ldaddr + size < ldaddr)
        {
            //addr_val = 0;
            pass = FAIL;
            //fail("program write out of range");
            return 0;
        }

#ifdef CBMC
        if(ldaddr < ldaddr2+size2 && ldaddr2 < ldaddr+size)
            addr_val = 0;
//      if(i == 0)  // checking program loading
//          compind = (nondet_uint()%size);
#endif 
        // load data
        load(moddata, size, program+ldaddr, 0);
//      assert(program[ldaddr+compind]==moddata[compind]);  // checking module loading
        // update to next module
        moddata += size;
        block++;
    }
/*
#ifdef CBMC
    if(nondet_uint())
        writec(nondet_int(), nondet_ptr(), nondet_uint(), 0);
#endif
*/
    // lock newly loaded data
    lock(pages[PRG], program, program + MAX_PRG_SIZE);

    block = im->module;  // go back to first module
    moddata = (unsigned char*)(block + num); // program data of this module
//    ldaddr = block->addr;  // checking program loading
//    assert(!addr_val || program[ldaddr+compind]==moddata[compind]);

    int checkHash = 0;
    for(i=0; i<num; i++)
    {
        unsigned int ldaddr;
        size = block->size & 0xFFFF;     // size of current module
        ldaddr = block->addr;   // address to load this module into

        // check module hash
        sha1(program+ldaddr, size);
#ifndef CBMC
        for(j=0; j<H; j++){
            checkHash = 1;
            if(sha_out[j] != block->hash[j]){
                pass = FAIL;
                //fail("module hash mismatch");
                return 0;
            }
        }
#endif
        // update to next module
        moddata += size;
        block++;
    }
    //sassert (checkHash);
#ifdef CBMC
    // fail if modules overlap, or image or program was corrupted
    if(!addr_val || !pt_valid(pages[BOOT]) || !pt_valid(pages[PRG]))
    {
        pass = FAIL;
        return 0;
    }
#endif
#ifndef CBMC
    // check that program loaded correctly, for testing only
    for(i=0; i<moddata-(unsigned char*)block; i++){
        // FIXME
        // P0 = program[i];
        if(program[i] != *((unsigned char*)block + i)){
            pass = FAIL;  // FAIL
            //fail("load is wrong");
            break;
        }
    }
#endif
    //sassert (pass != FAIL);
    // PASS or FAIL
    if(pass != FAIL)
        pass = PASS;
    //unlock_wr(boot, boot+MAX_IM_SIZE);
    //unlock_wr((unsigned char*)&sha_regs.rd_addr, (unsigned char*)(&sha_regs.rd_addr+1));
    //unlock_wr((unsigned char*)&sha_regs.wr_addr, (unsigned char*)(&sha_regs.wr_addr+1));
    //unlock_wr((unsigned char*)&rsa_regs.opaddr, (unsigned char*)(&rsa_regs.opaddr+1));

    // FIXME
    // P0 = pass;

    //sassert (pass == PASS);
#ifdef CBMC
//    after = boot[compind];  // checking image locking
//    assert(after==before || !pt_valid(pages[BOOT]));
#else
#ifdef C
    printf("pass: %d\n", pass);
#else
    quit();
#endif
#endif
    return 0;
}

