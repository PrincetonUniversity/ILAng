// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu_test.h for the primary calling header

#include "Valu_test.h"         // For This
#include "Valu_test__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Valu_test) {
    Valu_test__Syms* __restrict vlSymsp = __VlSymsp = new Valu_test__Syms(this, name());
    Valu_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Valu_test::__Vconfigure(Valu_test__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Valu_test::~Valu_test() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Valu_test::eval() {
    Valu_test__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Valu_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Valu_test::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Valu_test::_eval_initial_loop(Valu_test__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Valu_test::_sequent__TOP__1(Valu_test__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Valu_test::_sequent__TOP__1\n"); );
    Valu_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__out,7,0);
    //char	__VpadToAlign5[3];
    // Body
    __Vdly__out = vlTOPp->out;
    // ALWAYS at alu_test.v:8
    if (vlTOPp->reset) {
	__Vdly__out = 0U;
    } else {
	if (vlTOPp->enable) {
	    __Vdly__out = (0xffU & ((IData)(1U) + (IData)(vlTOPp->out)));
	}
    }
    vlTOPp->out = __Vdly__out;
}

void Valu_test::_eval(Valu_test__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Valu_test::_eval\n"); );
    Valu_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Valu_test::_eval_initial(Valu_test__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Valu_test::_eval_initial\n"); );
    Valu_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Valu_test::final() {
    VL_DEBUG_IF(VL_PRINTF("    Valu_test::final\n"); );
    // Variables
    Valu_test__Syms* __restrict vlSymsp = this->__VlSymsp;
    Valu_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Valu_test::_eval_settle(Valu_test__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Valu_test::_eval_settle\n"); );
    Valu_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData Valu_test::_change_request(Valu_test__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Valu_test::_change_request\n"); );
    Valu_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void Valu_test::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    Valu_test::_ctor_var_reset\n"); );
    // Body
    out = VL_RAND_RESET_I(8);
    enable = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void Valu_test::_configure_coverage(Valu_test__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    Valu_test::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
