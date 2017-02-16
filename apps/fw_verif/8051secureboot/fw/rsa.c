#ifdef C
#ifndef CBMC
#include <openssl/sha.h>
#include <openssl/bn.h>
#include <string.h>
#endif
#endif
#include "rsa.h"

#include "seahorn/seahorn.h"

//XDATA_VAR(0xFE00, struct acc_regs, sha_ptr);
XDATA_VAR(0xFE00, struct sha_reg_struct, sha_ptr);
XDATA_VAR(0xF9F0, struct acc_regs, memwr_ptr);
XDATA_VAR(0xFA00, struct RSA_regs, rsa_ptr);

//struct hs_data sha_hs_data;

struct RSAmsg *decrypted;
unsigned char *sha_m;
unsigned char *hash;

__attribute__((optnone))
void HW_REG_WRITE_chr(unsigned char* addr, unsigned char data) {
    sha_ptr.start = data + *addr;
    rsa_ptr.start = data + *addr;
    *addr = data;
}

__attribute__((optnone))
void HW_REG_WRITE_int (unsigned int* addr, int data) {
    //sha_ptr.len = data + *addr;
    *addr = data;
}

__attribute__((optnone))
void HW_REG_WRITE_ptr (unsigned char** addr, unsigned char* data) {
    //sha_ptr.rd_addr = data;
    //sha_ptr.rd_addr = *addr;
    *addr = data;
}

void writecWrap (unsigned char* addr, unsigned char data)
{
    // assertion on memory address check
    //sassert (addr == &sha_ptr.start || addr == &sha_ptr.state || 
    //         addr == &memwr_ptr.start || addr == &memwr_ptr.state);
    // MMIO
    //*addr = data;
    //return;
    if (addr == &sha_ptr.start || addr == &sha_ptr.state || 
        addr == &rsa_ptr.start || addr == &rsa_ptr.state) {
        HW_REG_WRITE_chr (addr, data);
    } else {
        *addr = data;
    }
    return;
}

void writeiWrap (unsigned int* addr, int data)
{
    // assertion on memory address check
    //sassert (addr == &sha_ptr.len || addr == &memwr_ptr.len);

    // MMIO
    *addr = data;
    return;
    /*
    if (addr == &sha_ptr.len) {
        HW_REG_WRITE_int (addr, data);
    } else {
        *addr = data;
    }
    return;
    */
}

void writepWrap (unsigned char** addr, unsigned char* data)
{
    // assertion on memory address check
    //sassert (addr == &sha_ptr.rd_addr || addr == &sha_ptr.wr_addr || 
    //         addr == &memwr_ptr.rd_addr || addr == &memwr_ptr.wr_addr);
    // MMIO
    *addr = data;
    return;
    /*
    if (addr == &sha_ptr.rd_addr || addr == &sha_ptr.wr_addr) {
        HW_REG_WRITE_ptr (addr, data);
    } else {
        *addr = data;
    }
    return;
    */
}

void writeaWrap (unsigned char* addr, unsigned char* data, int len)
{
    //for (int i=0; i<len; i++)
        //writecWrap (addr+i, data[i]);
    // FIXME
    for (int i=0; i<2; i++)
        addr[i] = data[i];
}

__attribute__((optnone))
unsigned char HW_REG_READ_chr (unsigned char* addr) 
{
    rsa_ptr.state = *addr;
    return sha_ptr.state + *addr;
}

unsigned char readcWrap (unsigned char* addr)
{
    if ((addr == &sha_ptr.state) || (addr == &sha_ptr.start) ||
        (addr == &rsa_ptr.start) || (addr == &rsa_ptr.state)) {
        return HW_REG_READ_chr (addr);
    } else {
        return *addr;
    }
}

#ifndef C
XDATA_ARR(0xFF80, 32, unsigned char, pt_wren);
XDATA_ARR(0xFFA0, 32, unsigned char, pt_rden);
#endif

// state of PRG for G in OAEP
XDATA_ARR(0xF8E0, H, unsigned char, gprg);

// initialize pt with registers and state arrays
void pt_init()
{
    //assume (pt_rden == (unsigned char*)0xFFA0);
    pt_rden = (unsigned char*)0xFFA0;
    unsigned int i;
    for(i=0; i<32; i++)
        pt_rden[i] = 0xFF;
}

