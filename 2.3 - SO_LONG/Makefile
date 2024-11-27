# ************************************************************************ #
#                			        MAIN                                   #
# ************************************************************************ #

NAME 		= so_long
NAME_BONUS 	= so_long_bonus


# ************************************************************************ #
#                			     DIRECTORIES                               #
# ************************************************************************ #

INCLUDES_DIR	= includes
SRCS_DIR		= src
SRCSB_DIR		= src_bonus
OBJS_DIR		= obj
OBJSB_DIR		= obj_bonus

FTPRINTF_DIR	= ft_printf
GNL_DIR			= get_next_line
MLX_DIR			= minilibx-linux

# ************************************************************************ #
#                			 SRCS && OBJECTS FILES                         #
# ************************************************************************ #

SOLONG = 		$(addprefix $(SRCS_DIR)/, main.c\
				error_display.c\
				error_map.c\
				file_checker.c\
				grid.c\
				init_images.c\
				init_map.c\
				input.c\
				map_allocation.c\
				map_checker.c\
				map_parsing.c\
				move_displayed.c\
				open_close_win.c\
				path_checker.c\
				symbol_checker.c\
				utils.c)

SOLONG_BONUS =  $(addprefix $(SRCSB_DIR)/, enemies_bonus.c)

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


SRCS			= ${SO_LONG} ${FTPRINTF} ${GNL}
FTPRINTF_OBJS 	= ${FTPRINTF:$(FTPRINTF_DIR)/%.c=$(OBJS_DIR)/%.o}
GNL_OBJS 		= ${GNL:$(GNL_DIR)/%.c=$(OBJS_DIR)/%.o}
SO_LONG_OBJS	= ${SOLONG:${SRCS_DIR}/%.c=$(OBJS_DIR)/%.o}
OBJS			= $(SO_LONG_OBJS) $(FTPRINTF_OBJS) $(GNL_OBJS)
OBJSB			= ${SOLONG_BONUS:${SRCSB_DIR}/%.c=$(OBJSB_DIR)/%.o}

# ************************************************************************ #
#                    			 COMPILATION                               #
# ************************************************************************ #

CC          = cc
CFLAGS      = -Wall -Werror -Wextra -g3 -I$(INCLUDES_DIR)
MLX_PATH    = minilibx-linux
MLX_LIB     = $(MLX_PATH)/libmlx_Linux.a
MLX_FLAGS   = -L$(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm -lz
RM = rm -rf

# ************************************************************************ #
#                  		       	 PROCESS                                   #
# ************************************************************************ #

all: $(NAME)

$(NAME): $(OBJS) $(OBJSB)
	@echo "\033[0;33m\n🚧 COMPILING SO_LONG... 🚧\n"
	$(CC) $(OBJS) $(OBJSB) $(MLX_FLAGS) $(CFLAGS) -o $(NAME)
	@echo "\033[1;32m🦕 ./$(NAME) created 🦕\n"

$(NAME_BONUS): $(OBJSB) $(OBJS)
	@echo "\033[0;33m\n🚧 COMPILING BONUSES... 🚧\n"
	$(CC) $(OBJSB) $(OBJS) -o $(NAME_BONUS) $(MLX_FLAGS) $(CFLAGS)
	@echo "\033[1;32m🦖 ./$(NAME_BONUS) created 🦖\n"

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

$(OBJS_DIR)/%.o: $(GNL_DIR)/%.c
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
COLOR_GREENB = \033[0;32m
COLOR_REDB = \033[1;91m