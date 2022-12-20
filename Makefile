SRCS = ft_printf.c ft_putuint_fdbase.c ft_putint_fdbase.c ft_putull_fdbase.c

OBJS = ${SRCS:.c=.o}
HEADER = ft_printf.h

NAME =  libftprintf.a
VPATH = printf_functions libft
LIBSDIR = libft
LIBS = $(addsuffix .a, ${LIBSDIR})   

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
TESTFLAGS = # -fsanitize=address -g

DEPDIR := .deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.

$(DEPDIR): ; @mkdir -p $@
DEPFILES := $(SRCS:%.c=$(DEPDIR)/%.d)
$(DEPFILES):



%.o : %.c	$(HEADER) ${LIBSDIR}${LIBS}
			${CC} ${CFLAGS} -c $< -o $@ 
	
all:		${NAME} ${LIBS}${LIBSDIR}/${LIBS}

${NAME}:	${OBJS} $(HEADER) ${LIBS}
#			${CC} ${CFLAGS} ${OBJS} $(HEADER) $(LIBS)
			cp ${LIBSDIR}/${LIBS} $(NAME)
			ar rcs ${NAME} ${OBJS}

test: all
	@	gcc main.c ${NAME}
	@	./a.out


${LIBS}:
			make -C ${LIBSDIR}

libftclean:
#		{LIBSDIR} #esto hay que arreglarlo

clean:		libftclean
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re:		fclean all

include $(wildcard $(DEPFILES))

.PHONY: all clean fclean re libftclean test 
