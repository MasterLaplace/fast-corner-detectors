##
## EPITECH PROJECT, 2023
## Fast Corner Detectors
## File description:
## Makefile
##

NAME	=	libfastcorner.a

SRC_DIR	=	src/

SRC		= 	$(SRC_DIR)fast.c
SRC		+=	$(SRC_DIR)nonmax.c
SRC		+=	$(SRC_DIR)fast_9.c
SRC		+=	$(SRC_DIR)fast_12.c

MAIN	=	$(SRC_DIR)main.c

OBJ		=	$(SRC:.c=.o)
MAIN_OBJ=	$(MAIN:.c=.o)

CFLAGS	=	-Wall -Wextra -iquote include/

ECHO	=	echo
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
DEFAULT	=	\033[0m
BOLD	=	\033[1m

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ) \
	&& $(ECHO) "$(GREEN)[OK]$(DEFAULT)" "$(GREEN)$(BOLD)$(NAME)$(DEFAULT)" \
	|| $(ECHO) "$(RED)[KO]$(DEFAULT)" "$(RED)$(BOLD)$(NAME)$(DEFAULT)"

clean:
	@rm -f $(OBJ)
	@rm -f $(MAIN_OBJ)
	@$(ECHO) "$(BLUE)$(BOLD)$(NAME)$(DEFAULT):" \
	"$(BLUE)$(BOLD)Cleaning object files$(DEFAULT)"

fclean:	clean
	@rm -f $(NAME)
	@$(ECHO) "$(BLUE)$(BOLD)$(NAME)$(DEFAULT):" \
	"$(BLUE)$(BOLD)Cleaning binary file$(DEFAULT)"

re:	fclean all

%.o:	%.c
	@gcc -c -o $@ $< $(CFLAGS)

.PHONY:	all clean fclean re
