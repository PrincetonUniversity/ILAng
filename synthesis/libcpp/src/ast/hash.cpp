
#include <ast.hpp>
#include <ast/hash.hpp>
#include <boost/functional/hash.hpp>
#include <logging.hpp>

namespace ila
{
    std::size_t hash_value(const Node& nref)
    {
        if (nref.hash_inited) {
            return nref.hash_value;
        }

        const Node* n = &nref;

        const BoolVar* boolvar = NULL; 
        const BoolConst* boolconst = NULL;
        const BoolOp* boolop = NULL;
        const BoolChoice* bchoiceop = NULL;

        const BitvectorVar* bvvar = NULL;
        const BitvectorConst* bvconst = NULL;
        const BitvectorOp* bvop = NULL;
        const BitvectorChoice* bvchoiceop = NULL;
        const BVInRange* inrangeop = NULL;

        const MemVar* memvar = NULL;
        const MemConst* memconst = NULL;
        const MemOp*  memop = NULL;
        const MemChoice* mchoiceop = NULL;

        const FuncVar* funcvar = NULL;

        // start with a hash of the node type //
        std::size_t seed = 0;
        boost::hash_combine(seed, n->type);

        // logging here takes a lot of time, so I tend to remove it
        //log2("Hash") << "Node: " << *n << std::endl;
        //log2("Hash") << "Initial seed: " << seed << std::endl;

        //// booleans ////
        if ((boolvar = dynamic_cast<const BoolVar*>(n))) {
            // rememeber type is accounted for.
            boost::hash_combine(seed, n->getName());
        } else if ((boolconst = dynamic_cast<const BoolConst*>(n))) {
            boost::hash_combine(seed, boolconst->val());
        } else if ((boolop = dynamic_cast<const BoolOp*>(n))) {
            boost::hash_combine(seed, static_cast<int>(boolop->arity));
            boost::hash_combine(seed, static_cast<int>(boolop->op));
        } else if((bchoiceop = dynamic_cast<const BoolChoice*>(n))) {
            choice_hash_combine(seed, bchoiceop);

        //// bitvectors ////
        } else if((bvvar = dynamic_cast<const BitvectorVar*>(n))) {
            // type is accounted for.
            boost::hash_combine(seed, n->getName());
        } else if((bvconst = dynamic_cast<const BitvectorConst*>(n))) {
            // have to use string rep unfortunately //
            boost::hash_combine(seed, bvconst->vstr());
        } else if ((bvop = dynamic_cast<const BitvectorOp*>(n))) {
            boost::hash_combine(seed, bvop->op);
            for (unsigned i=0; i != bvop->nParams(); i++) {
                boost::hash_combine(seed, bvop->param(i));
            }
        } else if ((bvchoiceop = dynamic_cast<const BitvectorChoice*>(n))) {
            choice_hash_combine(seed, bvchoiceop);
        } else if ((inrangeop = dynamic_cast<const BVInRange*>(n))) {
            // random number that represents bvinrange operators
            boost::hash_combine(seed, 1675467593);
        //// memories ////
        } else if ((memvar = dynamic_cast<const MemVar*>(n))) {
            // type is accounted for.
            boost::hash_combine(seed, n->getName());
        } else if ((memconst = dynamic_cast<const MemConst*>(n))) {
            boost::hash_combine(seed, 1870276294);
            boost::hash_combine(seed, memconst->memvalues);
        } else if ((memop = dynamic_cast<const MemOp*>(n))) {
            boost::hash_combine(seed, static_cast<int>(memop->op));
            boost::hash_combine(seed, static_cast<int>(memop->endian));
        } else if ((mchoiceop = dynamic_cast<const MemChoice*>(n))) {
            choice_hash_combine(seed, mchoiceop);
        //// Functions ////
        } else if ((funcvar = dynamic_cast<const FuncVar*>(n))) {
            // type is accounted for.
            boost::hash_combine(seed, n->getName());
        }

        // hash any arguments.
        for (unsigned i=0; i != n->nArgs(); i++) {
            const Node& arg_i = *(n->arg(i).get());
            boost::hash_combine(seed, arg_i);
        }
        //log2("Hash") << "Final seed: " << seed << std::endl;

        nref.hash_inited = true;
        nref.hash_value = seed;
        return (nref.hash_value);
    }

    std::size_t hash_value(const NodeType& ntype)
    {
        return ntype.hash_val;
    }

    std::size_t compute_hash_value(const NodeType& ntype)
    {
        std::size_t seed = 0;
        boost::hash_combine(seed, static_cast<int>(ntype.type));

        switch(ntype.type) {
        case NodeType::BOOL:
            break;
        case NodeType::BITVECTOR:
            boost::hash_combine(seed, ntype.bitWidth);
            break;
        case NodeType::MEM:
            boost::hash_combine(seed, ntype.addrWidth);
            boost::hash_combine(seed, ntype.dataWidth);
            break;
        case NodeType::FUNC:
            boost::hash_combine(seed, ntype.bitWidth);
            for (unsigned i = 0; i != ntype.argsWidth.size(); i++) {
                boost::hash_combine(seed, ntype.argsWidth[i]);
            }
            break;
        default:
            break;
        }
        return seed;
    }

    std::size_t hash_value(const MemValues& mv) {
        std::size_t seed = 0;
        boost::hash_combine(seed, mv.type);
        boost::hash_combine(seed, 
            boost::lexical_cast<std::string>(mv.MAX_ADDR));
        boost::hash_combine(seed, 
            boost::lexical_cast<std::string>(mv.def_value));
        for (auto it : mv.values) {
            boost::hash_combine(seed, 
                boost::lexical_cast<std::string>(it.first));
            boost::hash_combine(seed, 
                boost::lexical_cast<std::string>(it.second));
        }
        return seed;
    }
}
