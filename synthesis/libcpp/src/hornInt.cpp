#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <logging.hpp>
#include <common.hpp>
#include <horn.hpp>

namespace ila
{
    void HornTranslator::initVarInt (hvptr_t v, nptr_t n)
    {
        // TODO
    }

    void HornTranslator::initBoolOpInt (const BoolOp* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initBoolConstInt (const BoolConst* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initBvOpInt (const BitvectorOp* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initBvVarInt (const BitvectorVar* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initBvConstInt (const BitvectorConst* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initMemOpInt (const MemOp* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initMemConstInt (const MemConst* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initFuncVarInt (const FuncVar* n, hvptr_t v)
    {
        // TODO
    }
}
