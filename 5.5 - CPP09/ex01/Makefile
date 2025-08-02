# ************************************************************************ #
#                			        MAIN                                   #
# ************************************************************************ #

NAME 		= RPN

# ************************************************************************ #
#                			     DIRECTORIES                               #
# ************************************************************************ #

INCLUDES		= includes
SRCS_DIR		= src
OBJS_DIR		= obj
# ************************************************************************ #
#                			 SRCS && OBJECTS FILES                         #
# ************************************************************************ #

RPN 			= $(addprefix $(SRCS_DIR)/, main.cpp\
					RPN.cpp)
SRCS 			= ${RPN}
CPP_OBJS		= ${RPN:${SRCS_DIR}/%.cpp=$(OBJS_DIR)/%.o}
OBJS			= $(CPP_OBJS)

# ************************************************************************ #
#                    			 COMPILATION                               #
# ************************************************************************ #

CC          = c++
CFLAGS      = -Wall -Werror -Wextra -std=c++98 -I$(INCLUDES)
RM = rm -rf

# ************************************************************************ #
#                  		       	 PROCESS                                   #
# ************************************************************************ #

all:    $(NAME)

$(NAME): includes/colors.hpp docs/README.txt docs/test.sh $(OBJS_DIR) $(OBJS)
	@echo "\033[1;33m🪙  COMPILING RPN 🪙\n"
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@echo "\033[1;32m🪙 ./$(NAME) created 🪙\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp includes/colors.hpp docs/README.txt docs/test.sh
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
	@$(RM) $(NAME) includes/colors.hpp docs/README.txt docs/test.sh docs
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
	@echo '#define RESET		"\033[0m"' >> $@
	@echo '#define WHITE		"\033[1;97m"' >> $@
	@echo '#define FUCHSIA		"\033[1;38;5;201m"' >> $@
	@echo '#define BLUE_BRIGHT	"\033[1;94m"' >> $@
	@echo '#define GREEN		"\033[1;32m"' >> $@
	@echo '#define MAGENTA		"\033[1;35m"' >> $@
	@echo '#define CYAN			"\033[1;36m"' >> $@
	@echo '#define RED_BOLD		"\033[1;91m"' >> $@
	@echo '#define RED			"\033[0;91m"' >> $@
	@echo '#define YELLOW		"\033[1;93m"' >> $@
	@echo '#define ORANGE		"\033[1;38;5;208m"' >> $@
	@echo '#define PINK			"\033[1;38;5;205m"' >> $@
	@echo '#define TURQUOISE	"\033[1;38;5;45m"' >> $@
	@echo '#define GOLD			"\033[1;38;5;220m"' >> $@
	@echo '#define CORAL		"\033[1;38;5;203m"' >> $@
	@echo '#endif' >> $@

# ************************************************************************ #
#                   	          README                                   #
# ************************************************************************ #

docs/README.txt:
	@mkdir -p docs
	@echo 'Pour calculer la notation suivante  : "2 4 8 + *"' > $@
	@echo >> $@
	@echo >> $@
	@echo 'Étape 1 : Ajouter 2 dans la pile' >> $@
	@echo 'Pile    : [2]' >> $@
	@echo >> $@
	@echo '-------------------------------------------------------' >> $@
	@echo >> $@
	@echo 'Étape 2 : Ajouter 4 dans la pile' >> $@
	@echo 'Pile    : [2, 4]' >> $@
	@echo >> $@
	@echo '-------------------------------------------------------' >> $@
	@echo >> $@
	@echo 'Étape 3 : Ajouter 8 dans la pile' >> $@
	@echo 'Pile    : [2, 4, 8]' >> $@
	@echo >> $@
	@echo '-------------------------------------------------------' >> $@
	@echo >> $@
	@echo 'Étape 4  : Prendre les 2 derniers éléments : 8 et 4' >> $@
	@echo 'Calculer : 4 + 8 = 12' >> $@
	@echo >> $@
	@echo 'Remplacer ces 2 éléments par le résultat 12' >> $@
	@echo 'Pile     : [2, 12]' >> $@
	@echo >> $@
	@echo '-------------------------------------------------------' >> $@
	@echo >> $@
	@echo 'Étape 5  : Prendre les 2 derniers éléments : 12 et 2' >> $@
	@echo 'Calculer : 2 × 12 = 24' >> $@
	@echo >> $@
	@echo 'Remplacer ces 2 éléments par le résultat 24' >> $@
	@echo 'Pile     : [24]' >> $@
	@echo >> $@
	@echo '-------------------------------------------------------' >> $@
	@echo >> $@
	@echo 'Résultat final : 24' >> $@
	@echo >> $@
	@echo 'Ce qui vaut en calcul classique : ' >> $@
	@echo '2 * (4 + 8) = 2 * 12 = 24' >> $@

docs/test.sh:
	@echo '#!/bin/bash' > $@
	@echo >> $@
	@echo "GREEN='\\033[0;32m'" >> $@
	@echo "RED='\\033[0;31m'" >> $@
	@echo "BLUE='\\033[0;34m'" >> $@
	@echo "BOLD='\\033[0;1m'" >> $@
	@echo "END='\\033[0m'" >> $@
	@echo >> $@
	@echo 'make' >> $@
	@echo >> $@
	@echo 'testExpr() {' >> $@
	@echo '	result=$(./RPN "$$1")' >> $@
	@echo >> $@
	@echo '	if [ "$$result" == "$$2" ]; then' >> $@
	@echo '		echo -e "$${GREEN}$$1, result: $$2$${END}"' >> $@
	@echo '	else' >> $@
	@echo '		echo -e "$${RED}$$1, result: $$result (should be $$2)$${END}"' >> $@
	@echo '	fi' >> $@
	@echo '}' >> $@
	@echo >> $@
	@echo 'testExpr "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"' >> $@
	@echo 'testExpr "7 7 * 7 -" "42"' >> $@
	@echo 'testExpr "1 2 * 2 / 2 * 2 4 - +" "0"' >> $@
	@echo 'testExpr "(1 + 1)"' >> $@
	@echo 'testExpr "  2 4 * 8 +" "16"' >> $@
	@echo 'testExpr "2 4 8 + * " "24"' >> $@
	@echo 'testExpr "3 2 * 1   1 -"' >> $@
	@echo 'testExpr "2 5 * 4 + 3 2 * 1 + / " "2"' >> $@
	@echo 'testExpr "1 2 + 3 4 + *" "21"' >> $@
	@echo 'testExpr "1 2 3 * 4 +"' >> $@
	@echo 'testExpr "1 2 3 4 + * +" "15"' >> $@
	@echo 'testExpr "1 2 + 3 * 4 +" "13"' >> $@
	@echo 'testExpr "3 4 + 2 * 1 -" "13"' >> $@
	@echo 'testExpr "7 2 + 5 3 - *" "18"' >> $@
	@echo 'testExpr "9 2 / 1 + 8 *" "44"' >> $@
	@echo 'testExpr "00000000000002 3 + 5 6 - * 7 +" "2"' >> $@
	@echo 'testExpr "8 3 / 1 4 + * 7 -" "6.33333"' >> $@
	@echo 'testExpr "8 0 /"' >> $@
	@chmod +x $@