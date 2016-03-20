#include <ast.hpp>
#include <exception.hpp>
#include <type.hpp>
#include <util.hpp>
#include <boost/python.hpp>

using namespace boost::python;
using namespace ila;

BOOST_PYTHON_MODULE(ila)
{
    // setup the exception translator.
    register_exception_translator<PyILAException>(translateILAException);

    enum_<NodeType::Type>("Types")
        .value("INVALID", NodeType::INVALID)
        .value("BOOL", NodeType::BOOL)
        .value("BITVECTOR", NodeType::BITVECTOR)
        .value("MEM", NodeType::MEM)
    ;

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

    class_<NodeRef>("Node")
        .add_property("name", &NodeRef::getName)
        .add_property("type", &NodeRef::getType)
        .def("doSomething", &NodeRef::doSomething)
    ;

    class_<Context>("Context", init<>())
        .def("BitvectorVar", &Context::BitvectorVar, return_value_policy<manage_new_object>())
    ;
}
