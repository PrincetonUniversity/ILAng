#include <ast.hpp>
#include <ast/bvinrange.hpp>
#include <exception.hpp>

namespace ila
{
    BVInRange::BVInRange(const std::string& n_, 
                         const nptr_t& l, const nptr_t& h)
      : BitvectorExpr(l->type.bitWidth)
      , lo(l)
      , hi(h)
    {
        this->name = n_;
        if (lo->type != hi->type || !lo->type.isBitvector()) {
            throw PyILAException(PyExc_TypeError, "in-range args type error.");
        }
    }

    BVInRange::BVInRange(const BVInRange& that)
      : BitvectorExpr(that.type.bitWidth)
      , lo(that.lo)
      , hi(that.hi)
    {
    }

    BVInRange::~BVInRange()
    {
    }

    Node* BVInRange::clone() const
    {
        return new BVInRange(*this);
    }

    bool BVInRange::equal(const Node* that_) const
    {
        auto that = dynamic_cast<const BVInRange*>(that_);
        if (that) {
            return that->type == type &&
                   that->lo->equal(lo.get()) &&
                   that->hi->equal(hi.get());
        } else {
            return false;
        }
    }

    std::ostream& BVInRange::write(std::ostream& out) const
    {
        out << "(in-range " << *lo.get() << " " << *hi.get() << ")";
        return out;
    }

    unsigned BVInRange::nArgs() const
    {
        return 2;
    }

    nptr_t BVInRange::arg(unsigned i) const
    {
        if (i == 0) return lo;
        else if (i == 1) return hi;
        else return NULL;
    }
}

