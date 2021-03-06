// RUN: not llvm-mc -triple=aarch64 -show-encoding -mattr=+sme 2>&1 < %s| FileCheck %s

// ------------------------------------------------------------------------- //
// Invalid tile (expected: za[0-15]h.q or za[0-15]v.q)

st1q {za16h.q[w12]}, p0, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: unexpected token in argument list
// CHECK-NEXT: st1q {za16h.q[w12]}, p0, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

st1q {za[w12]}, p0/z, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid matrix operand, expected za[0-15]h.q or za[0-15]v.q
// CHECK-NEXT: st1q {za[w12]}, p0/z, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

st1q {za7v.d[w12]}, p0/z, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid matrix operand, expected za[0-15]h.q or za[0-15]v.q
// CHECK-NEXT: st1q {za7v.d[w12]}, p0/z, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

// ------------------------------------------------------------------------- //
// Invalid vector select register (expected: w12-w15)

st1q {za0h.q[w11]}, p0, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid operand for instruction
// CHECK-NEXT: st1q {za0h.q[w11]}, p0, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

st1q {za0h.q[w16]}, p0, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid operand for instruction
// CHECK-NEXT: st1q {za0h.q[w16]}, p0, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

// ------------------------------------------------------------------------- //
// Invalid predicate (expected: p0-p7)

st1q {za0h.q[w12]}, p8, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid restricted predicate register, expected p0..p7 (without element suffix)
// CHECK-NEXT: st1q {za0h.q[w12]}, p8, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

// ------------------------------------------------------------------------- //
// Unexpected predicate qualifier

st1q {za0h.q[w12]}, p0/z, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid operand for instruction
// CHECK-NEXT: st1q {za0h.q[w12]}, p0/z, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

st1q {za0h.q[w12]}, p0/m, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid operand for instruction
// CHECK-NEXT: st1q {za0h.q[w12]}, p0/m, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

// ------------------------------------------------------------------------- //
// Invalid memory operands

st1q {za0h.q[w12]}, p0, [w0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid operand for instruction
// CHECK-NEXT: st1q {za0h.q[w12]}, p0, [w0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

st1q {za0h.q[w12]}, p0, [x0, w0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: register must be x0..x30 or xzr, with required shift 'lsl #4'
// CHECK-NEXT: st1q {za0h.q[w12]}, p0, [x0, w0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

st1q {za0h.q[w12]}, p0, [x0, x0, lsl #5]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: register must be x0..x30 or xzr, with required shift 'lsl #4'
// CHECK-NEXT: st1q {za0h.q[w12]}, p0, [x0, x0, lsl #5]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:
