// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// RUN: %clang_cc1 -verify -fopenmp -triple x86_64-apple-darwin10.6.0 -fopenmp-targets=nvptx64-nvidia-cuda  -emit-llvm-bc -o %t-host.bc %s
// RUN: %clang_cc1 -verify -fopenmp -triple nvptx64-nvidia-cuda -fopenmp-targets=nvptx64-nvidia-cuda -emit-llvm %s -fopenmp-is-device -fopenmp-host-ir-file-path %t-host.bc -o - -disable-llvm-optzns | FileCheck %s --check-prefix=CHECK1
// expected-no-diagnostics

#ifndef HEADER
#define HEADER

#pragma omp declare target
typedef void **omp_allocator_handle_t;
extern const omp_allocator_handle_t omp_null_allocator;
extern const omp_allocator_handle_t omp_default_mem_alloc;
extern const omp_allocator_handle_t omp_large_cap_mem_alloc;
extern const omp_allocator_handle_t omp_const_mem_alloc;
extern const omp_allocator_handle_t omp_high_bw_mem_alloc;
extern const omp_allocator_handle_t omp_low_lat_mem_alloc;
extern const omp_allocator_handle_t omp_cgroup_mem_alloc;
extern const omp_allocator_handle_t omp_pteam_mem_alloc;
extern const omp_allocator_handle_t omp_thread_mem_alloc;

struct St{
 int a;
};

struct St1{
 int a;
 static int b;
#pragma omp allocate(b) allocator(omp_default_mem_alloc)
} d;

int a, b, c;
#pragma omp allocate(a) allocator(omp_large_cap_mem_alloc)
#pragma omp allocate(b) allocator(omp_const_mem_alloc)
#pragma omp allocate(d, c) allocator(omp_high_bw_mem_alloc)

template <class T>
struct ST {
  static T m;
  #pragma omp allocate(m) allocator(omp_low_lat_mem_alloc)
};

template <class T> T foo() {
  T v;
  #pragma omp allocate(v) allocator(omp_cgroup_mem_alloc)
  v = ST<T>::m;
  return v;
}

namespace ns{
  int a;
}
#pragma omp allocate(ns::a) allocator(omp_pteam_mem_alloc)

int main () {
  static int a;
#pragma omp allocate(a) allocator(omp_thread_mem_alloc)
  a=2;
  double b = 3;
  float c;
#pragma omp allocate(b) allocator(omp_default_mem_alloc)
#pragma omp allocate(c) allocator(omp_cgroup_mem_alloc)
  return (foo<int>());
}


extern template int ST<int>::m;

void baz(float &);

void bar() {
  float bar_a;
  double bar_b;
  int bar_c;
#pragma omp allocate(bar_c) allocator(omp_cgroup_mem_alloc)
#pragma omp parallel private(bar_a, bar_b) allocate(omp_thread_mem_alloc                  \
                                                    : bar_a) allocate(omp_pteam_mem_alloc \
                                                                      : bar_b)
  {
    bar_b = bar_a;
    baz(bar_a);
  }
}

