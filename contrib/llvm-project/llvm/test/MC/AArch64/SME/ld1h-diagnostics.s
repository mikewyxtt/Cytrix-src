// RUN: not llvm-mc -triple=aarch64 -show-encoding -mattr=+sme 2>&1 < %s| FileCheck %s

// ------------------------------------------------------------------------- //
// Invalid tile (expected: za[0-1]h.h or za[0-1]v.h)

ld1h {za2h.h[w12, #0]}, p0/z, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: unexpected token in argument list
// CHECK-NEXT: ld1h {za2h.h[w12, #0]}, p0/z, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

ld1h {za[w12, #0]}, p0/z, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid matrix operand, expected za[0-1]h.h or za[0-1]v.h
// CHECK-NEXT: ld1h {za[w12, #0]}, p0/z, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

ld1h {za0.b[w12, #0]}, p0/z, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid matrix operand, expected za[0-1]h.h or za[0-1]v.h
// CHECK-NEXT: ld1h {za0.b[w12, #0]}, p0/z, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

// ------------------------------------------------------------------------- //
// Invalid vector select register (expected: w12-w15)

ld1h {za0h.h[w11, #0]}, p0/z, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid operand for instruction
// CHECK-NEXT: ld1h {za0h.h[w11, #0]}, p0/z, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

ld1h {za0h.h[w16, #0]}, p0/z, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid operand for instruction
// CHECK-NEXT: ld1h {za0h.h[w16, #0]}, p0/z, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

// ------------------------------------------------------------------------- //
// Invalid vector select offset (expected: 0-7)

ld1h {za0h.h[w12]}, p0/z, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: immediate must be an integer in range [0, 7].
// CHECK-NEXT: ld1h {za0h.h[w12]}, p0/z, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

ld1h {za0h.h[w12, #8]}, p0/z, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: immediate must be an integer in range [0, 7].
// CHECK-NEXT: ld1h {za0h.h[w12, #8]}, p0/z, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

// ------------------------------------------------------------------------- //
// Invalid predicate (expected: p0-p7)

ld1h {za0h.h[w12, #0]}, p8/z, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid restricted predicate register, expected p0..p7 (without element suffix)
// CHECK-NEXT: ld1h {za0h.h[w12, #0]}, p8/z, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

// ------------------------------------------------------------------------- //
// Invalid predicate qualifier (expected: /z)

ld1h {za0h.h[w12, #0]}, p0/m, [x0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid operand for instruction
// CHECK-NEXT: ld1h {za0h.h[w12, #0]}, p0/m, [x0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

// ------------------------------------------------------------------------- //
// Invalid memory operands

ld1h {za0h.h[w12, #0]}, p0/z, [w0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid operand for instruction
// CHECK-NEXT: ld1h {za0h.h[w12, #0]}, p0/z, [w0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

ld1h {za0h.h[w12, #0]}, p0/z, [x0, w0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: register must be x0..x30 or xzr, with required shift 'lsl #1'
// CHECK-NEXT: ld1h {za0h.h[w12, #0]}, p0/z, [x0, w0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

ld1h {za0h.h[w12, #0]}, p0/z, [x0, x0, lsl #2]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: register must be x0..x30 or xzr, with required shift 'lsl #1'
// CHECK-NEXT: ld1h {za0h.h[w12, #0]}, p0/z, [x0, x0, lsl #2]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:
