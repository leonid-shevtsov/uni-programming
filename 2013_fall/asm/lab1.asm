section .text

global start

start:
  mov eax, -895073489
  call convert
  call printResult
  call exit

; Register usage:
; EAX, EDX, EBX - arithmetics
; CL - sign flag (for entire number)
; EDI - pointer to result

convert:
  mov edi, result
  test eax, eax
  mov cl, 0; number is positive
  js .invert
  jmp .divide
.invert:
  mov cl, 1; number is negative
  neg eax
  jmp .divide

.divide: ; actual conversion happens here. classic divisive algorithm
  mov edx, 0
  mov ebx, 10
  div ebx
  add edx, '0'
  mov byte [edi], dl
  inc edi
  inc dword [reslen]
  test eax, eax
  jnz .divide

.addMinus: ; conversion is finished. if number was negative, add a minus
  test cl, cl
  jz .reverse
  mov byte [edi], '-'
  inc edi
  inc dword [reslen]

; Register usage:
; AL, AH - buffers
; EDI, EBP - pointers
; ECX - counter

.reverse: ; Reverse the result by swapping pairs of chars from beginning [EDI] and end [EBP]
  mov ebp, edi
  sub edi, [reslen]
  sub ebp, 1
.swap:
  cmp edi, ebp
  jge .finish
  mov al, [edi]
  mov ah, [ebp]
  mov [edi], ah
  mov [ebp], al
  inc edi
  dec ebp
  jmp .swap

.finish: ; of convert
  ret

;;;;; BSD-specific system calls

printResult:
  ; add newline
  mov edi, result
  add edi, [reslen]
  mov byte [edi], 0xa ; carriage return
  inc dword [reslen]
  ; call print
  push dword [reslen]
  push dword result
  push dword 1
  call .print
  add esp, 12
  ret

.print:
  mov eax, 0x4
  int 0x80
  ret

exit:
  push dword 0
  mov eax, 0x1
  int 0x80

section .data

result times 15 db 0
; the resulting string
reslen dd 0 ; "dd" to make system call easier
