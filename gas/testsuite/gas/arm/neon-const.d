# name: Neon floating-point constants
# as: -mfpu=neon
# objdump: -dr --prefix-addresses --show-raw-insn

.*: +file format .*arm.*

Disassembly of section .text:
0[0-9a-f]+ <[^>]+> f2800050 	vmov\.i32	q0, #0	; 0x00000000
0[0-9a-f]+ <[^>]+> f2800f50 	vmov\.f32	q0, #2	; 0x40000000
0[0-9a-f]+ <[^>]+> f2810f50 	vmov\.f32	q0, #4	; 0x40800000
0[0-9a-f]+ <[^>]+> f2820f50 	vmov\.f32	q0, #8	; 0x41000000
0[0-9a-f]+ <[^>]+> f2830f50 	vmov\.f32	q0, #16	; 0x41800000
0[0-9a-f]+ <[^>]+> f2840f50 	vmov\.f32	q0, #0\.125	; 0x3e000000
0[0-9a-f]+ <[^>]+> f2850f50 	vmov\.f32	q0, #0\.25	; 0x3e800000
0[0-9a-f]+ <[^>]+> f2860f50 	vmov\.f32	q0, #0\.5	; 0x3f000000
0[0-9a-f]+ <[^>]+> f2870f50 	vmov\.f32	q0, #1	; 0x3f800000
0[0-9a-f]+ <[^>]+> f2800f51 	vmov\.f32	q0, #2\.125	; 0x40080000
0[0-9a-f]+ <[^>]+> f2810f51 	vmov\.f32	q0, #4\.25	; 0x40880000
0[0-9a-f]+ <[^>]+> f2820f51 	vmov\.f32	q0, #8\.5	; 0x41080000
0[0-9a-f]+ <[^>]+> f2830f51 	vmov\.f32	q0, #17	; 0x41880000
0[0-9a-f]+ <[^>]+> f2840f51 	vmov\.f32	q0, #0\.1328125	; 0x3e080000
0[0-9a-f]+ <[^>]+> f2850f51 	vmov\.f32	q0, #0\.265625	; 0x3e880000
0[0-9a-f]+ <[^>]+> f2860f51 	vmov\.f32	q0, #0\.53125	; 0x3f080000
0[0-9a-f]+ <[^>]+> f2870f51 	vmov\.f32	q0, #1\.0625	; 0x3f880000
0[0-9a-f]+ <[^>]+> f2800f52 	vmov\.f32	q0, #2\.25	; 0x40100000
0[0-9a-f]+ <[^>]+> f2810f52 	vmov\.f32	q0, #4\.5	; 0x40900000
0[0-9a-f]+ <[^>]+> f2820f52 	vmov\.f32	q0, #9	; 0x41100000
0[0-9a-f]+ <[^>]+> f2830f52 	vmov\.f32	q0, #18	; 0x41900000
0[0-9a-f]+ <[^>]+> f2840f52 	vmov\.f32	q0, #0\.140625	; 0x3e100000
0[0-9a-f]+ <[^>]+> f2850f52 	vmov\.f32	q0, #0\.28125	; 0x3e900000
0[0-9a-f]+ <[^>]+> f2860f52 	vmov\.f32	q0, #0\.5625	; 0x3f100000
0[0-9a-f]+ <[^>]+> f2870f52 	vmov\.f32	q0, #1\.125	; 0x3f900000
0[0-9a-f]+ <[^>]+> f2800f53 	vmov\.f32	q0, #2\.375	; 0x40180000
0[0-9a-f]+ <[^>]+> f2810f53 	vmov\.f32	q0, #4\.75	; 0x40980000
0[0-9a-f]+ <[^>]+> f2820f53 	vmov\.f32	q0, #9\.5	; 0x41180000
0[0-9a-f]+ <[^>]+> f2830f53 	vmov\.f32	q0, #19	; 0x41980000
0[0-9a-f]+ <[^>]+> f2840f53 	vmov\.f32	q0, #0\.1484375	; 0x3e180000
0[0-9a-f]+ <[^>]+> f2850f53 	vmov\.f32	q0, #0\.296875	; 0x3e980000
0[0-9a-f]+ <[^>]+> f2860f53 	vmov\.f32	q0, #0\.59375	; 0x3f180000
0[0-9a-f]+ <[^>]+> f2870f53 	vmov\.f32	q0, #1\.1875	; 0x3f980000
0[0-9a-f]+ <[^>]+> f2800f54 	vmov\.f32	q0, #2\.5	; 0x40200000
0[0-9a-f]+ <[^>]+> f2810f54 	vmov\.f32	q0, #5	; 0x40a00000
0[0-9a-f]+ <[^>]+> f2820f54 	vmov\.f32	q0, #10	; 0x41200000
0[0-9a-f]+ <[^>]+> f2830f54 	vmov\.f32	q0, #20	; 0x41a00000
0[0-9a-f]+ <[^>]+> f2840f54 	vmov\.f32	q0, #0\.15625	; 0x3e200000
0[0-9a-f]+ <[^>]+> f2850f54 	vmov\.f32	q0, #0\.3125	; 0x3ea00000
0[0-9a-f]+ <[^>]+> f2860f54 	vmov\.f32	q0, #0\.625	; 0x3f200000
0[0-9a-f]+ <[^>]+> f2870f54 	vmov\.f32	q0, #1\.25	; 0x3fa00000
0[0-9a-f]+ <[^>]+> f2800f55 	vmov\.f32	q0, #2\.625	; 0x40280000
0[0-9a-f]+ <[^>]+> f2810f55 	vmov\.f32	q0, #5\.25	; 0x40a80000
0[0-9a-f]+ <[^>]+> f2820f55 	vmov\.f32	q0, #10\.5	; 0x41280000
0[0-9a-f]+ <[^>]+> f2830f55 	vmov\.f32	q0, #21	; 0x41a80000
0[0-9a-f]+ <[^>]+> f2840f55 	vmov\.f32	q0, #0\.1640625	; 0x3e280000
0[0-9a-f]+ <[^>]+> f2850f55 	vmov\.f32	q0, #0\.328125	; 0x3ea80000
0[0-9a-f]+ <[^>]+> f2860f55 	vmov\.f32	q0, #0\.65625	; 0x3f280000
0[0-9a-f]+ <[^>]+> f2870f55 	vmov\.f32	q0, #1\.3125	; 0x3fa80000
0[0-9a-f]+ <[^>]+> f2800f56 	vmov\.f32	q0, #2\.75	; 0x40300000
0[0-9a-f]+ <[^>]+> f2810f56 	vmov\.f32	q0, #5\.5	; 0x40b00000
0[0-9a-f]+ <[^>]+> f2820f56 	vmov\.f32	q0, #11	; 0x41300000
0[0-9a-f]+ <[^>]+> f2830f56 	vmov\.f32	q0, #22	; 0x41b00000
0[0-9a-f]+ <[^>]+> f2840f56 	vmov\.f32	q0, #0\.171875	; 0x3e300000
0[0-9a-f]+ <[^>]+> f2850f56 	vmov\.f32	q0, #0\.34375	; 0x3eb00000
0[0-9a-f]+ <[^>]+> f2860f56 	vmov\.f32	q0, #0\.6875	; 0x3f300000
0[0-9a-f]+ <[^>]+> f2870f56 	vmov\.f32	q0, #1\.375	; 0x3fb00000
0[0-9a-f]+ <[^>]+> f2800f57 	vmov\.f32	q0, #2\.875	; 0x40380000
0[0-9a-f]+ <[^>]+> f2810f57 	vmov\.f32	q0, #5\.75	; 0x40b80000
0[0-9a-f]+ <[^>]+> f2820f57 	vmov\.f32	q0, #11\.5	; 0x41380000
0[0-9a-f]+ <[^>]+> f2830f57 	vmov\.f32	q0, #23	; 0x41b80000
0[0-9a-f]+ <[^>]+> f2840f57 	vmov\.f32	q0, #0\.1796875	; 0x3e380000
0[0-9a-f]+ <[^>]+> f2850f57 	vmov\.f32	q0, #0\.359375	; 0x3eb80000
0[0-9a-f]+ <[^>]+> f2860f57 	vmov\.f32	q0, #0\.71875	; 0x3f380000
0[0-9a-f]+ <[^>]+> f2870f57 	vmov\.f32	q0, #1\.4375	; 0x3fb80000
0[0-9a-f]+ <[^>]+> f2800f58 	vmov\.f32	q0, #3	; 0x40400000
0[0-9a-f]+ <[^>]+> f2810f58 	vmov\.f32	q0, #6	; 0x40c00000
0[0-9a-f]+ <[^>]+> f2820f58 	vmov\.f32	q0, #12	; 0x41400000
0[0-9a-f]+ <[^>]+> f2830f58 	vmov\.f32	q0, #24	; 0x41c00000
0[0-9a-f]+ <[^>]+> f2840f58 	vmov\.f32	q0, #0\.1875	; 0x3e400000
0[0-9a-f]+ <[^>]+> f2850f58 	vmov\.f32	q0, #0\.375	; 0x3ec00000
0[0-9a-f]+ <[^>]+> f2860f58 	vmov\.f32	q0, #0\.75	; 0x3f400000
0[0-9a-f]+ <[^>]+> f2870f58 	vmov\.f32	q0, #1\.5	; 0x3fc00000
0[0-9a-f]+ <[^>]+> f2800f59 	vmov\.f32	q0, #3\.125	; 0x40480000
0[0-9a-f]+ <[^>]+> f2810f59 	vmov\.f32	q0, #6\.25	; 0x40c80000
0[0-9a-f]+ <[^>]+> f2820f59 	vmov\.f32	q0, #12\.5	; 0x41480000
0[0-9a-f]+ <[^>]+> f2830f59 	vmov\.f32	q0, #25	; 0x41c80000
0[0-9a-f]+ <[^>]+> f2840f59 	vmov\.f32	q0, #0\.1953125	; 0x3e480000
0[0-9a-f]+ <[^>]+> f2850f59 	vmov\.f32	q0, #0\.390625	; 0x3ec80000
0[0-9a-f]+ <[^>]+> f2860f59 	vmov\.f32	q0, #0\.78125	; 0x3f480000
0[0-9a-f]+ <[^>]+> f2870f59 	vmov\.f32	q0, #1\.5625	; 0x3fc80000
0[0-9a-f]+ <[^>]+> f2800f5a 	vmov\.f32	q0, #3\.25	; 0x40500000
0[0-9a-f]+ <[^>]+> f2810f5a 	vmov\.f32	q0, #6\.5	; 0x40d00000
0[0-9a-f]+ <[^>]+> f2820f5a 	vmov\.f32	q0, #13	; 0x41500000
0[0-9a-f]+ <[^>]+> f2830f5a 	vmov\.f32	q0, #26	; 0x41d00000
0[0-9a-f]+ <[^>]+> f2840f5a 	vmov\.f32	q0, #0\.203125	; 0x3e500000
0[0-9a-f]+ <[^>]+> f2850f5a 	vmov\.f32	q0, #0\.40625	; 0x3ed00000
0[0-9a-f]+ <[^>]+> f2860f5a 	vmov\.f32	q0, #0\.8125	; 0x3f500000
0[0-9a-f]+ <[^>]+> f2870f5a 	vmov\.f32	q0, #1\.625	; 0x3fd00000
0[0-9a-f]+ <[^>]+> f2800f5b 	vmov\.f32	q0, #3\.375	; 0x40580000
0[0-9a-f]+ <[^>]+> f2810f5b 	vmov\.f32	q0, #6\.75	; 0x40d80000
0[0-9a-f]+ <[^>]+> f2820f5b 	vmov\.f32	q0, #13\.5	; 0x41580000
0[0-9a-f]+ <[^>]+> f2830f5b 	vmov\.f32	q0, #27	; 0x41d80000
0[0-9a-f]+ <[^>]+> f2840f5b 	vmov\.f32	q0, #0\.2109375	; 0x3e580000
0[0-9a-f]+ <[^>]+> f2850f5b 	vmov\.f32	q0, #0\.421875	; 0x3ed80000
0[0-9a-f]+ <[^>]+> f2860f5b 	vmov\.f32	q0, #0\.84375	; 0x3f580000
0[0-9a-f]+ <[^>]+> f2870f5b 	vmov\.f32	q0, #1\.6875	; 0x3fd80000
0[0-9a-f]+ <[^>]+> f2800f5c 	vmov\.f32	q0, #3\.5	; 0x40600000
0[0-9a-f]+ <[^>]+> f2810f5c 	vmov\.f32	q0, #7	; 0x40e00000
0[0-9a-f]+ <[^>]+> f2820f5c 	vmov\.f32	q0, #14	; 0x41600000
0[0-9a-f]+ <[^>]+> f2830f5c 	vmov\.f32	q0, #28	; 0x41e00000
0[0-9a-f]+ <[^>]+> f2840f5c 	vmov\.f32	q0, #0\.21875	; 0x3e600000
0[0-9a-f]+ <[^>]+> f2850f5c 	vmov\.f32	q0, #0\.4375	; 0x3ee00000
0[0-9a-f]+ <[^>]+> f2860f5c 	vmov\.f32	q0, #0\.875	; 0x3f600000
0[0-9a-f]+ <[^>]+> f2870f5c 	vmov\.f32	q0, #1\.75	; 0x3fe00000
0[0-9a-f]+ <[^>]+> f2800f5d 	vmov\.f32	q0, #3\.625	; 0x40680000
0[0-9a-f]+ <[^>]+> f2810f5d 	vmov\.f32	q0, #7\.25	; 0x40e80000
0[0-9a-f]+ <[^>]+> f2820f5d 	vmov\.f32	q0, #14\.5	; 0x41680000
0[0-9a-f]+ <[^>]+> f2830f5d 	vmov\.f32	q0, #29	; 0x41e80000
0[0-9a-f]+ <[^>]+> f2840f5d 	vmov\.f32	q0, #0\.2265625	; 0x3e680000
0[0-9a-f]+ <[^>]+> f2850f5d 	vmov\.f32	q0, #0\.453125	; 0x3ee80000
0[0-9a-f]+ <[^>]+> f2860f5d 	vmov\.f32	q0, #0\.90625	; 0x3f680000
0[0-9a-f]+ <[^>]+> f2870f5d 	vmov\.f32	q0, #1\.8125	; 0x3fe80000
0[0-9a-f]+ <[^>]+> f2800f5e 	vmov\.f32	q0, #3\.75	; 0x40700000
0[0-9a-f]+ <[^>]+> f2810f5e 	vmov\.f32	q0, #7\.5	; 0x40f00000
0[0-9a-f]+ <[^>]+> f2820f5e 	vmov\.f32	q0, #15	; 0x41700000
0[0-9a-f]+ <[^>]+> f2830f5e 	vmov\.f32	q0, #30	; 0x41f00000
0[0-9a-f]+ <[^>]+> f2840f5e 	vmov\.f32	q0, #0\.234375	; 0x3e700000
0[0-9a-f]+ <[^>]+> f2850f5e 	vmov\.f32	q0, #0\.46875	; 0x3ef00000
0[0-9a-f]+ <[^>]+> f2860f5e 	vmov\.f32	q0, #0\.9375	; 0x3f700000
0[0-9a-f]+ <[^>]+> f2870f5e 	vmov\.f32	q0, #1\.875	; 0x3ff00000
0[0-9a-f]+ <[^>]+> f2800f5f 	vmov\.f32	q0, #3\.875	; 0x40780000
0[0-9a-f]+ <[^>]+> f2810f5f 	vmov\.f32	q0, #7\.75	; 0x40f80000
0[0-9a-f]+ <[^>]+> f2820f5f 	vmov\.f32	q0, #15\.5	; 0x41780000
0[0-9a-f]+ <[^>]+> f2830f5f 	vmov\.f32	q0, #31	; 0x41f80000
0[0-9a-f]+ <[^>]+> f2840f5f 	vmov\.f32	q0, #0\.2421875	; 0x3e780000
0[0-9a-f]+ <[^>]+> f2850f5f 	vmov\.f32	q0, #0\.484375	; 0x3ef80000
0[0-9a-f]+ <[^>]+> f2860f5f 	vmov\.f32	q0, #0\.96875	; 0x3f780000
0[0-9a-f]+ <[^>]+> f2870f5f 	vmov\.f32	q0, #1\.9375	; 0x3ff80000
0[0-9a-f]+ <[^>]+> f3800650 	vmov\.i32	q0, #-2147483648	; 0x80000000
0[0-9a-f]+ <[^>]+> f3800f50 	vmov\.f32	q0, #-2	; 0xc0000000
0[0-9a-f]+ <[^>]+> f3810f50 	vmov\.f32	q0, #-4	; 0xc0800000
0[0-9a-f]+ <[^>]+> f3820f50 	vmov\.f32	q0, #-8	; 0xc1000000
0[0-9a-f]+ <[^>]+> f3830f50 	vmov\.f32	q0, #-16	; 0xc1800000
0[0-9a-f]+ <[^>]+> f3840f50 	vmov\.f32	q0, #-0\.125	; 0xbe000000
0[0-9a-f]+ <[^>]+> f3850f50 	vmov\.f32	q0, #-0\.25	; 0xbe800000
0[0-9a-f]+ <[^>]+> f3860f50 	vmov\.f32	q0, #-0\.5	; 0xbf000000
0[0-9a-f]+ <[^>]+> f3870f50 	vmov\.f32	q0, #-1	; 0xbf800000
0[0-9a-f]+ <[^>]+> f3800f51 	vmov\.f32	q0, #-2\.125	; 0xc0080000
0[0-9a-f]+ <[^>]+> f3810f51 	vmov\.f32	q0, #-4\.25	; 0xc0880000
0[0-9a-f]+ <[^>]+> f3820f51 	vmov\.f32	q0, #-8\.5	; 0xc1080000
0[0-9a-f]+ <[^>]+> f3830f51 	vmov\.f32	q0, #-17	; 0xc1880000
0[0-9a-f]+ <[^>]+> f3840f51 	vmov\.f32	q0, #-0\.1328125	; 0xbe080000
0[0-9a-f]+ <[^>]+> f3850f51 	vmov\.f32	q0, #-0\.265625	; 0xbe880000
0[0-9a-f]+ <[^>]+> f3860f51 	vmov\.f32	q0, #-0\.53125	; 0xbf080000
0[0-9a-f]+ <[^>]+> f3870f51 	vmov\.f32	q0, #-1\.0625	; 0xbf880000
0[0-9a-f]+ <[^>]+> f3800f52 	vmov\.f32	q0, #-2\.25	; 0xc0100000
0[0-9a-f]+ <[^>]+> f3810f52 	vmov\.f32	q0, #-4\.5	; 0xc0900000
0[0-9a-f]+ <[^>]+> f3820f52 	vmov\.f32	q0, #-9	; 0xc1100000
0[0-9a-f]+ <[^>]+> f3830f52 	vmov\.f32	q0, #-18	; 0xc1900000
0[0-9a-f]+ <[^>]+> f3840f52 	vmov\.f32	q0, #-0\.140625	; 0xbe100000
0[0-9a-f]+ <[^>]+> f3850f52 	vmov\.f32	q0, #-0\.28125	; 0xbe900000
0[0-9a-f]+ <[^>]+> f3860f52 	vmov\.f32	q0, #-0\.5625	; 0xbf100000
0[0-9a-f]+ <[^>]+> f3870f52 	vmov\.f32	q0, #-1\.125	; 0xbf900000
0[0-9a-f]+ <[^>]+> f3800f53 	vmov\.f32	q0, #-2\.375	; 0xc0180000
0[0-9a-f]+ <[^>]+> f3810f53 	vmov\.f32	q0, #-4\.75	; 0xc0980000
0[0-9a-f]+ <[^>]+> f3820f53 	vmov\.f32	q0, #-9\.5	; 0xc1180000
0[0-9a-f]+ <[^>]+> f3830f53 	vmov\.f32	q0, #-19	; 0xc1980000
0[0-9a-f]+ <[^>]+> f3840f53 	vmov\.f32	q0, #-0\.1484375	; 0xbe180000
0[0-9a-f]+ <[^>]+> f3850f53 	vmov\.f32	q0, #-0\.296875	; 0xbe980000
0[0-9a-f]+ <[^>]+> f3860f53 	vmov\.f32	q0, #-0\.59375	; 0xbf180000
0[0-9a-f]+ <[^>]+> f3870f53 	vmov\.f32	q0, #-1\.1875	; 0xbf980000
0[0-9a-f]+ <[^>]+> f3800f54 	vmov\.f32	q0, #-2\.5	; 0xc0200000
0[0-9a-f]+ <[^>]+> f3810f54 	vmov\.f32	q0, #-5	; 0xc0a00000
0[0-9a-f]+ <[^>]+> f3820f54 	vmov\.f32	q0, #-10	; 0xc1200000
0[0-9a-f]+ <[^>]+> f3830f54 	vmov\.f32	q0, #-20	; 0xc1a00000
0[0-9a-f]+ <[^>]+> f3840f54 	vmov\.f32	q0, #-0\.15625	; 0xbe200000
0[0-9a-f]+ <[^>]+> f3850f54 	vmov\.f32	q0, #-0\.3125	; 0xbea00000
0[0-9a-f]+ <[^>]+> f3860f54 	vmov\.f32	q0, #-0\.625	; 0xbf200000
0[0-9a-f]+ <[^>]+> f3870f54 	vmov\.f32	q0, #-1\.25	; 0xbfa00000
0[0-9a-f]+ <[^>]+> f3800f55 	vmov\.f32	q0, #-2\.625	; 0xc0280000
0[0-9a-f]+ <[^>]+> f3810f55 	vmov\.f32	q0, #-5\.25	; 0xc0a80000
0[0-9a-f]+ <[^>]+> f3820f55 	vmov\.f32	q0, #-10\.5	; 0xc1280000
0[0-9a-f]+ <[^>]+> f3830f55 	vmov\.f32	q0, #-21	; 0xc1a80000
0[0-9a-f]+ <[^>]+> f3840f55 	vmov\.f32	q0, #-0\.1640625	; 0xbe280000
0[0-9a-f]+ <[^>]+> f3850f55 	vmov\.f32	q0, #-0\.328125	; 0xbea80000
0[0-9a-f]+ <[^>]+> f3860f55 	vmov\.f32	q0, #-0\.65625	; 0xbf280000
0[0-9a-f]+ <[^>]+> f3870f55 	vmov\.f32	q0, #-1\.3125	; 0xbfa80000
0[0-9a-f]+ <[^>]+> f3800f56 	vmov\.f32	q0, #-2\.75	; 0xc0300000
0[0-9a-f]+ <[^>]+> f3810f56 	vmov\.f32	q0, #-5\.5	; 0xc0b00000
0[0-9a-f]+ <[^>]+> f3820f56 	vmov\.f32	q0, #-11	; 0xc1300000
0[0-9a-f]+ <[^>]+> f3830f56 	vmov\.f32	q0, #-22	; 0xc1b00000
0[0-9a-f]+ <[^>]+> f3840f56 	vmov\.f32	q0, #-0\.171875	; 0xbe300000
0[0-9a-f]+ <[^>]+> f3850f56 	vmov\.f32	q0, #-0\.34375	; 0xbeb00000
0[0-9a-f]+ <[^>]+> f3860f56 	vmov\.f32	q0, #-0\.6875	; 0xbf300000
0[0-9a-f]+ <[^>]+> f3870f56 	vmov\.f32	q0, #-1\.375	; 0xbfb00000
0[0-9a-f]+ <[^>]+> f3800f57 	vmov\.f32	q0, #-2\.875	; 0xc0380000
0[0-9a-f]+ <[^>]+> f3810f57 	vmov\.f32	q0, #-5\.75	; 0xc0b80000
0[0-9a-f]+ <[^>]+> f3820f57 	vmov\.f32	q0, #-11\.5	; 0xc1380000
0[0-9a-f]+ <[^>]+> f3830f57 	vmov\.f32	q0, #-23	; 0xc1b80000
0[0-9a-f]+ <[^>]+> f3840f57 	vmov\.f32	q0, #-0\.1796875	; 0xbe380000
0[0-9a-f]+ <[^>]+> f3850f57 	vmov\.f32	q0, #-0\.359375	; 0xbeb80000
0[0-9a-f]+ <[^>]+> f3860f57 	vmov\.f32	q0, #-0\.71875	; 0xbf380000
0[0-9a-f]+ <[^>]+> f3870f57 	vmov\.f32	q0, #-1\.4375	; 0xbfb80000
0[0-9a-f]+ <[^>]+> f3800f58 	vmov\.f32	q0, #-3	; 0xc0400000
0[0-9a-f]+ <[^>]+> f3810f58 	vmov\.f32	q0, #-6	; 0xc0c00000
0[0-9a-f]+ <[^>]+> f3820f58 	vmov\.f32	q0, #-12	; 0xc1400000
0[0-9a-f]+ <[^>]+> f3830f58 	vmov\.f32	q0, #-24	; 0xc1c00000
0[0-9a-f]+ <[^>]+> f3840f58 	vmov\.f32	q0, #-0\.1875	; 0xbe400000
0[0-9a-f]+ <[^>]+> f3850f58 	vmov\.f32	q0, #-0\.375	; 0xbec00000
0[0-9a-f]+ <[^>]+> f3860f58 	vmov\.f32	q0, #-0\.75	; 0xbf400000
0[0-9a-f]+ <[^>]+> f3870f58 	vmov\.f32	q0, #-1\.5	; 0xbfc00000
0[0-9a-f]+ <[^>]+> f3800f59 	vmov\.f32	q0, #-3\.125	; 0xc0480000
0[0-9a-f]+ <[^>]+> f3810f59 	vmov\.f32	q0, #-6\.25	; 0xc0c80000
0[0-9a-f]+ <[^>]+> f3820f59 	vmov\.f32	q0, #-12\.5	; 0xc1480000
0[0-9a-f]+ <[^>]+> f3830f59 	vmov\.f32	q0, #-25	; 0xc1c80000
0[0-9a-f]+ <[^>]+> f3840f59 	vmov\.f32	q0, #-0\.1953125	; 0xbe480000
0[0-9a-f]+ <[^>]+> f3850f59 	vmov\.f32	q0, #-0\.390625	; 0xbec80000
0[0-9a-f]+ <[^>]+> f3860f59 	vmov\.f32	q0, #-0\.78125	; 0xbf480000
0[0-9a-f]+ <[^>]+> f3870f59 	vmov\.f32	q0, #-1\.5625	; 0xbfc80000
0[0-9a-f]+ <[^>]+> f3800f5a 	vmov\.f32	q0, #-3\.25	; 0xc0500000
0[0-9a-f]+ <[^>]+> f3810f5a 	vmov\.f32	q0, #-6\.5	; 0xc0d00000
0[0-9a-f]+ <[^>]+> f3820f5a 	vmov\.f32	q0, #-13	; 0xc1500000
0[0-9a-f]+ <[^>]+> f3830f5a 	vmov\.f32	q0, #-26	; 0xc1d00000
0[0-9a-f]+ <[^>]+> f3840f5a 	vmov\.f32	q0, #-0\.203125	; 0xbe500000
0[0-9a-f]+ <[^>]+> f3850f5a 	vmov\.f32	q0, #-0\.40625	; 0xbed00000
0[0-9a-f]+ <[^>]+> f3860f5a 	vmov\.f32	q0, #-0\.8125	; 0xbf500000
0[0-9a-f]+ <[^>]+> f3870f5a 	vmov\.f32	q0, #-1\.625	; 0xbfd00000
0[0-9a-f]+ <[^>]+> f3800f5b 	vmov\.f32	q0, #-3\.375	; 0xc0580000
0[0-9a-f]+ <[^>]+> f3810f5b 	vmov\.f32	q0, #-6\.75	; 0xc0d80000
0[0-9a-f]+ <[^>]+> f3820f5b 	vmov\.f32	q0, #-13\.5	; 0xc1580000
0[0-9a-f]+ <[^>]+> f3830f5b 	vmov\.f32	q0, #-27	; 0xc1d80000
0[0-9a-f]+ <[^>]+> f3840f5b 	vmov\.f32	q0, #-0\.2109375	; 0xbe580000
0[0-9a-f]+ <[^>]+> f3850f5b 	vmov\.f32	q0, #-0\.421875	; 0xbed80000
0[0-9a-f]+ <[^>]+> f3860f5b 	vmov\.f32	q0, #-0\.84375	; 0xbf580000
0[0-9a-f]+ <[^>]+> f3870f5b 	vmov\.f32	q0, #-1\.6875	; 0xbfd80000
0[0-9a-f]+ <[^>]+> f3800f5c 	vmov\.f32	q0, #-3\.5	; 0xc0600000
0[0-9a-f]+ <[^>]+> f3810f5c 	vmov\.f32	q0, #-7	; 0xc0e00000
0[0-9a-f]+ <[^>]+> f3820f5c 	vmov\.f32	q0, #-14	; 0xc1600000
0[0-9a-f]+ <[^>]+> f3830f5c 	vmov\.f32	q0, #-28	; 0xc1e00000
0[0-9a-f]+ <[^>]+> f3840f5c 	vmov\.f32	q0, #-0\.21875	; 0xbe600000
0[0-9a-f]+ <[^>]+> f3850f5c 	vmov\.f32	q0, #-0\.4375	; 0xbee00000
0[0-9a-f]+ <[^>]+> f3860f5c 	vmov\.f32	q0, #-0\.875	; 0xbf600000
0[0-9a-f]+ <[^>]+> f3870f5c 	vmov\.f32	q0, #-1\.75	; 0xbfe00000
0[0-9a-f]+ <[^>]+> f3800f5d 	vmov\.f32	q0, #-3\.625	; 0xc0680000
0[0-9a-f]+ <[^>]+> f3810f5d 	vmov\.f32	q0, #-7\.25	; 0xc0e80000
0[0-9a-f]+ <[^>]+> f3820f5d 	vmov\.f32	q0, #-14\.5	; 0xc1680000
0[0-9a-f]+ <[^>]+> f3830f5d 	vmov\.f32	q0, #-29	; 0xc1e80000
0[0-9a-f]+ <[^>]+> f3840f5d 	vmov\.f32	q0, #-0\.2265625	; 0xbe680000
0[0-9a-f]+ <[^>]+> f3850f5d 	vmov\.f32	q0, #-0\.453125	; 0xbee80000
0[0-9a-f]+ <[^>]+> f3860f5d 	vmov\.f32	q0, #-0\.90625	; 0xbf680000
0[0-9a-f]+ <[^>]+> f3870f5d 	vmov\.f32	q0, #-1\.8125	; 0xbfe80000
0[0-9a-f]+ <[^>]+> f3800f5e 	vmov\.f32	q0, #-3\.75	; 0xc0700000
0[0-9a-f]+ <[^>]+> f3810f5e 	vmov\.f32	q0, #-7\.5	; 0xc0f00000
0[0-9a-f]+ <[^>]+> f3820f5e 	vmov\.f32	q0, #-15	; 0xc1700000
0[0-9a-f]+ <[^>]+> f3830f5e 	vmov\.f32	q0, #-30	; 0xc1f00000
0[0-9a-f]+ <[^>]+> f3840f5e 	vmov\.f32	q0, #-0\.234375	; 0xbe700000
0[0-9a-f]+ <[^>]+> f3850f5e 	vmov\.f32	q0, #-0\.46875	; 0xbef00000
0[0-9a-f]+ <[^>]+> f3860f5e 	vmov\.f32	q0, #-0\.9375	; 0xbf700000
0[0-9a-f]+ <[^>]+> f3870f5e 	vmov\.f32	q0, #-1\.875	; 0xbff00000
0[0-9a-f]+ <[^>]+> f3800f5f 	vmov\.f32	q0, #-3\.875	; 0xc0780000
0[0-9a-f]+ <[^>]+> f3810f5f 	vmov\.f32	q0, #-7\.75	; 0xc0f80000
0[0-9a-f]+ <[^>]+> f3820f5f 	vmov\.f32	q0, #-15\.5	; 0xc1780000
0[0-9a-f]+ <[^>]+> f3830f5f 	vmov\.f32	q0, #-31	; 0xc1f80000
0[0-9a-f]+ <[^>]+> f3840f5f 	vmov\.f32	q0, #-0\.2421875	; 0xbe780000
0[0-9a-f]+ <[^>]+> f3850f5f 	vmov\.f32	q0, #-0\.484375	; 0xbef80000
0[0-9a-f]+ <[^>]+> f3860f5f 	vmov\.f32	q0, #-0\.96875	; 0xbf780000
0[0-9a-f]+ <[^>]+> f3870f5f 	vmov\.f32	q0, #-1\.9375	; 0xbff80000
0[0-9a-f]+ <[^>]+> f3879e3f 	vmov\.i64	d9, #0xffffffffffffffff
