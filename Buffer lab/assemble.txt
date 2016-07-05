
bufbomb：     文件格式 elf32-i386


Disassembly of section .init:

080487e4 <_init>:
 80487e4:	53                   	push   %ebx
 80487e5:	83 ec 08             	sub    $0x8,%esp
 80487e8:	e8 00 00 00 00       	call   80487ed <_init+0x9>
 80487ed:	5b                   	pop    %ebx
 80487ee:	81 c3 07 38 00 00    	add    $0x3807,%ebx
 80487f4:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 80487fa:	85 c0                	test   %eax,%eax
 80487fc:	74 05                	je     8048803 <_init+0x1f>
 80487fe:	e8 ed 00 00 00       	call   80488f0 <__gmon_start__@plt>
 8048803:	83 c4 08             	add    $0x8,%esp
 8048806:	5b                   	pop    %ebx
 8048807:	c3                   	ret    

Disassembly of section .plt:

08048810 <read@plt-0x10>:
 8048810:	ff 35 f8 bf 04 08    	pushl  0x804bff8
 8048816:	ff 25 fc bf 04 08    	jmp    *0x804bffc
 804881c:	00 00                	add    %al,(%eax)
	...

08048820 <read@plt>:
 8048820:	ff 25 00 c0 04 08    	jmp    *0x804c000
 8048826:	68 00 00 00 00       	push   $0x0
 804882b:	e9 e0 ff ff ff       	jmp    8048810 <_init+0x2c>

08048830 <srandom@plt>:
 8048830:	ff 25 04 c0 04 08    	jmp    *0x804c004
 8048836:	68 08 00 00 00       	push   $0x8
 804883b:	e9 d0 ff ff ff       	jmp    8048810 <_init+0x2c>

08048840 <signal@plt>:
 8048840:	ff 25 08 c0 04 08    	jmp    *0x804c008
 8048846:	68 10 00 00 00       	push   $0x10
 804884b:	e9 c0 ff ff ff       	jmp    8048810 <_init+0x2c>

08048850 <alarm@plt>:
 8048850:	ff 25 0c c0 04 08    	jmp    *0x804c00c
 8048856:	68 18 00 00 00       	push   $0x18
 804885b:	e9 b0 ff ff ff       	jmp    8048810 <_init+0x2c>

08048860 <__stack_chk_fail@plt>:
 8048860:	ff 25 10 c0 04 08    	jmp    *0x804c010
 8048866:	68 20 00 00 00       	push   $0x20
 804886b:	e9 a0 ff ff ff       	jmp    8048810 <_init+0x2c>

08048870 <_IO_getc@plt>:
 8048870:	ff 25 14 c0 04 08    	jmp    *0x804c014
 8048876:	68 28 00 00 00       	push   $0x28
 804887b:	e9 90 ff ff ff       	jmp    8048810 <_init+0x2c>

08048880 <fwrite@plt>:
 8048880:	ff 25 18 c0 04 08    	jmp    *0x804c018
 8048886:	68 30 00 00 00       	push   $0x30
 804888b:	e9 80 ff ff ff       	jmp    8048810 <_init+0x2c>

08048890 <strcpy@plt>:
 8048890:	ff 25 1c c0 04 08    	jmp    *0x804c01c
 8048896:	68 38 00 00 00       	push   $0x38
 804889b:	e9 70 ff ff ff       	jmp    8048810 <_init+0x2c>

080488a0 <getpid@plt>:
 80488a0:	ff 25 20 c0 04 08    	jmp    *0x804c020
 80488a6:	68 40 00 00 00       	push   $0x40
 80488ab:	e9 60 ff ff ff       	jmp    8048810 <_init+0x2c>

080488b0 <gethostname@plt>:
 80488b0:	ff 25 24 c0 04 08    	jmp    *0x804c024
 80488b6:	68 48 00 00 00       	push   $0x48
 80488bb:	e9 50 ff ff ff       	jmp    8048810 <_init+0x2c>

080488c0 <puts@plt>:
 80488c0:	ff 25 28 c0 04 08    	jmp    *0x804c028
 80488c6:	68 50 00 00 00       	push   $0x50
 80488cb:	e9 40 ff ff ff       	jmp    8048810 <_init+0x2c>

080488d0 <__memmove_chk@plt>:
 80488d0:	ff 25 2c c0 04 08    	jmp    *0x804c02c
 80488d6:	68 58 00 00 00       	push   $0x58
 80488db:	e9 30 ff ff ff       	jmp    8048810 <_init+0x2c>

080488e0 <__memcpy_chk@plt>:
 80488e0:	ff 25 30 c0 04 08    	jmp    *0x804c030
 80488e6:	68 60 00 00 00       	push   $0x60
 80488eb:	e9 20 ff ff ff       	jmp    8048810 <_init+0x2c>

080488f0 <__gmon_start__@plt>:
 80488f0:	ff 25 34 c0 04 08    	jmp    *0x804c034
 80488f6:	68 68 00 00 00       	push   $0x68
 80488fb:	e9 10 ff ff ff       	jmp    8048810 <_init+0x2c>

08048900 <exit@plt>:
 8048900:	ff 25 38 c0 04 08    	jmp    *0x804c038
 8048906:	68 70 00 00 00       	push   $0x70
 804890b:	e9 00 ff ff ff       	jmp    8048810 <_init+0x2c>

08048910 <srand@plt>:
 8048910:	ff 25 3c c0 04 08    	jmp    *0x804c03c
 8048916:	68 78 00 00 00       	push   $0x78
 804891b:	e9 f0 fe ff ff       	jmp    8048810 <_init+0x2c>

08048920 <mmap@plt>:
 8048920:	ff 25 40 c0 04 08    	jmp    *0x804c040
 8048926:	68 80 00 00 00       	push   $0x80
 804892b:	e9 e0 fe ff ff       	jmp    8048810 <_init+0x2c>

08048930 <__libc_start_main@plt>:
 8048930:	ff 25 44 c0 04 08    	jmp    *0x804c044
 8048936:	68 88 00 00 00       	push   $0x88
 804893b:	e9 d0 fe ff ff       	jmp    8048810 <_init+0x2c>

08048940 <write@plt>:
 8048940:	ff 25 48 c0 04 08    	jmp    *0x804c048
 8048946:	68 90 00 00 00       	push   $0x90
 804894b:	e9 c0 fe ff ff       	jmp    8048810 <_init+0x2c>

08048950 <getopt@plt>:
 8048950:	ff 25 4c c0 04 08    	jmp    *0x804c04c
 8048956:	68 98 00 00 00       	push   $0x98
 804895b:	e9 b0 fe ff ff       	jmp    8048810 <_init+0x2c>

08048960 <strcasecmp@plt>:
 8048960:	ff 25 50 c0 04 08    	jmp    *0x804c050
 8048966:	68 a0 00 00 00       	push   $0xa0
 804896b:	e9 a0 fe ff ff       	jmp    8048810 <_init+0x2c>

08048970 <__isoc99_sscanf@plt>:
 8048970:	ff 25 54 c0 04 08    	jmp    *0x804c054
 8048976:	68 a8 00 00 00       	push   $0xa8
 804897b:	e9 90 fe ff ff       	jmp    8048810 <_init+0x2c>

08048980 <memset@plt>:
 8048980:	ff 25 58 c0 04 08    	jmp    *0x804c058
 8048986:	68 b0 00 00 00       	push   $0xb0
 804898b:	e9 80 fe ff ff       	jmp    8048810 <_init+0x2c>

08048990 <__strdup@plt>:
 8048990:	ff 25 5c c0 04 08    	jmp    *0x804c05c
 8048996:	68 b8 00 00 00       	push   $0xb8
 804899b:	e9 70 fe ff ff       	jmp    8048810 <_init+0x2c>

080489a0 <__errno_location@plt>:
 80489a0:	ff 25 60 c0 04 08    	jmp    *0x804c060
 80489a6:	68 c0 00 00 00       	push   $0xc0
 80489ab:	e9 60 fe ff ff       	jmp    8048810 <_init+0x2c>

080489b0 <rand@plt>:
 80489b0:	ff 25 64 c0 04 08    	jmp    *0x804c064
 80489b6:	68 c8 00 00 00       	push   $0xc8
 80489bb:	e9 50 fe ff ff       	jmp    8048810 <_init+0x2c>

080489c0 <__printf_chk@plt>:
 80489c0:	ff 25 68 c0 04 08    	jmp    *0x804c068
 80489c6:	68 d0 00 00 00       	push   $0xd0
 80489cb:	e9 40 fe ff ff       	jmp    8048810 <_init+0x2c>

080489d0 <munmap@plt>:
 80489d0:	ff 25 6c c0 04 08    	jmp    *0x804c06c
 80489d6:	68 d8 00 00 00       	push   $0xd8
 80489db:	e9 30 fe ff ff       	jmp    8048810 <_init+0x2c>

080489e0 <socket@plt>:
 80489e0:	ff 25 70 c0 04 08    	jmp    *0x804c070
 80489e6:	68 e0 00 00 00       	push   $0xe0
 80489eb:	e9 20 fe ff ff       	jmp    8048810 <_init+0x2c>

080489f0 <random@plt>:
 80489f0:	ff 25 74 c0 04 08    	jmp    *0x804c074
 80489f6:	68 e8 00 00 00       	push   $0xe8
 80489fb:	e9 10 fe ff ff       	jmp    8048810 <_init+0x2c>

08048a00 <gethostbyname@plt>:
 8048a00:	ff 25 78 c0 04 08    	jmp    *0x804c078
 8048a06:	68 f0 00 00 00       	push   $0xf0
 8048a0b:	e9 00 fe ff ff       	jmp    8048810 <_init+0x2c>

08048a10 <connect@plt>:
 8048a10:	ff 25 7c c0 04 08    	jmp    *0x804c07c
 8048a16:	68 f8 00 00 00       	push   $0xf8
 8048a1b:	e9 f0 fd ff ff       	jmp    8048810 <_init+0x2c>

08048a20 <close@plt>:
 8048a20:	ff 25 80 c0 04 08    	jmp    *0x804c080
 8048a26:	68 00 01 00 00       	push   $0x100
 8048a2b:	e9 e0 fd ff ff       	jmp    8048810 <_init+0x2c>

08048a30 <calloc@plt>:
 8048a30:	ff 25 84 c0 04 08    	jmp    *0x804c084
 8048a36:	68 08 01 00 00       	push   $0x108
 8048a3b:	e9 d0 fd ff ff       	jmp    8048810 <_init+0x2c>

08048a40 <__sprintf_chk@plt>:
 8048a40:	ff 25 88 c0 04 08    	jmp    *0x804c088
 8048a46:	68 10 01 00 00       	push   $0x110
 8048a4b:	e9 c0 fd ff ff       	jmp    8048810 <_init+0x2c>

Disassembly of section .text:

08048a50 <_start>:
 8048a50:	31 ed                	xor    %ebp,%ebp
 8048a52:	5e                   	pop    %esi
 8048a53:	89 e1                	mov    %esp,%ecx
 8048a55:	83 e4 f0             	and    $0xfffffff0,%esp
 8048a58:	50                   	push   %eax
 8048a59:	54                   	push   %esp
 8048a5a:	52                   	push   %edx
 8048a5b:	68 40 a2 04 08       	push   $0x804a240
 8048a60:	68 d0 a1 04 08       	push   $0x804a1d0
 8048a65:	51                   	push   %ecx
 8048a66:	56                   	push   %esi
 8048a67:	68 06 90 04 08       	push   $0x8049006
 8048a6c:	e8 bf fe ff ff       	call   8048930 <__libc_start_main@plt>
 8048a71:	f4                   	hlt    
 8048a72:	90                   	nop
 8048a73:	90                   	nop
 8048a74:	90                   	nop
 8048a75:	90                   	nop
 8048a76:	90                   	nop
 8048a77:	90                   	nop
 8048a78:	90                   	nop
 8048a79:	90                   	nop
 8048a7a:	90                   	nop
 8048a7b:	90                   	nop
 8048a7c:	90                   	nop
 8048a7d:	90                   	nop
 8048a7e:	90                   	nop
 8048a7f:	90                   	nop

08048a80 <deregister_tm_clones>:
 8048a80:	b8 e3 d0 04 08       	mov    $0x804d0e3,%eax
 8048a85:	2d e0 d0 04 08       	sub    $0x804d0e0,%eax
 8048a8a:	83 f8 06             	cmp    $0x6,%eax
 8048a8d:	77 01                	ja     8048a90 <deregister_tm_clones+0x10>
 8048a8f:	c3                   	ret    
 8048a90:	b8 00 00 00 00       	mov    $0x0,%eax
 8048a95:	85 c0                	test   %eax,%eax
 8048a97:	74 f6                	je     8048a8f <deregister_tm_clones+0xf>
 8048a99:	55                   	push   %ebp
 8048a9a:	89 e5                	mov    %esp,%ebp
 8048a9c:	83 ec 18             	sub    $0x18,%esp
 8048a9f:	c7 04 24 e0 d0 04 08 	movl   $0x804d0e0,(%esp)
 8048aa6:	ff d0                	call   *%eax
 8048aa8:	c9                   	leave  
 8048aa9:	c3                   	ret    
 8048aaa:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi

08048ab0 <register_tm_clones>:
 8048ab0:	b8 e0 d0 04 08       	mov    $0x804d0e0,%eax
 8048ab5:	2d e0 d0 04 08       	sub    $0x804d0e0,%eax
 8048aba:	c1 f8 02             	sar    $0x2,%eax
 8048abd:	89 c2                	mov    %eax,%edx
 8048abf:	c1 ea 1f             	shr    $0x1f,%edx
 8048ac2:	01 d0                	add    %edx,%eax
 8048ac4:	d1 f8                	sar    %eax
 8048ac6:	75 01                	jne    8048ac9 <register_tm_clones+0x19>
 8048ac8:	c3                   	ret    
 8048ac9:	ba 00 00 00 00       	mov    $0x0,%edx
 8048ace:	85 d2                	test   %edx,%edx
 8048ad0:	74 f6                	je     8048ac8 <register_tm_clones+0x18>
 8048ad2:	55                   	push   %ebp
 8048ad3:	89 e5                	mov    %esp,%ebp
 8048ad5:	83 ec 18             	sub    $0x18,%esp
 8048ad8:	89 44 24 04          	mov    %eax,0x4(%esp)
 8048adc:	c7 04 24 e0 d0 04 08 	movl   $0x804d0e0,(%esp)
 8048ae3:	ff d2                	call   *%edx
 8048ae5:	c9                   	leave  
 8048ae6:	c3                   	ret    
 8048ae7:	89 f6                	mov    %esi,%esi
 8048ae9:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

08048af0 <__do_global_dtors_aux>:
 8048af0:	80 3d ec d0 04 08 00 	cmpb   $0x0,0x804d0ec
 8048af7:	75 13                	jne    8048b0c <__do_global_dtors_aux+0x1c>
 8048af9:	55                   	push   %ebp
 8048afa:	89 e5                	mov    %esp,%ebp
 8048afc:	83 ec 08             	sub    $0x8,%esp
 8048aff:	e8 7c ff ff ff       	call   8048a80 <deregister_tm_clones>
 8048b04:	c6 05 ec d0 04 08 01 	movb   $0x1,0x804d0ec
 8048b0b:	c9                   	leave  
 8048b0c:	f3 c3                	repz ret 
 8048b0e:	66 90                	xchg   %ax,%ax

