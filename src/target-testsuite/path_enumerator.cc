#include <ilang/target-testsuite/path_enumerator.h>
#include <ilang/ila/instr_lvl_abs.h>

namespace ilang{

PathEnumerator::PathEnumerator() {}

void PathEnumerator::dfs(std::vector<std::vector<PathElement>>& pc, std::vector<PathElement>& path, const ExprPtr& e) {
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
	if (path.size() > 0)
	  pc.push_back(path);
	std::cout << "true" << std::endl;
	path.pop_back();
      }
      if (find_ite(e->arg(2))) {
        path.push_back(pe_f);
        dfs(pc, path, e->arg(2));
        path.pop_back(); 
      } else {
	path.push_back(pe_f);
	if (path.size() > 0)
	  pc.push_back(path);
	std::cout << "false" << std::endl;
	path.pop_back();
      }
    } else {
      if(e->arg_num() == 0)
	return; 
      std::vector<std::vector<PathElement>>* pc_list = new std::vector<std::vector<PathElement>>[e->arg_num()];
      for (int i = 0; i < e->arg_num(); i++) {
	std::vector<PathElement> new_path;
	if (find_ite(e->arg(i)))	
	  dfs(pc_list[i], new_path, e->arg(i));
      }
      std::vector<std::vector<PathElement>> new_pc = pc_list[0];
      for (int i = 1; i < e->arg_num(); i++) {
	new_pc = cross_product(new_pc, pc_list[i]);
      }
      std::cout << "pc size:" << pc.size() << std::endl;
      std::cout << "new pc size:" << new_pc.size() << std::endl;
      for (auto new_path = new_pc.begin(); new_path != new_pc.end(); new_path++) {
	auto tmp_path = path;
	tmp_path.insert(tmp_path.end(), new_path->begin(), new_path->end());
	pc.push_back(tmp_path);
      } 
    }
  } 
  validate_path(pc);
}

void PathEnumerator::insert_current_path() {
  if (current_path_.size() > 0)
    path_collector_.push_back(current_path_);
}

void PathEnumerator::validate_path(std::vector<std::vector<PathElement>>& pc) {
  for (auto path = pc.begin(); path != pc.end(); path++) {
    z3::context ctx;
    z3::solver slv(ctx);
    Z3ExprAdapter adpt(ctx); 
    for (auto cond = path->begin(); cond != path->end(); cond++) {
      auto z3_cond = adpt.GetExpr(cond->expr_ite->arg(0));
      auto ite_eval = cond->ite_eval;
      slv.add(z3::implies(z3_cond, ite_eval) && z3::implies(ite_eval, z3_cond));
      std::cout << z3_cond << "  " << cond->ite_eval << std::endl;
    } 
    std::cout << std::endl;
    if (slv.check() == z3::unsat) {
      std::cout << "path_delete" << std::endl;
      pc.erase(path); 
      path--;
    }
  }
  std::cout << "deleted size" << pc.size() << std::endl;
}

void PathEnumerator::cross_product(PathEnumerator& pe) {
  auto pc_a = path_collector_;
  auto pc_b = pe.path_collector_;
  std::cout << "path_a len: " << pc_a.size() << std::endl;
  std::cout << "path_b len: " << pc_b.size() << std::endl;
  if (pc_a.size() == 0) {
    path_collector_ = pe.path_collector_;
    return;
  } else if (pc_b.size() == 0) {
    return;
  } else {
    path_collector_.clear();
    for (auto path_a = pc_a.begin(); path_a != pc_a.end(); path_a++) {
      for (auto path_b = pc_b.begin(); path_b != pc_b.end(); path_b++) {
        auto new_path = *path_a;
        new_path.insert(new_path.end(), path_b->begin(), path_b->end());
        path_collector_.push_back(new_path);
      }
    }
    validate_path(path_collector_);
  }
}

std::vector<std::vector<PathElement>> PathEnumerator::cross_product(std::vector<std::vector<PathElement>>& pc_a, std::vector<std::vector<PathElement>>& pc_b) {
  if (pc_a.size() == 0) {
    return pc_b;
  } else if (pc_b.size() == 0) {
    return pc_a;
  } else {
    std::vector<std::vector<PathElement>> new_pc;
    for (auto path_a = pc_a.begin(); path_a != pc_a.end(); path_a++) {
      for (auto path_b = pc_b.begin(); path_b != pc_b.end(); path_b++) {
        auto new_path = *path_a;
        new_path.insert(new_path.end(), path_b->begin(), path_b->end());
        new_pc.push_back(new_path);
      } 
    }
    validate_path(new_pc);
    return new_pc;
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
