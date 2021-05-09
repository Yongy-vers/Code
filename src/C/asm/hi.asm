; hi.asm -- "Hi, World!" by using a C library.
;	based on x86_64 architecture



	global	main
	extern	puts

	section .text
main:					; This is called by the C library startup code
	mov	rdi, message		
	call	puts			; puts(message)
	ret				; return from main back into C library wrapper

	section .data
message:
	db	"Hi, World!", 0		; C string is ended up with 0