// set input and output addresses of HW accelerators
// these should not be changed for the duration of secureboot
unsigned char RSAinit(unsigned char* rsa_out, unsigned char* sha_in, unsigned char* sha_out)
{
    decrypted = (struct RSAmsg*)rsa_out;
    sha_m = sha_in;
    hash = sha_out;
    //sassert (sha_m == sha_in);
    //sassert (hash == sha_out);
    return 1;
}
// set up data transfer
// copy data of length bytes to startaddr
// if skipread, don't read from data, just write values already in memwr buffer to startaddr
void load(unsigned char* data, unsigned int length, unsigned char* startaddr, unsigned char skipread)
{
    writeptr(MEMWR, &memwr_regs.rd_addr,(XDATA unsigned char*)data);
    writeptr(MEMWR, &memwr_regs.wr_addr, (XDATA unsigned char*)startaddr);
    writei(MEMWR, &memwr_regs.len, length);
    writec(MEMWR, &memwr_regs.start, (unsigned char)(skipread << 1 | 1), 1); // load in HW

    //c_load(skipread);  // load in SW
    // wait for load to finish
    // FIXME
    /*
    for (unsigned int i = 0; i < length; i++) {
        startaddr[i] = data[i];
    }
    */
    //while(memwr_regs.state != 0);
}

// returns length of message
int unpad()
{
  int len;

  for(len = sizeof(rsa_regs.m.m)-1; len>=0; len--)
  {
      if(decrypted->m[len] == 1)
          break;
      else if(decrypted->m[len] != 0)
          return -1;
  }
  return len;
}

// set up message and compute SHA
unsigned char sha1(unsigned char *m, unsigned int len)
{
    unsigned int i;
    unsigned int mlen;

    //assume (sha_ptr.state == 0);
    //sassert (sha_ptr.state == 0);
    //assume (rsa_ptr.state == 0);
    //sassert (sha_regs.rd_addr == sha_m);
    
    // addresses have changed
    //sassert (sha_regs.rd_addr == sha_m);
    //sassert (sha_regs.wr_addr == hash);
    if(sha_regs.rd_addr != sha_m || sha_regs.wr_addr != hash)
        return 0;

    // setup data
    mlen = ((len+4) & 0xFFC0) + 64; // round len+5 up to multiple of 64

    // FIXME
    //pt.valid[pshai]=1; // reset validity of sha input
    unlock(pshai, sha_regs.rd_addr, sha_regs.rd_addr+mlen);

    if(m != sha_regs.rd_addr) // don't copy if already in right address
        load(m, len, sha_regs.rd_addr, 0); // copy m

    // add 100.. padding
    writec(pshai, sha_regs.rd_addr+len, 0x80, 1);

    //assume (rsa_ptr.state == 0);
    for(i=len+1; i<mlen; i++)
        writec(pshai, sha_regs.rd_addr+i, 0, 1);
    //sassert (rsa_ptr.state == 0);

    // insert length in bits
    writec(pshai, sha_regs.rd_addr+mlen-1, (len << 3) & 0xFF, 1);
    writec(pshai, sha_regs.rd_addr+mlen-2, (len >> 5) & 0xFF, 1);
    writec(pshai, sha_regs.rd_addr+mlen-3, (len >> 13) & 0xFF, 1);

    // encrypt with sha1
    lock(pshai, sha_regs.rd_addr, sha_regs.rd_addr+mlen);
    //pt.valid[pshao]=1; // reset validity of sha output
    unlock(pshao, sha_regs.wr_addr, sha_regs.wr_addr+H);
    //pt.valid[SHA]=1;

    //sassert (sha_ptr.state == 0);

    unlock(SHA, &sha_regs.start, (unsigned char*)(&sha_regs.len));
    writei(SHA, &sha_regs.len, mlen);
    writec(SHA, &sha_regs.start, 1, 1);  // start HW

    //sassert (sha_ptr.state == 0);
    //sassert (readc(&sha_regs.state) == 0);
    //sassert (sha_ptr.state == 1);
    //sassert (readc(&sha_regs.state) == 1);
    //sassert (sha_ptr.state != 1);

    writec(SHA, &sha_regs.state, 1, 1);  // XXX encoded bug

    //sassert (sha_ptr.state == 0);
    //sassert (readc(&sha_regs.state) == 0);

    //c_sha(len);         // do SW

    //while(sha_regs.state != 0);
    while (readc(&sha_regs.state) != 0);
    /*
    int cnt = 0;
    while (readc(&sha_regs.state) != 0) {
        cnt += 1;
    }
    assume (cnt <= 2);
    */

    //sassert (sha_ptr.state == 0);
    //sassert (readc(&sha_regs.state) == 0);
    //if (nd()) sassert (0);
    //sassert (0);

    lock(pshao, sha_regs.wr_addr, sha_regs.wr_addr+H);
    lock(SHA, &sha_regs.start, (unsigned char*)(&sha_regs.len));
    return 1;
}

