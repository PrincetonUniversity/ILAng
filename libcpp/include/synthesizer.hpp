#ifndef __SYNTHESIZER_HPP_DEFINED__
#define __SYNTHESIZER_HPP_DEFINED__

#include <set>
#include <map>
#include <string>
#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/variant.hpp>
#include <z3++.h>

#include <common.hpp>
#include <ast.hpp>
#include <smt.hpp>
#include <synrewriter.hpp>
#include <abstraction.hpp>

namespace ila
{

    // ---------------------------------------------------------------------- //
    struct SupportVars
    {
        // set of nodes.
        std::set<const Node*> vars;
        // visitor function.
        void operator() (const Node* n);
        // check if a node is present in the 
        bool hasNode(const Node* v) const;
        // version that uses nptr_t.
        bool hasNode(const nptr_t& v) const;
    };

    // ---------------------------------------------------------------------- //
    struct DistInput
    {
        std::map<std::string, MemValues>    mems;
        std::map<std::string, std::string>  bitvecs;
        std::map<std::string, bool>         bools;

        DistInput(Abstraction& a, Z3ExprAdapter& c, z3::model& m);
        void toPython(py::dict& d);

        bool getBoolValue(const std::string& n) const;
        std::string getBitvecStr(const std::string& n) const;
        const MemValues& getMemValues(const std::string& n) const;
    };

    // ---------------------------------------------------------------------- //
    struct SimOutput
    {
        boost::variant<MemValues, std::string, bool> out;
        // default constructor.
        SimOutput();
        // constructor with a particular output.
        SimOutput(const NodeType& nt, const py::object& r);
        // copy constructor.
        SimOutput(const SimOutput& that);
        // assignment operator.
        SimOutput& operator=(const SimOutput& that);
        // equality check.
        bool operator==(const SimOutput& that) const;
        // initialize with a particular output.
        void initOutput(const NodeType& nt, const py::object& r);
    };

    // ---------------------------------------------------------------------- //
    struct DistTreeNode;
    typedef boost::shared_ptr<DistTreeNode> dtree_ptr_t;
    struct DistTreeNode
    {
        typedef std::pair<SimOutput, dtree_ptr_t> outpair_t;
        typedef std::vector<outpair_t> outpair_vec_t;

        DistInput inputs;
        outpair_vec_t outputs;

        DistTreeNode(Abstraction& a, Z3ExprAdapter& c, z3::model& m);
    };

    // ---------------------------------------------------------------------- //
    struct SimoutAdapter : public boost::static_visitor<z3::expr>
    {
        Z3ExprRewritingAdapter& adapter;
        const Node* node;
        z3::expr r_expr;
        z3::expr r_cnst;

        // constructor.
        SimoutAdapter(Z3ExprRewritingAdapter& a, const Node* n);

        // visitors.
        z3::expr operator() (bool res) const;
        z3::expr operator() (const std::string& res) const;
        z3::expr operator() (const MemValues& mv) const;
    };

    // ---------------------------------------------------------------------- //
    class Synthesizer
    {
    protected:
        static const char* suffix1;
        static const char* suffix2;

        Abstraction& abs;
        SupportVars decodeSupport;

        int MAX_SYN_ITER;
        z3::context c;
        z3::solver S;
        Z3ExprAdapter c1, c2;
        dtree_ptr_t dtree;

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

        boost::shared_ptr<DistInput> _getDistInput(z3::expr y);

        nptr_t _synthesize(
            const std::string& name, 
            const nptr_t& de_expr, const nptr_t& expr,
            PyObject* pyfun);

        nptr_t _synthesizeEx(
            const std::string& name, 
            const nptr_t& de_expr, const nptr_t& expr,
            PyObject* pyfun);

        z3::expr _createSynMiter(const nptr_t& ex);

    public:
        // constructor.
        Synthesizer(Abstraction& abs);
        // destructor.
        ~Synthesizer();

        // synthesize all.
        void synthesizeAll(PyObject* pyfun);
    };
    // ---------------------------------------------------------------------- //
}

#endif
