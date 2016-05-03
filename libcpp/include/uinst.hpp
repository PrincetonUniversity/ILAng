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

        // microarch states.
        std::set<std::string> names;
        // inputs
        nmap_t inps;
        // registers.
        nmap_t regs;
        // bits.
        nmap_t bits;
        // memories.
        nmap_t mems;
        // functions.
        nmap_t funs;
    public:
        // constructor.
        MicroInst(Abstraction& abs,
                  const std::string& name,
                  const nptr_t& valid, 
                  const nptr_t& fetch,
                  const nptr_vec_t& decodes);
        // destructor.
        ~MicroInst();

        // Create a boolean variable.
        NodeRef* addBit(const std::string& name);
        // Create a bitvector variable.
        NodeRef* addReg(const std::string& name, int width);
        // Create a memory.
        NodeRef* addMem(const std::string& name, int addrW, int dataW);
        // Create a function.
        NodeRef* addFun(const std::string& name, int retW, const py::list& l);

        // Get an existing boolean.
        NodeRef* getBit(const std::string& name);
        // Get an existing bitvector.
        NodeRef* getReg(const std::string& name);
        // Get an existing memory.
        NodeRef* getMem(const std::string& name);
        // Get an existing function.
        NodeRef* getFun(const std::string& name);

        friend class UInstWrapper;

        // add a var if it does not exist.
        void addVar(nptr_t& nref);
    protected:
        // get a var with this name.
        NodeRef* getVar(const nmap_t& m, const std::string& n);
        // add var to map.
        void addVar(nmap_t& m, nptr_t& n);
        // Set the next template for this memory var.
        void setNext(const std::string& name, NodeRef* n);
        // Get the next template.
        NodeRef* getNext(const std::string& name) const;

        // check if this name exists.
        bool checkAndInsertName(const std::string& name);

    };
    typedef boost::shared_ptr<MicroInst> microinst_ptr_t;

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
