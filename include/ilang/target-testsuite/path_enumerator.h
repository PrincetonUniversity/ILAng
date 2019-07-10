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

typedef std::vector<PathElement> Path;
typedef std::vector<std::vector<PathElement>> PathCollector;

class PathEnumerator {
public:
  Path current_path_;
  PathCollector path_collector_;
 
  PathEnumerator();
  void dfs(const ExprPtr& e);
  void dfs(std::vector<std::vector<PathElement>>& pc, std::vector<PathElement>& path, const ExprPtr& e);
  bool find_ite(const ExprPtr& e);
  void cross_product(PathEnumerator& pe);
  PathCollector cross_product(PathCollector& path_a, PathCollector& path_b);

private:
  void validate_all_path(PathCollector& pc);
};
}

#endif
