; ModuleID = 'examples/mmio.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.HW_ITF_t = type { %union.STS_t, %union.DATA_t }
%union.STS_t = type { %struct.field_t }
%struct.field_t = type { i32 }
%union.DATA_t = type { i32 }

@mmio_HW = common global %struct.HW_ITF_t* null, align 8
@reg_HW = common global %struct.HW_ITF_t zeroinitializer, align 4

; Function Attrs: nounwind uwtable
define void @foo() #0 {
entry:
  %counter = alloca i32, align 4
  store i32 0, i32* %counter, align 4
  br label %while.cond

while.cond:                                       ; preds = %if.end, %entry
  %0 = load %struct.HW_ITF_t*, %struct.HW_ITF_t** @mmio_HW, align 8
  %STS = getelementptr inbounds %struct.HW_ITF_t, %struct.HW_ITF_t* %0, i32 0, i32 0
  %field = bitcast %union.STS_t* %STS to %struct.field_t*
  %1 = bitcast %struct.field_t* %field to i32*
  %bf.load = load i32, i32* %1, align 4
  %bf.lshr = lshr i32 %bf.load, 31
  %tobool = icmp ne i32 %bf.lshr, 0
  br i1 %tobool, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %2 = load i32, i32* %counter, align 4
  %inc = add nsw i32 %2, 1
  store i32 %inc, i32* %counter, align 4
  %3 = load i32, i32* %counter, align 4
  %cmp = icmp sge i32 %3, 5
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %while.body
  %4 = load %struct.HW_ITF_t*, %struct.HW_ITF_t** @mmio_HW, align 8
  %STS1 = getelementptr inbounds %struct.HW_ITF_t, %struct.HW_ITF_t* %4, i32 0, i32 0
  %val = bitcast %union.STS_t* %STS1 to i32*
  store i32 0, i32* %val, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %while.body
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %5 = load %struct.HW_ITF_t*, %struct.HW_ITF_t** @mmio_HW, align 8
  %DATA = getelementptr inbounds %struct.HW_ITF_t, %struct.HW_ITF_t* %5, i32 0, i32 1
  %val2 = bitcast %union.DATA_t* %DATA to i32*
  %6 = load i32, i32* %val2, align 4
  %cmp3 = icmp eq i32 %6, 1
  br i1 %cmp3, label %if.then4, label %if.else

if.then4:                                         ; preds = %while.end
  %7 = load %struct.HW_ITF_t*, %struct.HW_ITF_t** @mmio_HW, align 8
  %DATA5 = getelementptr inbounds %struct.HW_ITF_t, %struct.HW_ITF_t* %7, i32 0, i32 1
  %val6 = bitcast %union.DATA_t* %DATA5 to i32*
  store i32 0, i32* %val6, align 4
  br label %if.end9

if.else:                                          ; preds = %while.end
  %8 = load %struct.HW_ITF_t*, %struct.HW_ITF_t** @mmio_HW, align 8
  %DATA7 = getelementptr inbounds %struct.HW_ITF_t, %struct.HW_ITF_t* %8, i32 0, i32 1
  %val8 = bitcast %union.DATA_t* %DATA7 to i32*
  store i32 1, i32* %val8, align 4
  br label %if.end9

if.end9:                                          ; preds = %if.else, %if.then4
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  call void @foo()
  ret i32 0
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0 (tags/RELEASE_381/final)"}
