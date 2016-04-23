#ifndef _LOGGING_HPP_DEFINED_
#define _LOGGING_HPP_DEFINED_

#include <iostream>

namespace ila
{
    std::ostream& info();
    std::ostream& log1();
    std::ostream& log2();

    void initLogging();

    void setLogLevel(int l, const std::string& name);
}

#endif
