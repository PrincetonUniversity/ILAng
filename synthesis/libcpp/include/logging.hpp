#ifndef _LOGGING_HPP_DEFINED_
#define _LOGGING_HPP_DEFINED_

#include <iostream>

namespace ila
{
    std::ostream& info(const char* s);
    std::ostream& log1(const char* s);
    std::ostream& log2(const char* s);

    void initLogging();

    void setLogLevel(int l, const std::string& name);
    void enableLog(const std::string& name);
    void disableLog(const std::string& name);
    void clearLogs();
}

#endif
