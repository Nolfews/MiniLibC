;
; EPITECH PROJECT, 2025
; ASM
; File description:
; strcmp
;

BITS 64

section .text
    global strcmp

strcmp:

.loop:
    mov al, byte [rdi]   ; Load byte from first string (rdi)
    mov bl, byte [rsi]   ; Load byte from second string (rsi)
    cmp al, bl           ; Compare the bytes
    jne .not_equal       ; Jump if bytes are not equal
    test al, al          ; Check if end of string (null byte)
    jz .equal            ; Jump if both strings reached null terminator
    inc rdi              ; Increment first string pointer
    inc rsi              ; Increment second string pointer
    jmp .loop            ; Repeat loop

.not_equal:
    sub al, bl           ; Calculate the difference between the bytes
    movsx rax, al        ; Sign-extend the result to rax
    ret

.equal:
    xor rax, rax         ; Set rax to 0 (strings are equal)
    ret
