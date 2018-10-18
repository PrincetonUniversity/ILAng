; ModuleID = 'hw.c'
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i686-pc-linux-gnu"

%struct.HW_REG_t = type { %union.STS_t, %union.DATA_t }
%union.STS_t = type { i32 }
%union.DATA_t = type { i32 }

@reg_HW = common global %struct.HW_REG_t zeroinitializer, align 4

; Function Attrs: nounwind
define void @wr_STS(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  %0 = load i32, i32* %val.addr, align 4
  store i32 %0, i32* getelementptr inbounds (%struct.HW_REG_t, %struct.HW_REG_t* @reg_HW, i32 0, i32 0, i32 0), align 4
  ret void
}

; Function Attrs: nounwind
define void @wr_STS_busy(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  %0 = load i32, i32* %val.addr, align 4
  %bf.load = load i32, i32* getelementptr inbounds (%struct.HW_REG_t, %struct.HW_REG_t* @reg_HW, i32 0, i32 0, i32 0), align 4
  %bf.value = and i32 %0, 1
  %bf.shl = shl i32 %bf.value, 30
  %bf.clear = and i32 %bf.load, -1073741825
  %bf.set = or i32 %bf.clear, %bf.shl
  store i32 %bf.set, i32* getelementptr inbounds (%struct.HW_REG_t, %struct.HW_REG_t* @reg_HW, i32 0, i32 0, i32 0), align 4
  ret void
}

; Function Attrs: nounwind
define void @wr_DATA(i32 %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  store i32 %val, i32* %val.addr, align 4
  %0 = load i32, i32* %val.addr, align 4
  store i32 %0, i32* getelementptr inbounds (%struct.HW_REG_t, %struct.HW_REG_t* @reg_HW, i32 0, i32 1, i32 0), align 4
  ret void
}

; Function Attrs: nounwind
define i32 @rd_STS() #0 {
entry:
  %0 = load i32, i32* getelementptr inbounds (%struct.HW_REG_t, %struct.HW_REG_t* @reg_HW, i32 0, i32 0, i32 0), align 4
  ret i32 %0
}

; Function Attrs: nounwind
define i32 @rd_STS_busy() #0 {
entry:
  %bf.load = load i32, i32* getelementptr inbounds (%struct.HW_REG_t, %struct.HW_REG_t* @reg_HW, i32 0, i32 0, i32 0), align 4
  %bf.lshr = lshr i32 %bf.load, 30
  %bf.clear = and i32 %bf.lshr, 1
  ret i32 %bf.clear
}

; Function Attrs: nounwind
define i32 @rd_DATA() #0 {
entry:
  %0 = load i32, i32* getelementptr inbounds (%struct.HW_REG_t, %struct.HW_REG_t* @reg_HW, i32 0, i32 1, i32 0), align 4
  ret i32 %0
}

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0 (tags/RELEASE_381/final)"}
