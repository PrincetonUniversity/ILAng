#ifndef __SYNTHESIZER_HPP_DEFINED__
#define __SYNTHESIZER_HPP_DEFINED__

#include <map>
#include <string>
#include <boost/python.hpp>
#include <z3++.h>

#include <common.hpp>
#include <ast.hpp>
#include <smt.hpp>
#include <synrewriter.hpp>
#include <abstraction.hpp>

namespace ila
{
    class Synthesizer
    {
    protected:
        static const char* suffix1;
        static const char* suffix2;

        Abstraction& abs;
        int MAX_SYN_ITER;
        z3::context c;
        z3::solver S;
        Z3ExprAdapter c1, c2;

        void _extractModelValues(
            Z3ExprAdapter& c,
            z3::model& m, 
            py::dict& result
        );

        void _initSolverAssumptions(
            const nptr_vec_t& assumps,
            Z3ExprAdapter& c1,
            Z3ExprAdapter& c2);

        void _addExpr(
            const nptr_t& expr,
            Z3ExprAdapter& c1,
            Z3ExprAdapter& c2);

        nptr_t _synthesize(
            const std::string& name, 
            const nptr_t& de_expr, const nptr_t& expr,
            PyObject* pyfun);
    public:
        // constructor.
        Synthesizer(Abstraction& abs);
        // destructor.
        ~Synthesizer();

        // synthesize all.
        void synthesizeAll(PyObject* pyfun);
    };
}

#endif