#pragma omp end declare target
#endif
// CHECK1-LABEL: define {{[^@]+}}@main
// CHECK1-SAME: () #[[ATTR0:[0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[RETVAL:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[B:%.*]] = alloca double, align 8
// CHECK1-NEXT:    store i32 0, i32* [[RETVAL]], align 4
// CHECK1-NEXT:    store i32 2, i32* @_ZZ4mainE1a, align 4
// CHECK1-NEXT:    store double 3.000000e+00, double* [[B]], align 8
// CHECK1-NEXT:    [[CALL:%.*]] = call i32 @_Z3fooIiET_v() #[[ATTR6:[0-9]+]]
// CHECK1-NEXT:    ret i32 [[CALL]]
//
//
// CHECK1-LABEL: define {{[^@]+}}@_Z3fooIiET_v
// CHECK1-SAME: () #[[ATTR1:[0-9]+]] comdat {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[TMP0:%.*]] = load i32, i32* @_ZN2STIiE1mE, align 4
// CHECK1-NEXT:    store i32 [[TMP0]], i32* @v, align 4
// CHECK1-NEXT:    [[TMP1:%.*]] = load i32, i32* @v, align 4
// CHECK1-NEXT:    ret i32 [[TMP1]]
//
//
// CHECK1-LABEL: define {{[^@]+}}@_Z3barv
// CHECK1-SAME: () #[[ATTR1]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[BAR_A:%.*]] = alloca float, align 4
// CHECK1-NEXT:    [[BAR_B:%.*]] = alloca double, align 8
// CHECK1-NEXT:    [[OMP_OUTLINED_ARG_AGG_:%.*]] = alloca [[STRUCT_ANON:%.*]], align 1
// CHECK1-NEXT:    [[CAPTURED_VARS_ADDRS:%.*]] = alloca [1 x i8*], align 8
// CHECK1-NEXT:    [[TMP0:%.*]] = call i32 @__kmpc_global_thread_num(%struct.ident_t* @[[GLOB1:[0-9]+]])
// CHECK1-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [1 x i8*], [1 x i8*]* [[CAPTURED_VARS_ADDRS]], i64 0, i64 0
// CHECK1-NEXT:    [[TMP2:%.*]] = call i8* @__kmpc_alloc_shared(i64 1)
// CHECK1-NEXT:    [[TMP3:%.*]] = load [[STRUCT_ANON]], %struct.anon* [[OMP_OUTLINED_ARG_AGG_]], align 1
// CHECK1-NEXT:    [[TMP4:%.*]] = bitcast i8* [[TMP2]] to %struct.anon*
// CHECK1-NEXT:    store [[STRUCT_ANON]] [[TMP3]], %struct.anon* [[TMP4]], align 1
// CHECK1-NEXT:    store i8* [[TMP2]], i8** [[TMP1]], align 8
// CHECK1-NEXT:    [[TMP5:%.*]] = bitcast [1 x i8*]* [[CAPTURED_VARS_ADDRS]] to i8**
// CHECK1-NEXT:    call void @__kmpc_parallel_51(%struct.ident_t* @[[GLOB1]], i32 [[TMP0]], i32 1, i32 -1, i32 -1, i8* bitcast (void (i32*, i32*, %struct.anon*)* @__omp_outlined__ to i8*), i8* bitcast (void (i16, i32)* @__omp_outlined___wrapper to i8*), i8** [[TMP5]], i64 1)
// CHECK1-NEXT:    call void @__kmpc_free_shared(i8* [[TMP2]])
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@__omp_outlined__
// CHECK1-SAME: (i32* noalias [[DOTGLOBAL_TID_:%.*]], i32* noalias [[DOTBOUND_TID_:%.*]], %struct.anon* noalias [[__CONTEXT:%.*]]) #[[ATTR2:[0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca i32*, align 8
// CHECK1-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca i32*, align 8
// CHECK1-NEXT:    [[__CONTEXT_ADDR:%.*]] = alloca %struct.anon*, align 8
// CHECK1-NEXT:    [[BAR_A:%.*]] = alloca float, align 4
// CHECK1-NEXT:    store i32* [[DOTGLOBAL_TID_]], i32** [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    store i32* [[DOTBOUND_TID_]], i32** [[DOTBOUND_TID__ADDR]], align 8
// CHECK1-NEXT:    store %struct.anon* [[__CONTEXT]], %struct.anon** [[__CONTEXT_ADDR]], align 8
// CHECK1-NEXT:    [[TMP0:%.*]] = load %struct.anon*, %struct.anon** [[__CONTEXT_ADDR]], align 8
// CHECK1-NEXT:    [[TMP1:%.*]] = load float, float* [[BAR_A]], align 4
// CHECK1-NEXT:    [[CONV:%.*]] = fpext float [[TMP1]] to double
// CHECK1-NEXT:    store double [[CONV]], double* addrspacecast (double addrspace(3)* @bar_b to double*), align 8
// CHECK1-NEXT:    call void @_Z3bazRf(float* nonnull align 4 dereferenceable(4) [[BAR_A]]) #[[ATTR6]]
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@__omp_outlined___wrapper
// CHECK1-SAME: (i16 zeroext [[TMP0:%.*]], i32 [[TMP1:%.*]]) #[[ATTR4:[0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTADDR:%.*]] = alloca i16, align 2
// CHECK1-NEXT:    [[DOTADDR1:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTZERO_ADDR:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[GLOBAL_ARGS:%.*]] = alloca i8**, align 8
// CHECK1-NEXT:    store i32 0, i32* [[DOTZERO_ADDR]], align 4
// CHECK1-NEXT:    store i16 [[TMP0]], i16* [[DOTADDR]], align 2
// CHECK1-NEXT:    store i32 [[TMP1]], i32* [[DOTADDR1]], align 4
// CHECK1-NEXT:    call void @__kmpc_get_shared_variables(i8*** [[GLOBAL_ARGS]])
// CHECK1-NEXT:    call void @__omp_outlined__(i32* [[DOTADDR1]], i32* [[DOTZERO_ADDR]], %struct.anon* null) #[[ATTR5:[0-9]+]]
// CHECK1-NEXT:    ret void
//
