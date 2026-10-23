;
; EPITECH PROJECT, 2025
; ASM
; File description:
; memset
;

BITS 64

section .text
    global memset

memset:
    push rbp       ; Save the base pointer
    mov rbp, rsp   ; Set up the new base pointer

    mov r8, rdi    ; Save the destination pointer (return value)
    mov rcx, rdx   ; Load the number of bytes to set
    mov al, sil    ; Load the byte value to set

    test rcx, rcx  ; Check if the length is zero
    jz .done       ; If zero, jump to the end

    mov r9, rdi    ; Copy destination pointer to r9 for iteration

.fill_loop:
    mov [r9], al   ; Store the byte in the memory location
    inc r9         ; Move to the next byte
    dec rcx        ; Decrease the counter
    jnz .fill_loop ; Continue looping if counter is not zero

.done:
    mov rax, r8    ; Return the original destination pointer
    pop rbp        ; Restore the previous base pointer
    ret
