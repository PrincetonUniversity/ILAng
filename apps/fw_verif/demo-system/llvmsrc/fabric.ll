; ModuleID = '/home/byhuang/workspace/ILA/apps/fw_verif/demo-system/fwsrc/fabric.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.pthread_mutex_t = type { i32, i32, %struct.pthread_mutexattr_t }
%struct.pthread_mutexattr_t = type { i32, i32, i32, i32 }

@fab_lock = external global %struct.pthread_mutex_t, align 4
@reg_slv_int = external global i32, align 4
@reg_msg_mst2slv_db = common global i32 0, align 4
@reg_msg_mst2slv_dbm = common global i32 0, align 4
@reg_msg_mst2slv_dat0 = common global i32 0, align 4
@reg_msg_mst2slv_dat1 = common global i32 0, align 4
@reg_msg_slv2mst_db = common global i32 0, align 4
@reg_msg_slv2mst_dbm = common global i32 0, align 4
@reg_msg_slv2mst_dat0 = common global i32 0, align 4
@reg_msg_slv2mst_dat1 = common global i32 0, align 4

; Function Attrs: nounwind uwtable
define void @FAB_REG_LOCK() #0 {
entry:
  %call = call i32 @pthread_mutex_lock(%struct.pthread_mutex_t* @fab_lock)
  ret void
}

declare i32 @pthread_mutex_lock(%struct.pthread_mutex_t*) #1

; Function Attrs: nounwind uwtable
define void @FAB_REG_UNLOCK() #0 {
entry:
  %call = call i32 @pthread_mutex_unlock(%struct.pthread_mutex_t* @fab_lock)
  ret void
}

declare i32 @pthread_mutex_unlock(%struct.pthread_mutex_t*) #1

; Function Attrs: nounwind uwtable
define void @HW_REG_WRITE(i32 %addr, i32 %val) #0 {
entry:
  %addr.addr = alloca i32, align 4
  %val.addr = alloca i32, align 4
  store i32 %addr, i32* %addr.addr, align 4
  store i32 %val, i32* %val.addr, align 4
  call void @FAB_REG_LOCK()
  %0 = load i32, i32* %addr.addr, align 4
  switch i32 %0, label %sw.default [
    i32 -65536, label %sw.bb
    i32 -65535, label %sw.bb1
    i32 -65534, label %sw.bb2
    i32 -65533, label %sw.bb3
    i32 -65532, label %sw.bb4
    i32 -65531, label %sw.bb5
    i32 -65530, label %sw.bb6
    i32 -65529, label %sw.bb7
  ]

sw.bb:                                            ; preds = %entry
  %1 = load i32, i32* %val.addr, align 4
  call void @write_reg_msg_slv2mst_dbm(i32 %1)
  br label %sw.epilog

sw.bb1:                                           ; preds = %entry
  %2 = load i32, i32* %val.addr, align 4
  call void @write_reg_msg_mst2slv_db(i32 %2)
  br label %sw.epilog

sw.bb2:                                           ; preds = %entry
  %3 = load i32, i32* %val.addr, align 4
  call void @write_reg_msg_mst2slv_dat0(i32 %3)
  br label %sw.epilog

sw.bb3:                                           ; preds = %entry
  %4 = load i32, i32* %val.addr, align 4
  call void @write_reg_msg_mst2slv_dat1(i32 %4)
  br label %sw.epilog

sw.bb4:                                           ; preds = %entry
  %5 = load i32, i32* %val.addr, align 4
  call void @write_reg_msg_mst2slv_dbm(i32 %5)
  br label %sw.epilog

sw.bb5:                                           ; preds = %entry
  %6 = load i32, i32* %val.addr, align 4
  call void @write_reg_msg_slv2mst_db(i32 %6)
  br label %sw.epilog

sw.bb6:                                           ; preds = %entry
  %7 = load i32, i32* %val.addr, align 4
  call void @write_reg_msg_slv2mst_dat0(i32 %7)
  br label %sw.epilog

sw.bb7:                                           ; preds = %entry
  %8 = load i32, i32* %val.addr, align 4
  call void @write_reg_msg_slv2mst_dat1(i32 %8)
  br label %sw.epilog

sw.default:                                       ; preds = %entry
  call void @__VERIFIER_assert(i32 0)
  br label %sw.epilog

sw.epilog:                                        ; preds = %sw.default, %sw.bb7, %sw.bb6, %sw.bb5, %sw.bb4, %sw.bb3, %sw.bb2, %sw.bb1, %sw.bb
  call void @FAB_REG_UNLOCK()
  ret void
}