// HMAC computed and written to sha_regs.wr_addr
void HMAC(const unsigned char *key, unsigned int klen, const unsigned char *message, unsigned int mlen)
{
    unsigned int i;
    // inner hash
    unlock(page, sha_regs.rd_addr, sha_regs.rd_addr+mlen+64);
    for(i=0; i<klen; i++)
        writec(page, sha_regs.rd_addr+i, key[i] ^ 0x36, 1);
    for(i=klen; i<64;i++)
        writec(page, sha_regs.rd_addr+i, 0x36, 1);
    for(i=0; i<mlen; i++)
        writec(page, sha_regs.rd_addr+i+64, message[i], 1);

    sha1(sha_regs.rd_addr, 64+mlen);

    // outer hash
    unlock(page, sha_regs.rd_addr, sha_regs.rd_addr+84);
    for(i=0; i<klen; i++)
        writec(page, sha_regs.rd_addr+i, key[i] ^ 0x5c, 1);
    for(i=klen; i<64;i++)
        writec(page, sha_regs.rd_addr+i, 0x5c, 1);
    for(i=0; i<H; i++)
        writec(page, sha_regs.rd_addr+i+64, sha_regs.wr_addr[i], 1);

    sha1(sha_regs.rd_addr, 64 + H);
}

// copy seed into the PRG state
void PRGinit(unsigned char *seed, unsigned int slen, unsigned char *state)
{
    unsigned int i;
    if(slen > H) slen = H;
    unlock(page, state, state+H);
    writecarr(page, state, seed, slen);
    for(i=slen; i<H; i++)
        writec(page, state+i, 0, 1);
    lock(page, state, state+H);
}

// random zero and one for PRG
const unsigned char zero[] = {0x98, 0xBC, 0x1B, 0x58,
                             0xC2, 0x5B, 0x7B, 0x51,
                             0x48, 0x14, 0x83, 0xA7,
                             0xEA, 0xDB, 0x15, 0x2E,
                             0xCE, 0x7A, 0xE1, 0x0C,
                             0xF7, 0x1D, 0x96, 0xDE,
                             0xDE, 0x16, 0x68, 0x61,
                             0x48, 0x25, 0x99, 0x66};

const unsigned char one[] = {0xA2, 0x66, 0x95, 0x53,
                             0x0E, 0x13, 0x56, 0xA9,
                             0xDF, 0x42, 0x6F, 0x0F,
                             0x74, 0xA4, 0x06, 0xFF,
                             0xA0, 0x6D, 0x07, 0x17,
                             0x30, 0xAE, 0x16, 0xD2,
                             0x87, 0x76, 0x8A, 0x9B,
                             0x92, 0xAE, 0x36, 0xB9};


// generate random number, put in hash
void PRG(unsigned char* state)
{
    unsigned int i;
    unsigned char next[H];
    // compute next state
    HMAC(state, H, one, 32);
    for(i=0; i<H; i++)
        next[i] = sha_regs.wr_addr[i];

    // compute next output
    HMAC(state, H, zero, 32);
    unlock(page, state, state+H);
    writecarr(page, state, next, H);
    lock(page, state, state+H);
}

// seed for computing H function in OAEP
const unsigned char Hseed[] = {
    0x66, 0x02, 0x5D, 0xC9,
    0x80, 0x48, 0xA5, 0x9F,
    0x2C, 0xB3, 0xAA, 0x6C,
    0x1A, 0x81, 0xA9, 0xAA,
    0xE8, 0x93, 0x21, 0x0E/*,
    0x24, 0x99, 0x6F, 0x06,
    0xEB, 0xC0, 0x4F, 0x3A,
    0x0D, 0x2F, 0x8F, 0x0A*/
};

