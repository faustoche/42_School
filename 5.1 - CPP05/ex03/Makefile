# ************************************************************************ #
#                			        MAIN                                   #
# ************************************************************************ #

NAME 		= intern

# ************************************************************************ #
#                			     DIRECTORIES                               #
# ************************************************************************ #

INCLUDES		= includes
SRCS_DIR		= src
OBJS_DIR		= obj
# ************************************************************************ #
#                			 SRCS && OBJECTS FILES                         #
# ************************************************************************ #

INTERN 		= $(addprefix $(SRCS_DIR)/, main.cpp\
					AForm.cpp\
					Bureaucrat.cpp\
					PresidentialPardonForm.cpp\
					RobotomyRequestForm.cpp\
					ShrubberyCreationForm.cpp\
					Intern.cpp)
SRCS 			= ${INTERN}
CPP_OBJS		= ${INTERN:${SRCS_DIR}/%.cpp=$(OBJS_DIR)/%.o}
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

$(NAME): includes/colors.hpp $(OBJS_DIR) $(OBJS)
	@echo "\033[1;33m👶🏼  COMPILING FORMS 👶🏼\n"
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@echo "\033[1;32m👶🏼 ./$(NAME) created 👶🏼\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp includes/colors.hpp
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# ************************************************************************ #
#                  		     CLEANUP SESSION                               #
# ************************************************************************ #

clean:
	@$(RM) $(OBJS_DIR)
	@$(RM) $(OBJS:.o=.d)
	@echo "\033[1;32m🫧  DONE 🫧"

fclean: clean
	@$(RM) $(NAME) includes/colors.hpp home_shrubbery
	@echo "\033[1;32m🫧  FCLEAN DONE 🫧"

re: fclean all
	@echo "\033[1;32m🫧  RE DONE 🫧"

.PHONY: all clean fclean re

# ************************************************************************ #
#                   	       DEPENDENCIES                                #
# ************************************************************************ #

-include $(OBJS:.o=.d)

# ************************************************************************ #
#                   	          COLORS                                   #
# ************************************************************************ #

includes/colors.hpp:
	@echo '#ifndef COLORS_HPP' > $@
	@echo '#define COLORS_HPP' >> $@
	@echo '#define RESET       "\033[0m"' >> $@
	@echo '#define WHITE       "\033[1;97m"' >> $@
	@echo '#define FUCHSIA     "\033[1;38;5;201m"' >> $@
	@echo '#define BLUE_BRIGHT "\033[1;94m"' >> $@
	@echo '#define GREEN       "\033[1;32m"' >> $@
	@echo '#define MAGENTA     "\033[1;35m"' >> $@
	@echo '#define CYAN        "\033[1;36m"' >> $@
	@echo '#define RED_BOLD    "\033[1;91m"' >> $@
	@echo '#define YELLOW      "\033[1;93m"' >> $@
	@echo '#define ORANGE      "\033[1;38;5;208m"' >> $@
	@echo '#define PINK        "\033[1;38;5;205m"' >> $@
	@echo '#define TURQUOISE   "\033[1;38;5;45m"' >> $@
	@echo '#define GOLD        "\033[1;38;5;220m"' >> $@
	@echo '#define RED		   "\033[0;91m"' >> $@
	@echo '#define CORAL       "\033[1;38;5;203m"' >> $@
	@echo '#endif' >> $@
