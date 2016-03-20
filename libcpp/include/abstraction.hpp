#ifndef __ABSTRACTION_HPP_DEFINED__
#define __ABSTRACTION_HPP_DEFINED__

#include <string>
#include <ast.hpp>

namespace ila
{
    class Abstraction
    {
    private:
        int objCnt;
    protected:
        // Get a new ID.
        int getObjId();
    public:
        // Constructor.
        Abstraction();
        // Destructor.
        ~Abstraction();
        // Create a bitvector variable.
        NodeRef* BitvectorVar(const std::string& name, int width);

        friend class Node;
    };
}
#endif