// remove OAEP from message at location rsa_regs.opaddr
void removeOAEP()
{
    // FIXME
    assume (gprg == (unsigned char*)0xF8E0);

    unsigned int i,j;
    // compute r
    HMAC(Hseed, H, decrypted->m, N-K2-1);
    // copy r to message
    unlock(page, rsa_regs.opaddr, rsa_regs.opaddr + N);
    for(i=0; i< K2; i++)
        writec(page, decrypted->r+i,decrypted->r[i] ^ sha_regs.wr_addr[i], 1);
    lock(page, rsa_regs.opaddr, rsa_regs.opaddr+N);

    // find m
    PRGinit(decrypted->r, K2, gprg);
    PRG(gprg);
    unlock(page, rsa_regs.opaddr, rsa_regs.opaddr + N);
    i=0; j=0;
    while(i < N-K2-1)
    {
        if(j == H)
        {
            lock(page, rsa_regs.opaddr, rsa_regs.opaddr+N);
            PRG(gprg);
            j = 0;
            unlock(page, rsa_regs.opaddr, rsa_regs.opaddr + N);
        }
        writec(page, decrypted->m+i, decrypted->m[i] ^ sha_regs.wr_addr[j], 1);
        i++;
        j++;
    }
    lock(page, rsa_regs.opaddr, rsa_regs.opaddr+N);
}

// decrypt msg, puts decrypted text in rsa_regs.opaddr
// returns length of decrypted message
int decrypt(unsigned char* msg){
    unsigned int i;

    //assume (rsa_ptr.state == 0);
    //if (nd()) sassert (rsa_ptr.state = 0);

    // copy msg into RSA m register
    if(msg != (unsigned char*)&rsa_regs.m)
    {
        unlock(RSA_M, (unsigned char*)&rsa_regs.m, (unsigned char*)&rsa_regs.m+N);
        //load(msg, N, (unsigned int)rsa_regs.m, 0);
        writecarr(RSA_M, (unsigned char*)&rsa_regs.m, msg, N);

        // lock message during exponentiation
        lock(RSA_M, (unsigned char*)&rsa_regs.m, (unsigned char*)&rsa_regs.m + N);
    }

    // decrypt
    unlock(prsao, rsa_regs.opaddr, rsa_regs.opaddr+N);
    //assume (rsa_regs.state == 0);
    unlock(RSA, &rsa_regs.start, (unsigned char*)(&rsa_regs.state+1));    

    //if (nd()) sassert (0);
    writec(RSA, &rsa_regs.start, 1, 1);

    //if (nd()) sassert (0);
    //sassert (rsa_ptr.state == 1);
    //sassert (readc(&rsa_ptr.state) == 0);

    //c_exp();  // c abstraction

    //sassert (rsa_ptr.state != 1);

    writec(RSA, &rsa_regs.state, 1, 1);

    //sassert (rsa_ptr.state == 0);
    //sassert (readc(&rsa_ptr.state) == 0);

    //char tmpState = rsa_regs.state;

    //if (nd()) sassert (0);

    //while(rsa_regs.state != 0);
    while (readc(&rsa_regs.state) != 0);

    //sassert (rsa_ptr.state == 0);
    //sassert (readc(&rsa_ptr.state) == 0);
    //if (nd()) sassert (0);

    //sassert (tmpState == 0);

    lock(prsao, rsa_regs.opaddr, rsa_regs.opaddr+N);
    lock(RSA, &rsa_regs.start, (unsigned char*)(&rsa_regs.state+1));    
    // check pad byte
    if(decrypted->padbyte != 1)
        return -1;
    
    removeOAEP();

    return unpad();
}

unsigned char verifySignature(unsigned char* msg, unsigned int len, unsigned char* signature){
    unsigned int i;
    int slen;

    // decrypt the signature
    //sassert (rsa_ptr.state == 0);
    slen = decrypt(signature);

    // compare with hash of msg
    if(slen != H)
        return 0;
    else{
        sha1(msg, len);
        for(i=0; i<H; i++){
            if(sha_regs.wr_addr[i] != decrypted->m[i])
                return 0;
        }
        return 1;
    }
}

