SRCS = ft_printf.c 
SRCSBONUS = 

OBJS = ${SRCS:.c=.o}
OBJSBONUS = ${SRCSBONUS:.c=.o}
HEADER = libftprintf.h

NAME =  libftprintf.a

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
TESTFLAGS = # -fsanitize=address -g

%.o : %.c	$(HEADER) 
	
all:		$(NAME)  

test:		${OBJS} ${NAME}
			@${CC} ${TESTFLAGS} ${CFLAGS} main.c ${OBJS} $(HEADER)
			@./a.out

${NAME}:	${OBJS} $(HEADER)
			make -C libft
			cp libft/libft.a $(NAME)
			ar rcs ${NAME} ${OBJS}

bonus:		${OBJS} ${OBJSBONUS} $(HEADER)
			ar rcs ${NAME} ${OBJS} ${OBJSBONUS}
			@touch $@

clean:
			${RM} ${OBJS} ${OBJSBONUS} bonus
			make -C libft clean
fclean:			clean
			${RM} ${NAME}
			make -C libft fclean

re:		fclean all

.PHONY: all clean fclean re 
