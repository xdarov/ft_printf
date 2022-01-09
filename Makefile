NAME =		libftprintf.a

SRCS =		ft_printf.c funk.c flags.c	

HEADER =	ft_printf.h

OBJ =		$(patsubst %.c, %.o, $(SRCS))

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror -I$(HEADER)

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			ar rcs $(NAME) $?

%.o:		%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			@rm -f $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all