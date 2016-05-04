#ifndef _UINST_HPP_DEFINED_
#define _UINST_HPP_DEFINED_

#include <set>
#include <ast.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>

namespace ila
{
    class Abstraction;
    class NodeRef;

    // This is the actual microinst.
    class MicroInst
    {
    protected:
        // parent abstraction.
        Abstraction& abs;
        // name of this uinst.
        const std::string name;
        // fetch
        nptr_t valid;
        nptr_t fetchExpr;
        // decode
        nptr_vec_t decodeExprs;

    public:
        // constructor.
        MicroInst(Abstraction& abs,
                  const std::string& name,
                  const nptr_t& valid, 
                  const nptr_t& fetch,
                  const nptr_vec_t& decodes);
        // destructor.
        ~MicroInst();

        friend class UInstWrapper;

        // add a var if it does not exist.
        void addVar(nptr_t& nref);
    };

    // ---------------------------------------------------------------------- //
    // This object is given to python code.
    struct UInstWrapper
    {
        // the actual uinst.
        microinst_ptr_t uinst;

        // constructor which results in an invalid uinst. need by python.
        UInstWrapper();
        // constructor for a newly created uinst.
        UInstWrapper(MicroInst* inst);
        // constructor for an existing uinst.
        UInstWrapper(const microinst_ptr_t& ui);
        // destructor.
        ~UInstWrapper();

        // name
        std::string getName() const;

        // valid
        NodeRef* getValid() const;
        void setValid(NodeRef* v);

        // fetch
        NodeRef* getFetch() const;
        void setFetch(NodeRef* f);

        // decode.
        py::list getDecode() const;
        void setDecode(const py::list& decs);
    };
}

#endif