08048b10 <frame_dummy>:
 8048b10:	a1 04 bf 04 08       	mov    0x804bf04,%eax
 8048b15:	85 c0                	test   %eax,%eax
 8048b17:	74 1f                	je     8048b38 <frame_dummy+0x28>
 8048b19:	b8 00 00 00 00       	mov    $0x0,%eax
 8048b1e:	85 c0                	test   %eax,%eax
 8048b20:	74 16                	je     8048b38 <frame_dummy+0x28>
 8048b22:	55                   	push   %ebp
 8048b23:	89 e5                	mov    %esp,%ebp
 8048b25:	83 ec 18             	sub    $0x18,%esp
 8048b28:	c7 04 24 04 bf 04 08 	movl   $0x804bf04,(%esp)
 8048b2f:	ff d0                	call   *%eax
 8048b31:	c9                   	leave  
 8048b32:	e9 79 ff ff ff       	jmp    8048ab0 <register_tm_clones>
 8048b37:	90                   	nop
 8048b38:	e9 73 ff ff ff       	jmp    8048ab0 <register_tm_clones>
 8048b3d:	90                   	nop
 8048b3e:	90                   	nop
 8048b3f:	90                   	nop

08048b40 <bushandler>:
 8048b40:	55                   	push   %ebp
 8048b41:	89 e5                	mov    %esp,%ebp
 8048b43:	83 ec 18             	sub    $0x18,%esp
 8048b46:	c7 04 24 68 a2 04 08 	movl   $0x804a268,(%esp)
 8048b4d:	e8 6e fd ff ff       	call   80488c0 <puts@plt>
 8048b52:	c7 04 24 70 a4 04 08 	movl   $0x804a470,(%esp)
 8048b59:	e8 62 fd ff ff       	call   80488c0 <puts@plt>
 8048b5e:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048b65:	e8 96 fd ff ff       	call   8048900 <exit@plt>

08048b6a <seghandler>:
 8048b6a:	55                   	push   %ebp
 8048b6b:	89 e5                	mov    %esp,%ebp
 8048b6d:	83 ec 18             	sub    $0x18,%esp
 8048b70:	c7 04 24 88 a2 04 08 	movl   $0x804a288,(%esp)
 8048b77:	e8 44 fd ff ff       	call   80488c0 <puts@plt>
 8048b7c:	c7 04 24 70 a4 04 08 	movl   $0x804a470,(%esp)
 8048b83:	e8 38 fd ff ff       	call   80488c0 <puts@plt>
 8048b88:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048b8f:	e8 6c fd ff ff       	call   8048900 <exit@plt>

08048b94 <illegalhandler>:
 8048b94:	55                   	push   %ebp
 8048b95:	89 e5                	mov    %esp,%ebp
 8048b97:	83 ec 18             	sub    $0x18,%esp
 8048b9a:	c7 04 24 b0 a2 04 08 	movl   $0x804a2b0,(%esp)
 8048ba1:	e8 1a fd ff ff       	call   80488c0 <puts@plt>
 8048ba6:	c7 04 24 70 a4 04 08 	movl   $0x804a470,(%esp)
 8048bad:	e8 0e fd ff ff       	call   80488c0 <puts@plt>
 8048bb2:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048bb9:	e8 42 fd ff ff       	call   8048900 <exit@plt>

08048bbe <usage>:
 8048bbe:	55                   	push   %ebp
 8048bbf:	89 e5                	mov    %esp,%ebp
 8048bc1:	83 ec 18             	sub    $0x18,%esp
 8048bc4:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048bc8:	c7 44 24 04 86 a4 04 	movl   $0x804a486,0x4(%esp)
 8048bcf:	08 
 8048bd0:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048bd7:	e8 e4 fd ff ff       	call   80489c0 <__printf_chk@plt>
 8048bdc:	c7 04 24 a4 a4 04 08 	movl   $0x804a4a4,(%esp)
 8048be3:	e8 d8 fc ff ff       	call   80488c0 <puts@plt>
 8048be8:	c7 04 24 ba a4 04 08 	movl   $0x804a4ba,(%esp)
 8048bef:	e8 cc fc ff ff       	call   80488c0 <puts@plt>
 8048bf4:	c7 04 24 dc a2 04 08 	movl   $0x804a2dc,(%esp)
 8048bfb:	e8 c0 fc ff ff       	call   80488c0 <puts@plt>
 8048c00:	c7 04 24 18 a3 04 08 	movl   $0x804a318,(%esp)
 8048c07:	e8 b4 fc ff ff       	call   80488c0 <puts@plt>
 8048c0c:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048c13:	e8 e8 fc ff ff       	call   8048900 <exit@plt>

08048c18 <smoke>:
 8048c18:	55                   	push   %ebp
 8048c19:	89 e5                	mov    %esp,%ebp
 8048c1b:	83 ec 18             	sub    $0x18,%esp
 8048c1e:	c7 04 24 d3 a4 04 08 	movl   $0x804a4d3,(%esp)
 8048c25:	e8 96 fc ff ff       	call   80488c0 <puts@plt>
 8048c2a:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048c31:	e8 45 07 00 00       	call   804937b <validate>
 8048c36:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048c3d:	e8 be fc ff ff       	call   8048900 <exit@plt>

08048c42 <fizz>:
 8048c42:	55                   	push   %ebp
 8048c43:	89 e5                	mov    %esp,%ebp
 8048c45:	83 ec 18             	sub    $0x18,%esp
 8048c48:	8b 45 08             	mov    0x8(%ebp),%eax
 8048c4b:	3b 05 08 d1 04 08    	cmp    0x804d108,%eax
 8048c51:	75 26                	jne    8048c79 <fizz+0x37>
 8048c53:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048c57:	c7 44 24 04 ee a4 04 	movl   $0x804a4ee,0x4(%esp)
 8048c5e:	08 
 8048c5f:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048c66:	e8 55 fd ff ff       	call   80489c0 <__printf_chk@plt>
 8048c6b:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048c72:	e8 04 07 00 00       	call   804937b <validate>
 8048c77:	eb 18                	jmp    8048c91 <fizz+0x4f>
 8048c79:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048c7d:	c7 44 24 04 40 a3 04 	movl   $0x804a340,0x4(%esp)
 8048c84:	08 
 8048c85:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048c8c:	e8 2f fd ff ff       	call   80489c0 <__printf_chk@plt>
 8048c91:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048c98:	e8 63 fc ff ff       	call   8048900 <exit@plt>

08048c9d <bang>:
 8048c9d:	55                   	push   %ebp
 8048c9e:	89 e5                	mov    %esp,%ebp
 8048ca0:	83 ec 18             	sub    $0x18,%esp
 8048ca3:	a1 00 d1 04 08       	mov    0x804d100,%eax
 8048ca8:	3b 05 08 d1 04 08    	cmp    0x804d108,%eax
 8048cae:	75 26                	jne    8048cd6 <bang+0x39>
 8048cb0:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048cb4:	c7 44 24 04 60 a3 04 	movl   $0x804a360,0x4(%esp)
 8048cbb:	08 
 8048cbc:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048cc3:	e8 f8 fc ff ff       	call   80489c0 <__printf_chk@plt>
 8048cc8:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
 8048ccf:	e8 a7 06 00 00       	call   804937b <validate>
 8048cd4:	eb 18                	jmp    8048cee <bang+0x51>
 8048cd6:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048cda:	c7 44 24 04 0c a5 04 	movl   $0x804a50c,0x4(%esp)
 8048ce1:	08 
 8048ce2:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048ce9:	e8 d2 fc ff ff       	call   80489c0 <__printf_chk@plt>
 8048cee:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048cf5:	e8 06 fc ff ff       	call   8048900 <exit@plt>

08048cfa <Gets>:
 8048cfa:	55                   	push   %ebp
 8048cfb:	89 e5                	mov    %esp,%ebp
 8048cfd:	57                   	push   %edi
 8048cfe:	56                   	push   %esi
 8048cff:	53                   	push   %ebx
 8048d00:	83 ec 1c             	sub    $0x1c,%esp
 8048d03:	8b 75 08             	mov    0x8(%ebp),%esi
 8048d06:	c7 05 fc d0 04 08 00 	movl   $0x0,0x804d0fc
 8048d0d:	00 00 00 
 8048d10:	89 f3                	mov    %esi,%ebx
 8048d12:	eb 49                	jmp    8048d5d <Gets+0x63>
 8048d14:	83 c3 01             	add    $0x1,%ebx
 8048d17:	88 53 ff             	mov    %dl,-0x1(%ebx)
 8048d1a:	a1 fc d0 04 08       	mov    0x804d0fc,%eax
 8048d1f:	3d ff 03 00 00       	cmp    $0x3ff,%eax
 8048d24:	7f 37                	jg     8048d5d <Gets+0x63>
 8048d26:	8d 3c 40             	lea    (%eax,%eax,2),%edi
 8048d29:	89 d1                	mov    %edx,%ecx
 8048d2b:	c0 e9 04             	shr    $0x4,%cl
 8048d2e:	0f be c9             	movsbl %cl,%ecx
 8048d31:	0f b6 89 e8 a5 04 08 	movzbl 0x804a5e8(%ecx),%ecx
 8048d38:	88 8f 40 d1 04 08    	mov    %cl,0x804d140(%edi)
 8048d3e:	83 e2 0f             	and    $0xf,%edx
 8048d41:	0f b6 92 e8 a5 04 08 	movzbl 0x804a5e8(%edx),%edx
 8048d48:	88 97 41 d1 04 08    	mov    %dl,0x804d141(%edi)
 8048d4e:	c6 87 42 d1 04 08 20 	movb   $0x20,0x804d142(%edi)
 8048d55:	83 c0 01             	add    $0x1,%eax
 8048d58:	a3 fc d0 04 08       	mov    %eax,0x804d0fc
 8048d5d:	a1 0c d1 04 08       	mov    0x804d10c,%eax
 8048d62:	89 04 24             	mov    %eax,(%esp)
 8048d65:	e8 06 fb ff ff       	call   8048870 <_IO_getc@plt>
 8048d6a:	89 c2                	mov    %eax,%edx
 8048d6c:	83 f8 ff             	cmp    $0xffffffff,%eax
 8048d6f:	74 05                	je     8048d76 <Gets+0x7c>
 8048d71:	83 f8 0a             	cmp    $0xa,%eax
 8048d74:	75 9e                	jne    8048d14 <Gets+0x1a>
 8048d76:	c6 03 00             	movb   $0x0,(%ebx)
 8048d79:	a1 fc d0 04 08       	mov    0x804d0fc,%eax
 8048d7e:	c6 84 40 40 d1 04 08 	movb   $0x0,0x804d140(%eax,%eax,2)
 8048d85:	00 
 8048d86:	89 f0                	mov    %esi,%eax
 8048d88:	83 c4 1c             	add    $0x1c,%esp
 8048d8b:	5b                   	pop    %ebx
 8048d8c:	5e                   	pop    %esi
 8048d8d:	5f                   	pop    %edi
 8048d8e:	5d                   	pop    %ebp
 8048d8f:	c3                   	ret    

08048d90 <uniqueval>:
 8048d90:	55                   	push   %ebp
 8048d91:	89 e5                	mov    %esp,%ebp
 8048d93:	83 ec 18             	sub    $0x18,%esp
 8048d96:	e8 05 fb ff ff       	call   80488a0 <getpid@plt>
 8048d9b:	89 04 24             	mov    %eax,(%esp)
 8048d9e:	e8 8d fa ff ff       	call   8048830 <srandom@plt>
 8048da3:	e8 48 fc ff ff       	call   80489f0 <random@plt>
 8048da8:	c9                   	leave  
 8048da9:	c3                   	ret    

08048daa <test>:
 8048daa:	55                   	push   %ebp
 8048dab:	89 e5                	mov    %esp,%ebp
 8048dad:	53                   	push   %ebx
 8048dae:	83 ec 24             	sub    $0x24,%esp
 8048db1:	e8 da ff ff ff       	call   8048d90 <uniqueval>
 8048db6:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8048db9:	e8 36 04 00 00       	call   80491f4 <getbuf>
 8048dbe:	89 c3                	mov    %eax,%ebx
 8048dc0:	e8 cb ff ff ff       	call   8048d90 <uniqueval>
 8048dc5:	8b 55 f4             	mov    -0xc(%ebp),%edx
 8048dc8:	39 d0                	cmp    %edx,%eax
 8048dca:	74 0e                	je     8048dda <test+0x30>
 8048dcc:	c7 04 24 88 a3 04 08 	movl   $0x804a388,(%esp)
 8048dd3:	e8 e8 fa ff ff       	call   80488c0 <puts@plt>
 8048dd8:	eb 46                	jmp    8048e20 <test+0x76>
 8048dda:	3b 1d 08 d1 04 08    	cmp    0x804d108,%ebx
 8048de0:	75 26                	jne    8048e08 <test+0x5e>
 8048de2:	89 5c 24 08          	mov    %ebx,0x8(%esp)
 8048de6:	c7 44 24 04 2a a5 04 	movl   $0x804a52a,0x4(%esp)
 8048ded:	08 
 8048dee:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048df5:	e8 c6 fb ff ff       	call   80489c0 <__printf_chk@plt>
 8048dfa:	c7 04 24 03 00 00 00 	movl   $0x3,(%esp)
 8048e01:	e8 75 05 00 00       	call   804937b <validate>
 8048e06:	eb 18                	jmp    8048e20 <test+0x76>
 8048e08:	89 5c 24 08          	mov    %ebx,0x8(%esp)
 8048e0c:	c7 44 24 04 47 a5 04 	movl   $0x804a547,0x4(%esp)
 8048e13:	08 
 8048e14:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048e1b:	e8 a0 fb ff ff       	call   80489c0 <__printf_chk@plt>
 8048e20:	83 c4 24             	add    $0x24,%esp
 8048e23:	5b                   	pop    %ebx
 8048e24:	5d                   	pop    %ebp
 8048e25:	c3                   	ret    

08048e26 <testn>:
 8048e26:	55                   	push   %ebp
 8048e27:	89 e5                	mov    %esp,%ebp
 8048e29:	53                   	push   %ebx
 8048e2a:	83 ec 24             	sub    $0x24,%esp
 8048e2d:	e8 5e ff ff ff       	call   8048d90 <uniqueval>
 8048e32:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8048e35:	e8 d2 03 00 00       	call   804920c <getbufn>
 8048e3a:	89 c3                	mov    %eax,%ebx
 8048e3c:	e8 4f ff ff ff       	call   8048d90 <uniqueval>
 8048e41:	8b 55 f4             	mov    -0xc(%ebp),%edx
 8048e44:	39 d0                	cmp    %edx,%eax
 8048e46:	74 0e                	je     8048e56 <testn+0x30>
 8048e48:	c7 04 24 88 a3 04 08 	movl   $0x804a388,(%esp)
 8048e4f:	e8 6c fa ff ff       	call   80488c0 <puts@plt>
 8048e54:	eb 46                	jmp    8048e9c <testn+0x76>
 8048e56:	3b 1d 08 d1 04 08    	cmp    0x804d108,%ebx
 8048e5c:	75 26                	jne    8048e84 <testn+0x5e>
 8048e5e:	89 5c 24 08          	mov    %ebx,0x8(%esp)
 8048e62:	c7 44 24 04 b4 a3 04 	movl   $0x804a3b4,0x4(%esp)
 8048e69:	08 
 8048e6a:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048e71:	e8 4a fb ff ff       	call   80489c0 <__printf_chk@plt>
 8048e76:	c7 04 24 04 00 00 00 	movl   $0x4,(%esp)
 8048e7d:	e8 f9 04 00 00       	call   804937b <validate>
 8048e82:	eb 18                	jmp    8048e9c <testn+0x76>
 8048e84:	89 5c 24 08          	mov    %ebx,0x8(%esp)
 8048e88:	c7 44 24 04 62 a5 04 	movl   $0x804a562,0x4(%esp)
 8048e8f:	08 
 8048e90:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048e97:	e8 24 fb ff ff       	call   80489c0 <__printf_chk@plt>
 8048e9c:	83 c4 24             	add    $0x24,%esp
 8048e9f:	5b                   	pop    %ebx
 8048ea0:	5d                   	pop    %ebp
 8048ea1:	c3                   	ret    

