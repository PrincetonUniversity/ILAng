#ifndef __MEMVALUES_HPP_DEFINED__
#define __MEMVALUES_HPP_DEFINED__

#include <iostream>
#include <map>

#include <common.hpp>
#include <ast/node.hpp>
#include <type.hpp>

#include <boost/python.hpp>
#include <z3++.h>

namespace ila
{
    class Z3ExprAdapter;
    class MemVar;

    // This structure represents a memory with known values.
    // It is passed into python during synthesis.
    struct MemValues
    {
        typedef std::map<mp_int_t, mp_int_t> map_t;

        static z3::context c_eq;
        static z3::solver S_eq;

        NodeType type;
        mp_int_t MAX_ADDR;

        mp_int_t def_value;
        map_t values;

        // default.
        MemValues();
        // constructor.
        MemValues(int addrWidth, int dataWidth, const py::object& def_val);
        // constructor from imported memvalue.
        MemValues(int addrWidth, int dataWidth, 
                  const map_t values, const mp_int_t def_value);
        // construct from a model.
        MemValues(Z3ExprAdapter& c, const z3::model& m, const MemVar* mem);
        // copy constructor.
        MemValues(const MemValues& that);
        // destructor.
        ~MemValues();

        // assignment operator.
        MemValues& operator=(const MemValues& that);

        // return def_value
        py::object getDefault() const;
        // set def_value.
        void setDefault(const py::object& dv);
        // get nondefault values.
        py::object getValues() const;
        // __getitem__
        py::object getItem (const py::object& index) const;
        // __setitem__
        void setItem (const py::object& index, const py::object& value);

        // equality for python.
        bool eq(const MemValues& mv) const { return *this == mv; }
        // equality.
        bool operator==(const MemValues& mv) const;
        // equality using smt.
        bool semanticEqual(const MemValues& mv) const;
        // convert to z3.
        z3::expr toZ3(z3::context& c) const;
        // write to a string.
        std::string str() const;
        // gc: remove entries which are equal to the default.
        void gc();

        // support for __getitem__
        mp_int_t getItemInt(const mp_int_t& index) const;
    };
    std::ostream& operator<<(std::ostream& out, const MemValues& mv);
}

#endif
