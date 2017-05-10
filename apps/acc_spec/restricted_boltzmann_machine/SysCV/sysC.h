// dummy class for dealing with system C

extern "C" void *__CPROVER_malloc(size_t size);

namespace std
{
	class iocout
	{
        public:
		iocout & operator << (const char *) {}
		iocout & operator << (int) {} 
		iocout & operator << (float) {} 
	};
	iocout cout;
	int endl;
}

class sc_signal_bool
{
public:
    sc_signal_bool(){}
    sc_signal_bool(const char *p) {}
    bool data;
    bool read() {return data;}
    void write(const bool &d) {data = d;}
    bool operator =(const bool & d) {data = d; return data;}
    operator bool & () {return data;}

    bool pos() { return data;} // no use
};
#define sc_in_bool sc_signal_bool
#define sc_out_bool sc_signal_bool

class sc_signal_u32
{
public:
    sc_signal_u32(){}
    sc_signal_u32(const char *p) {}
    u32 data;
    u32 read() {return data;}
    void write(const u32 &d) {data = d;}
    u32 operator =(const u32 & d) {data = d; return data;}
    operator u32 & () {return data;}

    u32 pos() { return data;} // no use
};
#define sc_in_u32 sc_signal_u32
#define sc_out_u32 sc_signal_u32

class sc_signal_u16
{
public:
    sc_signal_u16(){}
    sc_signal_u16(const char *p) {}
    u16 data;
    u16 read() {return data;}
    void write(const u16 &d) {data = d;}
    u16 operator =(const u16 & d) {data = d; return data;}
    operator u16 & () {return data;}

    u16 pos() { return data;} // no use
};
#define sc_in_u16 sc_signal_u16
#define sc_out_u16 sc_signal_u16

class sc_signal_int32
{
public:
    sc_signal_int32(){}
    sc_signal_int32(const char *p) {}
    int32 data;
    int32 read() {return data;}
    void write(const int32 &d) {data = d;}
    int32 operator =(const int32 & d) {data = d; return data;}
    operator int32 & () {return data;}

    int32 pos() { return data;} // no use
};

/*
template <class T>
class sc_signal
{
public:
    sc_signal(){}
    sc_signal(const char *p) {}
    T data;
    T read() {return data;}
    void write(const T &d) {data = d;}
    T operator =(const T & d) {data = d; return data;}
    operator T & () {return data;}

    T pos() { return data;} // no use
};

#define sc_out sc_signal
#define sc_in sc_signal
*/

extern int cycleCnt;
void wait()
{
    cycleCnt ++;
}
void reset_signal_is (int , bool) {} // do nothing
void set_stack_size(int) {} // do nothing



#define SC_MODULE(user_module_name)  struct user_module_name 
#define SC_CTOR(user_module_name)  user_module_name()
#define SC_CTHREAD(func_name, clock_name) do{} while(0)


template <class Tp, unsigned Depth>
class SysCArray1D
{
public:
    Tp *arrayPnt;
    SysCArray1D()
    {
        arrayPnt = (Tp *)  __CPROVER_malloc(sizeof(Tp) * Depth);
    }
    Tp& operator[] (unsigned idx){
        return arrayPnt[idx];
    }

};

template <class Tp, unsigned xDepth, unsigned yDepth>
class SysCArray2Dst
{
public:
    SysCArray2Dst()
    {
        arrayPnt = (Tp *) __CPROVER_malloc(sizeof(Tp) * xDepth*yDepth);
        arrayPnt0= (Tp *) __CPROVER_malloc(sizeof(Tp) * 1*yDepth);
    }
    Tp* arrayPnt;
    Tp* arrayPnt0;
    Tp* operator[] (unsigned Xidx){
        if(Xidx == 0)
            return arrayPnt0;
        return &(arrayPnt[Xidx*yDepth]);
    }
};

template <class Tp, unsigned xDepth, unsigned yDepth>
class SysCArray2D
{
public:
    SysCArray2D()
    {
    	unsigned eqsize;
    	unsigned acsize = xDepth*yDepth;
    	
    	if(acsize == 1)
    		eqsize = 1;
    	else if(acsize == 2)
    		eqsize = 2;
    	else if(acsize >2 && acsize <=4)
    		eqsize = 4;
    	else if (acsize > 4 && acsize <= 8 ) 
			eqsize = 8;
		else if (acsize > 8 && acsize <= 16 ) 
			eqsize = 16;
		else if (acsize > 16 && acsize <= 32 ) 
			eqsize = 32;
		else if (acsize > 32 && acsize <= 64 ) 
			eqsize = 64;
		else if (acsize > 64 && acsize <= 128 ) 
			eqsize = 128;
		else if (acsize > 128 && acsize <= 256 ) 
			eqsize = 256;
		else if (acsize > 256 && acsize <= 512 ) 
			eqsize = 512;
		else if (acsize > 512 && acsize <= 1024 ) 
			eqsize = 1024;
		else if (acsize > 1024 && acsize <= 2048 ) 
			eqsize = 2048;
		else if (acsize > 2048 && acsize <= 4096 ) 
			eqsize = 4096;
		else if (acsize > 4096 && acsize <= 8192 ) 
			eqsize = 8192;
		else if (acsize > 8192 && acsize <= 16384 ) 
			eqsize = 16384;
		else if (acsize > 16384 && acsize <= 32768 ) 
			eqsize = 32768;
		else if (acsize > 32768 && acsize <= 65536 ) 
			eqsize = 65536;

        arrayPnt = (Tp *) __CPROVER_malloc(sizeof(Tp) * eqsize);        
    }
    Tp* arrayPnt;
    Tp* operator[] (unsigned Xidx){
        return &(arrayPnt[Xidx*yDepth]);
    }
};
