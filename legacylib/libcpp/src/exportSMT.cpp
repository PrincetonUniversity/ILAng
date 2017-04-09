#include <exportSMT.hpp>

namespace ila
{
    // the function solver.to_smt2() does not always exists
    // for Z3 >= 4.4.2, it's okay, but won't work with 4.3.2
    // we need to handle this
    // using SFINAE (substitution failure is not an error)
    // 

	// Credit to 
	// http://stackoverflow.com/questions/257288/is-it-possible-to-write-a-c-template-to-check-for-a-functions-existence
    #define HAS_MEM_FUNC(func, name)                                        \
    template<typename T, typename Sign>                                 \
    struct name {                                                       \
        typedef char yes[1];                                            \
        typedef char no [2];                                            \
        template <typename U, U> struct type_check;                     \
        template <typename _1> static yes &chk(type_check<Sign, &_1::func > *); \
        template <typename   > static no  &chk(...);                    \
        static bool const value = sizeof(chk<T>(0)) == sizeof(yes);     \
    }
	
    template<bool C, typename T = void>
    struct enable_if {
        typedef T type;
    };
    template<typename T>
    struct enable_if<false, T> { };
	
    HAS_MEM_FUNC(to_smt2, has_to_smt2);

    template<typename T> 
    typename enable_if<has_to_smt2<T, 
	                   std::string(T::*)(char const * )>::value, std::string>::type
    toSmt(T & t) {
        /* something when T has toString ... */
	    return t.to_smt2();
    }
	
	template<typename T> 
	typename enable_if<!has_to_smt2<T, std::string(T::*)(char const * )>::value, std::string>::type
	toSmt(T & t) {
   		/* something when T doesnt have toString ... */
   	return std::string("T::to_smt2() does not exist. Need a newer version (>= 4.4.2) of Z3.");
	}
	
    void SMTExport::exportSMT(std::ofstream & out, const Node * n, const std::string & name, int width)
    {
        using namespace z3;

        if(n==NULL)
            out<<("<NULL>");

        context c_;
        Z3ExprAdapter c(c_,"");
        expr outVar = c_.bv_const( (name + "_OUT_").c_str(), width );

        z3::expr ex1 = c.getExpr(n);
        solver S(c_);
        S.add( outVar==ex1 );
        out<<( toSmt(S) );

    }

    int SMTExport::get_width(const Node *n)
    {
        const BoolExpr * boolexp = NULL;
        const BitvectorExpr * bitvectorexpr = NULL;
        const FuncExpr * funcexpr = NULL;
        const MemExpr * memexpr = NULL;

        if (  (boolexp = dynamic_cast<const BoolExpr*>(n)) )  {
            return 1;
        }
        else if( (bitvectorexpr = dynamic_cast<const BitvectorVar*>(n)) ) {
            return bitvectorexpr->type.bitWidth;
        }
        else if( (funcexpr = dynamic_cast<const FuncExpr*>(n)) ) {
            return funcexpr->type.bitWidth;
        }
        else if( (memexpr = dynamic_cast<const MemExpr*>(n))  ) {
            return memexpr->type.dataWidth;
        }
        else
            ILA_ASSERT(false, "Node type not supported.");

        return 0;

    }   

    bool SMTExport::isStageVar(const std::string &inpName, const nstage_vec_t & stageStore)
    {
        for(const auto & item: stageStore  )
        {
            if (item.first == inpName)
                return true;
        }
        return false;
    }
}