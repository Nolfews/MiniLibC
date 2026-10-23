;
; EPITECH PROJECT, 2025
; ASM
; File description:
; strcasecmp
;

BITS 64

section .text
    global strcasecmp

strcasecmp:
    test rsi, rsi         ; Check if second string (rsi) is null
    jz .error_empty_str2   ; Jump if second string is null
    mov al, [rsi]         ; Load first byte of second string
    test al, al           ; Check if second string is empty
    jz .error_empty_str2   ; Jump if second string is empty

.loop:
    mov al, [rdi]         ; Load byte from first string (rdi)
    mov bl, [rsi]         ; Load byte from second string (rsi)

    call .to_lower        ; Convert byte from first string to lowercase
    call .to_lower_bl     ; Convert byte from second string to lowercase

    cmp al, bl            ; Compare both bytes
    jne .diff_found       ; Jump if bytes are different

    test al, al           ; Check if both strings are at end
    je .equal             ; Jump if end of both strings is reached

    inc rdi               ; Increment pointer of first string
    inc rsi               ; Increment pointer of second string
    jmp .loop             ; Repeat loop

.error_empty_str2:
    mov al, [rdi]         ; Load byte from first string (rdi)
    movsx rax, al         ; Sign-extend to rax (result)
    ret

.diff_found:
    sub al, bl            ; Compute difference between bytes
    movsx rax, al         ; Sign-extend to rax (result)
    ret

.equal:
    xor rax, rax          ; Set rax to 0 (strings are equal)
    ret

.to_lower:
    cmp al, 'A'           ; Check if character is >= 'A'
    jb .end_lower         ; Jump if less than 'A'
    cmp al, 'Z'           ; Check if character is <= 'Z'
    ja .end_lower         ; Jump if greater than 'Z'
    add al, 32            ; Convert uppercase to lowercase

.end_lower:
    ret

.to_lower_bl:
    cmp bl, 'A'           ; Check if character is >= 'A'
    jb .end_lower_bl      ; Jump if less than 'A'
    cmp bl, 'Z'           ; Check if character is <= 'Z'
    ja .end_lower_bl      ; Jump if greater than 'Z'
    add bl, 32            ; Convert uppercase to lowercase

.end_lower_bl:
    ret
