
#define DATA_WIDTH 8
#define FIFO_SIZE 16
#define FIFO_IDX_WIDTH 4

Ila fifo_no_protect(const std::string& fifo_name) {
  Ila m(fifo_name);

  auto w_en_in    = m.NewBoolInput("w_en_in");
  auto r_en_in    = m.NewBoolInput("r_en_in");
  auto w_data_in  = m.NewBvInput  ("w_data_in" , DATA_WIDTH);
  auto r_data_out = m.NewBvState  ("r_data_out", DATA_WIDTH);

  auto rptr    = m.NewBvState("rptr", FIFO_IDX_WIDTH + 1);
  auto wptr    = m.NewBvState("wptr", FIFO_IDX_WIDTH + 1);
  auto storage = m.NewMemState("storage", FIFO_IDX_WIDTH , DATA_WIDTH);

  m.AddInit(rptr == 0);
  m.AddInit(wptr == 0);

  {
    auto instr = m.NewInstr("Enqueue");

    instr.SetDecode( w_en_in );
    instr.SetUpdate( storage, Store(storage, wptr(FIFO_IDX_WIDTH-1,0), w_data_in) );
    instr.SetUpdate( wptr, wptr + 1 );
  }
  {
    auto instr = m.NewInstr("Dequeue");

    instr.SetDecode( r_en_in );
    instr.SetUpdate( r_data_out, Load(storage, rptr(FIFO_IDX_WIDTH-1,0) ) );
    instr.SetUpdate( rptr, rptr + 1 );
  }

  return m;

}



Ila fifo_w_protect(const std::string& fifo_name) {
  Ila m(fifo_name);

  auto w_en_in    = m.NewBoolInput("w_en_in");
  auto r_en_in    = m.NewBoolInput("r_en_in");
  auto w_data_in  = m.NewBvInput  ("w_data_in" , DATA_WIDTH);
  auto r_data_out = m.NewBvState  ("r_data_out", DATA_WIDTH);

  auto rptr    = m.NewBvState("rptr", FIFO_IDX_WIDTH + 1 );
  auto wptr    = m.NewBvState("wptr", FIFO_IDX_WIDTH + 1);
  auto storage = m.NewMemState("storage", FIFO_IDX_WIDTH , DATA_WIDTH);
  auto count   = m.NewBvState("count", FIFO_IDX_WIDTH + 1);

  m.AddInit(rptr == 0);
  m.AddInit(wptr == 0);
  m.AddInit(count == 0);

  {
    auto instr = m.NewInstr("Enqueue");

    instr.SetDecode( w_en_in & (count < FIFO_SIZE) );
    instr.SetUpdate( storage, Store(storage, wptr(FIFO_IDX_WIDTH-1,0), w_data_in) );
    instr.SetUpdate( wptr, wptr + 1 );
    instr.SetUpdate( count, count + 1);
  }
  {
    auto instr = m.NewInstr("Dequeue");

    instr.SetDecode( r_en_in & (count != 0) );
    instr.SetUpdate( r_data_out, Load(storage, rptr(FIFO_IDX_WIDTH-1,0) ) );
    instr.SetUpdate( rptr, rptr + 1 );
    instr.SetUpdate( count, count - 1);
  }
  return m;
}


