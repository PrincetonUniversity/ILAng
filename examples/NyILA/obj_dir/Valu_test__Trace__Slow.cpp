// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Valu_test__Syms.h"


//======================

void Valu_test::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Valu_test::traceInit, &Valu_test::traceFull, &Valu_test::traceChg, this);
}
void Valu_test::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Valu_test* t=(Valu_test*)userthis;
    Valu_test__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Valu_test::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Valu_test* t=(Valu_test*)userthis;
    Valu_test__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Valu_test::traceInitThis(Valu_test__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Valu_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Valu_test::traceFullThis(Valu_test__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Valu_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Valu_test::traceInitThis__1(Valu_test__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Valu_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBus  (c+1,"out",-1,7,0);
	vcdp->declBit  (c+2,"enable",-1);
	vcdp->declBit  (c+3,"clk",-1);
	vcdp->declBit  (c+4,"reset",-1);
	vcdp->declBus  (c+1,"counter out",-1,7,0);
	vcdp->declBit  (c+2,"counter enable",-1);
	vcdp->declBit  (c+3,"counter clk",-1);
	vcdp->declBit  (c+4,"counter reset",-1);
    }
}

void Valu_test::traceFullThis__1(Valu_test__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Valu_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlTOPp->out),8);
	vcdp->fullBit  (c+2,(vlTOPp->enable));
	vcdp->fullBit  (c+3,(vlTOPp->clk));
	vcdp->fullBit  (c+4,(vlTOPp->reset));
    }
}
