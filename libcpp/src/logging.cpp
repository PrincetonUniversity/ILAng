#include <logging.hpp>
#include <fstream>
#include <exception.hpp>

namespace ila
{
    std::ostream* infostream;
    std::ostream* log1stream;
    std::ostream* log2stream;

    void initLogging()
    {
        infostream = &std::cout;
        log1stream = new std::ofstream("/dev/null");
        log2stream = new std::ofstream("/dev/null");
    }

    std::ostream& info() { return *infostream; }
    std::ostream& log1() { return *log1stream; }
    std::ostream& log2() { return *log2stream; }

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
}

