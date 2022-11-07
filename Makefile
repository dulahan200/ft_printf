SRCS = ft_printf.c 

OBJS = ${SRCS:.c=.o}
HEADER = libftprintf.h

NAME =  libftprintf.a
VPATH = printf_functions libft
LIBSDIR = libft
LIBS = $(addsufix .a, ${LIBSDIR})   

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra # -Werror
TESTFLAGS = # -fsanitize=address -g

%.o : %.c	$(HEADER) 
			${CC} ${CFLAGS} -c $< -o $@ 
	
all:		${NAME} ${LIBS}

${NAME}:	${OBJS} $(HEADER) ${LIBS}
#			${CC} ${CFLAGS} ${OBJS} $(HEADER) $(LIBS)
			cp ${LIBS} $(NAME)
			ar rcs ${NAME} ${OBJS}

${LIBS}:
			make -C ${LIBSDIR}

libftclean:
			make -C libft clean

clean:		libftclean
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re libftclean 