08048ea2 <launch>:
 8048ea2:	55                   	push   %ebp
 8048ea3:	89 e5                	mov    %esp,%ebp
 8048ea5:	53                   	push   %ebx
 8048ea6:	83 ec 64             	sub    $0x64,%esp
 8048ea9:	89 c3                	mov    %eax,%ebx
 8048eab:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 8048eb1:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8048eb4:	31 c0                	xor    %eax,%eax
 8048eb6:	8d 4d b4             	lea    -0x4c(%ebp),%ecx
 8048eb9:	81 e1 f0 3f 00 00    	and    $0x3ff0,%ecx
 8048ebf:	8d 44 11 1e          	lea    0x1e(%ecx,%edx,1),%eax
 8048ec3:	83 e0 f0             	and    $0xfffffff0,%eax
 8048ec6:	29 c4                	sub    %eax,%esp
 8048ec8:	8d 44 24 1b          	lea    0x1b(%esp),%eax
 8048ecc:	83 e0 f0             	and    $0xfffffff0,%eax
 8048ecf:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 8048ed3:	c7 44 24 04 f4 00 00 	movl   $0xf4,0x4(%esp)
 8048eda:	00 
 8048edb:	89 04 24             	mov    %eax,(%esp)
 8048ede:	e8 9d fa ff ff       	call   8048980 <memset@plt>
 8048ee3:	c7 44 24 04 7e a5 04 	movl   $0x804a57e,0x4(%esp)
 8048eea:	08 
 8048eeb:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048ef2:	e8 c9 fa ff ff       	call   80489c0 <__printf_chk@plt>
 8048ef7:	85 db                	test   %ebx,%ebx
 8048ef9:	74 07                	je     8048f02 <launch+0x60>
 8048efb:	e8 26 ff ff ff       	call   8048e26 <testn>
 8048f00:	eb 05                	jmp    8048f07 <launch+0x65>
 8048f02:	e8 a3 fe ff ff       	call   8048daa <test>
 8048f07:	83 3d 04 d1 04 08 00 	cmpl   $0x0,0x804d104
 8048f0e:	75 16                	jne    8048f26 <launch+0x84>
 8048f10:	c7 04 24 70 a4 04 08 	movl   $0x804a470,(%esp)
 8048f17:	e8 a4 f9 ff ff       	call   80488c0 <puts@plt>
 8048f1c:	c7 05 04 d1 04 08 00 	movl   $0x0,0x804d104
 8048f23:	00 00 00 
 8048f26:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8048f29:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax
 8048f30:	74 05                	je     8048f37 <launch+0x95>
 8048f32:	e8 29 f9 ff ff       	call   8048860 <__stack_chk_fail@plt>
 8048f37:	8b 5d fc             	mov    -0x4(%ebp),%ebx
 8048f3a:	c9                   	leave  
 8048f3b:	c3                   	ret    

08048f3c <launcher>:
 8048f3c:	55                   	push   %ebp
 8048f3d:	89 e5                	mov    %esp,%ebp
 8048f3f:	83 ec 28             	sub    $0x28,%esp
 8048f42:	8b 45 08             	mov    0x8(%ebp),%eax
 8048f45:	a3 f8 d0 04 08       	mov    %eax,0x804d0f8
 8048f4a:	8b 45 0c             	mov    0xc(%ebp),%eax
 8048f4d:	a3 f4 d0 04 08       	mov    %eax,0x804d0f4
 8048f52:	c7 44 24 14 00 00 00 	movl   $0x0,0x14(%esp)
 8048f59:	00 
 8048f5a:	c7 44 24 10 00 00 00 	movl   $0x0,0x10(%esp)
 8048f61:	00 
 8048f62:	c7 44 24 0c 32 01 00 	movl   $0x132,0xc(%esp)
 8048f69:	00 
 8048f6a:	c7 44 24 08 07 00 00 	movl   $0x7,0x8(%esp)
 8048f71:	00 
 8048f72:	c7 44 24 04 00 00 10 	movl   $0x100000,0x4(%esp)
 8048f79:	00 
 8048f7a:	c7 04 24 00 60 58 55 	movl   $0x55586000,(%esp)
 8048f81:	e8 9a f9 ff ff       	call   8048920 <mmap@plt>
 8048f86:	3d 00 60 58 55       	cmp    $0x55586000,%eax
 8048f8b:	74 31                	je     8048fbe <launcher+0x82>
 8048f8d:	a1 e0 d0 04 08       	mov    0x804d0e0,%eax
 8048f92:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8048f96:	c7 44 24 08 47 00 00 	movl   $0x47,0x8(%esp)
 8048f9d:	00 
 8048f9e:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8048fa5:	00 
 8048fa6:	c7 04 24 d4 a3 04 08 	movl   $0x804a3d4,(%esp)
 8048fad:	e8 ce f8 ff ff       	call   8048880 <fwrite@plt>
 8048fb2:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048fb9:	e8 42 f9 ff ff       	call   8048900 <exit@plt>
 8048fbe:	c7 05 20 d1 04 08 f8 	movl   $0x55685ff8,0x804d120
 8048fc5:	5f 68 55 
 8048fc8:	ba f8 5f 68 55       	mov    $0x55685ff8,%edx
 8048fcd:	89 e0                	mov    %esp,%eax
 8048fcf:	89 d4                	mov    %edx,%esp
 8048fd1:	89 c2                	mov    %eax,%edx
 8048fd3:	89 15 f0 d0 04 08    	mov    %edx,0x804d0f0
 8048fd9:	8b 15 f4 d0 04 08    	mov    0x804d0f4,%edx
 8048fdf:	a1 f8 d0 04 08       	mov    0x804d0f8,%eax
 8048fe4:	e8 b9 fe ff ff       	call   8048ea2 <launch>
 8048fe9:	a1 f0 d0 04 08       	mov    0x804d0f0,%eax
 8048fee:	89 c4                	mov    %eax,%esp
 8048ff0:	c7 44 24 04 00 00 10 	movl   $0x100000,0x4(%esp)
 8048ff7:	00 
 8048ff8:	c7 04 24 00 60 58 55 	movl   $0x55586000,(%esp)
 8048fff:	e8 cc f9 ff ff       	call   80489d0 <munmap@plt>
 8049004:	c9                   	leave  
 8049005:	c3                   	ret    

08049006 <main>:
 8049006:	55                   	push   %ebp
 8049007:	89 e5                	mov    %esp,%ebp
 8049009:	57                   	push   %edi
 804900a:	56                   	push   %esi
 804900b:	53                   	push   %ebx
 804900c:	83 e4 f0             	and    $0xfffffff0,%esp
 804900f:	83 ec 20             	sub    $0x20,%esp
 8049012:	8b 75 08             	mov    0x8(%ebp),%esi
 8049015:	8b 5d 0c             	mov    0xc(%ebp),%ebx
 8049018:	c7 44 24 04 6a 8b 04 	movl   $0x8048b6a,0x4(%esp)
 804901f:	08 
 8049020:	c7 04 24 0b 00 00 00 	movl   $0xb,(%esp)
 8049027:	e8 14 f8 ff ff       	call   8048840 <signal@plt>
 804902c:	c7 44 24 04 40 8b 04 	movl   $0x8048b40,0x4(%esp)
 8049033:	08 
 8049034:	c7 04 24 07 00 00 00 	movl   $0x7,(%esp)
 804903b:	e8 00 f8 ff ff       	call   8048840 <signal@plt>
 8049040:	c7 44 24 04 94 8b 04 	movl   $0x8048b94,0x4(%esp)
 8049047:	08 
 8049048:	c7 04 24 04 00 00 00 	movl   $0x4,(%esp)
 804904f:	e8 ec f7 ff ff       	call   8048840 <signal@plt>
 8049054:	a1 e4 d0 04 08       	mov    0x804d0e4,%eax
 8049059:	a3 0c d1 04 08       	mov    %eax,0x804d10c
 804905e:	bf 01 00 00 00       	mov    $0x1,%edi
 8049063:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
 804906a:	00 
 804906b:	eb 73                	jmp    80490e0 <main+0xda>
 804906d:	83 e8 67             	sub    $0x67,%eax
 8049070:	3c 0e                	cmp    $0xe,%al
 8049072:	77 65                	ja     80490d9 <main+0xd3>
 8049074:	0f b6 c0             	movzbl %al,%eax
 8049077:	ff 24 85 ac a5 04 08 	jmp    *0x804a5ac(,%eax,4)
 804907e:	c7 44 24 1c 01 00 00 	movl   $0x1,0x1c(%esp)
 8049085:	00 
 8049086:	bf 05 00 00 00       	mov    $0x5,%edi
 804908b:	eb 53                	jmp    80490e0 <main+0xda>
 804908d:	8b 03                	mov    (%ebx),%eax
 804908f:	e8 2a fb ff ff       	call   8048bbe <usage>
 8049094:	a1 e8 d0 04 08       	mov    0x804d0e8,%eax
 8049099:	89 04 24             	mov    %eax,(%esp)
 804909c:	e8 ef f8 ff ff       	call   8048990 <__strdup@plt>
 80490a1:	a3 18 d1 04 08       	mov    %eax,0x804d118
 80490a6:	89 04 24             	mov    %eax,(%esp)
 80490a9:	e8 e4 10 00 00       	call   804a192 <gencookie>
 80490ae:	a3 08 d1 04 08       	mov    %eax,0x804d108
 80490b3:	eb 2b                	jmp    80490e0 <main+0xda>
 80490b5:	c7 04 24 1c a4 04 08 	movl   $0x804a41c,(%esp)
 80490bc:	e8 ff f7 ff ff       	call   80488c0 <puts@plt>
 80490c1:	c7 05 14 d1 04 08 00 	movl   $0x0,0x804d114
 80490c8:	00 00 00 
 80490cb:	eb 13                	jmp    80490e0 <main+0xda>
 80490cd:	c7 05 10 d1 04 08 01 	movl   $0x1,0x804d110
 80490d4:	00 00 00 
 80490d7:	eb 07                	jmp    80490e0 <main+0xda>
 80490d9:	8b 03                	mov    (%ebx),%eax
 80490db:	e8 de fa ff ff       	call   8048bbe <usage>
 80490e0:	c7 44 24 08 8b a5 04 	movl   $0x804a58b,0x8(%esp)
 80490e7:	08 
 80490e8:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 80490ec:	89 34 24             	mov    %esi,(%esp)
 80490ef:	e8 5c f8 ff ff       	call   8048950 <getopt@plt>
 80490f4:	3c ff                	cmp    $0xff,%al
 80490f6:	0f 85 71 ff ff ff    	jne    804906d <main+0x67>
 80490fc:	83 3d 18 d1 04 08 00 	cmpl   $0x0,0x804d118
 8049103:	75 21                	jne    8049126 <main+0x120>
 8049105:	8b 03                	mov    (%ebx),%eax
 8049107:	89 44 24 08          	mov    %eax,0x8(%esp)
 804910b:	c7 44 24 04 44 a4 04 	movl   $0x804a444,0x4(%esp)
 8049112:	08 
 8049113:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 804911a:	e8 a1 f8 ff ff       	call   80489c0 <__printf_chk@plt>
 804911f:	8b 03                	mov    (%ebx),%eax
 8049121:	e8 98 fa ff ff       	call   8048bbe <usage>
 8049126:	e8 01 01 00 00       	call   804922c <initialize_bomb>
 804912b:	a1 18 d1 04 08       	mov    0x804d118,%eax
 8049130:	89 44 24 08          	mov    %eax,0x8(%esp)
 8049134:	c7 44 24 04 92 a5 04 	movl   $0x804a592,0x4(%esp)
 804913b:	08 
 804913c:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8049143:	e8 78 f8 ff ff       	call   80489c0 <__printf_chk@plt>
 8049148:	a1 08 d1 04 08       	mov    0x804d108,%eax
 804914d:	89 44 24 08          	mov    %eax,0x8(%esp)
 8049151:	c7 44 24 04 9e a5 04 	movl   $0x804a59e,0x4(%esp)
 8049158:	08 
 8049159:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8049160:	e8 5b f8 ff ff       	call   80489c0 <__printf_chk@plt>
 8049165:	a1 08 d1 04 08       	mov    0x804d108,%eax
 804916a:	89 04 24             	mov    %eax,(%esp)
 804916d:	e8 be f6 ff ff       	call   8048830 <srandom@plt>
 8049172:	e8 79 f8 ff ff       	call   80489f0 <random@plt>
 8049177:	25 f0 0f 00 00       	and    $0xff0,%eax
 804917c:	05 00 01 00 00       	add    $0x100,%eax
 8049181:	89 44 24 18          	mov    %eax,0x18(%esp)
 8049185:	c7 44 24 04 04 00 00 	movl   $0x4,0x4(%esp)
 804918c:	00 
 804918d:	89 3c 24             	mov    %edi,(%esp)
 8049190:	e8 9b f8 ff ff       	call   8048a30 <calloc@plt>
 8049195:	89 c6                	mov    %eax,%esi
 8049197:	c7 00 00 00 00 00    	movl   $0x0,(%eax)
 804919d:	bb 01 00 00 00       	mov    $0x1,%ebx
 80491a2:	eb 17                	jmp    80491bb <main+0x1b5>
 80491a4:	e8 47 f8 ff ff       	call   80489f0 <random@plt>
 80491a9:	25 f0 00 00 00       	and    $0xf0,%eax
 80491ae:	ba 80 00 00 00       	mov    $0x80,%edx
 80491b3:	29 c2                	sub    %eax,%edx
 80491b5:	89 14 9e             	mov    %edx,(%esi,%ebx,4)
 80491b8:	83 c3 01             	add    $0x1,%ebx
 80491bb:	39 fb                	cmp    %edi,%ebx
 80491bd:	7c e5                	jl     80491a4 <main+0x19e>
 80491bf:	bb 00 00 00 00       	mov    $0x0,%ebx
 80491c4:	eb 1a                	jmp    80491e0 <main+0x1da>
 80491c6:	8b 44 24 18          	mov    0x18(%esp),%eax
 80491ca:	03 04 9e             	add    (%esi,%ebx,4),%eax
 80491cd:	89 44 24 04          	mov    %eax,0x4(%esp)
 80491d1:	8b 44 24 1c          	mov    0x1c(%esp),%eax
 80491d5:	89 04 24             	mov    %eax,(%esp)
 80491d8:	e8 5f fd ff ff       	call   8048f3c <launcher>
 80491dd:	83 c3 01             	add    $0x1,%ebx
 80491e0:	39 fb                	cmp    %edi,%ebx
 80491e2:	7c e2                	jl     80491c6 <main+0x1c0>
 80491e4:	b8 00 00 00 00       	mov    $0x0,%eax
 80491e9:	8d 65 f4             	lea    -0xc(%ebp),%esp
 80491ec:	5b                   	pop    %ebx
 80491ed:	5e                   	pop    %esi
 80491ee:	5f                   	pop    %edi
 80491ef:	5d                   	pop    %ebp
 80491f0:	c3                   	ret    
 80491f1:	90                   	nop
 80491f2:	90                   	nop
 80491f3:	90                   	nop

