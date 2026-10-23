##
## EPITECH PROJECT, 2025
## ASM
## File description:
## Makefile
##

.PHONY: all clean fclean re coverage test_run tests_run

GREEN=\033[1;32m
BLUE=\033[1;34m
RED=\033[1;31m
YELLOW=\033[1;33m
NC=\033[0m

NAME = libasm.so

SRC = 	src/strlen.asm			\
		src/strchr.asm			\
		src/strrchr.asm			\
		src/memset.asm			\
		src/memcpy.asm			\
		src/strcmp.asm			\
		src/memmove.asm			\
		src/strncmp.asm			\
		src/strcasecmp.asm		\
		src/strstr.asm			\
		src/strpbrk.asm			\
		src/strcspn.asm			\

TEST_SRC =	tests/test.c		\

TEST_BIN = tests/test_main

OBJ = $(SRC:.asm=.o)

CC = ld

ASM = nasm

FLAGS = -f elf64

LDFLAGS = -shared -o

all: $(NAME)

$(NAME): $(OBJ)
	@echo -e "$(BLUE)ᒥ🔧ᒧ Compilation de $(NAME)...$(NC)"
	@$(CC) $(LDFLAGS) $(NAME) $(OBJ)
	@echo -e "$(GREEN)ᒥ✅ᒧ Compilation terminée avec succès !$(NC)"

%.o: %.asm
	@echo -e "$(YELLOW)ᒥ🚀ᒧ Compilation de $<...$(NC)"
	@$(ASM) $(FLAGS) $< -o $@

clean:
	@echo -e "$(RED)ᒥ🔥ᒧ Suppression des fichiers objets...$(NC)"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_MAIN)
	@echo -e "$(GREEN)ᒥ✅ᒧ Clean terminé !$(NC)"

fclean: clean
	@echo -e "$(RED)ᒥ🔥ᒧ Suppression de $(NAME)...$(NC)"
	@rm -rf $(NAME)
	@rm -rf unit_tests
	@rm -rf *.gcno
	@rm -rf *.gcda
	@rm -rf vgcore.*
	@echo -e "$(GREEN)ᒥ✅ᒧ Full clean terminé !$(NC)"

re: fclean all

coverage: test_run
	@echo -e "$(BLUE)ᒥ📊ᒧ Génération du rapport de couverture...$(NC)"
	@gcovr
	@echo -e "$(GREEN)ᒥ✅ᒧ Rapport généré !$(NC)"

test_run: $(OBJ)
	@echo -e "$(BLUE)ᒥ🧪ᒧ Compilation des tests...$(NC)"
	@gcc $(CFLAGS) $(TEST_SRC) -o $(TEST_BIN) -L. -lasm
	@echo -e "$(GREEN)ᒥ✅ᒧ Tests compilés ! Lancement...$(NC)"
	@./$(TEST_BIN)

tests_run: test_run
