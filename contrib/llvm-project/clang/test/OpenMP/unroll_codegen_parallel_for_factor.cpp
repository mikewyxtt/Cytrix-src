// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// Check code generation
// RUN: %clang_cc1 -verify -triple x86_64-pc-linux-gnu -fopenmp -fopenmp-version=51 -emit-llvm %s -o - | FileCheck %s --check-prefix=IR

// Check same results after serialization round-trip
// RUN: %clang_cc1 -verify -triple x86_64-pc-linux-gnu -fopenmp -fopenmp-version=51 -emit-pch -o %t %s
// RUN: %clang_cc1 -verify -triple x86_64-pc-linux-gnu -fopenmp -fopenmp-version=51 -include-pch %t -emit-llvm %s -o - | FileCheck %s --check-prefix=IR
// expected-no-diagnostics

#ifndef HEADER
#define HEADER

// placeholder for loop body code.
extern "C" void body(...) {}


// IR-LABEL: @func(
// IR-NEXT:  entry:
// IR-NEXT:    [[START_ADDR:%.*]] = alloca i32, align 4
// IR-NEXT:    [[END_ADDR:%.*]] = alloca i32, align 4
// IR-NEXT:    [[STEP_ADDR:%.*]] = alloca i32, align 4
// IR-NEXT:    [[OMP_OUTLINED_ARG_AGG_:%.*]] = alloca [[STRUCT_ANON:%.*]], align 8
// IR-NEXT:    store i32 [[START:%.*]], i32* [[START_ADDR]], align 4
// IR-NEXT:    store i32 [[END:%.*]], i32* [[END_ADDR]], align 4
// IR-NEXT:    store i32 [[STEP:%.*]], i32* [[STEP_ADDR]], align 4
// IR-NEXT:    [[TMP0:%.*]] = getelementptr inbounds [[STRUCT_ANON]], %struct.anon* [[OMP_OUTLINED_ARG_AGG_]], i32 0, i32 0
// IR-NEXT:    store i32* [[END_ADDR]], i32** [[TMP0]], align 8
// IR-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [[STRUCT_ANON]], %struct.anon* [[OMP_OUTLINED_ARG_AGG_]], i32 0, i32 1
// IR-NEXT:    store i32* [[STEP_ADDR]], i32** [[TMP1]], align 8
// IR-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[STRUCT_ANON]], %struct.anon* [[OMP_OUTLINED_ARG_AGG_]], i32 0, i32 2
// IR-NEXT:    store i32* [[START_ADDR]], i32** [[TMP2]], align 8
// IR-NEXT:    call void (%struct.ident_t*, i32, void (i32*, i32*, ...)*, ...) @__kmpc_fork_call(%struct.ident_t* @[[GLOB2:[0-9]+]], i32 1, void (i32*, i32*, ...)* bitcast (void (i32*, i32*, %struct.anon*)* @.omp_outlined. to void (i32*, i32*, ...)*), %struct.anon* [[OMP_OUTLINED_ARG_AGG_]])
// IR-NEXT:    ret void
//
extern "C" void func(int start, int end, int step) {
  #pragma omp parallel for
  #pragma omp unroll partial(7)
  for (int i = start; i < end; i+=step)
    body(start, end, step, i);
}



#endif /* HEADER */

