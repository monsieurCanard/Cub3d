# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 15:47:28 by anthony           #+#    #+#              #
#    Updated: 2024/04/26 15:41:37 by antgabri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################
##  COMPILE	  ##
################

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3
OPTION	=	-L $(MLX_DIR) -lmlx -lX11 -lXext -lm
################
##   LIBS	  ##
################

LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_DIR	= libs/libft/
LIBFT_INC	= $(LIBFT_DIR)includes/

MLX			= $(MLX_DIR)libmlx_Linux.a
MLX_DIR		= minilibx-linux/
MLX_INC		= $(MLX_DIR)
#################
##   INCLUDE   ##
#################

INCLUDE_LIST	=	./includes/				\
					./$(LIBFT_INC)			\
					./$(MLX_INC)
INCLUDE			=	$(addprefix -I, $(INCLUDE_LIST))


#######################
##   SOURCES FILES   ##
#######################

SRC_DIR				=	sources/


##----------------------------------------------------------------------------------##
##									SOURCES PARTS									##
##----------------------------------------------------------------------------------##

SRC_PARSER_DIR		=	parser/

SRC_PARSER_LIST		=	map/take_map.c		\
						open_map.c			\
						read_files_utils.c	\
						read_files.c		\
						split_color.c		\
						take_data.c
SRC_PARSER			=	$(addprefix $(SRC_PARSER_DIR), $(SRC_PARSER_LIST))

SRC_COMPONENTS_DIR	=	components/

SRC_COMPONENTS_LIST	=	free.c	\
						pixel_put.c
SRC_COMPONENTS		=	$(addprefix $(SRC_COMPONENTS_DIR), $(SRC_COMPONENTS_LIST))

SRC_EVENTS_DIR		=	events/

SRC_EVENTS_LIST		=	key_press.c \
						close_window.c
SRC_EVENTS			=	$(addprefix $(SRC_EVENTS_DIR), $(SRC_EVENTS_LIST))


SRC_INIT_DATA_DIR	=	init_data/

SRC_INIT_DATA_LIST	=	init_mlx.c
SRC_INIT_DATA		=	$(addprefix $(SRC_INIT_DATA_DIR), $(SRC_INIT_DATA_LIST))

SRC_PLAYER_DIR		=	player/

SRC_PLAYER_LIST		=	create_player.c
SRC_PLAYER			=	$(addprefix $(SRC_PLAYER_DIR), $(SRC_PLAYER_LIST))

SRC_GAME_DIR		=	game/

SRC_GAME_LIST		=	start_game.c
SRC_GAME			=	$(addprefix $(SRC_GAME_DIR), $(SRC_GAME_LIST))

##----------------------------------------------------------------------------------##
SRC_LIST			=	main.c				\
						$(SRC_PARSER)		\
						$(SRC_COMPONENTS)	\
						$(SRC_INIT_DATA)	\
						$(SRC_EVENTS)		\
						$(SRC_PLAYER)		\
						$(SRC_GAME)
SRC					=	$(addprefix $(SRC_DIR), $(SRC_LIST))

##################
##   OBJ/NAME   ##
##################

NAME		=	cub3D

NORM_LOG	:=	norme_log

OBJ_DIR		=	objects/
OBJ_LIST	=	$(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

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

#################
##    RULES    ##
#################

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(MLX):
	@make -sC $(MLX_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@$(eval COMPILED_SRCS=$(shell expr $(COMPILED_SRCS) + 1))
	@$(call print_progress,$(COMPILED_SRCS),$(TOTAL_SRCS), $<)


$(NAME): $(call $(RQ_SRC)) $(OBJ_LIST)
	@echo "\033[2K$(COLOR_ORANGE)$(BOLD)Compilation complete ! $(COLOR_BLUE)Cub3d is Ready !$(COLOR_RESET)"
	@$(CC) $(CFLAGS) $^ $(INCLUDE) $(OPTION) $(LIBFT) -o $@

clean:
	@echo "$(COLOR_RED)$(BOLD)Delete $(NAME) objects$(COLOR_RESET)"
	@rm -rf $(OBJ_DIR) $(NORM_LOG)
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(MLX_DIR)

fclean: clean
	@echo "$(COLOR_RED)$(BOLD)Delete Cub3d$(COLOR_RESET)"
	@rm -f $(NAME)
	@echo "$(COLOR_RED)$(BOLD)Delete Libft$(COLOR_RESET)"
	@rm -f $(LIBFT)

norme:
	@echo "$(COLOR_BLUE)Norminette...$(COLOR_RESET)"
	@norminette $(SRC) $(INCLUDES) $(LIBFT_DIR) > $(NORM_LOG) ; \
	if grep -q "Error" $(NORM_LOG); then \
		echo "$(COLOR_RED)Norme : KO!$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_GREEN)Norme : OK!$(COLOR_RESET)"; \
	fi; \

re: fclean all

.PHONY: all clean fclean re norme