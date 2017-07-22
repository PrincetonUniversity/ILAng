; ModuleID = '/home/soc/workspace/fwVerif/demo/fwsrc/slv.c'
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i686-pc-linux-gnu"

%struct.MB_ITF_t = type { %struct.STS, %struct.R_CMD, %struct.R_DAT0, %struct.R_DAT1, %struct.R_SIZE, %struct.S_CMD, %struct.S_DAT0, %struct.S_DAT1, %struct.S_SIZE, %struct.ACK }
%struct.STS = type { i32, %struct.field }
%struct.field = type { i32, i32 }
%struct.R_CMD = type { i32 }
%struct.R_DAT0 = type { i32 }
%struct.R_DAT1 = type { i32 }
%struct.R_SIZE = type { i32 }
%struct.S_CMD = type { i32 }
%struct.S_DAT0 = type { i32 }
%struct.S_DAT1 = type { i32 }
%struct.S_SIZE = type { i32 }
%struct.ACK = type { i32 }

@gSlvFlag = global [2 x i32] zeroinitializer, align 4
@gMbCtx = global [8 x i32] zeroinitializer, align 4
@mst_sram = external global [0 x i8], align 1
@reg_MB = external global %struct.MB_ITF_t*, align 4
@reg_slv_int = external global i32, align 4

; Function Attrs: nounwind
define void @mainSlv() #0 {
entry:
  %slvBuff = alloca i8*, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %0 = load i32, i32* getelementptr inbounds ([2 x i32], [2 x i32]* @gSlvFlag, i32 0, i32 0), align 4
  %tobool = icmp ne i32 %0, 0
  %lnot = xor i1 %tobool, true
  br i1 %lnot, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %1 = load i32, i32* getelementptr inbounds ([2 x i32], [2 x i32]* @gSlvFlag, i32 0, i32 1), align 4
  %call = call noalias i8* @malloc(i32 %1) #3
  store i8* %call, i8** %slvBuff, align 4
  %2 = load i8*, i8** %slvBuff, align 4
  %3 = load i32, i32* getelementptr inbounds ([2 x i32], [2 x i32]* @gSlvFlag, i32 0, i32 1), align 4
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* %2, i8* getelementptr inbounds ([0 x i8], [0 x i8]* @mst_sram, i32 0, i32 0), i32 %3, i32 1, i1 false)
  %4 = load i32, i32* getelementptr inbounds ([2 x i32], [2 x i32]* @gSlvFlag, i32 0, i32 1), align 4
  %cmp = icmp ule i32 %4, 32
  %conv = zext i1 %cmp to i32
  call void @__VERIFIER_assert(i32 %conv)
  store i32 4, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 0), align 4
  store i32 0, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 3), align 4
  call void @sendMsgSlv2Mst()
  %5 = load i8*, i8** %slvBuff, align 4
  call void @free(i8* %5) #3
  ret void
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i32) #0

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i32(i8* nocapture, i8* nocapture readonly, i32, i32, i1) #1

declare void @__VERIFIER_assert(i32) #2

; Function Attrs: nounwind
declare void @free(i8*) #0

; Function Attrs: nounwind
define void @sendMsgSlv2Mst() #0 {
entry:
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %0 = load %struct.MB_ITF_t*, %struct.MB_ITF_t** @reg_MB, align 4
  %STS = getelementptr inbounds %struct.MB_ITF_t, %struct.MB_ITF_t* %0, i32 0, i32 0
  %field = getelementptr inbounds %struct.STS, %struct.STS* %STS, i32 0, i32 1
  %busy = getelementptr inbounds %struct.field, %struct.field* %field, i32 0, i32 1
  %1 = load i32, i32* %busy, align 4
  %tobool = icmp ne i32 %1, 0
  br i1 %tobool, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %2 = load i32, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 1), align 4
  %3 = load %struct.MB_ITF_t*, %struct.MB_ITF_t** @reg_MB, align 4
  %S_DAT0 = getelementptr inbounds %struct.MB_ITF_t, %struct.MB_ITF_t* %3, i32 0, i32 6
  %val = getelementptr inbounds %struct.S_DAT0, %struct.S_DAT0* %S_DAT0, i32 0, i32 0
  store i32 %2, i32* %val, align 4
  %4 = load i32, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 2), align 4
  %5 = load %struct.MB_ITF_t*, %struct.MB_ITF_t** @reg_MB, align 4
  %S_DAT1 = getelementptr inbounds %struct.MB_ITF_t, %struct.MB_ITF_t* %5, i32 0, i32 7
  %val1 = getelementptr inbounds %struct.S_DAT1, %struct.S_DAT1* %S_DAT1, i32 0, i32 0
  store i32 %4, i32* %val1, align 4
  %6 = load i32, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 3), align 4
  %7 = load %struct.MB_ITF_t*, %struct.MB_ITF_t** @reg_MB, align 4
  %S_SIZE = getelementptr inbounds %struct.MB_ITF_t, %struct.MB_ITF_t* %7, i32 0, i32 8
  %val2 = getelementptr inbounds %struct.S_SIZE, %struct.S_SIZE* %S_SIZE, i32 0, i32 0
  store i32 %6, i32* %val2, align 4
  %8 = load i32, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 0), align 4
  %9 = load %struct.MB_ITF_t*, %struct.MB_ITF_t** @reg_MB, align 4
  %S_CMD = getelementptr inbounds %struct.MB_ITF_t, %struct.MB_ITF_t* %9, i32 0, i32 5
  %val3 = getelementptr inbounds %struct.S_CMD, %struct.S_CMD* %S_CMD, i32 0, i32 0
  store i32 %8, i32* %val3, align 4
  ret void
}

