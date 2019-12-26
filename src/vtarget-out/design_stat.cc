/// \file The Source for design statistics
// ---Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/vtarget-out/design_stat.h>

#include <fstream>

namespace ilang {

void DesignStatistics::StoreToFile(const std::string& fn) const {
  std::ofstream fout(fn);
  if (!fout.is_open()) {
    ILA_ERROR << "Unable to write to " << fn;
    return;
  }
  fout << TimeOfEqCheck << std::endl;
  fout << TimeOfInvValidate << std::endl;
  fout << TimeOfInvProof << std::endl;
  fout << TimeOfInvSyn << std::endl;
  fout << TimeOfInvSynEnhance << std::endl;
  fout << TotalTime << std::endl;
  fout << TimeOfInvSynSeries.size() << std::endl;
  for (auto&& t : TimeOfInvSynSeries)
    fout << " " << t << std::endl;
}

void DesignStatistics::LoadFromFile(const std::string& fn) {
  std::ifstream fin(fn);
  if (!fin.is_open()) {
    ILA_ERROR << "Unable to read " << fn;
    return;
  }
  fin >> TimeOfEqCheck;
  fin >> TimeOfInvValidate;
  fin >> TimeOfInvProof;
  fin >> TimeOfInvSyn;
  fin >> TimeOfInvSynEnhance;
  fin >> TotalTime;
  unsigned series;
  double tmp;
  fin >> series;
  for (unsigned idx = 0; idx < series; ++idx) {
    fin >> tmp;
    TimeOfInvSynSeries.push_back(tmp);
  }
}

}; // namespace ilang