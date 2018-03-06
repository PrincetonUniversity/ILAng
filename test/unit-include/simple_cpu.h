/// \file
/// The ILA model of a simple processor.

#ifndef SIMPLE_CPU_H__
#define SIMPLE_CPU_H__

#include <memory>

namespace ila {

class InstrLvlAbs;
class Ila;

std::shared_ptr<InstrLvlAbs> SimpleCpu(const std::string& name);
Ila SimpleCpuRef(const std::string& name);
int GenLoad(const int& dst, const int& addr);
int GenAdd(const int& dst, const int& in1, const int& in2);
int GenStore(const int& src, const int& addr);

}; // namespace ila

#endif // SIMPLE_CPU_H__

