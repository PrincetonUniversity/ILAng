/// \file
/// Example model -- simple stream buffer.

#include <memory>

namespace ila {

class InstrLvlAbs;
class Ila;

class ExmpStrmBuff {
 public:
  Ila GetStrmBuffSpec(const std::string& name = "SBSpec");

  Ila GetStrmBuffImpl(const std::string& name = "SBImpl");

  std::shared_ptr<InstrLvlAbs> GetStrmBuffSpecRaw(
      const std::string& name = "SBSpec");

  std::shared_ptr<InstrLvlAbs> GetStrmBuffImplRaw(
      const std::string& name = "SBImpl");

  inline const int& buff_size() const { return buff_size_; }
  inline const int& reg_size() const { return reg_size_; }

 private:
  int buff_size_ = 8;
  int reg_size_ = 8;

};  // class ExamStreamBuff

}  // namespace ila
