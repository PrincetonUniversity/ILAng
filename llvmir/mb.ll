; ModuleID = 'mb.c'
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i686-pc-linux-gnu"

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
  store i32 %val, i32* %val.addr, align 4
  ret void
}

; Function Attrs: nounwind
define void @write_reg_MB_S_DAT0(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  ret void
}

; Function Attrs: nounwind
define void @write_reg_MB_S_DAT1(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  ret void
}

; Function Attrs: nounwind
define void @write_reg_MB_S_SIZE(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  ret void
}

; Function Attrs: nounwind
define i32 @read_reg_MB_STS() #0 {
entry:
  ret i32 0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_R_CMD() #0 {
entry:
  ret i32 0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_R_DAT0() #0 {
entry:
  ret i32 0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_R_DAT1() #0 {
entry:
  ret i32 0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_R_SIZE() #0 {
entry:
  ret i32 0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_S_CMD() #0 {
entry:
  ret i32 0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_S_DAT0() #0 {
entry:
  ret i32 0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_S_DAT1() #0 {
entry:
  ret i32 0
}

; Function Attrs: nounwind
define i32 @read_reg_MB_S_SIZE() #0 {
entry:
  ret i32 0
}

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0 (tags/RELEASE_381/final)"}