; Function Attrs: nounwind
define void @intHdl() #0 {
entry:
  %0 = load i32, i32* @reg_slv_int, align 4
  %cmp = icmp eq i32 %0, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  call void @getMbCtx()
  call void @handleCmd()
  store i32 0, i32* @reg_slv_int, align 4
  br label %return

return:                                           ; preds = %if.end, %if.then
  ret void
}

; Function Attrs: nounwind
define void @getMbCtx() #0 {
entry:
  %0 = load %struct.MB_ITF_t*, %struct.MB_ITF_t** @reg_MB, align 4
  %ACK = getelementptr inbounds %struct.MB_ITF_t, %struct.MB_ITF_t* %0, i32 0, i32 9
  %val = getelementptr inbounds %struct.ACK, %struct.ACK* %ACK, i32 0, i32 0
  store i32 1, i32* %val, align 4
  %1 = load %struct.MB_ITF_t*, %struct.MB_ITF_t** @reg_MB, align 4
  %R_CMD = getelementptr inbounds %struct.MB_ITF_t, %struct.MB_ITF_t* %1, i32 0, i32 1
  %val1 = getelementptr inbounds %struct.R_CMD, %struct.R_CMD* %R_CMD, i32 0, i32 0
  %2 = load i32, i32* %val1, align 4
  store i32 %2, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 4), align 4
  %3 = load %struct.MB_ITF_t*, %struct.MB_ITF_t** @reg_MB, align 4
  %R_DAT0 = getelementptr inbounds %struct.MB_ITF_t, %struct.MB_ITF_t* %3, i32 0, i32 2
  %val2 = getelementptr inbounds %struct.R_DAT0, %struct.R_DAT0* %R_DAT0, i32 0, i32 0
  %4 = load i32, i32* %val2, align 4
  store i32 %4, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 5), align 4
  %5 = load %struct.MB_ITF_t*, %struct.MB_ITF_t** @reg_MB, align 4
  %R_DAT1 = getelementptr inbounds %struct.MB_ITF_t, %struct.MB_ITF_t* %5, i32 0, i32 3
  %val3 = getelementptr inbounds %struct.R_DAT1, %struct.R_DAT1* %R_DAT1, i32 0, i32 0
  %6 = load i32, i32* %val3, align 4
  store i32 %6, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 6), align 4
  %7 = load %struct.MB_ITF_t*, %struct.MB_ITF_t** @reg_MB, align 4
  %R_SIZE = getelementptr inbounds %struct.MB_ITF_t, %struct.MB_ITF_t* %7, i32 0, i32 4
  %val4 = getelementptr inbounds %struct.R_SIZE, %struct.R_SIZE* %R_SIZE, i32 0, i32 0
  %8 = load i32, i32* %val4, align 4
  store i32 %8, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 7), align 4
  ret void
}

; Function Attrs: nounwind
define void @handleCmd() #0 {
entry:
  %0 = load i32, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 4), align 4
  switch i32 %0, label %sw.default [
    i32 1, label %sw.bb
    i32 3, label %sw.bb1
  ]

sw.bb:                                            ; preds = %entry
  store i32 2, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 0), align 4
  store i32 4, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 1), align 4
  store i32 1, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 3), align 4
  call void @sendMsgSlv2Mst()
  br label %sw.epilog

sw.bb1:                                           ; preds = %entry
  %1 = load i32, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 7), align 4
  %cmp = icmp eq i32 %1, 1
  %conv = zext i1 %cmp to i32
  call void @__VERIFIER_assert(i32 %conv)
  %2 = load i32, i32* getelementptr inbounds ([8 x i32], [8 x i32]* @gMbCtx, i32 0, i32 5), align 4
  store i32 %2, i32* getelementptr inbounds ([2 x i32], [2 x i32]* @gSlvFlag, i32 0, i32 1), align 4
  store i32 1, i32* getelementptr inbounds ([2 x i32], [2 x i32]* @gSlvFlag, i32 0, i32 0), align 4
  br label %sw.epilog

sw.default:                                       ; preds = %entry
  br label %sw.epilog

sw.epilog:                                        ; preds = %sw.default, %sw.bb1, %sw.bb
  ret void
}

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { argmemonly nounwind }
attributes #2 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0 (tags/RELEASE_381/final)"}
