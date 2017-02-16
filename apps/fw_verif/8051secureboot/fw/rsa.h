#ifndef RSA_H
#define RSA_H

#ifdef CBMC
#ifndef C
#define C
#endif
#endif

#ifdef C
#define MEM_SIZE (MAX_IM_SIZE*2 + MAX_PRG_SIZE + 4*N + 2*H + 0x40 + 3*sizeof(struct acc_regs))
#define FRONT (MAX_PRG_SIZE + MAX_IM_SIZE)
#define GAP   (0x10000-MEM_SIZE)
#define XDATA_VAR(addr, type, name) type* name
#define XDATA_ARR(addr, size, type, name) type* name
#define XDATA
#define CODE
#else
/* FIXME
#define XDATA_VAR(addr, type, name) __xdata __at(addr) type name
#define XDATA_ARR(addr, size, type, name) __xdata __at(addr) type name[size]
#define XDATA __xdata
#define CODE __code
*/
#define XDATA_VAR(addr, type, name) type name
//#define XDATA_ARR(addr, size, type, name) type name[size]
#define XDATA_ARR(addr, size, type, name) type* name// = new type [size]
#define XDATA 
#define CODE
#endif

#ifdef CBMC 
#define MAX_PRG_SIZE 50
#define MAX_IM_SIZE  100
#define N 16
#define H 4
#define K1 4
#define K2 4
#define BUFF_SIZE 100
#else
// XXX
/*
#define MAX_PRG_SIZE 0x3000
#define MAX_IM_SIZE  0x2000
#define N 256
#define H 20
#define K1 16
#define K2 16
*/
// XXX
#define MAX_PRG_SIZE 50
#define MAX_IM_SIZE  100
#define N 16
#define H 4
#define K1 4
#define K2 4
#define BUFF_SIZE 100
// XXX
#ifdef C
#define BUFF_SIZE 0x2000
#endif
#endif

#ifdef C
// pages in pt
#define MEMWR    0
#define RSA_M    1
#define RSA_KEYS 2
#define RSA      3
#define SHA      4

unsigned char* mem_add(unsigned int size);
int pt_add(unsigned char* start, unsigned int size);
int pt_valid(int page);
int pt_reset(int page);
int pt_find(unsigned char* start);
int writec(int page, unsigned char* addr, unsigned char data, unsigned char trusted);
int writecarr(int page, unsigned char* addr, unsigned char* data, unsigned int len);
int writeptr(int page, unsigned char** addr, unsigned char* data);
int lock(int page, unsigned char* startaddr, unsigned char* endaddr);
int unlock(int page, unsigned char* startaddr, unsigned char* endaddr);
#else
/* FIXME
#define pt_reset(page) 
#define writec(page, addr, data, trusted) *(addr) = data
#define writecarr(page, addr, data, len) for(i=0; i<len; i++) (addr)[i]=(data)[i]
#define writei(page, addr, data) *(addr) = data;
#define writeptr(page, addr, data) *(addr) = data
#define lock(page, start, end) lock_wr(start, end)
#define unlock(page, start, end) unlock_wr(start, end)
*/ 

extern int nd();

extern void HW_REG_WRITE_chr(unsigned char* addr, unsigned char data);
extern void HW_REG_WRITE_int(unsigned int* addr, int data);
extern void HW_REG_WRITE_ptr(unsigned char** addr, unsigned char* data);

void writecWrap (unsigned char* addr, unsigned char data);
#define writec(page, addr, data, trusted) writecWrap(addr, data)
//#define writec(page, addr, data, trusted) HW_REG_WRITE_chr(addr, data)
void writeiWrap (unsigned int* addr, int data);
#define writei(page, addr, data) *(addr) = data
//#define writei(page, addr, data) writeiWrap(addr, data)
//#define writei(page, addr, data) HW_REG_WRITE_int(addr, data)
void writepWrap (unsigned char** addr, unsigned char* data);
#define writeptr(page, addr, data) *(addr) = data
//#define writeptr(page, addr, data) writepWrap(addr, data)
//#define writeptr(page, addr, data) HW_REG_WRITE_ptr(addr, data)
void writeaWrap (unsigned char* addr, unsigned char* data, int len);
#define writecarr(page, addr, data, len) writeaWrap(addr, data, len)

extern unsigned char HW_REG_READ_chr (unsigned char* addr);
unsigned char readcWrap (unsigned char* addr);
#define readc(addr) readcWrap(addr)

#define pt_reset(page)
#define lock(page, start, end) lock_wr(start, end)
#define unlock(page, start, end) unlock_wr(start, end)

int unlock_wr(unsigned char* startaddr, unsigned char* endaddr);
int lock_wr(unsigned char* startaddr, unsigned char* endaddr);
#endif

#ifndef CBMC
#define assert(exp) 
#endif

struct RSAmsg{
    unsigned char padbyte;
    unsigned char m[N-K2-K1-1];
    unsigned char zeros[K1];
    unsigned char r[K2];
};

struct acc_regs{
    unsigned char start;
    unsigned char state;
    XDATA unsigned char *rd_addr;
    XDATA unsigned char *wr_addr;
    unsigned int len;
};

struct sha_reg_struct {
    unsigned char start;
    unsigned char state;
    unsigned char *rd_addr;
    unsigned char *wr_addr;
    unsigned int len;
    unsigned int bytes_read;
    unsigned char hs_data[160];
    unsigned char rd_data[520];
};

struct RSA_regs{
    struct RSAmsg m;
    unsigned char exp[N];
    unsigned char n[N];
    unsigned char start;
    unsigned char state;
    unsigned char *opaddr;
    int byte_counter;
};
#ifdef C
extern unsigned char mem[];
#define sha_regs (*sha_ptr)
#define memwr_regs (*memwr_ptr)
#define rsa_regs (*rsa_ptr)
#else
#define sha_ptr sha_regs
#define memwr_ptr memwr_regs
#define rsa_ptr rsa_regs
#endif

#ifdef CBMC
extern unsigned char valid;
#endif

//extern XDATA_VAR(0xFE00, struct acc_regs, sha_ptr);
extern XDATA_VAR(0xFE00, struct sha_reg_struct, sha_ptr);
extern XDATA_VAR(0xF9F0, struct acc_regs, memwr_ptr);
extern XDATA_VAR(0xFA00, struct RSA_regs, rsa_ptr);

unsigned char* mem_add(unsigned int size);
void pt_init(void);
unsigned char RSAinit(unsigned char* rsa_out, unsigned char* sha_in, unsigned char* sha_out);
void load(unsigned char* data, unsigned int length, unsigned char* startaddr, unsigned char skipread);
unsigned char sha1(unsigned char *m, unsigned int len);
unsigned char verifySignature(unsigned char* msg, unsigned int len, unsigned char* signature);

#endif
