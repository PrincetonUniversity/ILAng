#ifndef ILANG_TARGET_TESTSUITE_PATH_ENUMERATOR_H__
#define ILANG_TARGET_TESTSUITE_PATH_ENUMERATOR_H__

#include <ilang/ila/expr_fuse.h>
#include <ilang/ila/ast_fuse.h>
namespace ilang{

struct PathElement{
  ExprPtr expr_ite;
  bool ite_eval;
  bool operator < (const PathElement& pe) {
    return this->ite_eval < pe.ite_eval;
  }
};

class PathEnumerator {
public:
  PathEnumerator();
  void dfs(std::vector<std::vector<PathElement>>& pc, std::vector<PathElement>& path, const ExprPtr& e);
  bool find_ite(const ExprPtr& e);
  std::vector<PathElement> current_path_;
  std::vector<std::vector<PathElement>> path_collector_;
  void cross_product(PathEnumerator& pe);
  std::vector<std::vector<PathElement>> cross_product(std::vector<std::vector<PathElement>>& path_a, std::vector<std::vector<PathElement>>& path_b);

private:
  void insert_current_path();
  void validate_path(std::vector<std::vector<PathElement>>& pc);
};
}
















#endif
