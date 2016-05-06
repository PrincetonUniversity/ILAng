#ifndef __BVINRANGE_HPP_DEFINED__
#define __BVINRANGE_HPP_DEFINED__

#include <common.hpp>
#include <ast/node.hpp>
#include <ast/bool.hpp>
#include <ast/bitvec.hpp>
#include <type.hpp>

namespace ila {
    class Abstraction;

    class BVInRange : public BitvectorExpr
    {
    protected:
        nptr_t lo;
        nptr_t hi;
    public:
        // constructor.
        BVInRange(const std::string& name,
                  const nptr_t& lo, const nptr_t& hi);
        // copy constructor.
        BVInRange(const BVInRange& that);
        // destructor.
        virtual ~BVInRange();

        // clone.
        virtual Node* clone() const;
        // equal.
        virtual bool equal(const Node* that) const;
        // stream output.
        virtual std::ostream& write(std::ostream& out) const;
        // # of args.
        virtual unsigned nArgs() const;
        // arg i.
        virtual nptr_t arg(unsigned i) const;
    };
}

#endif
