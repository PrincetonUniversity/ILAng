#include <iostream>
#include <boost/lexical_cast.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <abstraction.hpp>


namespace ila
{
    // ---------------------------------------------------------------------- //
    int Node::totalObjCnt = 0;

    // ---------------------------------------------------------------------- //
    Node::Node()
      : ctx(NULL)
      , id(-1)
      , type(NodeType())
    {
    }

    Node::Node(Abstraction* c, NodeType t) 
      : ctx(c)
      , id(ctx->getObjId())
      , type(t) 
    {
        _initName();
    }

    Node::~Node()
    {
    }

    // ---------------------------------------------------------------------- //
    void Node::_initName()
    {
        name = "n" + boost::lexical_cast<std::string>(id);
    }

    // ---------------------------------------------------------------------- //
    unsigned Node::nArgs() const
    {
        return 0;
    }

    nptr_t Node::arg(unsigned i) const 
    {
        return NULL;
    }

    // ---------------------------------------------------------------------- //
    Node* Node::clone() const
    {
        return new Node();
    }

    bool Node::equal(const Node* that) const
    {
        throw new PyILAException(
            PyExc_RuntimeError, 
            "Node::equal not implemented.");
        return false;
    }

    py::object Node::getValue() const
    {
        throw PyILAException(PyExc_AttributeError,
            "Object does not have a value attribute.");
        return py::object();
    }


    std::ostream& Node::write(std::ostream& out) const
    {
        return (out << name);
    }

    // ---------------------------------------------------------------------- //
    // private visitor class //
    namespace {
        struct SynCounter {
            int cnt;
        public:
            SynCounter() : cnt(0) {}
            void operator() (const Node* n) {
                if (dynamic_cast<const BoolChoice*>(n)      ||
                    dynamic_cast<const BitvectorChoice*>(n) ||
                    dynamic_cast<const MemChoice*>(n)       ||
                    dynamic_cast<const BVInRange*>(n))
                {
                    cnt += 1;
                }
            }
            operator int() const {
                return cnt;
            }
        };
    }

    bool Node::hasSynthesisConstructs() const
    {
        SynCounter sc;
        depthFirstVisit(sc);
        return (static_cast<int>(sc) != 0);
    }

    // ---------------------------------------------------------------------- //
    std::ostream& operator<<(std::ostream& out, const Node& that)
    {
        return that.write(out);
    }

    // ---------------------------------------------------------------------- //
    void Node::visit(NodeVisitorI& vi)
    {
        unsigned n = nArgs();
        vi.preVisit(this);
        for (unsigned i=0; i != n; i++) {
            const nptr_t& arg_i = this->arg(i);
            arg_i->visit(vi);
        }
        vi.postVisit(this);
    }

    // ---------------------------------------------------------------------- //
    void NodeVisitorI::preVisit(const Node* n)
    {
    }

    void NodeVisitorI::postVisit(const Node* n)
    {
    }
    // ---------------------------------------------------------------------- //
}
