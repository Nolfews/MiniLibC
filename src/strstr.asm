;
; EPITECH PROJECT, 2025
; ASM
; File description:
; strstr
;

BITS 64

section .text
    global strstr
    extern strncmp

strstr:
    push rbx             ; Save rbx register
    push r12             ; Save r12 register
    push r13             ; Save r13 register
    push r14             ; Save r14 register

    mov r12, rdi         ; Set r12 to the haystack (first argument)
    mov r13, rsi         ; Set r13 to the needle (second argument)

    mov al, [rsi]        ; Load first byte of the needle
    test al, al          ; Check if needle is empty
    jz .return_haystack  ; If empty, return the haystack

    xor rcx, rcx         ; Clear rcx (used for needle length)
    mov rsi, r13         ; Set rsi to point to the needle

.strlen_needle:
    mov al, [rsi + rcx]  ; Load byte from needle
    test al, al          ; Check if end of needle (null terminator)
    jz .strlen_needle_end; Jump if end of needle reached
    inc rcx              ; Increment needle length
    jmp .strlen_needle    ; Repeat loop

.strlen_needle_end:
    mov r14, rcx         ; Store needle length in r14

.outer_loop:
    mov al, [r12]        ; Load byte from haystack
    test al, al          ; Check if end of haystack (null terminator)
    jz .not_found        ; If end of haystack, return null

    mov rdi, r12         ; Set rdi to start of haystack
    mov rsi, r13         ; Set rsi to start of needle
    mov rdx, r14         ; Set rdx to needle length

    push r12             ; Save r12
    push r13             ; Save r13
    push r14             ; Save r14
    call strncmp wrt ..plt ; Call strncmp to compare needle and haystack
    pop r14              ; Restore r14
    pop r13              ; Restore r13
    pop r12              ; Restore r12

    test rax, rax        ; Check result of strncmp
    jz .found            ; If match, jump to found

    inc r12              ; Move to next character in haystack
    jmp .outer_loop      ; Repeat outer loop

.found:
    mov rax, r12         ; Return the pointer to the start of the match
    jmp .end

.not_found:
    xor rax, rax         ; Return null (no match)
    jmp .end

.return_haystack:
    mov rax, r12         ; Return the haystack if needle is empty

.end:
    pop r14              ; Restore r14
    pop r13              ; Restore r13
    pop r12              ; Restore r12
    pop rbx              ; Restore rbx
    ret