080491f4 <getbuf>:
 80491f4:	55                   	push   %ebp
 80491f5:	89 e5                	mov    %esp,%ebp
 80491f7:	83 ec 38             	sub    $0x38,%esp
 80491fa:	8d 45 d8             	lea    -0x28(%ebp),%eax
 80491fd:	89 04 24             	mov    %eax,(%esp)
 8049200:	e8 f5 fa ff ff       	call   8048cfa <Gets>
 8049205:	b8 01 00 00 00       	mov    $0x1,%eax
 804920a:	c9                   	leave  
 804920b:	c3                   	ret    

0804920c <getbufn>:
 804920c:	55                   	push   %ebp
 804920d:	89 e5                	mov    %esp,%ebp
 804920f:	81 ec 18 02 00 00    	sub    $0x218,%esp
 8049215:	8d 85 f8 fd ff ff    	lea    -0x208(%ebp),%eax
 804921b:	89 04 24             	mov    %eax,(%esp)
 804921e:	e8 d7 fa ff ff       	call   8048cfa <Gets>
 8049223:	b8 01 00 00 00       	mov    $0x1,%eax
 8049228:	c9                   	leave  
 8049229:	c3                   	ret    
 804922a:	90                   	nop
 804922b:	90                   	nop

0804922c <initialize_bomb>:
 804922c:	55                   	push   %ebp
 804922d:	89 e5                	mov    %esp,%ebp
 804922f:	56                   	push   %esi
 8049230:	53                   	push   %ebx
 8049231:	81 ec 20 24 00 00    	sub    $0x2420,%esp
 8049237:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 804923d:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049240:	31 c0                	xor    %eax,%eax
 8049242:	83 3d 10 d1 04 08 00 	cmpl   $0x0,0x804d110
 8049249:	74 0c                	je     8049257 <initialize_bomb+0x2b>
 804924b:	c7 04 24 ff ff ff ff 	movl   $0xffffffff,(%esp)
 8049252:	e8 1d 0c 00 00       	call   8049e74 <init_timeout>
 8049257:	83 3d 14 d1 04 08 00 	cmpl   $0x0,0x804d114
 804925e:	0f 84 fc 00 00 00    	je     8049360 <initialize_bomb+0x134>
 8049264:	c7 44 24 04 00 04 00 	movl   $0x400,0x4(%esp)
 804926b:	00 
 804926c:	8d 85 f4 db ff ff    	lea    -0x240c(%ebp),%eax
 8049272:	89 04 24             	mov    %eax,(%esp)
 8049275:	e8 36 f6 ff ff       	call   80488b0 <gethostname@plt>
 804927a:	85 c0                	test   %eax,%eax
 804927c:	75 19                	jne    8049297 <initialize_bomb+0x6b>
 804927e:	a1 e0 c0 04 08       	mov    0x804c0e0,%eax
 8049283:	bb 00 00 00 00       	mov    $0x0,%ebx
 8049288:	8d b5 f4 db ff ff    	lea    -0x240c(%ebp),%esi
 804928e:	85 c0                	test   %eax,%eax
 8049290:	75 1d                	jne    80492af <initialize_bomb+0x83>
 8049292:	e9 98 00 00 00       	jmp    804932f <initialize_bomb+0x103>
 8049297:	c7 04 24 f8 a5 04 08 	movl   $0x804a5f8,(%esp)
 804929e:	e8 1d f6 ff ff       	call   80488c0 <puts@plt>
 80492a3:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 80492aa:	e8 51 f6 ff ff       	call   8048900 <exit@plt>
 80492af:	89 74 24 04          	mov    %esi,0x4(%esp)
 80492b3:	89 04 24             	mov    %eax,(%esp)
 80492b6:	e8 a5 f6 ff ff       	call   8048960 <strcasecmp@plt>
 80492bb:	85 c0                	test   %eax,%eax
 80492bd:	74 5c                	je     804931b <initialize_bomb+0xef>
 80492bf:	83 c3 01             	add    $0x1,%ebx
 80492c2:	8b 04 9d e0 c0 04 08 	mov    0x804c0e0(,%ebx,4),%eax
 80492c9:	85 c0                	test   %eax,%eax
 80492cb:	75 e2                	jne    80492af <initialize_bomb+0x83>
 80492cd:	eb 60                	jmp    804932f <initialize_bomb+0x103>
 80492cf:	89 04 24             	mov    %eax,(%esp)
 80492d2:	e8 e9 f5 ff ff       	call   80488c0 <puts@plt>
 80492d7:	83 c3 01             	add    $0x1,%ebx
 80492da:	8b 04 9d e0 c0 04 08 	mov    0x804c0e0(,%ebx,4),%eax
 80492e1:	85 c0                	test   %eax,%eax
 80492e3:	75 ea                	jne    80492cf <initialize_bomb+0xa3>
 80492e5:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 80492ec:	e8 0f f6 ff ff       	call   8048900 <exit@plt>
 80492f1:	8d 85 f4 df ff ff    	lea    -0x200c(%ebp),%eax
 80492f7:	89 44 24 08          	mov    %eax,0x8(%esp)
 80492fb:	c7 44 24 04 66 a7 04 	movl   $0x804a766,0x4(%esp)
 8049302:	08 
 8049303:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 804930a:	e8 b1 f6 ff ff       	call   80489c0 <__printf_chk@plt>
 804930f:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8049316:	e8 e5 f5 ff ff       	call   8048900 <exit@plt>
 804931b:	8d 85 f4 df ff ff    	lea    -0x200c(%ebp),%eax
 8049321:	89 04 24             	mov    %eax,(%esp)
 8049324:	e8 85 0b 00 00       	call   8049eae <init_driver>
 8049329:	85 c0                	test   %eax,%eax
 804932b:	79 33                	jns    8049360 <initialize_bomb+0x134>
 804932d:	eb c2                	jmp    80492f1 <initialize_bomb+0xc5>
 804932f:	8d 85 f4 db ff ff    	lea    -0x240c(%ebp),%eax
 8049335:	89 44 24 08          	mov    %eax,0x8(%esp)
 8049339:	c7 44 24 04 30 a6 04 	movl   $0x804a630,0x4(%esp)
 8049340:	08 
 8049341:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8049348:	e8 73 f6 ff ff       	call   80489c0 <__printf_chk@plt>
 804934d:	a1 e0 c0 04 08       	mov    0x804c0e0,%eax
 8049352:	85 c0                	test   %eax,%eax
 8049354:	74 8f                	je     80492e5 <initialize_bomb+0xb9>
 8049356:	bb 00 00 00 00       	mov    $0x0,%ebx
 804935b:	e9 6f ff ff ff       	jmp    80492cf <initialize_bomb+0xa3>
 8049360:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8049363:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax
 804936a:	74 05                	je     8049371 <initialize_bomb+0x145>
 804936c:	e8 ef f4 ff ff       	call   8048860 <__stack_chk_fail@plt>
 8049371:	81 c4 20 24 00 00    	add    $0x2420,%esp
 8049377:	5b                   	pop    %ebx
 8049378:	5e                   	pop    %esi
 8049379:	5d                   	pop    %ebp
 804937a:	c3                   	ret    

0804937b <validate>:
 804937b:	55                   	push   %ebp
 804937c:	89 e5                	mov    %esp,%ebp
 804937e:	57                   	push   %edi
 804937f:	53                   	push   %ebx
 8049380:	81 ec 30 40 00 00    	sub    $0x4030,%esp
 8049386:	8b 5d 08             	mov    0x8(%ebp),%ebx
 8049389:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 804938f:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049392:	31 c0                	xor    %eax,%eax
 8049394:	83 3d 18 d1 04 08 00 	cmpl   $0x0,0x804d118
 804939b:	75 11                	jne    80493ae <validate+0x33>
 804939d:	c7 04 24 6c a6 04 08 	movl   $0x804a66c,(%esp)
 80493a4:	e8 17 f5 ff ff       	call   80488c0 <puts@plt>
 80493a9:	e9 2c 01 00 00       	jmp    80494da <validate+0x15f>
 80493ae:	83 fb 04             	cmp    $0x4,%ebx
 80493b1:	76 11                	jbe    80493c4 <validate+0x49>
 80493b3:	c7 04 24 98 a6 04 08 	movl   $0x804a698,(%esp)
 80493ba:	e8 01 f5 ff ff       	call   80488c0 <puts@plt>
 80493bf:	e9 16 01 00 00       	jmp    80494da <validate+0x15f>
 80493c4:	c7 05 04 d1 04 08 01 	movl   $0x1,0x804d104
 80493cb:	00 00 00 
 80493ce:	8b 04 9d c0 c0 04 08 	mov    0x804c0c0(,%ebx,4),%eax
 80493d5:	83 e8 01             	sub    $0x1,%eax
 80493d8:	89 04 9d c0 c0 04 08 	mov    %eax,0x804c0c0(,%ebx,4)
 80493df:	85 c0                	test   %eax,%eax
 80493e1:	7e 11                	jle    80493f4 <validate+0x79>
 80493e3:	c7 04 24 7b a7 04 08 	movl   $0x804a77b,(%esp)
 80493ea:	e8 d1 f4 ff ff       	call   80488c0 <puts@plt>
 80493ef:	e9 e6 00 00 00       	jmp    80494da <validate+0x15f>
 80493f4:	c7 04 24 86 a7 04 08 	movl   $0x804a786,(%esp)
 80493fb:	e8 c0 f4 ff ff       	call   80488c0 <puts@plt>
 8049400:	83 3d 14 d1 04 08 00 	cmpl   $0x0,0x804d114
 8049407:	0f 84 c1 00 00 00    	je     80494ce <validate+0x153>
 804940d:	bf 40 d1 04 08       	mov    $0x804d140,%edi
 8049412:	b8 00 00 00 00       	mov    $0x0,%eax
 8049417:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 804941c:	f2 ae                	repnz scas %es:(%edi),%al
 804941e:	89 ca                	mov    %ecx,%edx
 8049420:	f7 d2                	not    %edx
 8049422:	89 d1                	mov    %edx,%ecx
 8049424:	83 c1 1f             	add    $0x1f,%ecx
 8049427:	81 f9 00 20 00 00    	cmp    $0x2000,%ecx
 804942d:	76 11                	jbe    8049440 <validate+0xc5>
 804942f:	c7 04 24 c0 a6 04 08 	movl   $0x804a6c0,(%esp)
 8049436:	e8 85 f4 ff ff       	call   80488c0 <puts@plt>
 804943b:	e9 9a 00 00 00       	jmp    80494da <validate+0x15f>
 8049440:	c7 44 24 18 40 d1 04 	movl   $0x804d140,0x18(%esp)
 8049447:	08 
 8049448:	a1 08 d1 04 08       	mov    0x804d108,%eax
 804944d:	89 44 24 14          	mov    %eax,0x14(%esp)
 8049451:	89 5c 24 10          	mov    %ebx,0x10(%esp)
 8049455:	c7 44 24 0c 8c a7 04 	movl   $0x804a78c,0xc(%esp)
 804945c:	08 
 804945d:	c7 44 24 08 00 20 00 	movl   $0x2000,0x8(%esp)
 8049464:	00 
 8049465:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 804946c:	00 
 804946d:	8d 9d f4 bf ff ff    	lea    -0x400c(%ebp),%ebx
 8049473:	89 1c 24             	mov    %ebx,(%esp)
 8049476:	e8 c5 f5 ff ff       	call   8048a40 <__sprintf_chk@plt>
 804947b:	8d 85 f4 df ff ff    	lea    -0x200c(%ebp),%eax
 8049481:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8049485:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 804948c:	00 
 804948d:	89 5c 24 04          	mov    %ebx,0x4(%esp)
 8049491:	a1 18 d1 04 08       	mov    0x804d118,%eax
 8049496:	89 04 24             	mov    %eax,(%esp)
 8049499:	e8 f1 0b 00 00       	call   804a08f <driver_post>
 804949e:	85 c0                	test   %eax,%eax
 80494a0:	75 0e                	jne    80494b0 <validate+0x135>
 80494a2:	c7 04 24 f8 a6 04 08 	movl   $0x804a6f8,(%esp)
 80494a9:	e8 12 f4 ff ff       	call   80488c0 <puts@plt>
 80494ae:	eb 1e                	jmp    80494ce <validate+0x153>
 80494b0:	8d 85 f4 df ff ff    	lea    -0x200c(%ebp),%eax
 80494b6:	89 44 24 08          	mov    %eax,0x8(%esp)
 80494ba:	c7 44 24 04 28 a7 04 	movl   $0x804a728,0x4(%esp)
 80494c1:	08 
 80494c2:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 80494c9:	e8 f2 f4 ff ff       	call   80489c0 <__printf_chk@plt>
 80494ce:	c7 04 24 95 a7 04 08 	movl   $0x804a795,(%esp)
 80494d5:	e8 e6 f3 ff ff       	call   80488c0 <puts@plt>
 80494da:	8b 45 f4             	mov    -0xc(%ebp),%eax
 80494dd:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax
 80494e4:	74 05                	je     80494eb <validate+0x170>
 80494e6:	e8 75 f3 ff ff       	call   8048860 <__stack_chk_fail@plt>
 80494eb:	81 c4 30 40 00 00    	add    $0x4030,%esp
 80494f1:	5b                   	pop    %ebx
 80494f2:	5f                   	pop    %edi
 80494f3:	5d                   	pop    %ebp
 80494f4:	c3                   	ret    
 80494f5:	90                   	nop
 80494f6:	90                   	nop
 80494f7:	90                   	nop
 80494f8:	90                   	nop
 80494f9:	90                   	nop
 80494fa:	90                   	nop
 80494fb:	90                   	nop
 80494fc:	90                   	nop
 80494fd:	90                   	nop
 80494fe:	90                   	nop
 80494ff:	90                   	nop

08049500 <sigalrm_handler>:
 8049500:	55                   	push   %ebp
 8049501:	89 e5                	mov    %esp,%ebp
 8049503:	83 ec 18             	sub    $0x18,%esp
 8049506:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 804950d:	00 
 804950e:	c7 44 24 04 04 a8 04 	movl   $0x804a804,0x4(%esp)
 8049515:	08 
 8049516:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 804951d:	e8 9e f4 ff ff       	call   80489c0 <__printf_chk@plt>
 8049522:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8049529:	e8 d2 f3 ff ff       	call   8048900 <exit@plt>

