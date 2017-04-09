#include <boost/algorithm/string.hpp>
#include <logging.hpp>
#include <fstream>
#include <exception.hpp>
#include <set>
#include <util.hpp>

namespace ila
{
    std::ostream* infostream;
    std::ostream* log1stream;
    std::ostream* log2stream;
    std::ostream* nullstream;
    std::set<std::string> enabledLogs;

    void initLogging()
    {
        infostream = &std::cout;
        log1stream = new std::ofstream("/dev/null");
        log2stream = new std::ofstream("/dev/null");
        nullstream = new std::ofstream("/dev/null");
    }

    std::ostream& _log(std::ostream& l, const char* s)
    {
        std::vector<std::string> parts;
        boost::split(parts, s, boost::is_any_of("."));

        ILA_ASSERT(parts.size() > 0, "Cannot be empty.");
        std::string prefix = parts[0];
        if (enabledLogs.find(prefix) != enabledLogs.end()) { 
            return l << "[" << s << "] "; 
        }
        for (unsigned i=1; i != parts.size(); i++) {
            prefix += "." + parts[i];
            if (enabledLogs.find(prefix) != enabledLogs.end()) { 
                return l << "[" << s << "] "; 
            }
        }
        return *nullstream;
    }

    std::ostream& info(const char* l) { return _log(*infostream, l); }
    std::ostream& log1(const char* l) { return _log(*log1stream, l); }
    std::ostream& log2(const char* l) { return _log(*log2stream, l); }

    void clearStream(std::ostream*& ptr)
    {
        if (ptr != &std::cout) {
            delete ptr;
        } 
        ptr = new std::ofstream("/dev/null");
    }

    void setStream(std::ostream*& ptr, const std::string& filename)
    {
        if (ptr != &std::cout) {
            delete ptr;
        } 
        if (filename == "") {
            ptr = &std::cout;
        } else {
            ptr = new std::ofstream(filename);
        }
    }

    void setLogLevel(int l, const std::string& name)
    {
        if (l == 0) {
            clearStream(infostream);
            clearStream(log1stream);
            clearStream(log2stream);
        } else if (l == 1) {
            setStream(infostream, name);
            clearStream(log1stream);
            clearStream(log2stream);
        } else if (l == 2) {
            setStream(infostream, name);
            log1stream = infostream;
            clearStream(log2stream);
        } else {
            setStream(infostream, name);
            log1stream = infostream;
            log2stream = infostream;
        }
    }

    void enableLog(const std::string& name)
    {
        enabledLogs.insert(name);
    }

    void disableLog(const std::string& name)
    {
        enabledLogs.erase(name);
    }

    void clearLogs()
    {
        enabledLogs.clear();
    }

}

