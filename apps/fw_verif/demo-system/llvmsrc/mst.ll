; ModuleID = '/home/byhuang/workspace/ILA/apps/fw_verif/demo-system/fwsrc/mst.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@mst_sram = external global [0 x i8], align 1

; Function Attrs: nounwind uwtable
define void @mainMst() #0 {
entry:
  %recCmd = alloca i32, align 4
  %recData = alloca [2 x i32], align 4
  %recDataSize = alloca i8, align 1
  %imgSize = alloca i32, align 4
  %mstBuff = alloca i8*, align 8
  call void @sendMsgMst2Slv(i32 1, i32* null, i8 zeroext 0)
  store i32 0, i32* %recCmd, align 4
  %0 = bitcast [2 x i32]* %recData to i8*
  call void @llvm.memset.p0i8.i64(i8* %0, i8 0, i64 8, i32 4, i1 false)
  store i8 0, i8* %recDataSize, align 1
  %arraydecay = getelementptr inbounds [2 x i32], [2 x i32]* %recData, i32 0, i32 0
  call void @receiveMsgSlv2Mst(i32* %recCmd, i32* %arraydecay, i8* %recDataSize)
  %1 = load i8, i8* %recDataSize, align 1
  %conv = zext i8 %1 to i32
  %cmp = icmp sge i32 %conv, 1
  br i1 %cmp, label %land.lhs.true, label %cond.false

land.lhs.true:                                    ; preds = %entry
  %arrayidx = getelementptr inbounds [2 x i32], [2 x i32]* %recData, i64 0, i64 0
  %2 = load i32, i32* %arrayidx, align 4
  %cmp2 = icmp ule i32 %2, 32
  br i1 %cmp2, label %cond.true, label %cond.false

cond.true:                                        ; preds = %land.lhs.true
  %arrayidx4 = getelementptr inbounds [2 x i32], [2 x i32]* %recData, i64 0, i64 0
  %3 = load i32, i32* %arrayidx4, align 4
  br label %cond.end

cond.false:                                       ; preds = %land.lhs.true, %entry
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %3, %cond.true ], [ 32, %cond.false ]
  store i32 %cond, i32* %imgSize, align 4
  %4 = load i32, i32* %imgSize, align 4
  %conv5 = zext i32 %4 to i64
  %call = call noalias i8* @calloc(i64 1, i64 %conv5) #4
  store i8* %call, i8** %mstBuff, align 8
  %5 = load i8*, i8** %mstBuff, align 8
  %6 = load i32, i32* %imgSize, align 4
  %conv6 = zext i32 %6 to i64
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* getelementptr inbounds ([0 x i8], [0 x i8]* @mst_sram, i32 0, i32 0), i8* %5, i64 %conv6, i32 1, i1 false)
  call void @sendMsgMst2Slv(i32 3, i32* %imgSize, i8 zeroext 1)
  %arraydecay7 = getelementptr inbounds [2 x i32], [2 x i32]* %recData, i32 0, i32 0
  call void @receiveMsgSlv2Mst(i32* %recCmd, i32* %arraydecay7, i8* %recDataSize)
  %7 = load i8*, i8** %mstBuff, align 8
  call void @free(i8* %7) #4
  ret void
}

; Function Attrs: nounwind uwtable
define void @sendMsgMst2Slv(i32 %cmd, i32* %data, i8 zeroext %dataSize) #0 {
entry:
  %cmd.addr = alloca i32, align 4
  %data.addr = alloca i32*, align 8
  %dataSize.addr = alloca i8, align 1
  %i = alloca i8, align 1
  %db = alloca i32, align 4
  store i32 %cmd, i32* %cmd.addr, align 4
  store i32* %data, i32** %data.addr, align 8
  store i8 %dataSize, i8* %dataSize.addr, align 1
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %call = call i32 @HW_REG_READ(i32 -65532)
  %tobool = icmp ne i32 %call, 0
  br i1 %tobool, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  br label %while.cond

while.end:                                        ; preds = %while.cond
  store i8 0, i8* %i, align 1
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %while.end
  %0 = load i8, i8* %i, align 1
  %conv = zext i8 %0 to i32
  %1 = load i8, i8* %dataSize.addr, align 1
  %conv1 = zext i8 %1 to i32
  %cmp = icmp slt i32 %conv, %conv1
  br i1 %cmp, label %land.rhs, label %land.end

land.rhs:                                         ; preds = %for.cond
  %2 = load i8, i8* %i, align 1
  %conv3 = zext i8 %2 to i32
  %cmp4 = icmp slt i32 %conv3, 2
  br label %land.end

land.end:                                         ; preds = %land.rhs, %for.cond
  %3 = phi i1 [ false, %for.cond ], [ %cmp4, %land.rhs ]
  br i1 %3, label %for.body, label %for.end

