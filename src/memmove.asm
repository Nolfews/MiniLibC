;
; EPITECH PROJECT, 2025
; ASM
; File description:
; memmove
;

BITS 64

section .text
    global memmove

memmove:
    mov rax, rdi         ; Set rax to the destination pointer (rdi)

    cmp rdx, 0           ; Check if length (rdx) is zero
    je .done             ; If zero, return

    cmp rdi, rsi         ; Compare destination with some register
    je .done             ; If equal, return

    jb .forward_copy     ; If destination is below source, copy forward

    mov rcx, rsi         ; Set rcx to source pointer (rsi)
    add rcx, rdx         ; Add length to source, to check if overlap occurs
    cmp rdi, rcx         ; Compare destination with end of source + length
    jae .forward_copy    ; If destination is after source range, copy forward

.reverse_copy:
    mov rcx, rdx         ; Set rcx to length
    lea r8, [rsi + rdx - 1]  ; Set r8 to the last byte of source
    lea r9, [rdi + rdx - 1]  ; Set r9 to the last byte of destination

.reverse_loop:
    mov bl, [r8]         ; Load byte from source (r8)
    mov [r9], bl         ; Store byte to destination (r9)
    dec r8               ; Decrement source pointer
    dec r9               ; Decrement destination pointer
    dec rcx              ; Decrease the counter
    jnz .reverse_loop    ; Repeat loop until counter is zero
    jmp .done            ; Jump to done when done copying

.forward_copy:
    mov rcx, rdx         ; Set rcx to length
    mov r8, rsi          ; Set r8 to the source pointer (rsi)
    mov r9, rdi          ; Set r9 to the destination pointer (rdi)

.forward_loop:
    mov bl, [r8]         ; Load byte from source (r8)
    mov [r9], bl         ; Store byte to destination (r9)
    inc r8               ; Increment source pointer
    inc r9               ; Increment destination pointer
    dec rcx              ; Decrease the counter
    jnz .forward_loop    ; Repeat loop until counter is zero

.done:
    ret
