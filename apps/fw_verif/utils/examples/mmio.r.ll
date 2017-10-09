; ModuleID = 'mmio.c'
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i686-pc-linux-gnu"

%struct.HW_ITF_t = type { %struct.STS, %struct.DATA }
%struct.STS = type { i32, %struct.field }
%struct.field = type { i32, i32, i32 }
%struct.DATA = type { i32 }

@mmio_HW = external global %struct.HW_ITF_t*, align 4

; Function Attrs: nounwind
define void @foo() #0 {
entry:
  %counter = alloca i32, align 4
  store i32 0, i32* %counter, align 4
  br label %while.cond

while.cond:                                       ; preds = %if.end, %entry
  %0 = load %struct.HW_ITF_t*, %struct.HW_ITF_t** @mmio_HW, align 4
  %1 = call i32 bitcast (i32 (...)* @rd_STS_busy to i32 ()*)()
  %tobool = icmp ne i32 %1, 0
  br i1 %tobool, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %2 = load i32, i32* %counter, align 4
  %inc = add nsw i32 %2, 1
  store i32 %inc, i32* %counter, align 4
  %3 = load i32, i32* %counter, align 4
  %cmp = icmp sge i32 %3, 5
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %while.body
  %4 = load %struct.HW_ITF_t*, %struct.HW_ITF_t** @mmio_HW, align 4
  call void @wr_STS(i32 0)
  br label %if.end

if.else:                                          ; preds = %while.body
  %5 = load %struct.HW_ITF_t*, %struct.HW_ITF_t** @mmio_HW, align 4
  call void @wr_STS_busy(i32 1)
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %6 = load %struct.HW_ITF_t*, %struct.HW_ITF_t** @mmio_HW, align 4
  %7 = call i32 bitcast (i32 (...)* @rd_DATA to i32 ()*)()
  %cmp6 = icmp eq i32 %7, 1
  br i1 %cmp6, label %if.then7, label %if.else10

if.then7:                                         ; preds = %while.end
  %8 = load %struct.HW_ITF_t*, %struct.HW_ITF_t** @mmio_HW, align 4
  call void @wr_DATA(i32 0)
  br label %if.end13

if.else10:                                        ; preds = %while.end
  %9 = load %struct.HW_ITF_t*, %struct.HW_ITF_t** @mmio_HW, align 4
  call void @wr_DATA(i32 1)
  br label %if.end13

if.end13:                                         ; preds = %if.else10, %if.then7
  ret void
}

; Function Attrs: nounwind
define i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %x = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  call void @foo()
  store i32 0, i32* %x, align 4
  %call = call i32 bitcast (i32 (...)* @HW_REG_READ to i32 ()*)()
  store i32 %call, i32* %x, align 4
  %0 = load i32, i32* %x, align 4
  call void @HW_REG_WRITE(i32 %0)
  ret i32 0
}

declare i32 @HW_REG_READ(...) #1

declare void @HW_REG_WRITE(i32) #1

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }


!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0 (tags/RELEASE_381/final)"}
declare i32 @rd_DATA(...)
declare void @wr_DATA(i32) #4
declare void @wr_STS(i32) #4
declare void @wr_STS_busy(i32) #4
declare i32 @rd_STS_busy(...) #4
