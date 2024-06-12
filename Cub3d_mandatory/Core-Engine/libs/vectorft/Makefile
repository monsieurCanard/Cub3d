# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 14:46:57 by jbrousse          #+#    #+#              #
#    Updated: 2024/05/10 13:04:30 by jbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## 	COMPILE	 ##
###############

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I

##############
##  SOURCE	##
##############

SRC_DIR			=	sources/

SRC_VECT2_DIR	=	vector2/
SRC_VECT2_LIST	=	add_vector2.c		\
					cross_vector2.c		\
					dot_vector2.c		\
					magnitude_vector2.c	\
					normalize_vector2.c	\
					sub_vector2.c		\
					vector2.c
SRC_VECT2		=	$(addprefix $(SRC_VECT2_DIR), $(SRC_VECT2_LIST))

SRC_VECT3_DIR	=	vector3/
SRC_VECT3_LIST	=	add_vector3.c		\
					cross_vector3.c		\
					dot_vector3.c		\
					magnitude_vector3.c	\
					normalize_vector3.c	\
					sub_vector3.c		\
					vector3.c
SRC_VECT3		=	$(addprefix $(SRC_VECT3_DIR), $(SRC_VECT3_LIST))

SRC_LIST		=	$(SRC_VECT2) \
					$(SRC_VECT3)
SRC				=	$(addprefix $(SRC_DIR), $(SRC_LIST))

################
##	INCLUDES  ##
################

INCLUDES	=	includes/

################
##	OBJ/NAME  ##
################

NAME		=	vectorft.a

OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

#################
##	 COLORS	   ##
#################

COLOR_RESET		=	\033[0m
COLOR_GREEN		=	\033[38;5;76m
COLOR_RED		=	\033[38;5;160m
COLOR_BLUE		=	\033[38;5;45m
COLOR_ORANGE	=	\033[38;5;220m
BOLD			=	\033[1m
UNDERLINE		=	\033[4m

################
##	PROGRESS  ##
################

COMPILED_SRCS		:=	1

TOTAL_SRCS			:=	$(words $(SRC))


MAX_PATH_LENGTH 	:=	$(shell find $(SRC_DIR) -name '*.c' | awk '{print length}' | sort -nr | head -n1)
MAX_NAME_LENGTH 	:=	$(shell find $(SRC_DIR) -name '*.c' -exec basename {} \; | awk '{ print length }' | sort -nr | head -n1)

define progress_bar
	printf "$(COLOR_BLUE)Compiling: [$(COLOR_GREEN)"; \
	for i in $$(seq 1 $(4)); do \
		if [ $$i -le $$(($(1)*$(4)/$(2))) ]; then \
			printf "#"; \
		else \
			printf "."; \
		fi; \
	done; \
	printf "$(COLOR_BLUE)] $(BOLD)$(1)/$(2) $(COLOR_GREEN)$(3)$(COLOR_RESET)\r"
endef

define print_progress
	@$(eval WIDTH := $(shell tput cols))
	@$(eval LEN := $(shell expr $(WIDTH) - $(MAX_PATH_LENGTH) - 26))
	
	@printf "\033[2K"; \
	if [ $(LEN) -le 10 ]; then \
		printf "$(COLOR_BLUE)Compiling: $(BOLD)$(1)/$(2)$(COLOR_RESET)$(COLOR_GREEN) $(notdir $(3))$(COLOR_RESET)\r"; \
	else \
		$(call progress_bar,$(1),$(2),$(3),$(LEN)); \
	fi
endef

#############
##	RULES  ##
#############

all: $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

	@$(eval COMPILED_SRCS=$(shell expr $(COMPILED_SRCS) + 1))
	@$(call print_progress,$(COMPILED_SRCS),$(TOTAL_SRCS), $<)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[2K$(COLOR_ORANGE)$(BOLD)Compilation complete ! $(COLOR_BLUE)Vectorft is Ready !$(COLOR_RESET)"

clean: 
	@rm -fr  $(OBJ_DIR)
	@rm -f norme_log
	@echo "$(COLOR_RED)$(BOLD)Delete Vectorft objects$(COLOR_RESET)"


fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR_RED)$(BOLD)Delete Vectorft$(COLOR_RESET)"


re: fclean all

norme:
	@echo "$(COLOR_BLUE)Norminette...$(COLOR_RESET)"
	@norminette $(SRC_DIR) $(INCLUDES) > norme_log ; \
	if grep -q "Error" norme_log; then \
		echo "$(COLOR_RED)Norme : KO!$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_GREEN)Norme : OK!$(COLOR_RESET)"; \
	fi; \

.PHONY: all clean fclean re