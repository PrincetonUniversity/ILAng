#include <ast.hpp>
#include <boost/python.hpp>

using namespace boost::python;
using namespace ila;

BOOST_PYTHON_MODULE(ila)
{
    class_<Node>("Node")
        .def("setName", &Node::setName)
        .def("getName", &Node::getName)
        .def("doSomething", &Node::doSomething)
    ;
}
