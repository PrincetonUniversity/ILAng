#include <memvalues.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <boost/python.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    MemValues::MemValues(int aw, int dw, const boost::python::object& dv)
      : type(NodeType::getMem(aw, dw))
      , MAX_ADDR(mp_int_t(1) << aw)
      , def_value(to_cpp_int(dv))
    {
    }

    MemValues::~MemValues()
    {
    }

    boost::python::object MemValues::getDefault() const
    {
        return to_pyint(def_value);
    }

    void MemValues::setDefault(const boost::python::object& o)
    {
        try {
            mp_int_t dv = to_cpp_int(o);
            def_value = dv;
        } catch(const boost::bad_lexical_cast&) {
            throw PyILAException(PyExc_ValueError, "Invalid default value.");
        }
    }

    boost::python::object MemValues::getValues() const
    {
        boost::python::list l;
        for (auto p : values) {
            auto ai = to_pyint(p.first);
            auto di = to_pyint(p.second);
            auto ti = make_tuple(ai, di);
            l.append(ti);
        }
        return l;
    }

    boost::python::object MemValues::getItem(const boost::python::object& index_) const
    {
        try {
            mp_int_t index = to_cpp_int(index_);
            if (index < 0 || index >= MAX_ADDR) {
                throw PyILAException(PyExc_IndexError, "Index out of range.");
                return boost::python::object();
            }
            auto pos = values.find(index);
            if (pos == values.end()) {
                return to_pyint(def_value);
            } else {
                return to_pyint(pos->second);
            }
        } catch(const boost::bad_lexical_cast&) {
            throw PyILAException(PyExc_ValueError, "Invalid index value.");
        }
    }

    void MemValues::setItem(
        const boost::python::object& index_, 
        const boost::python::object& value_)
    {
        mp_int_t index;
        mp_int_t value;

        try {
            index = to_cpp_int(index_);
        } catch (const boost::bad_lexical_cast&) {
            throw PyILAException(PyExc_ValueError, "Invalid index value.");
        }

        try {
            value = to_cpp_int(value_);
        } catch (const boost::bad_lexical_cast&) {
            throw PyILAException(PyExc_ValueError, "Invalid value.");
        }

        if (value == def_value) {
            auto pos = values.find(index);
            if (pos != values.end()) {
                values.erase(pos);
            }
        } else {
            values[index] = value;
        }
    }
    
    bool MemValues::operator==(const MemValues& that) const
    {
        if (def_value != that.def_value) return false;
        if (values.size() != that.values.size()) return false;
        auto it = values.begin();
        auto jt = that.values.begin();
        for (; it != values.end() && jt != values.end(); it++, jt++) {
            if (it->first != jt->first || it->second != jt->second)
                return false;
        }
        return true;
    }

    z3::expr MemValues::toZ3(z3::context& c) const
    {
        auto addrsort = c.bv_sort(type.addrWidth);
        auto datasort = c.bv_sort(type.dataWidth);

        auto defstr = boost::lexical_cast<std::string>(def_value);
        auto defexpr = c.bv_val(defstr.c_str(), type.dataWidth);

        auto e1 = const_array(addrsort, defexpr);
        for (auto p : values) {
            auto addrstr = boost::lexical_cast<std::string>(p.first);
            auto addrexpr = c.bv_val(addrstr.c_str(), type.addrWidth);
            auto datastr = boost::lexical_cast<std::string>(p.second);
            auto dataexpr = c.bv_val(datastr.c_str(), type.dataWidth);
            auto e2 = store(e1, addrexpr, dataexpr);
            e1 = e2;
        }
        return e1;
    }

    std::ostream& operator<<(std::ostream& out, const MemValues& mv)
    {
        bool first = true;
        out << "[";

        for (auto p : mv.values) {
            if (!first) { out << " "; } else { first = false; }
            out << std::hex << "0x" << p.first << ": " << "0x" << p.second;
        }

        if (!first) { out << " "; } 
        out << "default: 0x" << std::hex << mv.def_value << std::dec << "]";

        return out;
    }

}
