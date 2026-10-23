;
; EPITECH PROJECT, 2025
; ASM
; File description:
; strrchr
;

BITS 64

section .text
    global strrchr
    global rindex
    extern strlen

rindex:
strrchr:
    push rbx             ; Save rbx register

    test rdi, rdi        ; Check if the string is empty (null pointer)
    jz .return_null      ; Jump to return_null if the string is empty

    xor rbx, rbx         ; set rbx to 0
    mov bl, sil       ; Move the character to search (sil) into rbx

    push rdi             ; Save rdi (string pointer) on stack
    call strlen wrt ..plt ; Call strlen to get the length of the string
    pop rdi              ; Restore rdi (string pointer)

    lea rcx, [rdi + rax] ; Set rcx to the end of the string (rdi + length)

    test rbx, rbx        ; Check if search character is null
    jz .found            ; If null, jump to found (search character is not used)

.search_loop:
    movzx rax, byte [rcx] ; Load current byte from string
    cmp al, bl            ; Compare it with the search character
    je .found             ; If they are equal, jump to found

    dec rcx               ; Move backwards in the string
    cmp rcx, rdi          ; Check if we have reached the start of the string
    jb .return_null       ; If so, return null (no match)

    jmp .search_loop      ; Repeat loop

.found:
    mov rax, rcx          ; Return pointer to the found character
    jmp .return           ; Jump to return

.return_null:
    xor rax, rax          ; Return null (0) if not found

.return:
    pop rbx               ; Restore rbx register
    ret