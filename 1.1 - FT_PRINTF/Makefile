##### COMPILATION #####

CC = cc
CFLAGS = -Wall -Werror -Wextra

##### UTILE #####

RM = rm -rf

NAME = libftprintf.a

##### OBJETS #####

LIBC = ft_printf.c ft_putc.c ft_putdi.c ft_putp.c ft_puts.c ft_putun.c ft_putx.c

##### INGREDIENTS #####

SRCS = ${LIBC}

OBJS = ${SRCS:.c=.o}

##### COULEURS #####

COLOR_RESET = \033[0m
COLOR_GREENB = \033[0;32m
COLOR_REDB = \033[1;91m

##### PROCESS #####

all : ${NAME}

${NAME}:	${OBJS}
	ar rcs	${NAME} ${OBJS}
	@echo "${COLOR_GREENB}COMPILATION DONE${COLOR_RESET}"

%.o: %.c libftprintf.h
	${CC} ${CFLAGS} -I includes/ -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}
	@echo "${COLOR_REDB}CLEAN DONE${COLOR_RESET}"

fclean: clean
	${RM} ${NAME}
	@echo "${COLOR_REDB}FCLEAN DONE${COLOR_RESET}"

re: clean all
	@echo "${COLOR_REDB}RE DONE${COLOR_RESET}"

.PHONY: all clean fclean re