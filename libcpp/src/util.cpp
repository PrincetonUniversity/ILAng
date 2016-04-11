#include <util.hpp>
#include <exception.hpp>
#include <boost/python.hpp>

#include <string>
#include <string.h>

namespace ila {

    // ---------------------------------------------------------------------- //
    void ila_assert(bool b, const char* msg, const char* file, int line)
    {
        if (!b) {
            size_t sz = strlen(msg) + strlen(file) + 48;
            char* buf = new char[sz];
            snprintf(buf, sz-1, "error %s line %d: %s", file, line, msg);
            std::string str(buf);
            delete [] buf;

            throw PyILAException(PyExc_RuntimeError, str);
        }
    }

    void ila_assert(bool b, const std::string& msg, const char* file, int line)
    {
        if (!b) {
            size_t sz = msg.size() + strlen(file) + 48;
            char* buf = new char[sz];
            snprintf(buf, sz-1, "error %s line %d: %s", file, line, msg.c_str());
            std::string str(buf);
            delete [] buf;

            throw PyILAException(PyExc_RuntimeError, str);
        }
    }

    // ---------------------------------------------------------------------- //
    mp_int_t to_cpp_int(const py::object& l)
    {
        PyObject* pyobj = l.ptr();
        PyObject* pystr = PyObject_Str(pyobj);
        std::string lstr(PyString_AsString(pystr));
        Py_DECREF(pystr);

        return boost::lexical_cast<mp_int_t>(lstr);
    }

    std::string to_string(const py::object& l)
    {
        PyObject* pyobj = l.ptr();
        PyObject* pystr = PyObject_Str(pyobj);
        std::string lstr(PyString_AsString(pystr));
        Py_DECREF(pystr);
        return lstr;
    }

    py::object to_pyint(const mp_int_t& i)
    {
        std::string si = boost::lexical_cast<std::string>(i);
        return to_pyint(si);
    }

    py::object to_pyint(const std::string& s)
    {
        using namespace py;

        PyObject* oi = PyInt_FromString((char*)s.c_str(), NULL, 0);
        py::object pi(handle<>(borrowed(oi)));
        return pi;
    }

    bool is_py_int(const py::object& l)
    {
        PyObject* pyobj = l.ptr();
        return PyInt_Check(pyobj);
    }

    bool is_py_int_or_long(const py::object& l)
    {
        PyObject* pyobj = l.ptr();
        return PyInt_Check(pyobj) || PyLong_Check(pyobj);
    }
}
