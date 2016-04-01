#include <boost/python.hpp>

#include <ast.hpp>
#include <type.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <abstraction.hpp>

using namespace boost::python;
using namespace ila;

BOOST_PYTHON_MODULE(ila)
{
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
        .def("doSomething", &NodeRef::doSomething)
        .def("equal", &NodeRef::equal)
        .def_readonly("value", &NodeRef::value)
        .def("__invert__", 
                &NodeRef::complement, 
                return_value_policy<manage_new_object>())
        .def("__neg__", 
                &NodeRef::negate, 
                return_value_policy<manage_new_object>())
        .def("__and__",
                &NodeRef::logicalAnd,
                return_value_policy<manage_new_object>())
        .def("__or__",
                &NodeRef::logicalOr,
                return_value_policy<manage_new_object>())
        .def("__xor__",
                &NodeRef::logicalXor,
                return_value_policy<manage_new_object>())
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
        .def("__eq__",
                &NodeRef::eq,
                return_value_policy<manage_new_object>())
        .def("__ne__",
                &NodeRef::neq,
                return_value_policy<manage_new_object>())
        // For operator function call
        .def("logicalNot",
                &NodeRef::logicalNot,
                return_value_policy<manage_new_object>())
        .def("logicalAnd",
                &NodeRef::logicalAnd,
                return_value_policy<manage_new_object>())
        .def("logicalOr",
                &NodeRef::logicalOr,
                return_value_policy<manage_new_object>())
        .def("logicalXor",
                &NodeRef::logicalXor,
                return_value_policy<manage_new_object>())
        .def("logicalXnor",
                &NodeRef::logicalXnor,
                return_value_policy<manage_new_object>())
        .def("logicalNand",
                &NodeRef::logicalNand,
                return_value_policy<manage_new_object>())
        .def("logicalNor",
                &NodeRef::logicalNor,
                return_value_policy<manage_new_object>())
        .def("add", 
                &NodeRef::add,
                return_value_policy<manage_new_object>())
        .def("addInt", 
                &NodeRef::addInt,
                return_value_policy<manage_new_object>())
        .def("raddInt", 
                &NodeRef::raddInt,
                return_value_policy<manage_new_object>())
        .def("sub", 
                &NodeRef::sub,
                return_value_policy<manage_new_object>())
        .def("subInt", 
                &NodeRef::subInt,
                return_value_policy<manage_new_object>())
        .def("rsubInt", 
                &NodeRef::rsubInt,
                return_value_policy<manage_new_object>())
        .def("sdiv", 
                &NodeRef::sdiv,
                return_value_policy<manage_new_object>())
        .def("sdivInt", 
                &NodeRef::sdivInt,
                return_value_policy<manage_new_object>())
        .def("rsdivInt", 
                &NodeRef::rsdivInt,
                return_value_policy<manage_new_object>())
        .def("udiv", 
                &NodeRef::udiv,
                return_value_policy<manage_new_object>())
        .def("udivInt", 
                &NodeRef::udivInt,
                return_value_policy<manage_new_object>())
        .def("rudivInt", 
                &NodeRef::rudivInt,
                return_value_policy<manage_new_object>())
        .def("srem", 
                &NodeRef::srem,
                return_value_policy<manage_new_object>())
        .def("urem", 
                &NodeRef::urem,
                return_value_policy<manage_new_object>())
        .def("sremInt", 
                &NodeRef::sremInt,
                return_value_policy<manage_new_object>())
        .def("uremInt", 
                &NodeRef::uremInt,
                return_value_policy<manage_new_object>())
        .def("smod", 
                &NodeRef::smod,
                return_value_policy<manage_new_object>())
        .def("smodInt", 
                &NodeRef::smodInt,
                return_value_policy<manage_new_object>())
        .def("shl", 
                &NodeRef::shl,
                return_value_policy<manage_new_object>())
        .def("shlInt", 
                &NodeRef::shlInt,
                return_value_policy<manage_new_object>())
        .def("lshr", 
                &NodeRef::lshr,
                return_value_policy<manage_new_object>())
        .def("lshrInt", 
                &NodeRef::lshrInt,
                return_value_policy<manage_new_object>())
        .def("ashr", 
                &NodeRef::ashr,
                return_value_policy<manage_new_object>())
        .def("ashrInt", 
                &NodeRef::ashrInt,
                return_value_policy<manage_new_object>())
        .def("mul", 
                &NodeRef::mul,
                return_value_policy<manage_new_object>())
        .def("mulInt", 
                &NodeRef::mulInt,
                return_value_policy<manage_new_object>())
        .def("concat",
                &NodeRef::concat,
                return_value_policy<manage_new_object>())
        .def("eq",
                &NodeRef::eq,
                return_value_policy<manage_new_object>())
        .def("neq",
                &NodeRef::neq,
                return_value_policy<manage_new_object>())
        .def("slt",
                &NodeRef::slt,
                return_value_policy<manage_new_object>())
        .def("sle",
                &NodeRef::sle,
                return_value_policy<manage_new_object>())
        .def("sgt",
                &NodeRef::sgt,
                return_value_policy<manage_new_object>())
        .def("sge",
                &NodeRef::sge,
                return_value_policy<manage_new_object>())
        .def("ult",
                &NodeRef::ult,
                return_value_policy<manage_new_object>())
        .def("ule",
                &NodeRef::ule,
                return_value_policy<manage_new_object>())
        .def("ugt",
                &NodeRef::ugt,
                return_value_policy<manage_new_object>())
        .def("uge",
                &NodeRef::uge,
                return_value_policy<manage_new_object>())
        .def(self_ns::str(self))
    ;

    // This is the top-level class.
    class_<Abstraction>("Abstraction", init<>())
        .def("reg", &Abstraction::addReg, return_value_policy<manage_new_object>())
        .def("bit", &Abstraction::addBit, return_value_policy<manage_new_object>())

        .def("const", &Abstraction::bvConstLong, return_value_policy<manage_new_object>())
        .def("const", &Abstraction::bvConstInt, return_value_policy<manage_new_object>())
        .def("bool", &Abstraction::boolConstB, return_value_policy<manage_new_object>())
        .def("bool", &Abstraction::boolConstI, return_value_policy<manage_new_object>())
        .def("bool", &Abstraction::boolConstL, return_value_policy<manage_new_object>())

        .def("choice", &Abstraction::choice2, return_value_policy<manage_new_object>())

        .def("synthesize", &Abstraction::synthesize)
        .def("areEqual", &Abstraction::areEqual)
    ;
}