0804952e <rio_readlineb>:
 804952e:	55                   	push   %ebp
 804952f:	89 e5                	mov    %esp,%ebp
 8049531:	57                   	push   %edi
 8049532:	56                   	push   %esi
 8049533:	53                   	push   %ebx
 8049534:	83 ec 4c             	sub    $0x4c,%esp
 8049537:	89 55 d0             	mov    %edx,-0x30(%ebp)
 804953a:	83 f9 01             	cmp    $0x1,%ecx
 804953d:	0f 86 c8 00 00 00    	jbe    804960b <rio_readlineb+0xdd>
 8049543:	89 c3                	mov    %eax,%ebx
 8049545:	89 4d c4             	mov    %ecx,-0x3c(%ebp)
 8049548:	c7 45 d4 01 00 00 00 	movl   $0x1,-0x2c(%ebp)
 804954f:	8d 78 0c             	lea    0xc(%eax),%edi
 8049552:	eb 38                	jmp    804958c <rio_readlineb+0x5e>
 8049554:	c7 44 24 08 00 20 00 	movl   $0x2000,0x8(%esp)
 804955b:	00 
 804955c:	89 7c 24 04          	mov    %edi,0x4(%esp)
 8049560:	8b 03                	mov    (%ebx),%eax
 8049562:	89 04 24             	mov    %eax,(%esp)
 8049565:	e8 b6 f2 ff ff       	call   8048820 <read@plt>
 804956a:	89 43 04             	mov    %eax,0x4(%ebx)
 804956d:	85 c0                	test   %eax,%eax
 804956f:	79 14                	jns    8049585 <rio_readlineb+0x57>
 8049571:	e8 2a f4 ff ff       	call   80489a0 <__errno_location@plt>
 8049576:	83 38 04             	cmpl   $0x4,(%eax)
 8049579:	74 11                	je     804958c <rio_readlineb+0x5e>
 804957b:	90                   	nop
 804957c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 8049580:	e9 98 00 00 00       	jmp    804961d <rio_readlineb+0xef>
 8049585:	85 c0                	test   %eax,%eax
 8049587:	74 6a                	je     80495f3 <rio_readlineb+0xc5>
 8049589:	89 7b 08             	mov    %edi,0x8(%ebx)
 804958c:	8b 73 04             	mov    0x4(%ebx),%esi
 804958f:	85 f6                	test   %esi,%esi
 8049591:	7e c1                	jle    8049554 <rio_readlineb+0x26>
 8049593:	85 f6                	test   %esi,%esi
 8049595:	0f 95 c0             	setne  %al
 8049598:	0f b6 c0             	movzbl %al,%eax
 804959b:	89 45 cc             	mov    %eax,-0x34(%ebp)
 804959e:	8b 4b 08             	mov    0x8(%ebx),%ecx
 80495a1:	c7 44 24 0c 01 00 00 	movl   $0x1,0xc(%esp)
 80495a8:	00 
 80495a9:	89 44 24 08          	mov    %eax,0x8(%esp)
 80495ad:	89 4d c8             	mov    %ecx,-0x38(%ebp)
 80495b0:	89 4c 24 04          	mov    %ecx,0x4(%esp)
 80495b4:	8d 55 e7             	lea    -0x19(%ebp),%edx
 80495b7:	89 14 24             	mov    %edx,(%esp)
 80495ba:	e8 21 f3 ff ff       	call   80488e0 <__memcpy_chk@plt>
 80495bf:	8b 4d c8             	mov    -0x38(%ebp),%ecx
 80495c2:	8b 55 cc             	mov    -0x34(%ebp),%edx
 80495c5:	01 d1                	add    %edx,%ecx
 80495c7:	89 4b 08             	mov    %ecx,0x8(%ebx)
 80495ca:	29 d6                	sub    %edx,%esi
 80495cc:	89 73 04             	mov    %esi,0x4(%ebx)
 80495cf:	83 fa 01             	cmp    $0x1,%edx
 80495d2:	75 14                	jne    80495e8 <rio_readlineb+0xba>
 80495d4:	83 45 d0 01          	addl   $0x1,-0x30(%ebp)
 80495d8:	0f b6 45 e7          	movzbl -0x19(%ebp),%eax
 80495dc:	8b 55 d0             	mov    -0x30(%ebp),%edx
 80495df:	88 42 ff             	mov    %al,-0x1(%edx)
 80495e2:	3c 0a                	cmp    $0xa,%al
 80495e4:	75 17                	jne    80495fd <rio_readlineb+0xcf>
 80495e6:	eb 2a                	jmp    8049612 <rio_readlineb+0xe4>
 80495e8:	83 7d cc 00          	cmpl   $0x0,-0x34(%ebp)
 80495ec:	75 36                	jne    8049624 <rio_readlineb+0xf6>
 80495ee:	8b 45 d4             	mov    -0x2c(%ebp),%eax
 80495f1:	eb 03                	jmp    80495f6 <rio_readlineb+0xc8>
 80495f3:	8b 45 d4             	mov    -0x2c(%ebp),%eax
 80495f6:	83 f8 01             	cmp    $0x1,%eax
 80495f9:	75 17                	jne    8049612 <rio_readlineb+0xe4>
 80495fb:	eb 2e                	jmp    804962b <rio_readlineb+0xfd>
 80495fd:	83 45 d4 01          	addl   $0x1,-0x2c(%ebp)
 8049601:	8b 45 c4             	mov    -0x3c(%ebp),%eax
 8049604:	39 45 d4             	cmp    %eax,-0x2c(%ebp)
 8049607:	74 09                	je     8049612 <rio_readlineb+0xe4>
 8049609:	eb 81                	jmp    804958c <rio_readlineb+0x5e>
 804960b:	c7 45 d4 01 00 00 00 	movl   $0x1,-0x2c(%ebp)
 8049612:	8b 45 d0             	mov    -0x30(%ebp),%eax
 8049615:	c6 00 00             	movb   $0x0,(%eax)
 8049618:	8b 45 d4             	mov    -0x2c(%ebp),%eax
 804961b:	eb 13                	jmp    8049630 <rio_readlineb+0x102>
 804961d:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049622:	eb 0c                	jmp    8049630 <rio_readlineb+0x102>
 8049624:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049629:	eb 05                	jmp    8049630 <rio_readlineb+0x102>
 804962b:	b8 00 00 00 00       	mov    $0x0,%eax
 8049630:	83 c4 4c             	add    $0x4c,%esp
 8049633:	5b                   	pop    %ebx
 8049634:	5e                   	pop    %esi
 8049635:	5f                   	pop    %edi
 8049636:	5d                   	pop    %ebp
 8049637:	c3                   	ret    

