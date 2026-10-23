;
; EPITECH PROJECT, 2025
; ASM
; File description:
; strpbrk
;

BITS 64

section .text
    global strpbrk

strpbrk:
    push rbp             ; Save base pointer
    mov rbp, rsp         ; Set base pointer to current stack pointer
    push rbx             ; Save rbx register
    push r12             ; Save r12 register

    mov r12, rdi         ; Set r12 to first string (rdi)
    mov rbx, rsi         ; Set rbx to second string (rsi)

    cmp byte [r12], 0    ; Check if first string is empty (null byte)
    je .not_found        ; Jump to not_found if first string is empty

.outer_loop:
    movzx eax, byte [r12]    ; Load byte from first string
    test al, al              ; Check if byte is null (end of string)
    jz .not_found            ; Jump if end of first string

    mov rsi, rbx             ; Set rsi to second string (rbx)

.inner_loop:
    movzx edx, byte [rsi]    ; Load byte from second string
    test dl, dl              ; Check if byte is null (end of second string)
    jz .next_char            ; Jump if end of second string

    cmp al, dl               ; Compare bytes
    je .found                ; Jump if a match is found

    inc rsi                  ; Increment pointer for second string
    jmp .inner_loop          ; Repeat inner loop

.next_char:
    inc r12                  ; Increment pointer for first string
    jmp .outer_loop          ; Repeat outer loop

.found:
    mov rax, r12             ; Return pointer to matching byte in first string
    jmp .exit                ; Exit the function

.not_found:
    xor rax, rax             ; Return 0 if no match is found

.exit:
    pop r12                  ; Restore r12 register
    pop rbx                  ; Restore rbx register
    pop rbp                  ; Restore base pointer
    ret
