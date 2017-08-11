// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Valu_test__Syms_H_
#define _Valu_test__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Valu_test.h"

// SYMS CLASS
class Valu_test__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool	__Vm_activity;		///< Used by trace routines to determine change occurred
    bool	__Vm_didInit;
    //char	__VpadToAlign10[6];
    
    // SUBCELL STATE
    Valu_test*                     TOPp;
    
    // COVERAGE
    
    // SCOPE NAMES
    
    // CREATORS
    Valu_test__Syms(Valu_test* topp, const char* namep);
    ~Valu_test__Syms() {};
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    inline bool getClearActivity() { bool r=__Vm_activity; __Vm_activity=false; return r;}
    
} VL_ATTR_ALIGNED(64);

#endif  /*guard*/
