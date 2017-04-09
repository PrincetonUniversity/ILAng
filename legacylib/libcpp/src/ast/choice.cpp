#include <ast.hpp>
#include <type.hpp>
#include <ast/choice.hpp>
#include <exception.hpp>
#include <util.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    Choice::Choice(
        const std::string& name,
        const std::vector< boost::shared_ptr<Node> >& args_)
      : args(args_)
    {
        for (unsigned i=1; i != args.size(); i++) {
            std::string var("choice." + name + "." + 
                            boost::lexical_cast<std::string>(i));
            choiceVars.push_back(var);
        }
    }

    Choice::Choice(
        const Choice* that,
        const nptr_vec_t& args_)
      : args(args_)
      , choiceVars(that->choiceVars)
    {
    }

    Choice::~Choice()
    {
    }

    NodeType Choice::getChoiceType(
        const std::vector< boost::shared_ptr<Node> >& args)
    {
        if (args.size() <= 1) {
            return NodeType(NodeType::INVALID);
        }
        NodeType r = args[0]->type;
        for (unsigned i=1; i != args.size(); i++) {
            if (args[i]->type != r) {
                return NodeType(NodeType::INVALID);
            }
        }
        return r;
    }

    bool Choice::equal(const Choice& that) const
    {
        if (args.size() != that.args.size()) return false;
        for (unsigned i=0; i != args.size(); i++) {
            if (!args[i]->equal(that.args[i].get())) return false;
        }
        return true;
    }

    std::ostream& Choice::write(std::ostream& out) const
    {
        out << "(choice";
        for (auto arg : args) {
            arg->write(out << " ");
        }
        return (out << ")");
    }

    // ---------------------------------------------------------------------- //
    ReadSlice::ReadSlice(const std::string& name,
                         const nptr_vec_t& args, 
                         const nptr_t& bv, 
                         int w, int incr)
      : BitvectorChoice(name, args)
      , bitvec(bv)
      , width(w)
      , increment(incr)
    {
    }

    ReadSlice::~ReadSlice()
    {
    }

    // ---------------------------------------------------------------------- //
    ReadSlice* ReadSlice::createReadSlice(
        const std::string& name, const nptr_t& bv, int width, int incr)
    {
        if (!bv->type.isBitvector() || bv->type.bitWidth <= width || width <= 0) {
            throw PyILAException(PyExc_TypeError, 
                "Argument to readslice must be a bitvector of width greater than result width.");
            return NULL;
        }
        nptr_vec_t args;
        int msb = width-1, lsb=0;
        for(; msb < bv->type.bitWidth; msb+=incr, lsb+=incr) {
            nptr_t ni(new BitvectorOp(BitvectorOp::EXTRACT, bv, msb, lsb));
            args.push_back(ni);
        }
        return new ReadSlice(name, args, bv, width, incr);
    }

    // ---------------------------------------------------------------------- //
    Node* ReadSlice::clone() const
    {
        return new ReadSlice(name, choice.args, bitvec, width, increment);
    }

    std::ostream& ReadSlice::write(std::ostream& out) const
    {
        return out << "(read-slice " << "#" << width << " "
                   << "#" << increment << " "
                   << *bitvec.get() << ")";
    }

    // ---------------------------------------------------------------------- //
    WriteSlice::WriteSlice(const std::string& name,
                           const nptr_vec_t& args, 
                           const nptr_t& bv, const nptr_t& wr, int incr)
      : BitvectorChoice(name, args)
      , bitvec(bv)
      , data(wr)
      , increment(incr)
    {
    }

    WriteSlice::~WriteSlice()
    {
    }

    // ---------------------------------------------------------------------- //
    WriteSlice* WriteSlice::createWriteSlice(
        const std::string& name,
        const nptr_t& bv, const nptr_t& wr, int incr)
    {
        if (!bv->type.isBitvector() || !wr->type.isBitvector() ||
             bv->type.bitWidth <= wr->type.bitWidth) {

            throw PyILAException(PyExc_TypeError, 
                "Arguments to writeslice have the wrong type.");
            return NULL;
        }
        nptr_vec_t args;
        int msb = wr->type.bitWidth-1, lsb=0;
        for(; msb < bv->type.bitWidth; msb+=incr, lsb+=incr) {
            int msb1 = bv->type.bitWidth-1;
            int lsb1 = msb+1;

            nptr_vec_t pieces;
            // is there a slice to the left of 'wr'?
            if (msb1 >= lsb1) {
                nptr_t n1(new BitvectorOp(
                    BitvectorOp::EXTRACT, bv, msb1, lsb1));
                pieces.push_back(n1);
            } 
            pieces.push_back(wr);

            // is there a slice to the right of 'wr'?
            nptr_t n2;
            int msb2 = lsb-1;
            int lsb2 = 0;
            if (msb2 >= 0) {
                nptr_t n2(new BitvectorOp(
                    BitvectorOp::EXTRACT, bv, msb2, lsb2));
                pieces.push_back(n2);
            }

            // now put the slices together.
            ILA_ASSERT(pieces.size() == 2 || pieces.size() == 3,
                       "Must have 2 or 3 pieces for writeslice args.");
            if (pieces.size() == 2) {
                nptr_t r(new BitvectorOp(
                    BitvectorOp::CONCAT, pieces[0], pieces[1]));
                args.push_back(r);
            } else {
                nptr_t r1(new BitvectorOp(
                    BitvectorOp::CONCAT, pieces[0], pieces[1]));
                nptr_t r2(new BitvectorOp(
                    BitvectorOp::CONCAT, r1, pieces[2]));
                args.push_back(r2);
            }
        }
        return new WriteSlice(name, args, bv, wr, incr);
    }

    // ---------------------------------------------------------------------- //
    Node* WriteSlice::clone() const
    {
        return new WriteSlice(name, choice.args, bitvec, data, increment);
    }

    std::ostream& WriteSlice::write(std::ostream& out) const
    {
        return out << "(write-slice " << *bitvec.get() << " "
                   << "#" << increment << " "
                   << *data.get() << ")";
    }


}
