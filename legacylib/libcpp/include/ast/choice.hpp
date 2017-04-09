#ifndef __AST_SYN_HPP_DEFINED__
#define __AST_SYN_HPP_DEFINED__

#include <ast/node.hpp>
#include <ast/bool.hpp>
#include <ast/bitvec.hpp>
#include <type.hpp>

namespace ila 
{
    class Abstraction;

    // ---------------------------------------------------------------------- //
    struct Choice {
        // the operands themselves.
        nptr_vec_t args;
        // vector of names for boolean variables.
        std::vector< std::string > choiceVars;
        // constructor.
        Choice(const std::string& name, 
               const nptr_vec_t& args);
        // kind of a copy constructor.
        Choice(const Choice* that, 
               const nptr_vec_t& args_);
        // destructor.
        ~Choice();
        
        // check types and return the result type.
        static NodeType getChoiceType(
            const nptr_vec_t& args);

        // check equality.
        bool equal(const Choice& that) const;

        // dump to stream.
        std::ostream& write(std::ostream& out) const;

        // choice variable name.
        const char* getChoiceVarName(unsigned i) const {
            if ((i+1) < args.size()) {
                return choiceVars[i].c_str();
            } else {
                return NULL;
            }
        }
    };

    // ---------------------------------------------------------------------- //
    template<typename T>
    class ChoiceExpr : public T
    {
    protected:
        Choice choice;
    public:
        // constructor.
        ChoiceExpr(
            const std::string& n_,
            const nptr_vec_t& args_)
          : T(Choice::getChoiceType(args_))
          , choice(n_, args_)
        {
            this->name = n_;
        }

        // destructor
        virtual ~ChoiceExpr() {}

        // clone.
        virtual Node* clone() const
        {
            return new ChoiceExpr(
                this->name, choice.args);
        }

        // clone with new args.
        ChoiceExpr* clone(const nptr_vec_t& args) const
        {
            return new ChoiceExpr(this->name, args);
        }

        // equal.
        virtual bool equal(const Node* that_) const
        {
            const ChoiceExpr<T>* that = 
                dynamic_cast< const ChoiceExpr<T>* >(that_);
            if (that == NULL) return false;
            else return choice.equal(that->choice);
        }

        // write to stream.
        virtual std::ostream& write(std::ostream& out) const
        {
            return choice.write(out);
        }

        // number of arguments.
        virtual unsigned nArgs() const
        {
            return choice.args.size();
        }

        // return arg i.
        virtual nptr_t arg(unsigned i) const
        {
            if (i < choice.args.size()) { return choice.args[i]; } 
            else { return NULL; }
        }

        // return the SMT variable name.
        const char* getChoiceVarName(unsigned i) const {
            return choice.getChoiceVarName(i);
        }
    };

    // ---------------------------------------------------------------------- //
    typedef ChoiceExpr<BitvectorExpr> BitvectorChoice;
    typedef ChoiceExpr<BoolExpr> BoolChoice;
    typedef ChoiceExpr<MemExpr> MemChoice;

    // ---------------------------------------------------------------------- //
    class ReadSlice : public BitvectorChoice
    {
    private:
        // private constructor: called by the static function.
        ReadSlice(const std::string& name, 
                  const nptr_vec_t& args, 
                  const nptr_t& bv, 
                  int width, int incr);
    public:
        // destructor.
        virtual ~ReadSlice();

        // the bitvector.
        nptr_t bitvec;
        // slice width.
        int width;
        // the increment between slices.
        int increment;

        // factory method.
        static ReadSlice* createReadSlice(
            const std::string& name, 
            const nptr_t& bv, int width, int incr);
            
        // clone.
        virtual Node* clone() const;

        // stream output
        virtual std::ostream& write(std::ostream& out) const;
    };

    // ---------------------------------------------------------------------- //
    class WriteSlice : public BitvectorChoice
    {
    private:
        // private constructor: called by the static function.
        WriteSlice(const std::string& name, 
                   const nptr_vec_t& args, 
                   const nptr_t& bv, 
                   const nptr_t& wr, int incr);
    public:
        // destructor.
        virtual ~WriteSlice();
        // the bitvector.
        nptr_t bitvec;
        // the thing to replace it with.
        nptr_t data;
        // the increment for the choices of slice to write.
        int increment;

        // factory method.
        static WriteSlice* createWriteSlice(
            const std::string& name, 
            const nptr_t& bv, const nptr_t& wr, int incr);
            
        // clone.
        virtual Node* clone() const;

        // stream output
        virtual std::ostream& write(std::ostream& out) const;
    };
}

#endif
