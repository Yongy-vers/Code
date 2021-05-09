; hello.asm -- "Hello World!"
;
;	Author: Yongy vers
;	Date: 2021/5/9

	global _start

	section .text

_start:
	mov eax, 0x4		; use the write syscall
	mov ebx, 1		; use stdout as the fd
	mov ecx, message	; use the message as the buffer
	mov edx, message_length	; and supply the length
	int 0x80		; syscall

	; now gracefully exit

	mov eax, 0x1
	mov ebx, 0
	int 0x80


	section .data
message: db "Hello World!", 0xA	; 0xA == 10 == '\n'
message_length equ $-message
