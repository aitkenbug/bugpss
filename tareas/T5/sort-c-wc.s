	.file	"sort-c-wc.c"
	.option nopic
	.attribute arch, "rv32i2p0_m2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	strCmp
	.type	strCmp, @function
strCmp:
	lbu	a5,0(a0)
	lbu	a4,0(a1)
	beq	a5,zero,.L2
.L3:
	bne	a5,a4,.L2
	addi	a0,a0,1
	addi	a1,a1,1
	lbu	a5,0(a0)
	lbu	a4,0(a1)
	bne	a5,zero,.L3
.L2:
	sub	a0,a5,a4
	ret
	.size	strCmp, .-strCmp
	.align	2
	.globl	contarPal
	.type	contarPal, @function
contarPal:
	addi	sp,sp,-16
	sw	ra,12(sp)
	sw	s0,8(sp)
	sw	s1,4(sp)
	lbu	s0,0(a0)
	beq	s0,zero,.L10
	mv	s1,a0
	addi	s0,s0,-32
	snez	s0,s0
	call	strlen
	mv	a5,s1
	add	a0,s1,a0
	li	a3,32
	j	.L7
.L12:
	lbu	a4,-1(a5)
	sub	a4,a4,a3
	seqz	a4,a4
	add	s0,s0,a4
.L8:
	addi	a5,a5,1
.L7:
	beq	a5,a0,.L5
	lbu	a4,0(a5)
	bne	a4,a3,.L12
	j	.L8
.L10:
	li	s0,0
.L5:
	mv	a0,s0
	lw	ra,12(sp)
	lw	s0,8(sp)
	lw	s1,4(sp)
	addi	sp,sp,16
	jr	ra
	.size	contarPal, .-contarPal
	.align	2
	.globl	sort
	.type	sort, @function
sort:
	addi	sp,sp,-32
	sw	ra,28(sp)
	sw	s0,24(sp)
	sw	s1,20(sp)
	sw	s2,16(sp)
	sw	s3,12(sp)
	sw	s4,8(sp)
	sw	s5,4(sp)
	slli	s4,a1,2
	addi	s4,s4,-4
	add	s4,a0,s4
	bgeu	a0,s4,.L13
	mv	s5,a0
	mv	s0,a0
	j	.L17
.L15:
	sw	s3,0(s0)
	sw	s2,4(s0)
	mv	s0,s5
.L17:
	lw	s2,0(s0)
	mv	a0,s2
	call	contarPal
	mv	s1,a0
	lw	s3,4(s0)
	mv	a0,s3
	call	contarPal
	bgt	s1,a0,.L15
	addi	s0,s0,4
	bgtu	s4,s0,.L17
.L13:
	lw	ra,28(sp)
	lw	s0,24(sp)
	lw	s1,20(sp)
	lw	s2,16(sp)
	lw	s3,12(sp)
	lw	s4,8(sp)
	lw	s5,4(sp)
	addi	sp,sp,32
	jr	ra
	.size	sort, .-sort
	.ident	"GCC: (GNU) 11.1.0"
