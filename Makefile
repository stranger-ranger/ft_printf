NAME	=	libftprintf.a

HEADER	=	ft_printf.h

SRC	=	ft_printf.c	ft_printf_hexadecimal.c	ft_printf_utils.c

CC	=	gcc

FLAGS	=	-Wall -Werror -Wextra

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			ar -rcs $(NAME) $(OBJ) $?

.c.o:		$(HEADER)
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ) $(OBJ_B)

fclean:	clean
			@$(RM) $(NAME)

re:	fclean all
