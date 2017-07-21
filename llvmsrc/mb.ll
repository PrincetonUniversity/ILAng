; ModuleID = '/home/soc/workspace/fwVerif/demo/fwsrc/mb.c'
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i686-pc-linux-gnu"

%struct.MB_REG_t = type { %union.STS_t, %union.R_CMD_t, %union.R_DAT0_t, %union.R_DAT1_t, %union.R_SIZE_t, %union.S_CMD_t, %union.S_DAT0_t, %union.S_DAT1_t, %union.S_SIZE_t, %union.ACK_t }
%union.STS_t = type { i32 }
%union.R_CMD_t = type { i32 }
%union.R_DAT0_t = type { i32 }
%union.R_DAT1_t = type { i32 }
%union.R_SIZE_t = type { i32 }
%union.S_CMD_t = type { i32 }
%union.S_DAT0_t = type { i32 }
%union.S_DAT1_t = type { i32 }
%union.S_SIZE_t = type { i32 }
%union.ACK_t = type { i32 }

@hw_reg_MB = common global %struct.MB_REG_t zeroinitializer, align 4

; Function Attrs: nounwind
define void @write_reg_MB_STS(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  ret void
}

; Function Attrs: nounwind
define void @write_reg_MB_R_CMD(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  ret void
}

; Function Attrs: nounwind
define void @write_reg_MB_R_DAT0(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  ret void
}

; Function Attrs: nounwind
define void @write_reg_MB_R_DAT1(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  ret void
}

; Function Attrs: nounwind
define void @write_reg_MB_R_SIZE(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  ret void
}

; Function Attrs: nounwind
define void @write_reg_MB_S_CMD(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  %db = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  %bf.load = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 0, i32 0), align 4
  %bf.clear = and i32 %bf.load, 2147483647
  %bf.set = or i32 %bf.clear, -2147483648
  store i32 %bf.set, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 0, i32 0), align 4
  %0 = load i32, i32* %val.addr, align 4
  store i32 %0, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 5, i32 0), align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %call = call i32 bitcast (i32 (...)* @read_reg_msg_slv2mst_dbm to i32 ()*)()
  %tobool = icmp ne i32 %call, 0
  br i1 %tobool, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %1 = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 6, i32 0), align 4
  call void @write_reg_msg_slv2mst_dat0(i32 %1)
  %2 = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 7, i32 0), align 4
  call void @write_reg_msg_slv2mst_dat1(i32 %2)
  %3 = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 5, i32 0), align 4
  %shl = shl i32 %3, 9
  %4 = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 8, i32 0), align 4
  %shl1 = shl i32 %4, 1
  %or = or i32 %shl, %shl1
  %or2 = or i32 %or, 1
  store i32 %or2, i32* %db, align 4
  %5 = load i32, i32* %db, align 4
  call void @write_reg_msg_slv2mst_db(i32 %5)
  %bf.load3 = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 0, i32 0), align 4
  %bf.clear4 = and i32 %bf.load3, 2147483647
  store i32 %bf.clear4, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 0, i32 0), align 4
  ret void
}

declare i32 @read_reg_msg_slv2mst_dbm(...) #1

declare void @write_reg_msg_slv2mst_dat0(i32) #1

declare void @write_reg_msg_slv2mst_dat1(i32) #1

declare void @write_reg_msg_slv2mst_db(i32) #1

; Function Attrs: nounwind
define void @write_reg_MB_S_DAT0(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  %0 = load i32, i32* %val.addr, align 4
  store i32 %0, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 6, i32 0), align 4
  ret void
}

; Function Attrs: nounwind
define void @write_reg_MB_S_DAT1(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  %0 = load i32, i32* %val.addr, align 4
  store i32 %0, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 7, i32 0), align 4
  ret void
}

; Function Attrs: nounwind
define void @write_reg_MB_S_SIZE(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  %0 = load i32, i32* %val.addr, align 4
  store i32 %0, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 8, i32 0), align 4
  ret void
}

; Function Attrs: nounwind
define void @write_reg_MB_ACK(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  %db = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  %call = call i32 bitcast (i32 (...)* @read_reg_msg_mst2slv_db to i32 ()*)()
  store i32 %call, i32* %db, align 4
  %0 = load i32, i32* %db, align 4
  %shr = lshr i32 %0, 9
  store i32 %shr, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 1, i32 0), align 4
  %1 = load i32, i32* %db, align 4
  %shr1 = lshr i32 %1, 1
  %and = and i32 %shr1, 255
  store i32 %and, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 4, i32 0), align 4
  %call2 = call i32 bitcast (i32 (...)* @read_reg_msg_mst2slv_dat0 to i32 ()*)()
  store i32 %call2, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 2, i32 0), align 4
  %call3 = call i32 bitcast (i32 (...)* @read_reg_msg_mst2slv_dat1 to i32 ()*)()
  store i32 %call3, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 3, i32 0), align 4
  call void @write_reg_msg_mst2slv_db(i32 0)
  ret void
}

declare i32 @read_reg_msg_mst2slv_db(...) #1

declare i32 @read_reg_msg_mst2slv_dat0(...) #1

declare i32 @read_reg_msg_mst2slv_dat1(...) #1

declare void @write_reg_msg_mst2slv_db(i32) #1

; Function Attrs: nounwind
define void @write_reg_MB_STS_busy(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  ret void
}

; Function Attrs: nounwind
define i32 @read_reg_MB_STS() #0 {
entry:
  %0 = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 0, i32 0), align 4
  ret i32 %0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_R_CMD() #0 {
entry:
  %0 = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 1, i32 0), align 4
  ret i32 %0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_R_DAT0() #0 {
entry:
  %0 = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 2, i32 0), align 4
  ret i32 %0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_R_DAT1() #0 {
entry:
  %0 = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 3, i32 0), align 4
  ret i32 %0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_R_SIZE() #0 {
entry:
  %0 = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 4, i32 0), align 4
  ret i32 %0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_S_CMD() #0 {
entry:
  %0 = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 5, i32 0), align 4
  ret i32 %0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_S_DAT0() #0 {
entry:
  %0 = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 6, i32 0), align 4
  ret i32 %0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_S_DAT1() #0 {
entry:
  %0 = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 7, i32 0), align 4
  ret i32 %0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_S_SIZE() #0 {
entry:
  %0 = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 8, i32 0), align 4
  ret i32 %0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_ACK() #0 {
entry:
  ret i32 0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_STS_busy() #0 {
entry:
  %bf.load = load i32, i32* getelementptr inbounds (%struct.MB_REG_t, %struct.MB_REG_t* @hw_reg_MB, i32 0, i32 0, i32 0), align 4
  %bf.lshr = lshr i32 %bf.load, 31
  ret i32 %bf.lshr
}

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0 (tags/RELEASE_381/final)"}
