SRCS = ft_printf.c ft_putuint_fdbase.c ft_putint_fdbase.c ft_putull_fdbase.c

OBJS = ${SRCS:.c=.o}
OBJDIR = obj
HEADER = ft_printf.h

NAME =  libftprintf.a
VPATH = printf_functions libft
LIBSDIR = libft
LIBS = $(addsuffix .a, ${LIBSDIR})   

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
TESTFLAGS = # -fsanitize=address -g

DEPDIR := ${OBJDIR}/.deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d
DEPFILES := $(SRCS:%.c=$(DEPDIR)/%.d)



%.o : %.c	$(HEADER) ${LIBSDIR} ${LIBS} $(DEPDIR)/%.d | $(DEPDIR) ${OBJDIR}

			${CC} ${CFLAGS} ${DEPFLAGS} -c $< -o $(OBJDIR)/$*.o 

	
all:		${NAME} ${LIBS}${LIBSDIR}/${LIBS}
	
			
$(DEPFILES):

${NAME}:	${OBJS} $(HEADER) ${LIBS}
#			${CC} ${CFLAGS} $(addprefix ${OBJDIR}/, ${OBJS}) $(HEADER) $(LIBS)
			ar rcs ${NAME} $(addprefix ${OBJDIR}/, ${OBJS})
			ar rcs ${NAME} ${LIBSDIR}/${LIBS} ${NAME}
			ranlib ${NAME} 

##canviar el nom el lib ft, moure/ho a la actual, i fer arrcs name addprefix...etc.

$(OBJDIR): ; @mkdir -p $@

$(DEPDIR): ; @mkdir -p $@

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
