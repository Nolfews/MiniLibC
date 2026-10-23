;
; EPITECH PROJECT, 2025
; ASM
; File description:
; strlen
;

BITS 64

section .text
    global strlen

strlen:
    xor rax, rax         ; Clear rax (will store string length)
    mov rcx, rdi         ; Set rcx to the start of the string (rdi)

.loop:
    cmp byte [rcx], 0    ; Compare current byte with null terminator
    je .done             ; Jump to done if null terminator found
    inc rcx              ; Increment string pointer
    inc rax              ; Increment length counter
    jmp .loop            ; Repeat loop

.done:
    ret
