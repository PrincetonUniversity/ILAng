/// \file
/// Example model -- simple stream buffer.

#include <memory>
#include <string>

namespace ilang {

class InstrLvlAbs;
class Ila;

class ExmpStrmBuff {
public:
  Ila GetStrmBuffSpec(const std::string& name);

  Ila GetStrmBuffImpl(const std::string& name);

  std::shared_ptr<InstrLvlAbs> GetStrmBuffSpecRaw(const std::string& name);

  std::shared_ptr<InstrLvlAbs> GetStrmBuffImplRaw(const std::string& name);

  inline const int& buff_size() const { return buff_size_; }
  inline const int& reg_size() const { return reg_size_; }

private:
  int buff_size_ = 8;
  int reg_size_ = 8;

}; // class ExamStreamBuff

} // namespace ilang