08049638 <submitr>:
 8049638:	55                   	push   %ebp
 8049639:	89 e5                	mov    %esp,%ebp
 804963b:	57                   	push   %edi
 804963c:	56                   	push   %esi
 804963d:	53                   	push   %ebx
 804963e:	81 ec 7c a0 00 00    	sub    $0xa07c,%esp
 8049644:	8b 7d 08             	mov    0x8(%ebp),%edi
 8049647:	8b 45 10             	mov    0x10(%ebp),%eax
 804964a:	89 85 b0 5f ff ff    	mov    %eax,-0xa050(%ebp)
 8049650:	8b 45 14             	mov    0x14(%ebp),%eax
 8049653:	89 85 ac 5f ff ff    	mov    %eax,-0xa054(%ebp)
 8049659:	8b 45 18             	mov    0x18(%ebp),%eax
 804965c:	89 85 a8 5f ff ff    	mov    %eax,-0xa058(%ebp)
 8049662:	8b 5d 1c             	mov    0x1c(%ebp),%ebx
 8049665:	8b 45 20             	mov    0x20(%ebp),%eax
 8049668:	89 85 a4 5f ff ff    	mov    %eax,-0xa05c(%ebp)
 804966e:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 8049674:	89 45 e4             	mov    %eax,-0x1c(%ebp)
 8049677:	31 c0                	xor    %eax,%eax
 8049679:	c7 85 c4 5f ff ff 00 	movl   $0x0,-0xa03c(%ebp)
 8049680:	00 00 00 
 8049683:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 804968a:	00 
 804968b:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8049692:	00 
 8049693:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
 804969a:	e8 41 f3 ff ff       	call   80489e0 <socket@plt>
 804969f:	89 85 b4 5f ff ff    	mov    %eax,-0xa04c(%ebp)
 80496a5:	85 c0                	test   %eax,%eax
 80496a7:	79 54                	jns    80496fd <submitr+0xc5>
 80496a9:	8b 85 a4 5f ff ff    	mov    -0xa05c(%ebp),%eax
 80496af:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 80496b5:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 80496bc:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 80496c3:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 80496ca:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 80496d1:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 80496d8:	c7 40 18 63 72 65 61 	movl   $0x61657263,0x18(%eax)
 80496df:	c7 40 1c 74 65 20 73 	movl   $0x73206574,0x1c(%eax)
 80496e6:	c7 40 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%eax)
 80496ed:	66 c7 40 24 74 00    	movw   $0x74,0x24(%eax)
 80496f3:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 80496f8:	e9 52 06 00 00       	jmp    8049d4f <submitr+0x717>
 80496fd:	89 3c 24             	mov    %edi,(%esp)
 8049700:	e8 fb f2 ff ff       	call   8048a00 <gethostbyname@plt>
 8049705:	85 c0                	test   %eax,%eax
 8049707:	75 42                	jne    804974b <submitr+0x113>
 8049709:	89 7c 24 10          	mov    %edi,0x10(%esp)
 804970d:	c7 44 24 0c 28 a8 04 	movl   $0x804a828,0xc(%esp)
 8049714:	08 
 8049715:	c7 44 24 08 ff ff ff 	movl   $0xffffffff,0x8(%esp)
 804971c:	ff 
 804971d:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8049724:	00 
 8049725:	8b 85 a4 5f ff ff    	mov    -0xa05c(%ebp),%eax
 804972b:	89 04 24             	mov    %eax,(%esp)
 804972e:	e8 0d f3 ff ff       	call   8048a40 <__sprintf_chk@plt>
 8049733:	8b 85 b4 5f ff ff    	mov    -0xa04c(%ebp),%eax
 8049739:	89 04 24             	mov    %eax,(%esp)
 804973c:	e8 df f2 ff ff       	call   8048a20 <close@plt>
 8049741:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049746:	e9 04 06 00 00       	jmp    8049d4f <submitr+0x717>
 804974b:	8d b5 c8 5f ff ff    	lea    -0xa038(%ebp),%esi
 8049751:	c7 85 c8 5f ff ff 00 	movl   $0x0,-0xa038(%ebp)
 8049758:	00 00 00 
 804975b:	c7 85 cc 5f ff ff 00 	movl   $0x0,-0xa034(%ebp)
 8049762:	00 00 00 
 8049765:	c7 85 d0 5f ff ff 00 	movl   $0x0,-0xa030(%ebp)
 804976c:	00 00 00 
 804976f:	c7 85 d4 5f ff ff 00 	movl   $0x0,-0xa02c(%ebp)
 8049776:	00 00 00 
 8049779:	66 c7 85 c8 5f ff ff 	movw   $0x2,-0xa038(%ebp)
 8049780:	02 00 
 8049782:	c7 44 24 0c 0c 00 00 	movl   $0xc,0xc(%esp)
 8049789:	00 
 804978a:	8b 50 0c             	mov    0xc(%eax),%edx
 804978d:	89 54 24 08          	mov    %edx,0x8(%esp)
 8049791:	8b 40 10             	mov    0x10(%eax),%eax
 8049794:	8b 00                	mov    (%eax),%eax
 8049796:	89 44 24 04          	mov    %eax,0x4(%esp)
 804979a:	8d 85 cc 5f ff ff    	lea    -0xa034(%ebp),%eax
 80497a0:	89 04 24             	mov    %eax,(%esp)
 80497a3:	e8 28 f1 ff ff       	call   80488d0 <__memmove_chk@plt>
 80497a8:	0f b7 45 0c          	movzwl 0xc(%ebp),%eax
 80497ac:	66 c1 c8 08          	ror    $0x8,%ax
 80497b0:	66 89 85 ca 5f ff ff 	mov    %ax,-0xa036(%ebp)
 80497b7:	c7 44 24 08 10 00 00 	movl   $0x10,0x8(%esp)
 80497be:	00 
 80497bf:	89 74 24 04          	mov    %esi,0x4(%esp)
 80497c3:	8b 85 b4 5f ff ff    	mov    -0xa04c(%ebp),%eax
 80497c9:	89 04 24             	mov    %eax,(%esp)
 80497cc:	e8 3f f2 ff ff       	call   8048a10 <connect@plt>
 80497d1:	85 c0                	test   %eax,%eax
 80497d3:	79 42                	jns    8049817 <submitr+0x1df>
 80497d5:	89 7c 24 10          	mov    %edi,0x10(%esp)
 80497d9:	c7 44 24 0c 54 a8 04 	movl   $0x804a854,0xc(%esp)
 80497e0:	08 
 80497e1:	c7 44 24 08 ff ff ff 	movl   $0xffffffff,0x8(%esp)
 80497e8:	ff 
 80497e9:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 80497f0:	00 
 80497f1:	8b 85 a4 5f ff ff    	mov    -0xa05c(%ebp),%eax
 80497f7:	89 04 24             	mov    %eax,(%esp)
 80497fa:	e8 41 f2 ff ff       	call   8048a40 <__sprintf_chk@plt>
 80497ff:	8b 85 b4 5f ff ff    	mov    -0xa04c(%ebp),%eax
 8049805:	89 04 24             	mov    %eax,(%esp)
 8049808:	e8 13 f2 ff ff       	call   8048a20 <close@plt>
 804980d:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049812:	e9 38 05 00 00       	jmp    8049d4f <submitr+0x717>
 8049817:	ba ff ff ff ff       	mov    $0xffffffff,%edx
 804981c:	89 df                	mov    %ebx,%edi
 804981e:	b8 00 00 00 00       	mov    $0x0,%eax
 8049823:	89 d1                	mov    %edx,%ecx
 8049825:	f2 ae                	repnz scas %es:(%edi),%al
 8049827:	f7 d1                	not    %ecx
 8049829:	89 8d a0 5f ff ff    	mov    %ecx,-0xa060(%ebp)
 804982f:	8b bd b0 5f ff ff    	mov    -0xa050(%ebp),%edi
 8049835:	89 d1                	mov    %edx,%ecx
 8049837:	f2 ae                	repnz scas %es:(%edi),%al
 8049839:	89 8d 9c 5f ff ff    	mov    %ecx,-0xa064(%ebp)
 804983f:	8b bd ac 5f ff ff    	mov    -0xa054(%ebp),%edi
 8049845:	89 d1                	mov    %edx,%ecx
 8049847:	f2 ae                	repnz scas %es:(%edi),%al
 8049849:	89 ce                	mov    %ecx,%esi
 804984b:	f7 d6                	not    %esi
 804984d:	8b bd a8 5f ff ff    	mov    -0xa058(%ebp),%edi
 8049853:	89 d1                	mov    %edx,%ecx
 8049855:	f2 ae                	repnz scas %es:(%edi),%al
 8049857:	2b b5 9c 5f ff ff    	sub    -0xa064(%ebp),%esi
 804985d:	29 ce                	sub    %ecx,%esi
 804985f:	8b 8d a0 5f ff ff    	mov    -0xa060(%ebp),%ecx
 8049865:	8d 44 49 fd          	lea    -0x3(%ecx,%ecx,2),%eax
 8049869:	8d 44 06 7b          	lea    0x7b(%esi,%eax,1),%eax
 804986d:	3d 00 20 00 00       	cmp    $0x2000,%eax
 8049872:	76 7f                	jbe    80498f3 <submitr+0x2bb>
 8049874:	8b 85 a4 5f ff ff    	mov    -0xa05c(%ebp),%eax
 804987a:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 8049880:	c7 40 04 72 3a 20 52 	movl   $0x52203a72,0x4(%eax)
 8049887:	c7 40 08 65 73 75 6c 	movl   $0x6c757365,0x8(%eax)
 804988e:	c7 40 0c 74 20 73 74 	movl   $0x74732074,0xc(%eax)
 8049895:	c7 40 10 72 69 6e 67 	movl   $0x676e6972,0x10(%eax)
 804989c:	c7 40 14 20 74 6f 6f 	movl   $0x6f6f7420,0x14(%eax)
 80498a3:	c7 40 18 20 6c 61 72 	movl   $0x72616c20,0x18(%eax)
 80498aa:	c7 40 1c 67 65 2e 20 	movl   $0x202e6567,0x1c(%eax)
 80498b1:	c7 40 20 49 6e 63 72 	movl   $0x72636e49,0x20(%eax)
 80498b8:	c7 40 24 65 61 73 65 	movl   $0x65736165,0x24(%eax)
 80498bf:	c7 40 28 20 53 55 42 	movl   $0x42555320,0x28(%eax)
 80498c6:	c7 40 2c 4d 49 54 52 	movl   $0x5254494d,0x2c(%eax)
 80498cd:	c7 40 30 5f 4d 41 58 	movl   $0x58414d5f,0x30(%eax)
 80498d4:	c7 40 34 42 55 46 00 	movl   $0x465542,0x34(%eax)
 80498db:	8b 85 b4 5f ff ff    	mov    -0xa04c(%ebp),%eax
 80498e1:	89 04 24             	mov    %eax,(%esp)
 80498e4:	e8 37 f1 ff ff       	call   8048a20 <close@plt>
 80498e9:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 80498ee:	e9 5c 04 00 00       	jmp    8049d4f <submitr+0x717>
 80498f3:	8d 95 d8 7f ff ff    	lea    -0x8028(%ebp),%edx
 80498f9:	b9 00 08 00 00       	mov    $0x800,%ecx
 80498fe:	b8 00 00 00 00       	mov    $0x0,%eax
 8049903:	89 d7                	mov    %edx,%edi
 8049905:	f3 ab                	rep stos %eax,%es:(%edi)
 8049907:	89 df                	mov    %ebx,%edi
 8049909:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 804990e:	f2 ae                	repnz scas %es:(%edi),%al
 8049910:	f7 d1                	not    %ecx
 8049912:	83 e9 01             	sub    $0x1,%ecx
 8049915:	89 ce                	mov    %ecx,%esi
 8049917:	0f 84 47 04 00 00    	je     8049d64 <submitr+0x72c>
 804991d:	89 d7                	mov    %edx,%edi
 804991f:	0f b6 03             	movzbl (%ebx),%eax
 8049922:	3c 2a                	cmp    $0x2a,%al
 8049924:	74 21                	je     8049947 <submitr+0x30f>
 8049926:	8d 50 d3             	lea    -0x2d(%eax),%edx
 8049929:	80 fa 01             	cmp    $0x1,%dl
 804992c:	76 19                	jbe    8049947 <submitr+0x30f>
 804992e:	3c 5f                	cmp    $0x5f,%al
 8049930:	74 15                	je     8049947 <submitr+0x30f>
 8049932:	8d 50 d0             	lea    -0x30(%eax),%edx
 8049935:	80 fa 09             	cmp    $0x9,%dl
 8049938:	76 0d                	jbe    8049947 <submitr+0x30f>
 804993a:	89 c2                	mov    %eax,%edx
 804993c:	83 e2 df             	and    $0xffffffdf,%edx
 804993f:	83 ea 41             	sub    $0x41,%edx
 8049942:	80 fa 19             	cmp    $0x19,%dl
 8049945:	77 07                	ja     804994e <submitr+0x316>
 8049947:	8d 57 01             	lea    0x1(%edi),%edx
 804994a:	88 07                	mov    %al,(%edi)
 804994c:	eb 69                	jmp    80499b7 <submitr+0x37f>
 804994e:	3c 20                	cmp    $0x20,%al
 8049950:	75 08                	jne    804995a <submitr+0x322>
 8049952:	8d 57 01             	lea    0x1(%edi),%edx
 8049955:	c6 07 2b             	movb   $0x2b,(%edi)
 8049958:	eb 5d                	jmp    80499b7 <submitr+0x37f>
 804995a:	8d 50 e0             	lea    -0x20(%eax),%edx
 804995d:	80 fa 5f             	cmp    $0x5f,%dl
 8049960:	76 08                	jbe    804996a <submitr+0x332>
 8049962:	3c 09                	cmp    $0x9,%al
 8049964:	0f 85 78 04 00 00    	jne    8049de2 <submitr+0x7aa>
 804996a:	0f b6 c0             	movzbl %al,%eax
 804996d:	89 44 24 10          	mov    %eax,0x10(%esp)
 8049971:	c7 44 24 0c 68 a9 04 	movl   $0x804a968,0xc(%esp)
 8049978:	08 
 8049979:	c7 44 24 08 08 00 00 	movl   $0x8,0x8(%esp)
 8049980:	00 
 8049981:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8049988:	00 
 8049989:	8d 85 d8 df ff ff    	lea    -0x2028(%ebp),%eax
 804998f:	89 04 24             	mov    %eax,(%esp)
 8049992:	e8 a9 f0 ff ff       	call   8048a40 <__sprintf_chk@plt>
 8049997:	0f b6 85 d8 df ff ff 	movzbl -0x2028(%ebp),%eax
 804999e:	88 07                	mov    %al,(%edi)
 80499a0:	0f b6 85 d9 df ff ff 	movzbl -0x2027(%ebp),%eax
 80499a7:	88 47 01             	mov    %al,0x1(%edi)
 80499aa:	8d 57 03             	lea    0x3(%edi),%edx
 80499ad:	0f b6 85 da df ff ff 	movzbl -0x2026(%ebp),%eax
 80499b4:	88 47 02             	mov    %al,0x2(%edi)
 80499b7:	83 c3 01             	add    $0x1,%ebx
 80499ba:	83 ee 01             	sub    $0x1,%esi
 80499bd:	0f 84 a1 03 00 00    	je     8049d64 <submitr+0x72c>
 80499c3:	89 d7                	mov    %edx,%edi
 80499c5:	e9 55 ff ff ff       	jmp    804991f <submitr+0x2e7>
 80499ca:	89 5c 24 08          	mov    %ebx,0x8(%esp)
 80499ce:	89 74 24 04          	mov    %esi,0x4(%esp)
 80499d2:	89 3c 24             	mov    %edi,(%esp)
 80499d5:	e8 66 ef ff ff       	call   8048940 <write@plt>
 80499da:	85 c0                	test   %eax,%eax
 80499dc:	7f 0f                	jg     80499ed <submitr+0x3b5>
 80499de:	e8 bd ef ff ff       	call   80489a0 <__errno_location@plt>
 80499e3:	83 38 04             	cmpl   $0x4,(%eax)
 80499e6:	75 15                	jne    80499fd <submitr+0x3c5>
 80499e8:	b8 00 00 00 00       	mov    $0x0,%eax
 80499ed:	01 c6                	add    %eax,%esi
 80499ef:	29 c3                	sub    %eax,%ebx
 80499f1:	75 d7                	jne    80499ca <submitr+0x392>
 80499f3:	8b bd b0 5f ff ff    	mov    -0xa050(%ebp),%edi
 80499f9:	85 ff                	test   %edi,%edi
 80499fb:	79 6a                	jns    8049a67 <submitr+0x42f>
 80499fd:	8b 85 a4 5f ff ff    	mov    -0xa05c(%ebp),%eax
 8049a03:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 8049a09:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 8049a10:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 8049a17:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 8049a1e:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 8049a25:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 8049a2c:	c7 40 18 77 72 69 74 	movl   $0x74697277,0x18(%eax)
 8049a33:	c7 40 1c 65 20 74 6f 	movl   $0x6f742065,0x1c(%eax)
 8049a3a:	c7 40 20 20 74 68 65 	movl   $0x65687420,0x20(%eax)
 8049a41:	c7 40 24 20 73 65 72 	movl   $0x72657320,0x24(%eax)
 8049a48:	c7 40 28 76 65 72 00 	movl   $0x726576,0x28(%eax)
 8049a4f:	8b 85 b4 5f ff ff    	mov    -0xa04c(%ebp),%eax
 8049a55:	89 04 24             	mov    %eax,(%esp)
 8049a58:	e8 c3 ef ff ff       	call   8048a20 <close@plt>
 8049a5d:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049a62:	e9 e8 02 00 00       	jmp    8049d4f <submitr+0x717>
 8049a67:	8b 85 b4 5f ff ff    	mov    -0xa04c(%ebp),%eax
 8049a6d:	89 85 d8 df ff ff    	mov    %eax,-0x2028(%ebp)
 8049a73:	c7 85 dc df ff ff 00 	movl   $0x0,-0x2024(%ebp)
 8049a7a:	00 00 00 
 8049a7d:	8d 85 e4 df ff ff    	lea    -0x201c(%ebp),%eax
 8049a83:	89 85 e0 df ff ff    	mov    %eax,-0x2020(%ebp)
 8049a89:	b9 00 20 00 00       	mov    $0x2000,%ecx
 8049a8e:	8d 95 d8 5f ff ff    	lea    -0xa028(%ebp),%edx
 8049a94:	8d 85 d8 df ff ff    	lea    -0x2028(%ebp),%eax
 8049a9a:	e8 8f fa ff ff       	call   804952e <rio_readlineb>
 8049a9f:	85 c0                	test   %eax,%eax
 8049aa1:	7f 7e                	jg     8049b21 <submitr+0x4e9>
 8049aa3:	8b 85 a4 5f ff ff    	mov    -0xa05c(%ebp),%eax
 8049aa9:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 8049aaf:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 8049ab6:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 8049abd:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 8049ac4:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 8049acb:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 8049ad2:	c7 40 18 72 65 61 64 	movl   $0x64616572,0x18(%eax)
 8049ad9:	c7 40 1c 20 66 69 72 	movl   $0x72696620,0x1c(%eax)
 8049ae0:	c7 40 20 73 74 20 68 	movl   $0x68207473,0x20(%eax)
 8049ae7:	c7 40 24 65 61 64 65 	movl   $0x65646165,0x24(%eax)
 8049aee:	c7 40 28 72 20 66 72 	movl   $0x72662072,0x28(%eax)
 8049af5:	c7 40 2c 6f 6d 20 73 	movl   $0x73206d6f,0x2c(%eax)
 8049afc:	c7 40 30 65 72 76 65 	movl   $0x65767265,0x30(%eax)
 8049b03:	66 c7 40 34 72 00    	movw   $0x72,0x34(%eax)
 8049b09:	8b 85 b4 5f ff ff    	mov    -0xa04c(%ebp),%eax
 8049b0f:	89 04 24             	mov    %eax,(%esp)
 8049b12:	e8 09 ef ff ff       	call   8048a20 <close@plt>
 8049b17:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049b1c:	e9 2e 02 00 00       	jmp    8049d4f <submitr+0x717>
 8049b21:	8d 85 d8 bf ff ff    	lea    -0x4028(%ebp),%eax
 8049b27:	89 44 24 10          	mov    %eax,0x10(%esp)
 8049b2b:	8d 85 c4 5f ff ff    	lea    -0xa03c(%ebp),%eax
 8049b31:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8049b35:	8d 85 d8 9f ff ff    	lea    -0x6028(%ebp),%eax
 8049b3b:	89 44 24 08          	mov    %eax,0x8(%esp)
 8049b3f:	c7 44 24 04 6f a9 04 	movl   $0x804a96f,0x4(%esp)
 8049b46:	08 
 8049b47:	8d 85 d8 5f ff ff    	lea    -0xa028(%ebp),%eax
 8049b4d:	89 04 24             	mov    %eax,(%esp)
 8049b50:	e8 1b ee ff ff       	call   8048970 <__isoc99_sscanf@plt>
 8049b55:	8b 85 c4 5f ff ff    	mov    -0xa03c(%ebp),%eax
 8049b5b:	3d c8 00 00 00       	cmp    $0xc8,%eax
 8049b60:	0f 84 db 00 00 00    	je     8049c41 <submitr+0x609>
 8049b66:	8d 95 d8 bf ff ff    	lea    -0x4028(%ebp),%edx
 8049b6c:	89 54 24 14          	mov    %edx,0x14(%esp)
 8049b70:	89 44 24 10          	mov    %eax,0x10(%esp)
 8049b74:	c7 44 24 0c 7c a8 04 	movl   $0x804a87c,0xc(%esp)
 8049b7b:	08 
 8049b7c:	c7 44 24 08 ff ff ff 	movl   $0xffffffff,0x8(%esp)
 8049b83:	ff 
 8049b84:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8049b8b:	00 
 8049b8c:	8b 85 a4 5f ff ff    	mov    -0xa05c(%ebp),%eax
 8049b92:	89 04 24             	mov    %eax,(%esp)
 8049b95:	e8 a6 ee ff ff       	call   8048a40 <__sprintf_chk@plt>
 8049b9a:	8b 85 b4 5f ff ff    	mov    -0xa04c(%ebp),%eax
 8049ba0:	89 04 24             	mov    %eax,(%esp)
 8049ba3:	e8 78 ee ff ff       	call   8048a20 <close@plt>
 8049ba8:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049bad:	e9 9d 01 00 00       	jmp    8049d4f <submitr+0x717>
 8049bb2:	b9 00 20 00 00       	mov    $0x2000,%ecx
 8049bb7:	8d 95 d8 5f ff ff    	lea    -0xa028(%ebp),%edx
 8049bbd:	8d 85 d8 df ff ff    	lea    -0x2028(%ebp),%eax
 8049bc3:	e8 66 f9 ff ff       	call   804952e <rio_readlineb>
 8049bc8:	85 c0                	test   %eax,%eax
 8049bca:	7f 75                	jg     8049c41 <submitr+0x609>
 8049bcc:	8b 85 a4 5f ff ff    	mov    -0xa05c(%ebp),%eax
 8049bd2:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 8049bd8:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 8049bdf:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 8049be6:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 8049bed:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 8049bf4:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 8049bfb:	c7 40 18 72 65 61 64 	movl   $0x64616572,0x18(%eax)
 8049c02:	c7 40 1c 20 68 65 61 	movl   $0x61656820,0x1c(%eax)
 8049c09:	c7 40 20 64 65 72 73 	movl   $0x73726564,0x20(%eax)
 8049c10:	c7 40 24 20 66 72 6f 	movl   $0x6f726620,0x24(%eax)
 8049c17:	c7 40 28 6d 20 73 65 	movl   $0x6573206d,0x28(%eax)
 8049c1e:	c7 40 2c 72 76 65 72 	movl   $0x72657672,0x2c(%eax)
 8049c25:	c6 40 30 00          	movb   $0x0,0x30(%eax)
 8049c29:	8b 85 b4 5f ff ff    	mov    -0xa04c(%ebp),%eax
 8049c2f:	89 04 24             	mov    %eax,(%esp)
 8049c32:	e8 e9 ed ff ff       	call   8048a20 <close@plt>
 8049c37:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049c3c:	e9 0e 01 00 00       	jmp    8049d4f <submitr+0x717>
 8049c41:	80 bd d8 5f ff ff 0d 	cmpb   $0xd,-0xa028(%ebp)
 8049c48:	0f 85 64 ff ff ff    	jne    8049bb2 <submitr+0x57a>
 8049c4e:	80 bd d9 5f ff ff 0a 	cmpb   $0xa,-0xa027(%ebp)
 8049c55:	0f 85 57 ff ff ff    	jne    8049bb2 <submitr+0x57a>
 8049c5b:	80 bd da 5f ff ff 00 	cmpb   $0x0,-0xa026(%ebp)
 8049c62:	0f 85 4a ff ff ff    	jne    8049bb2 <submitr+0x57a>
 8049c68:	b9 00 20 00 00       	mov    $0x2000,%ecx
 8049c6d:	8d 95 d8 5f ff ff    	lea    -0xa028(%ebp),%edx
 8049c73:	8d 85 d8 df ff ff    	lea    -0x2028(%ebp),%eax
 8049c79:	e8 b0 f8 ff ff       	call   804952e <rio_readlineb>
 8049c7e:	85 c0                	test   %eax,%eax
 8049c80:	7f 7c                	jg     8049cfe <submitr+0x6c6>
 8049c82:	8b 85 a4 5f ff ff    	mov    -0xa05c(%ebp),%eax
 8049c88:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 8049c8e:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 8049c95:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 8049c9c:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 8049ca3:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 8049caa:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 8049cb1:	c7 40 18 72 65 61 64 	movl   $0x64616572,0x18(%eax)
 8049cb8:	c7 40 1c 20 73 74 61 	movl   $0x61747320,0x1c(%eax)
 8049cbf:	c7 40 20 74 75 73 20 	movl   $0x20737574,0x20(%eax)
 8049cc6:	c7 40 24 6d 65 73 73 	movl   $0x7373656d,0x24(%eax)
 8049ccd:	c7 40 28 61 67 65 20 	movl   $0x20656761,0x28(%eax)
 8049cd4:	c7 40 2c 66 72 6f 6d 	movl   $0x6d6f7266,0x2c(%eax)
 8049cdb:	c7 40 30 20 73 65 72 	movl   $0x72657320,0x30(%eax)
 8049ce2:	c7 40 34 76 65 72 00 	movl   $0x726576,0x34(%eax)
 8049ce9:	8b 85 b4 5f ff ff    	mov    -0xa04c(%ebp),%eax
 8049cef:	89 04 24             	mov    %eax,(%esp)
 8049cf2:	e8 29 ed ff ff       	call   8048a20 <close@plt>
 8049cf7:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049cfc:	eb 51                	jmp    8049d4f <submitr+0x717>
 8049cfe:	8d 85 d8 5f ff ff    	lea    -0xa028(%ebp),%eax
 8049d04:	89 44 24 04          	mov    %eax,0x4(%esp)
 8049d08:	8b b5 a4 5f ff ff    	mov    -0xa05c(%ebp),%esi
 8049d0e:	89 34 24             	mov    %esi,(%esp)
 8049d11:	e8 7a eb ff ff       	call   8048890 <strcpy@plt>
 8049d16:	8b 85 b4 5f ff ff    	mov    -0xa04c(%ebp),%eax
 8049d1c:	89 04 24             	mov    %eax,(%esp)
 8049d1f:	e8 fc ec ff ff       	call   8048a20 <close@plt>
 8049d24:	0f b6 06             	movzbl (%esi),%eax
 8049d27:	83 e8 4f             	sub    $0x4f,%eax
 8049d2a:	75 19                	jne    8049d45 <submitr+0x70d>
 8049d2c:	8b 85 a4 5f ff ff    	mov    -0xa05c(%ebp),%eax
 8049d32:	0f b6 40 01          	movzbl 0x1(%eax),%eax
 8049d36:	83 e8 4b             	sub    $0x4b,%eax
 8049d39:	75 0a                	jne    8049d45 <submitr+0x70d>
 8049d3b:	8b 85 a4 5f ff ff    	mov    -0xa05c(%ebp),%eax
 8049d41:	0f b6 40 02          	movzbl 0x2(%eax),%eax
 8049d45:	85 c0                	test   %eax,%eax
 8049d47:	0f 95 c0             	setne  %al
 8049d4a:	0f b6 c0             	movzbl %al,%eax
 8049d4d:	f7 d8                	neg    %eax
 8049d4f:	8b 4d e4             	mov    -0x1c(%ebp),%ecx
 8049d52:	65 33 0d 14 00 00 00 	xor    %gs:0x14,%ecx
 8049d59:	0f 84 0a 01 00 00    	je     8049e69 <submitr+0x831>
 8049d5f:	e9 00 01 00 00       	jmp    8049e64 <submitr+0x82c>
 8049d64:	8d 85 d8 7f ff ff    	lea    -0x8028(%ebp),%eax
 8049d6a:	89 44 24 1c          	mov    %eax,0x1c(%esp)
 8049d6e:	8b 85 a8 5f ff ff    	mov    -0xa058(%ebp),%eax
 8049d74:	89 44 24 18          	mov    %eax,0x18(%esp)
 8049d78:	8b 85 ac 5f ff ff    	mov    -0xa054(%ebp),%eax
 8049d7e:	89 44 24 14          	mov    %eax,0x14(%esp)
 8049d82:	8b 85 b0 5f ff ff    	mov    -0xa050(%ebp),%eax
 8049d88:	89 44 24 10          	mov    %eax,0x10(%esp)
 8049d8c:	c7 44 24 0c ac a8 04 	movl   $0x804a8ac,0xc(%esp)
 8049d93:	08 
 8049d94:	c7 44 24 08 00 20 00 	movl   $0x2000,0x8(%esp)
 8049d9b:	00 
 8049d9c:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8049da3:	00 
 8049da4:	8d bd d8 5f ff ff    	lea    -0xa028(%ebp),%edi
 8049daa:	89 3c 24             	mov    %edi,(%esp)
 8049dad:	e8 8e ec ff ff       	call   8048a40 <__sprintf_chk@plt>
 8049db2:	b8 00 00 00 00       	mov    $0x0,%eax
 8049db7:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 8049dbc:	f2 ae                	repnz scas %es:(%edi),%al
 8049dbe:	f7 d1                	not    %ecx
 8049dc0:	83 e9 01             	sub    $0x1,%ecx
 8049dc3:	0f 84 9e fc ff ff    	je     8049a67 <submitr+0x42f>
 8049dc9:	89 cb                	mov    %ecx,%ebx
 8049dcb:	8d b5 d8 5f ff ff    	lea    -0xa028(%ebp),%esi
 8049dd1:	89 8d b0 5f ff ff    	mov    %ecx,-0xa050(%ebp)
 8049dd7:	8b bd b4 5f ff ff    	mov    -0xa04c(%ebp),%edi
 8049ddd:	e9 e8 fb ff ff       	jmp    80499ca <submitr+0x392>
 8049de2:	8b 8d a4 5f ff ff    	mov    -0xa05c(%ebp),%ecx
 8049de8:	89 cf                	mov    %ecx,%edi
 8049dea:	be f8 a8 04 08       	mov    $0x804a8f8,%esi
 8049def:	b8 43 00 00 00       	mov    $0x43,%eax
 8049df4:	f6 c1 01             	test   $0x1,%cl
 8049df7:	74 16                	je     8049e0f <submitr+0x7d7>
 8049df9:	0f b6 05 f8 a8 04 08 	movzbl 0x804a8f8,%eax
 8049e00:	88 01                	mov    %al,(%ecx)
 8049e02:	8d 79 01             	lea    0x1(%ecx),%edi
 8049e05:	be f9 a8 04 08       	mov    $0x804a8f9,%esi
 8049e0a:	b8 42 00 00 00       	mov    $0x42,%eax
 8049e0f:	f7 c7 02 00 00 00    	test   $0x2,%edi
 8049e15:	74 0f                	je     8049e26 <submitr+0x7ee>
 8049e17:	0f b7 16             	movzwl (%esi),%edx
 8049e1a:	66 89 17             	mov    %dx,(%edi)
 8049e1d:	83 c7 02             	add    $0x2,%edi
 8049e20:	83 c6 02             	add    $0x2,%esi
 8049e23:	83 e8 02             	sub    $0x2,%eax
 8049e26:	89 c1                	mov    %eax,%ecx
 8049e28:	c1 e9 02             	shr    $0x2,%ecx
 8049e2b:	f3 a5                	rep movsl %ds:(%esi),%es:(%edi)
 8049e2d:	ba 00 00 00 00       	mov    $0x0,%edx
 8049e32:	a8 02                	test   $0x2,%al
 8049e34:	74 0b                	je     8049e41 <submitr+0x809>
 8049e36:	0f b7 16             	movzwl (%esi),%edx
 8049e39:	66 89 17             	mov    %dx,(%edi)
 8049e3c:	ba 02 00 00 00       	mov    $0x2,%edx
 8049e41:	a8 01                	test   $0x1,%al
 8049e43:	74 07                	je     8049e4c <submitr+0x814>
 8049e45:	0f b6 04 16          	movzbl (%esi,%edx,1),%eax
 8049e49:	88 04 17             	mov    %al,(%edi,%edx,1)
 8049e4c:	8b 85 b4 5f ff ff    	mov    -0xa04c(%ebp),%eax
 8049e52:	89 04 24             	mov    %eax,(%esp)
 8049e55:	e8 c6 eb ff ff       	call   8048a20 <close@plt>
 8049e5a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049e5f:	e9 eb fe ff ff       	jmp    8049d4f <submitr+0x717>
 8049e64:	e8 f7 e9 ff ff       	call   8048860 <__stack_chk_fail@plt>
 8049e69:	81 c4 7c a0 00 00    	add    $0xa07c,%esp
 8049e6f:	5b                   	pop    %ebx
 8049e70:	5e                   	pop    %esi
 8049e71:	5f                   	pop    %edi
 8049e72:	5d                   	pop    %ebp
 8049e73:	c3                   	ret    

