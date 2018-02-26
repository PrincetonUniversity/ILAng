#include <instruction.hpp>
#include <ast.hpp>

using namespace ila;

Instruction::Instruction(const std::string &inst_name, Abstraction * Abs) : abs(Abs), name (inst_name)
{
}

void Instruction::CheckType(const std::string& name, NodeRef* n)
{
    nmap_t * m = abs->getMap(name,n);
    if (m == NULL) return;
    auto pos = m->find(name);
    
    ILA_ASSERT(pos != m->end(), "Invalid iterator.");

        // check types.
        if (n->node->type != pos->second.var->type) {
            throw PyILAException(PyExc_TypeError, 
                "Next expression not same type as variable");

        }
}
    
 void Instruction::setDecode(NodeRef *de)
 {
    if (!de->node->type.isBool()) {
        throw PyILAException(PyExc_TypeError,
            "Decode expressions must be boolean.");
        return;
    }
    decodeExpr = de->node;
 }


NodeRef* Instruction::getDecode()
{
    return new NodeRef(decodeExpr);
}

// Set next


// Set next
void Instruction::setNext(const std::string& name, NodeRef* n)
{
    CheckType(name,n);
    updates[name] = n->node;
}

// Get next
NodeRef* Instruction::getNext(const std::string& name) const
{
    nUpdate_t::const_iterator pos = updates.find(name);
    if(pos == updates.end() ) {
        throw PyILAException(PyExc_RuntimeError,
            "next state function has not been assigned");
        return NULL;
        }
    return new NodeRef(pos->second);
}


    std::ostream & operator << (std::ostream & out, const Instruction &inst)
    {
        return (out << "<Instruction:"<<inst.getName()<<">");
    }

// ------------- Inst ref -------------------------
InstRef::InstRef() 
{
    throw PyILAException(PyExc_RuntimeError, "Cannot create instruction ref directly. Use the context object.");

}
InstRef::InstRef(Instruction *inst) : instPtr(inst)
{

}
InstRef::InstRef(const nInstPtr_t &inst) : instPtr(inst) 
{

}
InstRef::InstRef(const InstRef & inst) : instPtr(inst.instPtr)
{

}
InstRef::~InstRef()
{

}

std::string InstRef::getName() const
{
    return instPtr->getName();
}

void InstRef::setDecode(NodeRef *de)
{
    instPtr->setDecode(de);
}

// Function: get decode
NodeRef* InstRef::getDecode()
{
    return instPtr->getDecode();
}

// Set next
void InstRef::setNext(const std::string& name, NodeRef* n)
{
    instPtr->setNext(name, n);
}

// Get next
NodeRef* InstRef::getNext(const std::string& name) const
{
    return instPtr->getNext(name);
}


std::ostream & operator << (std::ostream & out, const InstRef &inst)
{
    return (out << *(inst.instPtr.get()));
}