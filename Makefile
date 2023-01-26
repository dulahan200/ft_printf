SRCS = ft_printf.c ft_putuint_fdbase.c ft_putint_fdbase.c ft_putull_fdbase.c

HEADER = ft_printf.h

NAME =  libftprintf.a
VPATH = printf_functions libft OBJDIR
LIBSDIR = libft
LIBS = $(addsuffix .a, ${LIBSDIR})   

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
TESTFLAGS = # -fsanitize=address -g

OBJDIR = obj
DEPDIR := ${OBJDIR}/.deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d
DEPFILES := $(SRCS:%.c=$(DEPDIR)/%.d)
OBJS 		=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

$(OBJDIR)/%.o: %.c | $(DEPDIR) ${OBJDIR}
			${CC} ${CFLAGS} ${DEPFLAGS} -c $< -o $@ 

## ESTO FUNCIONA PERO HACE RELINK
#%.o : %.c	$(HEADER) ${LIBSDIR} ${LIBS} $(DEPDIR)/%.d | $(DEPDIR) ${OBJDIR}
#			${CC} ${CFLAGS} ${DEPFLAGS} -c $< -o $(OBJDIR)/$*.o 

all:		 makelibs ${NAME} 
			

${NAME}:	${OBJS} $(HEADER) $(LIBSDIR)/$(LIBS)
			cp ${LIBSDIR}/${LIBS} ${NAME}
			ar rcs ${NAME} ${OBJS}

$(OBJDIR): ; @mkdir -p $@

$(DEPDIR): ; @mkdir -p $@

$(DEPFILES):

test: all
			${CC} ${CFLAGS} ${OBJS} $(HEADER) $(LIBS)
	@	./a.out

makelibs:
		@	make -C ${LIBSDIR}

clean:		
			${RM} -r ${OBJDIR} 
# removes only file and not folder			${RM} $(addprefix ${OBJDIR}/, ${OBJS})${OBJS} 
			make clean -C ${LIBSDIR}

fclean:		clean
			${RM} ${NAME}
			make fclean -C ${LIBSDIR}

re:		fclean all

include $(wildcard $(DEPFILES))

.PHONY: all clean fclean re test makelibs

#################
# Dependency implementation based on
# https://make.mad-scientist.net/papers/advanced-auto-dependency-generation/
