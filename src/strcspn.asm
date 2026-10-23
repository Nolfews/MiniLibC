;
; EPITECH PROJECT, 2025
; ASM
; File description:
; strcspn
;

BITS 64

section .text
    global strcspn

strcspn:
    push rbp             ; Save base pointer
    mov rbp, rsp         ; Set base pointer to current stack pointer
    push rbx             ; Save rbx register
    xor rcx, rcx         ; Clear rcx (will store the result)

.outer_loop:
    movzx rax, byte [rdi]  ; Load byte from first string (rdi)
    test rax, rax          ; Check if byte is null (end of string)
    jz .done               ; Jump to done if end of string

    mov rbx, rsi           ; Set rbx to start of second string (rsi)

.inner_loop:
    movzx rdx, byte [rbx]  ; Load byte from second string (rbx)
    test rdx, rdx          ; Check if byte is null (end of second string)
    jz .continue_outer     ; Jump if end of second string

    cmp rax, rdx           ; Compare current byte from first string with second string
    je .done               ; Jump to done if match found

    inc rbx                ; Increment pointer in second string
    jmp .inner_loop        ; Repeat inner loop

.continue_outer:
    inc rcx                ; Increment length of non-matching part
    inc rdi                ; Increment pointer in first string
    jmp .outer_loop        ; Repeat outer loop

.done:
    mov rax, rcx           ; Return length of non-matching segment in rax
    pop rbx                ; Restore rbx register
    pop rbp                ; Restore base pointer
    ret
