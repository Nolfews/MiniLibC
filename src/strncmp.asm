;
; EPITECH PROJECT, 2025
; ASM
; File description:
; strncmp
;

BITS 64

section .text
global strncmp

strncmp:
    test rdx, rdx        ; Check if length (rdx) is zero
    jz .equal            ; Jump to equal if length is zero

.loop:
    test rdx, rdx        ; Check if length (rdx) is zero (again)
    jz .equal            ; Jump to equal if length is zero

    mov al, byte [rdi]   ; Load byte from first string (rdi)
    mov bl, byte [rsi]   ; Load byte from second string (rsi)
    cmp al, bl           ; Compare bytes
    jne .not_equal       ; Jump if bytes are not equal

    test al, al          ; Check if end of string (null byte)
    jz .equal            ; Jump to equal if null byte found

    inc rdi              ; Increment pointer for first string
    inc rsi              ; Increment pointer for second string
    dec rdx              ; Decrement remaining length
    jmp .loop            ; Repeat loop

.not_equal:
    sub al, bl           ; Calculate the difference between bytes
    movsx rax, al        ; Sign-extend the result to rax
    ret

.equal:
    xor rax, rax         ; Set rax to 0 (strings are equal)
    ret
