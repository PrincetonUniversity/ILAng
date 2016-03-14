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
        .def(init<NodeType::Type, int>())
        .def(init<NodeType::Type, int, int>())
        .def(self_ns::str(self))
        .def(!self)
    ;

    class_<Node>("Node", init<NodeType>())
        .def_readonly("type", &Node::type)
        .def_readonly("name", &Node::name)
        .def("doSomething", &Node::doSomething)
    ;

    class_<BitvectorExpr, bases<Node> >("BitvectorExpr", init<int>())
    ;

    class_<BitvectorVar, bases<BitvectorExpr> >("BitvectorVar", init<std::string, int>())
    ;
}
