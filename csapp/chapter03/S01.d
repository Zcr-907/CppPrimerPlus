
S01:	file format mach-o 64-bit x86-64

Disassembly of section __TEXT,__text:

0000000100003f70 <_main>:
100003f70: 55                          	pushq	%rbp
100003f71: 48 89 e5                    	movq	%rsp, %rbp
100003f74: 31 c0                       	xorl	%eax, %eax
100003f76: 5d                          	popq	%rbp
100003f77: c3                          	retq
100003f78: 0f 1f 84 00 00 00 00 00     	nopl	(%rax,%rax)

0000000100003f80 <__Z5lab01llPl>:
100003f80: 55                          	pushq	%rbp
100003f81: 48 89 e5                    	movq	%rsp, %rbp
100003f84: 53                          	pushq	%rbx
100003f85: 50                          	pushq	%rax
100003f86: 48 89 d3                    	movq	%rdx, %rbx
100003f89: e8 12 00 00 00              	callq	0x100003fa0 <__Z4plusll>
100003f8e: 48 89 03                    	movq	%rax, (%rbx)
100003f91: 48 83 c4 08                 	addq	$8, %rsp
100003f95: 5b                          	popq	%rbx
100003f96: 5d                          	popq	%rbp
100003f97: c3                          	retq
100003f98: 0f 1f 84 00 00 00 00 00     	nopl	(%rax,%rax)

0000000100003fa0 <__Z4plusll>:
100003fa0: 55                          	pushq	%rbp
100003fa1: 48 89 e5                    	movq	%rsp, %rbp
100003fa4: 48 8d 04 37                 	leaq	(%rdi,%rsi), %rax
100003fa8: 5d                          	popq	%rbp
100003fa9: c3                          	retq
