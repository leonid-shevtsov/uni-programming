;;;;; BSD-specific system calls

; print <pointer to string> <length>
%macro print 2
  push dword %2
  push dword %1
  push dword 1
  mov eax, 0x4
  sub esp, 4
  int 0x80
  add esp, 16
  ret
%endmacro

; exit <errorlevel>
%macro exit 1
  push dword %1
  mov eax, 0x1
  int 0x80
%endmacro

; convert <number> <pointer to result> <pointer to result length>
%macro convert 3
; Register usage:
; EAX, EDX, EBX - arithmetics
; CL - sign flag (for entire number)
; EDI - pointer to result

  mov eax, %1
  mov edi, %2
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
  inc dword [%3]
  test eax, eax
  jnz .divide

.addMinus: ; conversion is finished. if number was negative, add a minus
  test cl, cl
  jz .reverse
  mov byte [edi], '-'
  inc edi
  inc dword [%3]

; Register usage:
; AL, AH - buffers
; EDI, EBP - pointers
; ECX - counter

.reverse: ; Reverse the result by swapping pairs of chars from beginning [EDI] and end [EBP]
  mov ebp, edi
  sub edi, [%3]
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

%endmacro


;;;;; Program code

section .text

global start

start:
  convert -895073489, result, reslen
  call printResult
  exit 0

printResult:
  ; add newline
  mov edi, result
  add edi, [reslen]
  mov byte [edi], 0xa ; carriage return
  inc dword [reslen]
  print result, [reslen]
  ret

section .data

result times 15 db 0
; the resulting string
reslen dd 0 ; "dd" to make system call easier
