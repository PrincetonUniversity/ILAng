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
        .def(init<NodeType::Type>())
        .def(self_ns::str(self))
    ;

    class_<Node>("Node")
        .def("setName", &Node::setName)
        .def("getName", &Node::getName)
        .def("doSomething", &Node::doSomething)
    ;
}
