// mapping for mmio example

_Type HW_ITF_t
_Name mmio_HW

_MapWr wr_STS STS -1 
_MapRd rd_STS STS -1
_MapWr wr_STS_busy STS 1
_MapRd rd_STS_busy STS 1
_MapWr wr_DATA DATA -1
_MapRd rd_DATA DATA -1