for.body:                                         ; preds = %land.end
  %4 = load i8, i8* %i, align 1
  %conv6 = zext i8 %4 to i32
  %add = add i32 -65534, %conv6
  %5 = load i8, i8* %i, align 1
  %idxprom = zext i8 %5 to i64
  %6 = load i32*, i32** %data.addr, align 8
  %arrayidx = getelementptr inbounds i32, i32* %6, i64 %idxprom
  %7 = load i32, i32* %arrayidx, align 4
  call void @HW_REG_WRITE(i32 %add, i32 %7)
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %8 = load i8, i8* %i, align 1
  %inc = add i8 %8, 1
  store i8 %inc, i8* %i, align 1
  br label %for.cond

for.end:                                          ; preds = %land.end
  %9 = load i32, i32* %cmd.addr, align 4
  %shl = shl i32 %9, 9
  %10 = load i8, i8* %dataSize.addr, align 1
  %conv7 = zext i8 %10 to i32
  %shl8 = shl i32 %conv7, 1
  %or = or i32 %shl, %shl8
  %or9 = or i32 %or, 1
  store i32 %or9, i32* %db, align 4
  %11 = load i32, i32* %db, align 4
  call void @HW_REG_WRITE(i32 -65535, i32 %11)
  ret void
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture, i8, i64, i32, i1) #1

; Function Attrs: nounwind uwtable
define void @receiveMsgSlv2Mst(i32* %cmd, i32* %data, i8* %dataSize) #0 {
entry:
  %cmd.addr = alloca i32*, align 8
  %data.addr = alloca i32*, align 8
  %dataSize.addr = alloca i8*, align 8
  %db = alloca i32, align 4
  %i = alloca i8, align 1
  store i32* %cmd, i32** %cmd.addr, align 8
  store i32* %data, i32** %data.addr, align 8
  store i8* %dataSize, i8** %dataSize.addr, align 8
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %call = call i32 @HW_REG_READ(i32 -65531)
  %cmp = icmp eq i32 %call, 0
  br i1 %cmp, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %call1 = call i32 @HW_REG_READ(i32 -65531)
  store i32 %call1, i32* %db, align 4
  %0 = load i32, i32* %db, align 4
  %shr = lshr i32 %0, 9
  %1 = load i32*, i32** %cmd.addr, align 8
  store i32 %shr, i32* %1, align 4
  %2 = load i32, i32* %db, align 4
  %shr2 = lshr i32 %2, 1
  %and = and i32 %shr2, 255
  %conv = trunc i32 %and to i8
  %3 = load i8*, i8** %dataSize.addr, align 8
  store i8 %conv, i8* %3, align 1
  store i8 0, i8* %i, align 1
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %while.end
  %4 = load i8, i8* %i, align 1
  %conv3 = zext i8 %4 to i32
  %5 = load i8*, i8** %dataSize.addr, align 8
  %6 = load i8, i8* %5, align 1
  %conv4 = zext i8 %6 to i32
  %cmp5 = icmp slt i32 %conv3, %conv4
  br i1 %cmp5, label %land.rhs, label %land.end

land.rhs:                                         ; preds = %for.cond
  %7 = load i8, i8* %i, align 1
  %conv7 = zext i8 %7 to i32
  %cmp8 = icmp slt i32 %conv7, 2
  br label %land.end

land.end:                                         ; preds = %land.rhs, %for.cond
  %8 = phi i1 [ false, %for.cond ], [ %cmp8, %land.rhs ]
  br i1 %8, label %for.body, label %for.end

for.body:                                         ; preds = %land.end
  %9 = load i8, i8* %i, align 1
  %conv10 = zext i8 %9 to i32
  %add = add i32 -65530, %conv10
  %call11 = call i32 @HW_REG_READ(i32 %add)
  %10 = load i8, i8* %i, align 1
  %idxprom = zext i8 %10 to i64
  %11 = load i32*, i32** %data.addr, align 8
  %arrayidx = getelementptr inbounds i32, i32* %11, i64 %idxprom
  store i32 %call11, i32* %arrayidx, align 4
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %12 = load i8, i8* %i, align 1
  %inc = add i8 %12, 1
  store i8 %inc, i8* %i, align 1
  br label %for.cond

for.end:                                          ; preds = %land.end
  call void @HW_REG_WRITE(i32 -65531, i32 0)
  ret void
}

; Function Attrs: nounwind
declare noalias i8* @calloc(i64, i64) #2

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #1

; Function Attrs: nounwind
declare void @free(i8*) #2

declare i32 @HW_REG_READ(i32) #3

declare void @HW_REG_WRITE(i32, i32) #3

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { argmemonly nounwind }
attributes #2 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0 (tags/RELEASE_381/final)"}
