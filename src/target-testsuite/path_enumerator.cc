#include <ilang/target-testsuite/path_enumerator.h>
#include <ilang/ila/instr_lvl_abs.h>

namespace ilang{

PathEnumerator::PathEnumerator() {}

void PathEnumerator::dfs(const ExprPtr& e) {
  dfs(path_collector_, current_path_, e);
  return;
}

void PathEnumerator::dfs(PathCollector& pc, Path& path, const ExprPtr& e) {
  auto expr_uid = GetUidExpr(e);
  if (expr_uid == AST_UID_EXPR::OP) {
    auto expr_op_uid = GetUidExprOp(e);
    if (expr_op_uid == AST_UID_EXPR_OP::ITE) {
      PathElement pe_t, pe_f;
      pe_t.expr_ite = e;
      pe_t.ite_eval = true;
      pe_f.expr_ite = e;
      pe_f.ite_eval = false;
      if (find_ite(e->arg(1))) {
	path.push_back(pe_t);
	dfs(pc, path, e->arg(1));
	path.pop_back();
      } else {
	path.push_back(pe_t);
	pc.push_back(path);
	path.pop_back();
      }
      if (find_ite(e->arg(2))) {
        path.push_back(pe_f);
        dfs(pc, path, e->arg(2));
        path.pop_back(); 
      } else {
	path.push_back(pe_f);
	pc.push_back(path);
	path.pop_back();
      }
    } else {
      if(e->arg_num() == 0)
	return; 
      PathCollector* pc_list = new PathCollector[e->arg_num()];
      for (int i = 0; i < e->arg_num(); i++) {
	Path new_path;
	if (find_ite(e->arg(i)))	
	  dfs(pc_list[i], new_path, e->arg(i));
      }
      PathCollector new_pc = pc_list[0];
      for (int i = 1; i < e->arg_num(); i++)
	new_pc = cross_product(new_pc, pc_list[i]);
      for (auto new_path = new_pc.begin(); new_path != new_pc.end(); new_path++) {
	auto current_path = path;
	current_path.insert(current_path.end(), new_path->begin(), new_path->end());
	pc.push_back(current_path);
      } 
    }
  } 
  validate_all_path(pc);
}

void PathEnumerator::validate_all_path(PathCollector& pc) {
  for (auto path = pc.begin(); path != pc.end(); path++) {
    z3::context ctx;
    z3::solver slv(ctx);
    Z3ExprAdapter adpt(ctx); 
    for (auto cond = path->begin(); cond != path->end(); cond++) {
      auto z3_cond = adpt.GetExpr(cond->expr_ite->arg(0));
      auto ite_eval = cond->ite_eval;
      slv.add(z3::implies(z3_cond, ite_eval) && z3::implies(ite_eval, z3_cond));
    } 
    if (slv.check() == z3::unsat) {
      pc.erase(path); 
      path--;
    }
  }
}

void PathEnumerator::cross_product(PathEnumerator& pe) {
  auto pc_a = path_collector_;
  auto pc_b = pe.path_collector_;
  path_collector_ = cross_product(pc_a, pc_b);
  return;
}

PathCollector PathEnumerator::cross_product(PathCollector& pc_a, PathCollector& pc_b) {
  if (pc_a.size() == 0) {
    return pc_b;
  } else if (pc_b.size() == 0) {
    return pc_a;
  } else {
    PathCollector new_pc;
    for (auto path_a = pc_a.begin(); path_a != pc_a.end(); path_a++) {
      for (auto path_b = pc_b.begin(); path_b != pc_b.end(); path_b++) {
        auto new_path = *path_a;
        new_path.insert(new_path.end(), path_b->begin(), path_b->end());
        new_pc.push_back(new_path);
      } 
    }
    validate_all_path(new_pc);
    return new_pc;
  }
}

bool PathEnumerator::find_ite(const ExprPtr& e) {
  auto expr_uid = GetUidExpr(e);
  if (expr_uid == AST_UID_EXPR::OP) {
    auto expr_op_uid = GetUidExprOp(e); 
    if (expr_op_uid == AST_UID_EXPR_OP::ITE)
      return true;
    else {
      for (int i = 0; i < e->arg_num(); i++) {
	if (find_ite(e->arg(i)))
	  return true;
      }
      return false;
    }
  } else
    return false; 
}

}
