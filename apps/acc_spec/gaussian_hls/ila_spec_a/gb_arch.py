import ila

DATA_SIZE       = 8
COUNT_SIZE      = 19
X_EXTEND        = 9
Y_EXTEND        = 9
IMG_X_SIZE      = 488
IMG_Y_SIZE      = 648
COL_ADDR_SIZE   = 9
ROW_ADDR_SIZE   = 10
WR_ADDR_SIZE    = 3

class GBArch ():
    def __init__ (self):
        self.abst = ila.Abstraction ('SPEC_A')
        m = self.abst

        BV_TRUE     = m.const (0x1, 1)
        BV_FALSE    = m.const (0x0, 1)
        self.READY_TRUE  = READY_TRUE  = BV_TRUE
        self.READY_FALSE = READY_FALSE = BV_FALSE
        self.VALID_TRUE  = VALID_TRUE  = BV_TRUE
        self.VALID_FALSE = VALID_FALSE = BV_FALSE

        self.DATA_SIZE   = DATA_SIZE

        ######################## input ports ###################################
        self.arg_0_TREADY = m.inp ('arg_0_TREADY', 1)
        self.arg_1_TVALID = m.inp ('arg_1_TVALID', 1)
        self.arg_1_TDATA  = m.inp ('arg_1_TDATA', DATA_SIZE)
        
        ######################## output ports ##################################
        self.arg_1_TREADY = m.reg ('arg_1_TREADY', 1)
        self.arg_0_TVALID = m.reg ('arg_0_TVALID', 1)
        self.arg_0_TDATA  = m.reg ('arg_0_TDATA', DATA_SIZE)

        ######################## states  #######################################
        # most recent pixel
        self.cur_pix = m.reg ('cur_pix', DATA_SIZE)

        # 8 488x1 bytes buffer in the 2-D RAM
        self.RAM = []
        self.RAM_size = Y_EXTEND - 1
        for i in xrange (0, self.RAM_size):
            buffName = 'RAM_%d' % i
            self.RAM.append (m.mem (buffName, COL_ADDR_SIZE, DATA_SIZE))

        # x index (column) in the 2-D RAM
        self.RAM_x      = m.reg ('RAM_x', COL_ADDR_SIZE)
        self.RAM_x_0    = m.const (0x0, COL_ADDR_SIZE)
        self.RAM_x_1    = m.const (0x1, COL_ADDR_SIZE)
        self.RAM_x_M    = m.const (IMG_X_SIZE, COL_ADDR_SIZE)

        # y index (row) in the 2-D RAM
        self.RAM_y      = m.reg ('RAM_y', ROW_ADDR_SIZE)
        self.RAM_y_0    = m.const (0x0, ROW_ADDR_SIZE)
        self.RAM_y_1    = m.const (0x1, ROW_ADDR_SIZE)
        self.RAM_y_M    = m.const (IMG_Y_SIZE, ROW_ADDR_SIZE)

        # w index (write) in the 2-D RAM
        self.RAM_w      = m.reg ('RAM_w', WR_ADDR_SIZE)
        self.RAM_w_0    = m.const (0x0, WR_ADDR_SIZE)
        self.RAM_w_1    = m.const (0x1, WR_ADDR_SIZE)
        self.RAM_w_M    = m.const (self.RAM_size-1, WR_ADDR_SIZE)

        # 8 1x9 bytes slice in the stencil
        self.stencil = []
        self.slice_size = Y_EXTEND * DATA_SIZE
        self.stencil_size = X_EXTEND
        for i in xrange (0, self.stencil_size):
            buffName = 'stencil_%d' % i
            self.stencil.append (m.reg (buffName, self.slice_size))

        # holding iterator for gb
        self.gbit = m.reg ('gbit', 4)

        # uninterpreted GB function
        self.fun = m.fun ('gb_fun', DATA_SIZE, [X_EXTEND * Y_EXTEND * DATA_SIZE])

        ######################## next states functions #########################
        self.arg_1_TREADY_nxt = self.arg_1_TREADY
        self.arg_0_TVALID_nxt = self.arg_0_TVALID
        self.arg_0_TDATA_nxt  = self.arg_0_TDATA

        self.cur_pix_nxt = self.cur_pix
        self.RAM_x_nxt = self.RAM_x
        self.RAM_y_nxt = self.RAM_y
        self.RAM_w_nxt = self.RAM_w
        self.gbit_nxt = self.gbit
        self.RAM_nxt   = []
        for i in xrange (0, self.RAM_size):
            self.RAM_nxt.append (self.RAM[i])
        self.stencil_nxt = []
        for i in xrange (0, self.stencil_size):
            self.stencil_nxt.append (self.stencil[i])

    def setNext (self):
        m = self.abst

        m.set_next ('arg_1_TREADY', self.arg_1_TREADY_nxt)
        m.set_next ('arg_0_TVALID', self.arg_0_TVALID_nxt)
        m.set_next ('arg_0_TDATA', self.arg_0_TDATA_nxt)
        m.set_next ('cur_pix', self.cur_pix_nxt)
        m.set_next ('RAM_x', self.RAM_x_nxt)
        m.set_next ('RAM_y', self.RAM_y_nxt)
        m.set_next ('RAM_w', self.RAM_w_nxt)
        m.set_next ('gbit', self.gbit_nxt)

        for i in xrange (0, self.RAM_size):
            buffName = 'RAM_%d' % i
            m.set_next (buffName, self.RAM_nxt[i])

        for i in xrange (0, self.stencil_size):
            buffName = 'stencil_%d' % i
            m.set_next (buffName, self.stencil_nxt[i])

    def exportVerilog (self, fileName):
        self.abst.generateVerilog (fileName)
