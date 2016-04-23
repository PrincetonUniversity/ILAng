#include <boost/python.hpp>

#include <ast.hpp>
#include <type.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <abstraction.hpp>
#include <logging.hpp>

using namespace boost::python;
using namespace ila;

BOOST_PYTHON_MODULE(ila)
{
    initLogging();

    // setup the exception translator.
    register_exception_translator
        <PyILAException>(translateILAException);

    // Enum for the types we recognize.
    enum_<NodeType::Type>("Types")
        .value("INVALID", NodeType::INVALID)
        .value("BOOL", NodeType::BOOL)
        .value("BITVECTOR", NodeType::BITVECTOR)
        .value("MEM", NodeType::MEM)
    ;

    // This is the typename + size (so the "real" type).
    class_<NodeType>("Type", init<>())
        .def_readonly("bitwidth", &NodeType::bitWidth)
        .def_readonly("addrwidth", &NodeType::addrWidth)
        .def_readonly("datawidth", &NodeType::dataWidth)
        .def(init<NodeType::Type>())
        .def(init<NodeType::Type, int>())
        .def(init<NodeType::Type, int, int>())
        .def(self_ns::str(self))
        .def(!self)
    ;

    // This is the real node type.
    class_<NodeRef>("Node")
        .add_property("name", &NodeRef::getName)
        .add_property("type", &NodeRef::getType)
        .def("equal", &NodeRef::equal)
        .def_readonly("value", &NodeRef::value)
        // unary operators.
        .def("__invert__", 
                &NodeRef::complement, 
                return_value_policy<manage_new_object>())
        .def("__neg__", 
                &NodeRef::negate, 
                return_value_policy<manage_new_object>())

        // logical operators.
        .def("__and__",
                &NodeRef::logicalAnd,
                return_value_policy<manage_new_object>())
        .def("__or__",
                &NodeRef::logicalOr,
                return_value_policy<manage_new_object>())
        .def("__xor__",
                &NodeRef::logicalXor,
                return_value_policy<manage_new_object>())

        // arithmetic operators.
        .def("__add__",
                &NodeRef::add,
                return_value_policy<manage_new_object>())
        .def("__add__",
                &NodeRef::addInt,
                return_value_policy<manage_new_object>())
        .def("__radd__",
                &NodeRef::raddInt,
                return_value_policy<manage_new_object>())
        .def("__sub__",
                &NodeRef::sub,
                return_value_policy<manage_new_object>())
        .def("__sub__",
                &NodeRef::subInt,
                return_value_policy<manage_new_object>())
        .def("__rsub__",
                &NodeRef::rsubInt,
                return_value_policy<manage_new_object>())
        .def("__mul__",
                &NodeRef::mul,
                return_value_policy<manage_new_object>())
        .def("__mul__",
                &NodeRef::mulInt,
                return_value_policy<manage_new_object>())
        .def("__rmul__",
                &NodeRef::rmulInt,
                return_value_policy<manage_new_object>())
        .def("__div__",
                &NodeRef::udiv,
                return_value_policy<manage_new_object>())
        .def("__div__",
                &NodeRef::udivInt,
                return_value_policy<manage_new_object>())
        .def("__rdiv__",
                &NodeRef::rudivInt,
                return_value_policy<manage_new_object>())
        .def("__mod__",
                &NodeRef::smod,
                return_value_policy<manage_new_object>())
        .def("__mod__",
                &NodeRef::smodInt,
                return_value_policy<manage_new_object>())
        .def("__rmod__",
                &NodeRef::rsmodInt,
                return_value_policy<manage_new_object>())
        .def("__lshift__",
                &NodeRef::shl,
                return_value_policy<manage_new_object>())
        .def("__lshift__",
                &NodeRef::shlInt,
                return_value_policy<manage_new_object>())
        .def("__rlshift__",
                &NodeRef::rshlInt,
                return_value_policy<manage_new_object>())
        .def("__rshift__",
                &NodeRef::lshr,
                return_value_policy<manage_new_object>())
        .def("__rshift__",
                &NodeRef::lshrInt,
                return_value_policy<manage_new_object>())
        .def("__rrshift__",
                &NodeRef::rlshrInt,
                return_value_policy<manage_new_object>())

        // comparison operators.
        .def("__eq__",
                &NodeRef::eq,
                return_value_policy<manage_new_object>())
        .def("__eq__",
                &NodeRef::eqInt,
                return_value_policy<manage_new_object>())
        .def("__ne__",
                &NodeRef::neq,
                return_value_policy<manage_new_object>())
        .def("__ne__",
                &NodeRef::neqInt,
                return_value_policy<manage_new_object>())
        .def("__lt__",
                &NodeRef::ult,
                return_value_policy<manage_new_object>())
        .def("__lt__",
                &NodeRef::ultInt,
                return_value_policy<manage_new_object>())
        .def("__le__",
                &NodeRef::ule,
                return_value_policy<manage_new_object>())
        .def("__le__",
                &NodeRef::uleInt,
                return_value_policy<manage_new_object>())
        .def("__gt__",
                &NodeRef::ugt,
                return_value_policy<manage_new_object>())
        .def("__gt__",
                &NodeRef::ugtInt,
                return_value_policy<manage_new_object>())
        .def("__ge__",
                &NodeRef::uge,
                return_value_policy<manage_new_object>())
        .def("__ge__",
                &NodeRef::ugeInt,
                return_value_policy<manage_new_object>())

        // slice operator
        .def("__getslice__",
                &NodeRef::slice,
                return_value_policy<manage_new_object>())
        // get bit operator
        .def("__getitem__",
                &NodeRef::getItem,
                return_value_policy<manage_new_object>())
        .def("__getitem__",
                &NodeRef::getItemInt,
                return_value_policy<manage_new_object>())

        .def(self_ns::str(self))
    ;

    // functions which expose operators on nodes.

    // memory write.
    def("store", &NodeRef::store,
            return_value_policy<manage_new_object>());

    // logical operators.
    def("nand", &NodeRef::logicalNand,
            return_value_policy<manage_new_object>());
    def("nor", &NodeRef::logicalNor,
            return_value_policy<manage_new_object>());
    def("xnor", &NodeRef::logicalXnor,
            return_value_policy<manage_new_object>());

    // arithmetic operators.
    def("sdiv", &NodeRef::sdiv,
            return_value_policy<manage_new_object>());
    def("sdiv", &NodeRef::sdivInt,
            return_value_policy<manage_new_object>());
    def("sdiv", &NodeRef::rsdivInt,
            return_value_policy<manage_new_object>()); 
    def("srem", &NodeRef::srem,
            return_value_policy<manage_new_object>()); 
    def("srem", &NodeRef::sremInt,
            return_value_policy<manage_new_object>()); 
    def("srem", &NodeRef::rsremInt,
            return_value_policy<manage_new_object>()); 
    def("urem", &NodeRef::urem,
            return_value_policy<manage_new_object>()); 
    def("urem", &NodeRef::uremInt,
            return_value_policy<manage_new_object>()); 
    def("urem", &NodeRef::ruremInt,
            return_value_policy<manage_new_object>()); 
    def("ashr", &NodeRef::ashr,
            return_value_policy<manage_new_object>()); 
    def("ashr", &NodeRef::ashrInt,
            return_value_policy<manage_new_object>()); 
    def("ashr", &NodeRef::rashrInt,
            return_value_policy<manage_new_object>()); 
    
    // manipulate operators.
    def("concat", &NodeRef::concat,
            return_value_policy<manage_new_object>());
    def("lrotate", &NodeRef::lrotate,
            return_value_policy<manage_new_object>());
    def("rrotate", &NodeRef::rrotate,
            return_value_policy<manage_new_object>());
    def("zero_extend", &NodeRef::zero_extend,
            return_value_policy<manage_new_object>());
    def("sign_extend", &NodeRef::sign_extend,
            return_value_policy<manage_new_object>());

    // comparison operators.
    def("slt", &NodeRef::slt,
            return_value_policy<manage_new_object>());
    def("slt", &NodeRef::sltInt,
            return_value_policy<manage_new_object>());
    def("sle", &NodeRef::sle,
            return_value_policy<manage_new_object>());
    def("slt", &NodeRef::sleInt,
            return_value_policy<manage_new_object>());
    def("sgt", &NodeRef::sgt,
            return_value_policy<manage_new_object>());
    def("sgt", &NodeRef::sgtInt,
            return_value_policy<manage_new_object>());
    def("sge", &NodeRef::sge,
            return_value_policy<manage_new_object>());
    def("sge", &NodeRef::sgeInt,
            return_value_policy<manage_new_object>());

    // nonzero.
    def("nonzero", &NodeRef::nonzero,
            return_value_policy<manage_new_object>());
    // imply.
    def("implies", &NodeRef::imply,
            return_value_policy<manage_new_object>());
    // ite.
    def("ite", &NodeRef::ite,
            return_value_policy<manage_new_object>());

    // choice
    def("choice", &NodeRef::choice2, 
            return_value_policy<manage_new_object>());
    def("choice", &NodeRef::choice3, 
            return_value_policy<manage_new_object>());
    def("choice", &NodeRef::choice4, 
            return_value_policy<manage_new_object>());
    def("choice", &NodeRef::choice5, 
            return_value_policy<manage_new_object>());
    def("choice", &NodeRef::choice6, 
            return_value_policy<manage_new_object>());
    def("choice", &NodeRef::choiceL, 
            return_value_policy<manage_new_object>());

    // inrange
    def("inrange", &NodeRef::inRange,
            return_value_policy<manage_new_object>());

    // readslice.
    def("readslice", &NodeRef::readSlice,
            return_value_policy<manage_new_object>());

    // writeslice
    def("writeslice", &NodeRef::writeSlice,
            return_value_policy<manage_new_object>());

    // logging.
    def("setloglevel", &ila::setLogLevel);

    // This is the top-level class.
    class_<Abstraction>("Abstraction", init<>())
        // inputs
        .def("inp", &Abstraction::addInp, return_value_policy<manage_new_object>())

        // bits.
        .def("bit", &Abstraction::addBit, return_value_policy<manage_new_object>())
        // registers.
        .def("reg", &Abstraction::addReg, return_value_policy<manage_new_object>())
        // memories.
        .def("mem", &Abstraction::addMem, return_value_policy<manage_new_object>())
        // next function
        .def("set_next", &Abstraction::setNext)
        // get next.
        .def("get_next", &Abstraction::getNext, return_value_policy<manage_new_object>())

        .def("const", &Abstraction::bvConstLong, return_value_policy<manage_new_object>())
        .def("const", &Abstraction::bvConstInt, return_value_policy<manage_new_object>())
        .def("const", &Abstraction::memConst, return_value_policy<manage_new_object>())
        .def("bool", &Abstraction::boolConstB, return_value_policy<manage_new_object>())
        .def("bool", &Abstraction::boolConstI, return_value_policy<manage_new_object>())
        .def("bool", &Abstraction::boolConstL, return_value_policy<manage_new_object>())

        .def("synthesize", &Abstraction::synthesizeAll)
        .def("synthesize", &Abstraction::synthesizeReg)
        .def("syn_elem", &Abstraction::synthesizeElement, return_value_policy<manage_new_object>())
        .def("areEqual", &Abstraction::areEqual)

        .def("add_assumption", &Abstraction::addAssumption)
        .def("get_all_assumptions", &Abstraction::getAllAssumptions)

        .def("exportOne", &Abstraction::exportOneToFile)
        .def("exportAll", &Abstraction::exportAllToFile)
        .def("importOne", &Abstraction::importOneFromFile, return_value_policy<manage_new_object>())
        .def("importAll", &Abstraction::importAllFromFile)

        .def("generateSim", &Abstraction::generateSim)

        .add_property("fetch_expr", 
            make_function(&Abstraction::getFetchExpr, return_value_policy<manage_new_object>()), 
            &Abstraction::setFetchExpr)
        .add_property("fetch_valid", 
            make_function(&Abstraction::getFetchValid, return_value_policy<manage_new_object>()), 
            &Abstraction::setFetchValid)

        .add_property("decode_exprs", 
            &Abstraction::getDecodeExpressions, 
            &Abstraction::setDecodeExpressions)

        .def_readwrite("enable_parameterized_synthesis", &Abstraction::paramSyn)
    ;

    class_<MemValues>("MemValues", init<int, int, const object&>())
        .add_property("default", &MemValues::getDefault, &MemValues::setDefault)
        .def_readonly("values", &MemValues::getValues)
        .def("__getitem__", &MemValues::getItem)
        .def("__setitem__", &MemValues::setItem)
        .def("__repr__", &MemValues::str)
        .def(self_ns::str(self))
    ;
}
