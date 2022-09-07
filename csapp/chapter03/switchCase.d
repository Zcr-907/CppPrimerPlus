
switchCase:	file format mach-o 64-bit x86-64

Disassembly of section __TEXT,__text:

0000000100003f70 <__Z9switchLabi>:
100003f70: 83 c7 9c                    	addl	$-100, %edi
100003f73: b8 fe ff ff ff              	movl	$4294967294, %eax       ## imm = 0xFFFFFFFE
100003f78: 83 ff 05                    	cmpl	$5, %edi
100003f7b: 77 12                       	ja	0x100003f8f <__Z9switchLabi+0x1f>
100003f7d: 55                          	pushq	%rbp
100003f7e: 48 89 e5                    	movq	%rsp, %rbp
100003f81: 48 63 c7                    	movslq	%edi, %rax
100003f84: 48 8d 0d 0d 00 00 00        	leaq	13(%rip), %rcx          ## 0x100003f98 <dyld_stub_binder+0x100003f98>
100003f8b: 8b 04 81                    	movl	(%rcx,%rax,4), %eax
100003f8e: 5d                          	popq	%rbp
100003f8f: c3                          	retq

0000000100003f90 <_main>:
100003f90: 55                          	pushq	%rbp
100003f91: 48 89 e5                    	movq	%rsp, %rbp
100003f94: 31 c0                       	xorl	%eax, %eax
100003f96: 5d                          	popq	%rbp
100003f97: c3                          	retq
