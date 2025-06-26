# ************************************************************************ #
#                			        MAIN                                   #
# ************************************************************************ #

NAME 		= Animal

# ************************************************************************ #
#                			     DIRECTORIES                               #
# ************************************************************************ #

INCLUDES		= includes
SRCS_DIR		= src
OBJS_DIR		= obj
# ************************************************************************ #
#                			 SRCS && OBJECTS FILES                         #
# ************************************************************************ #

ANIMAL 			= $(addprefix $(SRCS_DIR)/, main.cpp\
					Animal.cpp\
					Cat.cpp\
					Dog.cpp\
					WrongAnimal.cpp\
					WrongCat.cpp)
SRCS 			= ${ANIMAL}
CPP_OBJS		= ${ANIMAL:${SRCS_DIR}/%.cpp=$(OBJS_DIR)/%.o}
OBJS			= $(CPP_OBJS)

# ************************************************************************ #
#                    			 COMPILATION                               #
# ************************************************************************ #

CC          = c++
CFLAGS      = -Wall -Werror -Wextra -std=c++98 -g3 -I$(INCLUDES)
RM = rm -rf

# ************************************************************************ #
#                  		       	 PROCESS                                   #
# ************************************************************************ #

all:    $(NAME)

$(NAME):  $(OBJS_DIR) $(OBJS)
	@echo "\033[1;33m🐅  COMPILING ANIMAL 🐅\n"
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@echo "\033[1;32m🐅 ./$(NAME) created 🐅\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# ************************************************************************ #
#                  		     CLEANUP SESSION                               #
# ************************************************************************ #

clean:
	@$(RM) $(OBJS_DIR)
	@echo "\033[1;32m🫧  DONE 🫧"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;32m🫧  FCLEAN DONE 🫧"

re: fclean all
	@echo "\033[1;32m🫧  RE DONE 🫧"

.PHONY: all clean fclean re