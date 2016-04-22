//-----------------------------------------------------------------------------

// Roman Lysecky, Tony Givargis, Greg Stitt, Ann Gordon-Ross, and 
// Kris Miller 
//
// Copyright (C) 2001, All Rights Reserved.

//-----------------------------------------------------------------------------

// 8051 Instruction Set Simulator 
// Version 1.4

//-----------------------------------------------------------------------------

#ifndef i8051_inc
#define i8051_inc

//-----------------------------------------------------------------------------

//#define DEBUG
//#define DEBUG_PC
//#define DETAIL
#define PORTS
//#define PROGRAM_COMPLETION ((unsigned char)RAM[P1] == 0x7F)

//-----------------------------------------------------------------------------

// constants

static const unsigned int RomSize = 65536;
static const unsigned int RamSize = 384;
static const unsigned int XRamSize = 65536;

//-----------------------------------------------------------------------------

enum Opcode {
    ACALL, ADD1,  ADD2,  ADD3,  ADD4,  ADDC1, ADDC2, ADDC3, ADDC4,
    AJMP,  ANL1,  ANL2,  ANL3,  ANL4,  ANL5,  ANL6,  ANL7,  ANL8, 
    CJNE1, CJNE2, CJNE3, CJNE4, CLR1,  CLR2,  CLR3,  CPL1,  CPL2,  
    CPL3,  DA,    DEC1,  DEC2,  DEC3,  DEC4,  DIV,   DJNZ1, DJNZ2, 
    INC1,  INC2,  INC3,  INC4,  INC5,  JB,    JBC,   JC,    JMP,   
    JNB,   JNC,   JNZ,   JZ,    LCALL, LJMP,  MOV1,  MOV2,  MOV3,  
    MOV4,  MOV5,  MOV6,  MOV7,  MOV8,  MOV9,  MOV10, MOV11, MOV12, 
    MOV13, MOV14, MOV15, MOV16, MOV17, MOV18, MOVC1, MOVC2, MOVX1, 
    MOVX2, MOVX3, MOVX4, MUL,   NOP,   ORL1,  ORL2,  ORL3,  ORL4,  
    ORL5,  ORL6,  ORL7,  ORL8,  POP,   PUSH,  RET,   RETI,  RL,    
    RLC,   RR,    RRC,   SETB1, SETB2, SJMP,  SUBB1, SUBB2, SUBB3, 
    SUBB4, SWAP,  XCH1,  XCH2,  XCH3,  XCHD,  XRL1,  XRL2,  XRL3,  
    XRL4,  XRL5,  XRL6
};

 //-----------------------------------------------------------------------------

class I8051 
{
  private:
    enum Flag { P, USER, OV, RS0, RS1, F0, AC, CY };

  private:
    const int InvalidData;
    const int LineLength;
    const int RecordTypeLength;
    
  private:
    const unsigned short ACC;
    const unsigned short PSW;
    const unsigned short B;
    const unsigned short SP;
    const unsigned short P0;
    const unsigned short P1;
    const unsigned short P2;
    const unsigned short P3;
    const unsigned short DPL;
    const unsigned short DPH;

  private:
    char ROM[RomSize];
    char RAM[RamSize];
    char XRAM[XRamSize];
    unsigned short PC;
    unsigned long instrCount;
    unsigned long cycleCount;
    unsigned char IR;
    unsigned short tempDPTR;
    bool progEnd;
    unsigned short XRAM_ADDR;
    unsigned short XRAM_DATA_IN;
    unsigned short XRAM_DATA_OUT;

  public:
    I8051();
    ~I8051();
    
  public:
    bool Simulate(const char* fileName, const char* outFile = "output.txt");
    void SynSim(const char* filename);
    bool ProgramCompletion();
    void Stop();
    void Init8051();
    void InitState(const char* filename);
    Opcode Decode(const unsigned char IR);

  private:
    void SetBit(char &thisByte, unsigned char thisBit);
    void ClearBit(char &thisByte, unsigned char thisBit);
    unsigned char GetBit(char thisByte, unsigned char thisBit);
    unsigned char GetRegisterBank();
    static int ReadByte(std::istream& in);
    static int ReadWord(std::istream& in);
    void WriteState();
    void ReadMem(std::istream& in, char* ROM, int len);
    void WriteMem(std::ostream& out, char* mem, int len);

  private:
    void PrintHex(unsigned char byte, std::ostream* os = &std::cout);
    void PrintPorts();
    
  private:
    bool Hex2Short(const char* buf, unsigned &val);
    bool Load(const char* buf, unsigned char* rom, unsigned& prgSize);
    bool LoadHex(const char *filename);
};

//-----------------------------------------------------------------------------

#endif

