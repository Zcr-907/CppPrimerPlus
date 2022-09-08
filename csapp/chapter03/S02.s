
__Z9mallocArgi:                         ## @_Z9mallocArgi
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	callq	__Z9plusParami
	popq	%rbp
	retq
__Z9plusParami:                         ## @_Z9plusParami
## %bb.0:
	pushq	%rbp
	movq	%rsp, %rbp
	leal	1(%rdi), %eax
	popq	%rbp
	retq
