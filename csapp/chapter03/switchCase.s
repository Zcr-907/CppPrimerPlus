	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	__Z9switchLabi                  ## -- Begin function _Z9switchLabi
	.p2align	4, 0x90
__Z9switchLabi:                         ## @_Z9switchLabi
	.cfi_startproc
## %bb.0:
	addl	$-100, %edi
	movl	$-2, %eax
	cmpl	$5, %edi
	ja	LBB0_2
## %bb.1:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movslq	%edi, %rax
	leaq	l_switch.table._Z9switchLabi(%rip), %rcx
	movl	(%rcx,%rax,4), %eax
	popq	%rbp
LBB0_2:
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__const
	.p2align	2                               ## @switch.table._Z9switchLabi
l_switch.table._Z9switchLabi:
	.long	0                               ## 0x0
	.long	1                               ## 0x1
	.long	3                               ## 0x3
	.long	4294967294                      ## 0xfffffffe
	.long	4294967294                      ## 0xfffffffe
	.long	3                               ## 0x3

.subsections_via_symbols
