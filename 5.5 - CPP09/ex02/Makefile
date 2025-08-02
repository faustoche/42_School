# ************************************************************************ #
#                			        MAIN                                   #
# ************************************************************************ #

NAME 		= PmergeMe

# ************************************************************************ #
#                			     DIRECTORIES                               #
# ************************************************************************ #

INCLUDES		= includes
SRCS_DIR		= src
OBJS_DIR		= obj
# ************************************************************************ #
#                			 SRCS && OBJECTS FILES                         #
# ************************************************************************ #

PMERGEME 		= $(addprefix $(SRCS_DIR)/, main.cpp\
					PmergeMe.cpp)
SRCS 			= ${PMERGEME}
CPP_OBJS		= ${PMERGEME:${SRCS_DIR}/%.cpp=$(OBJS_DIR)/%.o}
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

$(NAME): includes/colors.hpp docs/README.txt $(OBJS_DIR) $(OBJS)
	@echo "\033[1;33m🪙  COMPILING PMERGEME 🪙\n"
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@echo "\033[1;32m🪙 ./$(NAME) created 🪙\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp includes/colors.hpp docs/README.txt
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
	@$(RM) $(NAME) includes/colors.hpp docs/README.txt docs
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
	@echo 'Algorithm Ford-Johnson' > $@
	@echo >> $@
	@echo 'Pour la suite de chiffres suivante :' >> $@
	@echo >> $@
	@echo '	*** [25, 7, 35, 9, 300, 2, 12, 660, 45, 88, 57, 3, 33, 6, 99] ***' >> $@
	@echo >> $@
	@echo 'Étape 1: On créé des paires.' >> $@
	@echo >> $@
	@echo '	*** [25, 7] [35, 9] [300, 2] [12, 660] [45, 88] [57, 3] [33, 6] *** 99 est mis de côté pour le moment' >> $@
	@echo >> $@
	@echo 'Étape 2: On trie chaque paire individuellement' >> $@
	@echo >> $@
	@echo '	*** [7, 25] [9, 35] [2, 300] [12, 600] [45, 88] [3, 57] [6, 33] ***' >> $@
	@echo >> $@
	@echo 'Étape 3: On sépare les mins et les maxs et on envois les max, triés récursivement, dans leur tableau final' >> $@
	@echo >> $@
	@echo '	*** min: 				[7, 9, 2, 12, 45, 3, 6] ***' >> $@
	@echo '	*** ordre d'\''insertion:	[1, 3, 2, 5,  4,  7, 6]' >> $@
	@echo '	*** max: 				[25, 33, 35, 57, 88, 300, 600] ***' >> $@
	@echo >> $@
	@echo 'Étape 4: On insère les mins dans le tableau final selon l'\''ordre de la suite de Jacobsthal' >> $@
	@echo '- La suite de Jacobsthal est calculé pour donner le résultat suivant : 0 1 1 3 5 11 (...)' >> $@
	@echo '- Au lieu d'\''insérer les éléments mins en passant par leurs index 0, 1, 2, 3, on utilise la suite de Jacobsthal' >> $@
	@echo '- Cela permet de réduire le nombre de comparaison et donc de réduire le temps d'\''exécution.' >> $@
	@echo '- En suivant la suite de Jacobsthal : 1 3 5 11' >> $@
	@echo '- On insère le premier élément : 7' >> $@
	@echo >> $@
	@echo '	*** max: [7, 25, 33, 35, 57, 88, 300, 600] ***' >> $@
	@echo >> $@
	@echo '- On insère le troisième élément : 2' >> $@
	@echo >> $@
	@echo '	*** max: [2, 7, 25, 33, 35, 57, 88, 300, 600] ***' >> $@
	@echo >> $@
	@echo '- On insère le dernier élément à gauche du troisième : 9' >> $@
	@echo >> $@
	@echo '	*** max: [2, 7, 9, 25, 33, 35, 57, 88, 300, 600] ***' >> $@
	@echo >> $@
	@echo '- On insère le cinquième élément : 45' >> $@
	@echo >> $@
	@echo '	*** max: [2, 7, 9, 25, 33, 35, 45, 57, 88, 300, 600] ***' >> $@
	@echo >> $@
	@echo '- On insère le dernier élément à gauche du cinquième : 12' >> $@
	@echo >> $@
	@echo '	*** max: [2, 7, 9, 12, 25, 33, 35, 45, 57, 88, 300, 600] ***' >> $@
	@echo >> $@
	@echo '- On devrait insérer le onzième mais il n'\''y en a pas, alors on prend le dernier : 6' >> $@
	@echo >> $@
	@echo '	*** max: [2, 6, 7, 9, 12, 25, 33, 35, 45, 57, 88, 300, 600] ***' >> $@
	@echo >> $@
	@echo '- On insère l'\''élément à gauche de celui qu'\''on vient d'\''insérer : 3' >> $@
	@echo >> $@
	@echo '	*** max: [2, 3, 6, 7, 9, 12, 25, 33, 35, 45, 57, 88, 300, 600] ***' >> $@