; ModuleID = 'src.c'
source_filename = "src.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @KCTF() #0 {
  call void @remake(i32 noundef 20577, i32 noundef 4486413, i32 noundef 0)
  call void @create(i32 noundef 255, i32 noundef 1)
  call void @sub(i32 noundef 1099601)
  call void @create(i32 noundef 112, i32 noundef 2)
  call void @create(i32 noundef 112, i32 noundef 2)
  call void @delete(i32 noundef 0)
  call void @delete(i32 noundef 0)
  call void @delete(i32 noundef 0)
  call void (...) @end()
  ret void
}

declare void @remake(i32 noundef, i32 noundef, i32 noundef) #1

declare void @create(i32 noundef, i32 noundef) #1

declare void @sub(i32 noundef) #1

declare void @delete(i32 noundef) #1

declare void @end(...) #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
