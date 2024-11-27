# ************************************************************************ #
#                			        MAIN                                   #
# ************************************************************************ #

NAME 		= philo
NAME_BONUS 	= philo_bonus


# ************************************************************************ #
#                			     DIRECTORIES                               #
# ************************************************************************ #

INCLUDES_DIR	= includes
SRCS_DIR		= src
SRCSB_DIR		= src_bonus
OBJS_DIR		= obj
OBJSB_DIR		= obj_bonus

FTPRINTF_DIR	= ft_printf

# ************************************************************************ #
#                			 SRCS && OBJECTS FILES                         #
# ************************************************************************ #

PHILO = 		$(addprefix $(SRCS_DIR)/, main.c\
				error_display.c)

PHILO_BONUS =  $(addprefix $(SRCSB_DIR)/, enemies_bonus.c)

FTPRINTF =		$(addprefix $(FTPRINTF_DIR)/, ft_printf.c\
				ft_putc.c\
				ft_putdi.c\
				ft_putp.c\
				ft_puts.c\
				ft_putun.c\
				ft_putx.c)

GNL =			$(addprefix $(GNL_DIR)/, get_next_line_utils1.c\
				get_next_line_utils2.c\
				get_next_line.c)


SRCS			= ${PHILO} ${FTPRINTF}
FTPRINTF_OBJS 	= ${FTPRINTF:$(FTPRINTF_DIR)/%.c=$(OBJS_DIR)/%.o}
PHILO_OBJS		= ${PHILO:${SRCS_DIR}/%.c=$(OBJS_DIR)/%.o}
OBJS			= $(PHILO_OBJS) $(FTPRINTF_OBJS)
OBJSB			= ${PHILO_BONUS:${SRCSB_DIR}/%.c=$(OBJSB_DIR)/%.o}

# ************************************************************************ #
#                    			 COMPILATION                               #
# ************************************************************************ #

CC          = cc
CFLAGS      = -Wall -Werror -Wextra -g3 -I$(INCLUDES_DIR)
RM = rm -rf

# ************************************************************************ #
#                  		       	 PROCESS                                   #
# ************************************************************************ #

all: $(NAME)

$(NAME): $(OBJS) $(OBJSB)
	@echo "\033[0;33m\n🧠💭 COMPILING PHILO... 💭🧠\n"
	$(CC) $(OBJS) $(OBJSB) $(CFLAGS) -o $(NAME)
	@echo "\033[1;32m👩🏻‍🏫👨🏻‍🏫 ./$(NAME) created 👨🏻‍🏫👩🏻‍🏫\n"

$(NAME_BONUS): $(OBJSB) $(OBJS)
	@echo "\033[0;33m\n🧠💭 COMPILING BONUSES... 💭🧠\n"
	$(CC) $(OBJSB) $(OBJS) -o $(NAME_BONUS) $(CFLAGS)
	@echo "\033[1;32m👩🏻‍🏫👨🏻‍🏫💡 ./$(NAME_BONUS) created 💡👨🏻‍🏫👩🏻‍🏫\n"

bonus: $(NAME_BONUS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSB_DIR)/%.o: $(SRCSB_DIR)/%.c | $(OBJSB_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: $(FTPRINTF_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJSB_DIR):
	@mkdir -p $(OBJSB_DIR)

# ************************************************************************ #
#                  		     CLEANUP SESSION                               #
# ************************************************************************ #

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJSB_DIR)
	@echo "\033[1;32m🧽 DONE 🧽"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "\033[1;32m🧽 DONE 🧽"

re: fclean all
	@echo "\033[1;32m🧽 RE DONE 🧽"

.PHONY: all clean fclean re

# ************************************************************************ #
#                  	        	     COLORS                                #
# ************************************************************************ #

COLOR_RESET = \033[0m

# Regular Colors
COLOR_BLACK = \033[0;30m
COLOR_RED = \033[0;31m
COLOR_GREEN = \033[0;32m
COLOR_YELLOW = \033[0;33m
COLOR_BLUE = \033[0;34m
COLOR_MAGENTA = \033[0;35m
COLOR_CYAN = \033[0;36m
COLOR_WHITE = \033[0;37m

# Bright Colors
COLOR_BLACKB = \033[1;30m
COLOR_REDB = \033[1;31m
COLOR_GREENB = \033[1;32m
COLOR_YELLOWB = \033[1;33m
COLOR_BLUEB = \033[1;34m
COLOR_MAGENTAB = \033[1;35m
COLOR_CYANB = \033[1;36m
COLOR_WHITEB = \033[1;37m

# Additional Styles
COLOR_BOLD = \033[1m
COLOR_DIM = \033[2m
COLOR_ITALIC = \033[3m
COLOR_UNDERLINE = \033[4m
COLOR_BLINK = \033[5m
COLOR_REVERSE = \033[7m
COLOR_HIDDEN = \033[8m