// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Valu_test__Syms.h"


//======================

void Valu_test::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Valu_test* t=(Valu_test*)userthis;
    Valu_test__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Valu_test::traceChgThis(Valu_test__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Valu_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Valu_test::traceChgThis__2(Valu_test__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Valu_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->out),8);
	vcdp->chgBit  (c+2,(vlTOPp->enable));
	vcdp->chgBit  (c+3,(vlTOPp->clk));
	vcdp->chgBit  (c+4,(vlTOPp->reset));
    }
}
