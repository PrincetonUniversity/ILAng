#include <ilang/target-testsuite/path_enumerator.h>
#include <ilang/ila/instr_lvl_abs.h>

namespace ilang{

PathEnumerator::PathEnumerator() {}

void PathEnumerator::dfs(const ExprPtr& e) {
  auto expr_uid = GetUidExpr(e);
  if (expr_uid == AST_UID_EXPR::OP) {
    auto expr_op_uid = GetUidExprOp(e);
    if (expr_op_uid == AST_UID_EXPR_OP::ITE) {
      PathElement pe_t, pe_f;
      pe_t.expr_ite = e;
      pe_t.ite_eval = true;
      pe_f.expr_ite = e;
      pe_f.ite_eval = false;
      std::cout << e << std::endl;
      if (find_ite(e->arg(1))) {
	current_path_.push_back(pe_t);
	dfs(e->arg(1));
	current_path_.pop_back();
      } else {
	current_path_.push_back(pe_t);
	insert_current_path();
	std::cout << "true" << std::endl;
	current_path_.pop_back();
      }
      if (find_ite(e->arg(2))) {
        current_path_.push_back(pe_f);
        dfs(e->arg(2));
        current_path_.pop_back(); 
      } else {
	current_path_.push_back(pe_f);
	insert_current_path();
	std::cout << "false" << std::endl;
	current_path_.pop_back();
      }
    } else {
      for (int i = 0; i < e->arg_num(); i++)
	dfs(e->arg(i));
    }
  } 
  validate_path();
}

void PathEnumerator::insert_current_path() {
  if (current_path_.size() > 0)
    path_collector_.push_back(current_path_);
}

void PathEnumerator::validate_path() {
  for (auto path = path_collector_.begin(); path != path_collector_.end(); path++) {
    z3::context ctx;
    z3::solver slv(ctx);
    Z3ExprAdapter adpt(ctx); 
    for (auto cond = path->begin(); cond != path->end(); cond++) {
      auto z3_cond = adpt.GetExpr(cond->expr_ite->arg(0));
      auto ite_eval = cond->ite_eval;
      slv.add(z3::implies(z3_cond, ite_eval) && z3::implies(ite_eval, z3_cond));
    } 
    if (slv.check() == z3::unsat) {
      std::cout << "path_delete" << std::endl;
      path_collector_.erase(path); 
    }
  }
}

/*
void PathEnumerator::insert_current_path() {
  if (current_path_.size() == 0)
    return;
  bool current_path_can_insert = true;
  for (path_iter = path_collector_.begin(); path_iter != path_collector_.end(); path_iter++) {
    auto exist_path = *path_iter;
    if (exist_path.size() == current_path_.size()) {
      bool element_wise_equal = true;
      for (int i = 0; i < exist_path.size(); i++) {
	if ((exist_path[i].expr_ite->name() == current_path_[i].expr_ite->name()) && (exist_path[i].ite_eval == current_path_[i].ite_eval)) { 
	  continue;
	} else {
	  element_wise_equal = false;
	  break;
	}
      }
      if (element_wise_equal) {
	current_path_can_insert = false;
	break;
      }
    }
  }
  if (current_path_can_insert)
    path_collector_.insert(current_path_);
}
*/
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