08049e74 <init_timeout>:
 8049e74:	55                   	push   %ebp
 8049e75:	89 e5                	mov    %esp,%ebp
 8049e77:	53                   	push   %ebx
 8049e78:	83 ec 14             	sub    $0x14,%esp
 8049e7b:	8b 5d 08             	mov    0x8(%ebp),%ebx
 8049e7e:	85 db                	test   %ebx,%ebx
 8049e80:	74 26                	je     8049ea8 <init_timeout+0x34>
 8049e82:	85 db                	test   %ebx,%ebx
 8049e84:	b8 02 00 00 00       	mov    $0x2,%eax
 8049e89:	0f 48 d8             	cmovs  %eax,%ebx
 8049e8c:	c7 44 24 04 00 95 04 	movl   $0x8049500,0x4(%esp)
 8049e93:	08 
 8049e94:	c7 04 24 0e 00 00 00 	movl   $0xe,(%esp)
 8049e9b:	e8 a0 e9 ff ff       	call   8048840 <signal@plt>
 8049ea0:	89 1c 24             	mov    %ebx,(%esp)
 8049ea3:	e8 a8 e9 ff ff       	call   8048850 <alarm@plt>
 8049ea8:	83 c4 14             	add    $0x14,%esp
 8049eab:	5b                   	pop    %ebx
 8049eac:	5d                   	pop    %ebp
 8049ead:	c3                   	ret    

