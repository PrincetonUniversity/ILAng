#ifndef __HORNTRANSLATOR_HPP_DEFINED__
#define __HORNTRANSLATOR_HPP_DEFINED__

#include <cassert>

#include <unordered_map>
#include <vector>
#include <memory>

#include <z3++.h>
#include <util.hpp>
#include <smt.hpp>

#include <ast.hpp>
#include <hornDB.hpp>

namespace ila
{
    class HornDB;
    class Abstraction;

    class HornTranslator
    {
    private:
       // pointer to the abstraction to be translated.
       Abstraction* abs;
       // horn clause data base
       // HornClauseDB m_db;
    public:
       // constructor.
       HornTranslator(Abstraction* a);
       // destructor.
       virtual ~HornTranslator();
       // convert whole abs to horn clauses.
       void transAll(const std::string& fileName);
       // convert one node to horn clauses.
       void transOne(NodeRef* node, const std::string& fileName);
    };
}

#endif /* __HORNTRANSLATOR_HPP_DEFINED__ */
