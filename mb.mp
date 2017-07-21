// File: mb.mp
// Synopsis: mapping for message buffer (MB) MMIO and ILA

_Type MB_ITF_t
_Name reg_MB

_MapWr write_reg_MB_STS STS -1
_MapWr write_reg_MB_R_CMD R_CMD -1
_MapWr write_reg_MB_R_DAT0 R_DAT0 -1
_MapWr write_reg_MB_R_DAT1 R_DAT1 -1
_MapWr write_reg_MB_R_SIZE R_SIZE -1
_MapWr write_reg_MB_S_CMD S_CMD -1
_MapWr write_reg_MB_S_DAT0 S_DAT0 -1
_MapWr write_reg_MB_S_DAT1 S_DAT1 -1
_MapWr write_reg_MB_S_SIZE S_SIZE -1
_MapWr write_reg_MB_ACK ACK -1

_MapRd read_reg_MB_STS STS -1
_MapRd read_reg_MB_R_CMD R_CMD -1
_MapRd read_reg_MB_R_DAT0 R_DAT0 -1
_MapRd read_reg_MB_R_DAT1 R_DAT1 -1
_MapRd read_reg_MB_R_SIZE R_SIZE -1
_MapRd read_reg_MB_S_CMD S_CMD -1
_MapRd read_reg_MB_S_DAT0 S_DAT0 -1
_MapRd read_reg_MB_S_DAT1 S_DAT1 -1
_MapRd read_reg_MB_S_SIZE S_SIZE -1
_MapRd read_reg_MB_ACK ACK -1

_MapWr write_reg_MB_STS_busy STS 1
_MapRd read_reg_MB_STS_busy STS 1

