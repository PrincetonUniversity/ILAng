#include <util.hpp>
#include <exception.hpp>
#include <boost/python.hpp>
#include <frameobject.h> // for PyFrameObject

#include <string>
#include <string.h>
#include <stdlib.h>

namespace ila {

    // ---------------------------------------------------------------------- //
    void ila_assert(bool b, const char* msg, const char* file, int line)
    {
        if (!b) {
            fprintf(stderr, 
                "%s:%d ASSERTION FAILURE %s\n", file, line, msg);
            dump_trace();
            abort();
        }
    }

    void ila_assert(bool b, const std::string& msg, const char* file, int line)
    {
        ila_assert(b, msg.c_str(), file, line);
    }

    void dump_trace()
    {
        fprintf(stderr, "Traceback (most recent call first):\n");
        PyThreadState *tstate = PyThreadState_GET();
        if (NULL != tstate && NULL != tstate->frame) {
            PyFrameObject *frame = tstate->frame;

            while (NULL != frame) {
                int line = PyFrame_GetLineNumber(frame);
                const char *filename = PyString_AsString(
                    frame->f_code->co_filename);
                const char *funcname = PyString_AsString(
                    frame->f_code->co_name);
                fprintf(stderr, "    File \"%s\", line %d in %s\n", 
                    filename, line, funcname);
                frame = frame->f_back;
            }
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

    // ---------------------------------------------------------------------- //
    void set_logging_level(int l)
    {
        // FIXME
#if 0
        if (l < 0) {
            throw PyILAException(PyExc_RuntimeError, 
                                 "Invalid level.");
        }
        auto lev = (l == 0) ? boost::log::trivial::fatal :
                   (l == 1) ? boost::log::trivial::debug :
                              boost::log::trivial::trace;
        boost::log::core::get()->set_filter(
            boost::log::trivial::severity >= lev);
#endif
    }

}
