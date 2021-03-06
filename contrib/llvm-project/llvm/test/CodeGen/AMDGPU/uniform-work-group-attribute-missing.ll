; NOTE: Assertions have been autogenerated by utils/update_test_checks.py UTC_ARGS: --function-signature --check-globals
; RUN: opt -S -mtriple=amdgcn-amd- -amdgpu-annotate-kernel-features %s | FileCheck %s

; If the kernel does not have the uniform-work-group-attribute, set both callee and caller as false

define void @foo() #0 {
; CHECK-LABEL: define {{[^@]+}}@foo
; CHECK-SAME: () #[[ATTR0:[0-9]+]] {
; CHECK-NEXT:    ret void
;
  ret void
}

define amdgpu_kernel void @kernel1() #1 {
; CHECK-LABEL: define {{[^@]+}}@kernel1
; CHECK-SAME: () #[[ATTR1:[0-9]+]] {
; CHECK-NEXT:    call void @foo()
; CHECK-NEXT:    ret void
;
  call void @foo()
  ret void
}

attributes #0 = { "uniform-work-group-size"="true" }

;.
; CHECK: attributes #[[ATTR0]] = { "uniform-work-group-size"="false" }
; CHECK: attributes #[[ATTR1]] = { "amdgpu-calls" "uniform-work-group-size"="false" }
;.
