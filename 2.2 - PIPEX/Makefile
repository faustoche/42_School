##### COMPILATION #####

CC          = cc -g3
CFLAGS      = -Wall -Werror -Wextra -Iincludes

##### UTILE #####

RM = rm -rf

NAME = pipex

##### OBJETS #####

PIPEX = src/pipes.c\
		src/errors.c\
		src/main.c\
		src/process.c\
		src/split.c\
		src/utils.c\
		ft_printf/ft_printf.c\
		ft_printf/ft_putc.c\
		ft_printf/ft_putdi.c\
		ft_printf/ft_putp.c\
		ft_printf/ft_puts.c\
		ft_printf/ft_putun.c\
		ft_printf/ft_putx.c\

##### INGREDIENTS #####

SRCS = ${PIPEX}
OBJS = ${SRCS:.c=.o}

##### COULEURS #####

COLOR_RESET = \033[0m
COLOR_GREENB = \033[0;32m
COLOR_REDB = \033[1;91m

##### PROCESS #####

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;33m\n✨ COMPILING PIPEX... ✨\n"
	$(CC) $(OBJS) -o $(NAME)
	@echo "\033[1;32m🌟 ./$(NAME) created 🌟\n"

clean:
	@echo "\033[0;31m🚮 Deleting Object files... 🚮\n"
	@rm -f $(OBJS)
	@echo "\033[1;32m✅ Done ✅\n"

fclean: clean
	@echo "\033[0;31m🚮 Deleting $(NAME)... 🚮"
	@rm -f $(NAME)
	@echo "\033[1;32m✅ Done ✅\n"

re: fclean all

.PHONY: all clean fclean re
