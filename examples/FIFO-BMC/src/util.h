
bool CheckOverUnderFlow(Ila fifo, int step) {

  bool underflowOroverflow = false;
  z3::context ctx;
  z3::solver s(ctx);
  IlaZ3Unroller un = (ctx);

  // add ILA initial condition to the unroller
  for (size_t i = 0; i != fifo.init_num(); i++) {
    un.AddInitPred(fifo.init(i));
  }

  // unrolling
  auto trans_rel = un.UnrollMonoConn(fifo, step);

  auto wptr = fifo.state("wptr");
  auto rptr = fifo.state("rptr");
  
  // derive full/empty conditions
  auto fifo_full = 
    ( wptr(FIFO_IDX_WIDTH-1,0) == rptr(FIFO_IDX_WIDTH-1,0) ) &
    ( wptr(FIFO_IDX_WIDTH    ) != rptr(FIFO_IDX_WIDTH)     );

  auto fifo_empty = wptr == rptr;

  // full -> full and wptr increase
  auto prev_full = un.GetZ3Expr(fifo_full,0);
  auto prev_wptr = un.GetZ3Expr(wptr, 0);

  s.add(trans_rel);
  for (int idx = 1; idx < step; idx ++ ) {
    auto this_full = un.GetZ3Expr(fifo_full, idx);
    auto this_wptr = un.GetZ3Expr(wptr, idx);
    auto constr = prev_full && ( prev_wptr + 1 ==  this_wptr );
    s.push();
    s.add(constr);

    prev_full = this_full;
    prev_wptr = this_wptr;

    if ( s.check() == z3::sat ) {
      std::cout << "Check failed: ";
      std::cout << fifo.name() << " can overflow at step " << idx << std::endl;
      
      std::ofstream ftrace("overflow.trace");
      ftrace << s.get_model();
      std::cout << "Trace saved at overflow.trace." << std::endl;
      underflowOroverflow = true;
      break;
    }
    s.pop();
  }

  s.reset();

  auto prev_empty = un.GetZ3Expr(fifo_empty,0);
  auto prev_rptr = un.GetZ3Expr(rptr, 0);

  s.add(trans_rel);
  for (int idx = 1; idx < step; idx ++ ) {
    auto this_empty = un.GetZ3Expr(fifo_empty, idx);
    auto this_rptr = un.GetZ3Expr(rptr, idx);
    auto constr = prev_empty && ( prev_rptr + 1 ==  this_rptr );
    s.push();
    s.add(constr);

    prev_empty = this_empty;
    prev_rptr  = this_rptr;

    if ( s.check() == z3::sat ) {
      std::cout << "Check failed: ";
      std::cout << fifo.name() << " can underflow at step " << idx << std::endl;


      std::ofstream ftrace("underflow.trace");
      ftrace << s.get_model();
      std::cout << "Trace saved at underflow.trace." << std::endl;

      underflowOroverflow = true;
      break;
    }
    s.pop();
  }

  return !underflowOroverflow;

}