08049eae <init_driver>:
 8049eae:	55                   	push   %ebp
 8049eaf:	89 e5                	mov    %esp,%ebp
 8049eb1:	57                   	push   %edi
 8049eb2:	56                   	push   %esi
 8049eb3:	53                   	push   %ebx
 8049eb4:	83 ec 4c             	sub    $0x4c,%esp
 8049eb7:	8b 75 08             	mov    0x8(%ebp),%esi
 8049eba:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 8049ec0:	89 45 e4             	mov    %eax,-0x1c(%ebp)
 8049ec3:	31 c0                	xor    %eax,%eax
 8049ec5:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8049ecc:	00 
 8049ecd:	c7 04 24 0d 00 00 00 	movl   $0xd,(%esp)
 8049ed4:	e8 67 e9 ff ff       	call   8048840 <signal@plt>
 8049ed9:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8049ee0:	00 
 8049ee1:	c7 04 24 1d 00 00 00 	movl   $0x1d,(%esp)
 8049ee8:	e8 53 e9 ff ff       	call   8048840 <signal@plt>
 8049eed:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8049ef4:	00 
 8049ef5:	c7 04 24 1d 00 00 00 	movl   $0x1d,(%esp)
 8049efc:	e8 3f e9 ff ff       	call   8048840 <signal@plt>
 8049f01:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 8049f08:	00 
 8049f09:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8049f10:	00 
 8049f11:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
 8049f18:	e8 c3 ea ff ff       	call   80489e0 <socket@plt>
 8049f1d:	89 c3                	mov    %eax,%ebx
 8049f1f:	85 c0                	test   %eax,%eax
 8049f21:	79 4e                	jns    8049f71 <init_driver+0xc3>
 8049f23:	c7 06 45 72 72 6f    	movl   $0x6f727245,(%esi)
 8049f29:	c7 46 04 72 3a 20 43 	movl   $0x43203a72,0x4(%esi)
 8049f30:	c7 46 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%esi)
 8049f37:	c7 46 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%esi)
 8049f3e:	c7 46 10 61 62 6c 65 	movl   $0x656c6261,0x10(%esi)
 8049f45:	c7 46 14 20 74 6f 20 	movl   $0x206f7420,0x14(%esi)
 8049f4c:	c7 46 18 63 72 65 61 	movl   $0x61657263,0x18(%esi)
 8049f53:	c7 46 1c 74 65 20 73 	movl   $0x73206574,0x1c(%esi)
 8049f5a:	c7 46 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%esi)
 8049f61:	66 c7 46 24 74 00    	movw   $0x74,0x24(%esi)
 8049f67:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049f6c:	e9 05 01 00 00       	jmp    804a076 <init_driver+0x1c8>
 8049f71:	c7 04 24 eb a7 04 08 	movl   $0x804a7eb,(%esp)
 8049f78:	e8 83 ea ff ff       	call   8048a00 <gethostbyname@plt>
 8049f7d:	85 c0                	test   %eax,%eax
 8049f7f:	75 3a                	jne    8049fbb <init_driver+0x10d>
 8049f81:	c7 44 24 10 eb a7 04 	movl   $0x804a7eb,0x10(%esp)
 8049f88:	08 
 8049f89:	c7 44 24 0c 28 a8 04 	movl   $0x804a828,0xc(%esp)
 8049f90:	08 
 8049f91:	c7 44 24 08 ff ff ff 	movl   $0xffffffff,0x8(%esp)
 8049f98:	ff 
 8049f99:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8049fa0:	00 
 8049fa1:	89 34 24             	mov    %esi,(%esp)
 8049fa4:	e8 97 ea ff ff       	call   8048a40 <__sprintf_chk@plt>
 8049fa9:	89 1c 24             	mov    %ebx,(%esp)
 8049fac:	e8 6f ea ff ff       	call   8048a20 <close@plt>
 8049fb1:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049fb6:	e9 bb 00 00 00       	jmp    804a076 <init_driver+0x1c8>
 8049fbb:	8d 7d d4             	lea    -0x2c(%ebp),%edi
 8049fbe:	c7 45 d4 00 00 00 00 	movl   $0x0,-0x2c(%ebp)
 8049fc5:	c7 45 d8 00 00 00 00 	movl   $0x0,-0x28(%ebp)
 8049fcc:	c7 45 dc 00 00 00 00 	movl   $0x0,-0x24(%ebp)
 8049fd3:	c7 45 e0 00 00 00 00 	movl   $0x0,-0x20(%ebp)
 8049fda:	66 c7 45 d4 02 00    	movw   $0x2,-0x2c(%ebp)
 8049fe0:	c7 44 24 0c 0c 00 00 	movl   $0xc,0xc(%esp)
 8049fe7:	00 
 8049fe8:	8b 50 0c             	mov    0xc(%eax),%edx
 8049feb:	89 54 24 08          	mov    %edx,0x8(%esp)
 8049fef:	8b 40 10             	mov    0x10(%eax),%eax
 8049ff2:	8b 00                	mov    (%eax),%eax
 8049ff4:	89 44 24 04          	mov    %eax,0x4(%esp)
 8049ff8:	8d 45 d8             	lea    -0x28(%ebp),%eax
 8049ffb:	89 04 24             	mov    %eax,(%esp)
 8049ffe:	e8 cd e8 ff ff       	call   80488d0 <__memmove_chk@plt>
 804a003:	66 c7 45 d6 47 26    	movw   $0x2647,-0x2a(%ebp)
 804a009:	c7 44 24 08 10 00 00 	movl   $0x10,0x8(%esp)
 804a010:	00 
 804a011:	89 7c 24 04          	mov    %edi,0x4(%esp)
 804a015:	89 1c 24             	mov    %ebx,(%esp)
 804a018:	e8 f3 e9 ff ff       	call   8048a10 <connect@plt>
 804a01d:	85 c0                	test   %eax,%eax
 804a01f:	79 3f                	jns    804a060 <init_driver+0x1b2>
 804a021:	c7 44 24 14 26 47 00 	movl   $0x4726,0x14(%esp)
 804a028:	00 
 804a029:	c7 44 24 10 eb a7 04 	movl   $0x804a7eb,0x10(%esp)
 804a030:	08 
 804a031:	c7 44 24 0c 3c a9 04 	movl   $0x804a93c,0xc(%esp)
 804a038:	08 
 804a039:	c7 44 24 08 ff ff ff 	movl   $0xffffffff,0x8(%esp)
 804a040:	ff 
 804a041:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 804a048:	00 
 804a049:	89 34 24             	mov    %esi,(%esp)
 804a04c:	e8 ef e9 ff ff       	call   8048a40 <__sprintf_chk@plt>
 804a051:	89 1c 24             	mov    %ebx,(%esp)
 804a054:	e8 c7 e9 ff ff       	call   8048a20 <close@plt>
 804a059:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 804a05e:	eb 16                	jmp    804a076 <init_driver+0x1c8>
 804a060:	89 1c 24             	mov    %ebx,(%esp)
 804a063:	e8 b8 e9 ff ff       	call   8048a20 <close@plt>
 804a068:	66 c7 06 4f 4b       	movw   $0x4b4f,(%esi)
 804a06d:	c6 46 02 00          	movb   $0x0,0x2(%esi)
 804a071:	b8 00 00 00 00       	mov    $0x0,%eax
 804a076:	8b 4d e4             	mov    -0x1c(%ebp),%ecx
 804a079:	65 33 0d 14 00 00 00 	xor    %gs:0x14,%ecx
 804a080:	74 05                	je     804a087 <init_driver+0x1d9>
 804a082:	e8 d9 e7 ff ff       	call   8048860 <__stack_chk_fail@plt>
 804a087:	83 c4 4c             	add    $0x4c,%esp
 804a08a:	5b                   	pop    %ebx
 804a08b:	5e                   	pop    %esi
 804a08c:	5f                   	pop    %edi
 804a08d:	5d                   	pop    %ebp
 804a08e:	c3                   	ret    

0804a08f <driver_post>:
 804a08f:	55                   	push   %ebp
 804a090:	89 e5                	mov    %esp,%ebp
 804a092:	53                   	push   %ebx
 804a093:	83 ec 24             	sub    $0x24,%esp
 804a096:	8b 45 08             	mov    0x8(%ebp),%eax
 804a099:	8b 5d 14             	mov    0x14(%ebp),%ebx
 804a09c:	83 7d 10 00          	cmpl   $0x0,0x10(%ebp)
 804a0a0:	74 2b                	je     804a0cd <driver_post+0x3e>
 804a0a2:	8b 45 0c             	mov    0xc(%ebp),%eax
 804a0a5:	89 44 24 08          	mov    %eax,0x8(%esp)
 804a0a9:	c7 44 24 04 80 a9 04 	movl   $0x804a980,0x4(%esp)
 804a0b0:	08 
 804a0b1:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 804a0b8:	e8 03 e9 ff ff       	call   80489c0 <__printf_chk@plt>
 804a0bd:	66 c7 03 4f 4b       	movw   $0x4b4f,(%ebx)
 804a0c2:	c6 43 02 00          	movb   $0x0,0x2(%ebx)
 804a0c6:	b8 00 00 00 00       	mov    $0x0,%eax
 804a0cb:	eb 4c                	jmp    804a119 <driver_post+0x8a>
 804a0cd:	85 c0                	test   %eax,%eax
 804a0cf:	74 3a                	je     804a10b <driver_post+0x7c>
 804a0d1:	80 38 00             	cmpb   $0x0,(%eax)
 804a0d4:	74 35                	je     804a10b <driver_post+0x7c>
 804a0d6:	89 5c 24 18          	mov    %ebx,0x18(%esp)
 804a0da:	8b 55 0c             	mov    0xc(%ebp),%edx
 804a0dd:	89 54 24 14          	mov    %edx,0x14(%esp)
 804a0e1:	c7 44 24 10 97 a9 04 	movl   $0x804a997,0x10(%esp)
 804a0e8:	08 
 804a0e9:	89 44 24 0c          	mov    %eax,0xc(%esp)
 804a0ed:	c7 44 24 08 9e a9 04 	movl   $0x804a99e,0x8(%esp)
 804a0f4:	08 
 804a0f5:	c7 44 24 04 26 47 00 	movl   $0x4726,0x4(%esp)
 804a0fc:	00 
 804a0fd:	c7 04 24 eb a7 04 08 	movl   $0x804a7eb,(%esp)
 804a104:	e8 2f f5 ff ff       	call   8049638 <submitr>
 804a109:	eb 0e                	jmp    804a119 <driver_post+0x8a>
 804a10b:	66 c7 03 4f 4b       	movw   $0x4b4f,(%ebx)
 804a110:	c6 43 02 00          	movb   $0x0,0x2(%ebx)
 804a114:	b8 00 00 00 00       	mov    $0x0,%eax
 804a119:	83 c4 24             	add    $0x24,%esp
 804a11c:	5b                   	pop    %ebx
 804a11d:	5d                   	pop    %ebp
 804a11e:	c3                   	ret    
 804a11f:	90                   	nop

0804a120 <hash>:
 804a120:	55                   	push   %ebp
 804a121:	89 e5                	mov    %esp,%ebp
 804a123:	8b 4d 08             	mov    0x8(%ebp),%ecx
 804a126:	0f b6 11             	movzbl (%ecx),%edx
 804a129:	84 d2                	test   %dl,%dl
 804a12b:	74 19                	je     804a146 <hash+0x26>
 804a12d:	b8 00 00 00 00       	mov    $0x0,%eax
 804a132:	6b c0 67             	imul   $0x67,%eax,%eax
 804a135:	83 c1 01             	add    $0x1,%ecx
 804a138:	0f be d2             	movsbl %dl,%edx
 804a13b:	01 d0                	add    %edx,%eax
 804a13d:	0f b6 11             	movzbl (%ecx),%edx
 804a140:	84 d2                	test   %dl,%dl
 804a142:	75 ee                	jne    804a132 <hash+0x12>
 804a144:	eb 05                	jmp    804a14b <hash+0x2b>
 804a146:	b8 00 00 00 00       	mov    $0x0,%eax
 804a14b:	5d                   	pop    %ebp
 804a14c:	c3                   	ret    

0804a14d <check>:
 804a14d:	55                   	push   %ebp
 804a14e:	89 e5                	mov    %esp,%ebp
 804a150:	8b 55 08             	mov    0x8(%ebp),%edx
 804a153:	89 d1                	mov    %edx,%ecx
 804a155:	c1 e9 1c             	shr    $0x1c,%ecx
 804a158:	b8 00 00 00 00       	mov    $0x0,%eax
 804a15d:	85 c9                	test   %ecx,%ecx
 804a15f:	74 2f                	je     804a190 <check+0x43>
 804a161:	80 fa 0a             	cmp    $0xa,%dl
 804a164:	74 17                	je     804a17d <check+0x30>
 804a166:	b9 08 00 00 00       	mov    $0x8,%ecx
 804a16b:	89 d0                	mov    %edx,%eax
 804a16d:	d3 e8                	shr    %cl,%eax
 804a16f:	3c 0a                	cmp    $0xa,%al
 804a171:	74 11                	je     804a184 <check+0x37>
 804a173:	83 c1 08             	add    $0x8,%ecx
 804a176:	83 f9 20             	cmp    $0x20,%ecx
 804a179:	75 f0                	jne    804a16b <check+0x1e>
 804a17b:	eb 0e                	jmp    804a18b <check+0x3e>
 804a17d:	b8 00 00 00 00       	mov    $0x0,%eax
 804a182:	eb 0c                	jmp    804a190 <check+0x43>
 804a184:	b8 00 00 00 00       	mov    $0x0,%eax
 804a189:	eb 05                	jmp    804a190 <check+0x43>
 804a18b:	b8 01 00 00 00       	mov    $0x1,%eax
 804a190:	5d                   	pop    %ebp
 804a191:	c3                   	ret    

0804a192 <gencookie>:
 804a192:	55                   	push   %ebp
 804a193:	89 e5                	mov    %esp,%ebp
 804a195:	53                   	push   %ebx
 804a196:	83 ec 14             	sub    $0x14,%esp
 804a199:	8b 45 08             	mov    0x8(%ebp),%eax
 804a19c:	89 04 24             	mov    %eax,(%esp)
 804a19f:	e8 7c ff ff ff       	call   804a120 <hash>
 804a1a4:	89 04 24             	mov    %eax,(%esp)
 804a1a7:	e8 64 e7 ff ff       	call   8048910 <srand@plt>
 804a1ac:	e8 ff e7 ff ff       	call   80489b0 <rand@plt>
 804a1b1:	89 c3                	mov    %eax,%ebx
 804a1b3:	89 04 24             	mov    %eax,(%esp)
 804a1b6:	e8 92 ff ff ff       	call   804a14d <check>
 804a1bb:	85 c0                	test   %eax,%eax
 804a1bd:	74 ed                	je     804a1ac <gencookie+0x1a>
 804a1bf:	89 d8                	mov    %ebx,%eax
 804a1c1:	83 c4 14             	add    $0x14,%esp
 804a1c4:	5b                   	pop    %ebx
 804a1c5:	5d                   	pop    %ebp
 804a1c6:	c3                   	ret    
 804a1c7:	90                   	nop
 804a1c8:	90                   	nop
 804a1c9:	90                   	nop
 804a1ca:	90                   	nop
 804a1cb:	90                   	nop
 804a1cc:	90                   	nop
 804a1cd:	90                   	nop
 804a1ce:	90                   	nop
 804a1cf:	90                   	nop

0804a1d0 <__libc_csu_init>:
 804a1d0:	55                   	push   %ebp
 804a1d1:	57                   	push   %edi
 804a1d2:	56                   	push   %esi
 804a1d3:	53                   	push   %ebx
 804a1d4:	e8 69 00 00 00       	call   804a242 <__i686.get_pc_thunk.bx>
 804a1d9:	81 c3 1b 1e 00 00    	add    $0x1e1b,%ebx
 804a1df:	83 ec 1c             	sub    $0x1c,%esp
 804a1e2:	8b 6c 24 30          	mov    0x30(%esp),%ebp
 804a1e6:	8d bb 0c ff ff ff    	lea    -0xf4(%ebx),%edi
 804a1ec:	e8 f3 e5 ff ff       	call   80487e4 <_init>
 804a1f1:	8d 83 08 ff ff ff    	lea    -0xf8(%ebx),%eax
 804a1f7:	29 c7                	sub    %eax,%edi
 804a1f9:	c1 ff 02             	sar    $0x2,%edi
 804a1fc:	85 ff                	test   %edi,%edi
 804a1fe:	74 29                	je     804a229 <__libc_csu_init+0x59>
 804a200:	31 f6                	xor    %esi,%esi
 804a202:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 804a208:	8b 44 24 38          	mov    0x38(%esp),%eax
 804a20c:	89 2c 24             	mov    %ebp,(%esp)
 804a20f:	89 44 24 08          	mov    %eax,0x8(%esp)
 804a213:	8b 44 24 34          	mov    0x34(%esp),%eax
 804a217:	89 44 24 04          	mov    %eax,0x4(%esp)
 804a21b:	ff 94 b3 08 ff ff ff 	call   *-0xf8(%ebx,%esi,4)
 804a222:	83 c6 01             	add    $0x1,%esi
 804a225:	39 fe                	cmp    %edi,%esi
 804a227:	75 df                	jne    804a208 <__libc_csu_init+0x38>
 804a229:	83 c4 1c             	add    $0x1c,%esp
 804a22c:	5b                   	pop    %ebx
 804a22d:	5e                   	pop    %esi
 804a22e:	5f                   	pop    %edi
 804a22f:	5d                   	pop    %ebp
 804a230:	c3                   	ret    
 804a231:	eb 0d                	jmp    804a240 <__libc_csu_fini>
 804a233:	90                   	nop
 804a234:	90                   	nop
 804a235:	90                   	nop
 804a236:	90                   	nop
 804a237:	90                   	nop
 804a238:	90                   	nop
 804a239:	90                   	nop
 804a23a:	90                   	nop
 804a23b:	90                   	nop
 804a23c:	90                   	nop
 804a23d:	90                   	nop
 804a23e:	90                   	nop
 804a23f:	90                   	nop

0804a240 <__libc_csu_fini>:
 804a240:	f3 c3                	repz ret 

0804a242 <__i686.get_pc_thunk.bx>:
 804a242:	8b 1c 24             	mov    (%esp),%ebx
 804a245:	c3                   	ret    
 804a246:	90                   	nop
 804a247:	90                   	nop

Disassembly of section .fini:

0804a248 <_fini>:
 804a248:	53                   	push   %ebx
 804a249:	83 ec 08             	sub    $0x8,%esp
 804a24c:	e8 00 00 00 00       	call   804a251 <_fini+0x9>
 804a251:	5b                   	pop    %ebx
 804a252:	81 c3 a3 1d 00 00    	add    $0x1da3,%ebx
 804a258:	83 c4 08             	add    $0x8,%esp
 804a25b:	5b                   	pop    %ebx
 804a25c:	c3                   	ret    
