;
; EPITECH PROJECT, 2025
; ASM
; File description:
; memcpy
;

BITS 64

section .text
    global memcpy

memcpy:
    mov rax, rdi         ; Set rax to the destination pointer (rdi)

    test rdi, rdi        ; Check if destination is NULL
    jz .return           ; If NULL, return

    test rsi, rsi        ; Check if source is NULL
    jz .return           ; If NULL, return

    test rdx, rdx        ; Check if length is 0
    jz .return           ; If 0, return

    mov rcx, rdx         ; Set rcx to the length (number of bytes to copy)
    mov r8, rsi          ; Set r8 to the source pointer (rsi)
    mov r9, rdi          ; Set r9 to the destination pointer (rdi)

.copy_loop:
    mov bl, [r8]         ; Load byte from source (r8)
    mov [r9], bl         ; Store byte to destination (r9)

    inc r8               ; Increment source pointer
    inc r9               ; Increment destination pointer

    dec rcx              ; Decrease the counter
    jnz .copy_loop       ; Repeat loop if counter is not zero

.return:
    ret
