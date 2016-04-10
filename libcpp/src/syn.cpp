#include <syn.hpp>
#include <util.hpp>

namespace ila
{
    SynRewriter::SynRewriter(z3::model& mod, Z3ExprAdapter& a)
      : m(mod)
      , adapter(a)
    {
    }

    SynRewriter::~SynRewriter()
    {
    }

    // ---------------------------------------------------------------------- //
    void SynRewriter::getNewArgs(
        const Node* op, 
        std::vector< boost::shared_ptr<Node> >& args)
    {
        unsigned n = op->nArgs();
        for (unsigned i=0; i < n; i++) {
            const Node* n = op->arg(i).get();
            auto pos = exprmap.find(n);
            ILA_ASSERT(pos != exprmap.end(), "Unable to find node in memo!");
            boost::shared_ptr<Node> arg = pos->second;
            args.push_back(arg);
        }
    }

    // ---------------------------------------------------------------------- //
    void SynRewriter::operator() (const Node* n)
    {
        // memoization.
        auto pos = exprmap.find(n);
        if (pos != exprmap.end()) {
            return;
        }

        // n->write(std::cout << "visiting: ") << std::endl;
        // std::cout << "visiting: " << *n << std::endl;

        // now handle the various types.
        const BoolVar* boolvar = NULL; 
        const BoolConst* boolconst = NULL;
        const BoolOp* boolop = NULL;
        const BoolChoice* bchoiceop = NULL;

        const BitvectorVar* bvvar = NULL;
        const BitvectorConst* bvconst = NULL;
        const BitvectorOp* bvop = NULL;
        const BitvectorChoice* bvchoiceop = NULL;

        const MemVar* memvar = NULL;
        const MemConst* memconst = NULL;
        const MemWr* memwr = NULL;
        const MemChoice* mchoiceop = NULL;

        //// bools ////
        if ((boolvar = dynamic_cast<const BoolVar*>(n))) {
            boost::shared_ptr<Node> nptr(n->clone());
            exprmap.insert({n, nptr});
        } else if ((boolconst = dynamic_cast<const BoolConst*>(n))) {
            boost::shared_ptr<Node> nptr(n->clone());
            exprmap.insert({n, nptr});
        } else if ((boolop = dynamic_cast<const BoolOp*>(n))) {
            std::vector< boost::shared_ptr<Node> > args;
            getNewArgs(boolop, args);
            boost::shared_ptr<Node> nptr(new BoolOp(boolop, args));
            exprmap.insert({n, nptr});
        } else if ((bchoiceop = dynamic_cast<const BoolChoice*>(n))) {
            _synChoiceExpr(bchoiceop);
        //// bitvector ////
        } else if((bvvar = dynamic_cast<const BitvectorVar*>(n))) {
            boost::shared_ptr<Node> nptr(n->clone());
            exprmap.insert({n, nptr});
        } else if((bvconst = dynamic_cast<const BitvectorConst*>(n))) {
            boost::shared_ptr<Node> nptr(n->clone());
            exprmap.insert({n, nptr});
        } else if ((bvop = dynamic_cast<const BitvectorOp*>(n))) {
            std::vector< boost::shared_ptr<Node> > args;
            getNewArgs(bvop, args);
            boost::shared_ptr<Node> nptr(new BitvectorOp(bvop, args));
            exprmap.insert({n, nptr});
        } else if ((bvchoiceop = dynamic_cast<const BitvectorChoice*>(n))) {
            _synChoiceExpr(bvchoiceop);
        //// memories ////
        } else if ((memvar = dynamic_cast<const MemVar*>(n))) {
            boost::shared_ptr<Node> nptr(n->clone());
            exprmap.insert({n, nptr});
        } else if ((memconst = dynamic_cast<const MemConst*>(n))) {
            boost::shared_ptr<Node> nptr(n->clone());
            exprmap.insert({n, nptr});
        } else if ((memwr = dynamic_cast<const MemWr*>(n))) {
            std::vector< boost::shared_ptr<Node> > args;
            getNewArgs(memwr, args);
            boost::shared_ptr<Node> nptr(new MemWr(args[0], args[1], args[2]));
            exprmap.insert({n, nptr});
        } else if ((mchoiceop = dynamic_cast<const MemChoice*>(n))) {
            _synChoiceExpr(mchoiceop);
        }
    }

    // ---------------------------------------------------------------------- //
    boost::shared_ptr<Node> SynRewriter::rewrite(const Node* n)
    {
        n->depthFirstVisit(*this);
        auto pos = exprmap.find(n);
        ILA_ASSERT(pos != exprmap.end(), "Unable to find node in memo.");
        return pos->second;
    }
}