; Function Attrs: nounwind uwtable
define void @write_reg_msg_slv2mst_dbm(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define void @write_reg_msg_mst2slv_db(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  %0 = load i32, i32* %val.addr, align 4
  %cmp = icmp ne i32 %0, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  br label %while.cond

while.cond:                                       ; preds = %while.body, %if.then
  %1 = load i32, i32* @reg_slv_int, align 4
  %tobool = icmp ne i32 %1, 0
  br i1 %tobool, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  br label %while.cond

while.end:                                        ; preds = %while.cond
  br label %if.end

if.end:                                           ; preds = %while.end, %entry
  %2 = load i32, i32* %val.addr, align 4
  store i32 %2, i32* @reg_msg_mst2slv_db, align 4
  %3 = load i32, i32* %val.addr, align 4
  store i32 %3, i32* @reg_msg_mst2slv_dbm, align 4
  store i32 1, i32* @reg_slv_int, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define void @write_reg_msg_mst2slv_dat0(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  %0 = load i32, i32* %val.addr, align 4
  store i32 %0, i32* @reg_msg_mst2slv_dat0, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define void @write_reg_msg_mst2slv_dat1(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  %0 = load i32, i32* %val.addr, align 4
  store i32 %0, i32* @reg_msg_mst2slv_dat1, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define void @write_reg_msg_mst2slv_dbm(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define void @write_reg_msg_slv2mst_db(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  %0 = load i32, i32* %val.addr, align 4
  store i32 %0, i32* @reg_msg_slv2mst_db, align 4
  %1 = load i32, i32* %val.addr, align 4
  store i32 %1, i32* @reg_msg_slv2mst_dbm, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define void @write_reg_msg_slv2mst_dat0(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  %0 = load i32, i32* %val.addr, align 4
  store i32 %0, i32* @reg_msg_slv2mst_dat0, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define void @write_reg_msg_slv2mst_dat1(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  %0 = load i32, i32* %val.addr, align 4
  store i32 %0, i32* @reg_msg_slv2mst_dat1, align 4
  ret void
}

declare void @__VERIFIER_assert(i32) #1

; Function Attrs: nounwind uwtable
define i32 @HW_REG_READ(i32 %addr) #0 {
entry:
  %addr.addr = alloca i32, align 4
  %res = alloca i32, align 4
  store i32 %addr, i32* %addr.addr, align 4
  call void @FAB_REG_LOCK()
  store i32 0, i32* %res, align 4
  %0 = load i32, i32* %addr.addr, align 4
  switch i32 %0, label %sw.default [
    i32 -65536, label %sw.bb
    i32 -65535, label %sw.bb1
    i32 -65534, label %sw.bb3
    i32 -65533, label %sw.bb5
    i32 -65532, label %sw.bb7
    i32 -65531, label %sw.bb9
    i32 -65530, label %sw.bb11
    i32 -65529, label %sw.bb13
  ]

sw.bb:                                            ; preds = %entry
  %call = call i32 @read_reg_msg_slv2mst_dbm()
  store i32 %call, i32* %res, align 4
  br label %sw.epilog

sw.bb1:                                           ; preds = %entry
  %call2 = call i32 @read_reg_msg_mst2slv_db()
  store i32 %call2, i32* %res, align 4
  br label %sw.epilog

sw.bb3:                                           ; preds = %entry
  %call4 = call i32 @read_reg_msg_mst2slv_dat0()
  store i32 %call4, i32* %res, align 4
  br label %sw.epilog

sw.bb5:                                           ; preds = %entry
  %call6 = call i32 @read_reg_msg_mst2slv_dat1()
  store i32 %call6, i32* %res, align 4
  br label %sw.epilog

sw.bb7:                                           ; preds = %entry
  %call8 = call i32 @read_reg_msg_mst2slv_dbm()
  store i32 %call8, i32* %res, align 4
  br label %sw.epilog

sw.bb9:                                           ; preds = %entry
  %call10 = call i32 @read_reg_msg_slv2mst_db()
  store i32 %call10, i32* %res, align 4
  br label %sw.epilog

sw.bb11:                                          ; preds = %entry
  %call12 = call i32 @read_reg_msg_slv2mst_dat0()
  store i32 %call12, i32* %res, align 4
  br label %sw.epilog

sw.bb13:                                          ; preds = %entry
  %call14 = call i32 @read_reg_msg_slv2mst_dat1()
  store i32 %call14, i32* %res, align 4
  br label %sw.epilog

sw.default:                                       ; preds = %entry
  call void @__VERIFIER_assert(i32 0)
  br label %sw.epilog

sw.epilog:                                        ; preds = %sw.default, %sw.bb13, %sw.bb11, %sw.bb9, %sw.bb7, %sw.bb5, %sw.bb3, %sw.bb1, %sw.bb
  call void @FAB_REG_UNLOCK()
  %1 = load i32, i32* %res, align 4
  ret i32 %1
}

; Function Attrs: nounwind uwtable
define i32 @read_reg_msg_mst2slv_db() #0 {
entry:
  %0 = load i32, i32* @reg_msg_mst2slv_db, align 4
  ret i32 %0
}

; Function Attrs: nounwind uwtable
define i32 @read_reg_msg_mst2slv_dbm() #0 {
entry:
  %0 = load i32, i32* @reg_msg_mst2slv_dbm, align 4
  ret i32 %0
}

; Function Attrs: nounwind uwtable
define i32 @read_reg_msg_mst2slv_dat0() #0 {
entry:
  %0 = load i32, i32* @reg_msg_mst2slv_dat0, align 4
  ret i32 %0
}

; Function Attrs: nounwind uwtable
define i32 @read_reg_msg_mst2slv_dat1() #0 {
entry:
  %0 = load i32, i32* @reg_msg_mst2slv_dat1, align 4
  ret i32 %0
}

; Function Attrs: nounwind uwtable
define i32 @read_reg_msg_slv2mst_db() #0 {
entry:
  %0 = load i32, i32* @reg_msg_slv2mst_db, align 4
  ret i32 %0
}

; Function Attrs: nounwind uwtable
define i32 @read_reg_msg_slv2mst_dbm() #0 {
entry:
  %0 = load i32, i32* @reg_msg_slv2mst_dbm, align 4
  ret i32 %0
}

; Function Attrs: nounwind uwtable
define i32 @read_reg_msg_slv2mst_dat0() #0 {
entry:
  %0 = load i32, i32* @reg_msg_slv2mst_dat0, align 4
  ret i32 %0
}

; Function Attrs: nounwind uwtable
define i32 @read_reg_msg_slv2mst_dat1() #0 {
entry:
  %0 = load i32, i32* @reg_msg_slv2mst_dat1, align 4
  ret i32 %0
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0 (tags/RELEASE_381/final)"}
