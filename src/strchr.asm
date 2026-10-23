;
; EPITECH PROJECT, 2025
; ASM
; File description:
; strchr
;

BITS 64

section .text
    global strchr
    global index

index:
strchr:
    mov rax, rdi         ; Copy string address (rdi) to rax
    mov dl, sil          ; Load target character (sil) into dl

.loop:
    cmp byte [rax], dl    ; Compare byte at rax with target character
    je .found            ; Jump if character is found
    cmp byte [rax], 0     ; Check if end of string is reached
    je .not_found         ; Jump if null terminator is found
    inc rax               ; Increment pointer to next byte in string
    jmp .loop             ; Repeat loop

.found:
    ret

.not_found:
    xor rax, rax          ; Set rax to 0 (not found)
    ret
