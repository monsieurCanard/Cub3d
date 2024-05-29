# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 15:47:28 by anthony           #+#    #+#              #
#    Updated: 2024/05/29 11:38:23 by antgabri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################
##  COMPILE	  ##
################

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3

################
##   LIBS	  ##
################

CORE_ENGINE		=	$(CORE_ENGINE_DIR)core_engine.a
CORE_ENGINE_DIR	=	Core-Engine/
CORE_ENGINE_INC	=	$(CORE_ENGINE_DIR)includes/
CORE_ENGINE_NORME = $(CORE_ENGINE_DIR)includes/ $(CORE_ENGINE_DIR)sources/ $(CORE_ENGINE_DIR)libs/libft/ $(CORE_ENGINE_DIR)libs/vectorft/

LIBFT_INC		= $(CORE_ENGINE_DIR)libs/libft/includes/

MLX_INC			= $(CORE_ENGINE_DIR)libs/minilibx/

VECTORFT_INC	= $(CORE_ENGINE_DIR)libs/vectorft/includes/

LDFLAGS 		= $(CORE_ENGINE) -lX11 -lXext -lm

#################
##   INCLUDE   ##
#################

INCLUDE_LIST	=	./includes/				\
					./$(LIBFT_INC)			\
					./$(MLX_INC)			\
					./$(VECTORFT_INC)		\
					./$(CORE_ENGINE_INC)
INCLUDE			=	$(addprefix -I, $(INCLUDE_LIST))


#######################
##   SOURCES FILES   ##
#######################

SRC_DIR				=	sources/


##----------------------------------------------------------------------------------##
##									SOURCES PARTS									##
##----------------------------------------------------------------------------------##

SRC_PARSER_DIR		=	parser/

SRC_PARSER_LIST		=	take_map.c			\
						open_map.c			\
						read_files_utils.c	\
						read_files.c		\
						split_color.c		\
						take_data.c			\
						verif_map.c			\
						verif_map_utils.c
SRC_PARSER			=	$(addprefix $(SRC_PARSER_DIR), $(SRC_PARSER_LIST))

SRC_PLAYER_DIR		=	player/

SRC_PLAYER_LIST		=	player_angle.c	\
						create_player.c	\
						get_player.c	\
						player_move.c
SRC_PLAYER			=	$(addprefix $(SRC_PLAYER_DIR), $(SRC_PLAYER_LIST))

SRC_RAYCAST_DIR		=	raycaster/

SRC_RAYCAST_LIST	=	raycast_init.c	\
						raycast_cal.c	\
						raycaster.c
SRC_RAYCAST			=	$(addprefix $(SRC_RAYCAST_DIR), $(SRC_RAYCAST_LIST))

SRC_GAME_DIR		=	game/
SRC_GAME_LIST		=	init_game.c		\
						start_game.c 	\
						stop_game.c		\
						event/key.c		\
						event/event.c
SRC_GAME			=	$(addprefix $(SRC_GAME_DIR), $(SRC_GAME_LIST))

SRC_UPDATE_GAME_DIR	=	update_game/
SRC_UPDATE_GAME_LIST=	update.c	\
						draw_floor_ceil.c
SRC_UPDATE_GAME		=	$(addprefix $(SRC_UPDATE_GAME_DIR), $(SRC_UPDATE_GAME_LIST))

SRC_DEBUG_DIR		=	debug/
SRC_DEBUG_LIST		=	debug_ray.c	
SRC_DEBUG			=	$(addprefix $(SRC_DEBUG_DIR), $(SRC_DEBUG_LIST))

##----------------------------------------------------------------------------------##
SRC_LIST			=	main.c				\
						utils.c				\
						$(SRC_DEBUG)		\
						$(SRC_PLAYER)		\
						$(SRC_PARSER)		\
						$(SRC_GAME)		\
						$(SRC_RAYCAST)		\
						$(SRC_UPDATE_GAME)
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
		printf "$(COLOR_BLUE)Compiling: $(BOLD)$(1)/$(2)$(COLOR_RESET)$(COLOR_GREEN) $(notdir $(3))$(COLOR_RESET)\n"; \
	else \
		$(call progress_bar,$(1),$(2),$(3),$(LEN)); \
	fi
endef

#################
##    RULES    ##
#################

all: $(CORE_ENGINE) $(NAME)


$(CORE_ENGINE):
	@make -sC $(CORE_ENGINE_DIR) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDES)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@$(eval COMPILED_SRCS=$(shell expr $(COMPILED_SRCS) + 1))
	@$(call print_progress,$(COMPILED_SRCS),$(TOTAL_SRCS), $<)


$(NAME): $(OBJ_LIST)
	@echo "\033[2K$(COLOR_ORANGE)$(BOLD)Compilation complete ! $(COLOR_BLUE)Cub3d is Ready !$(COLOR_RESET)"
	@$(CC) $(CFLAGS) $^ $(INCLUDE) $(LDFLAGS) -o $@

clean:
	@echo "$(COLOR_RED)$(BOLD)Delete $(NAME) objects$(COLOR_RESET)"
	@rm -rf $(OBJ_DIR) $(NORM_LOG)
	@make clean -sC $(CORE_ENGINE_DIR)

fclean: clean
	@echo "$(COLOR_RED)$(BOLD)Delete Cub3d$(COLOR_RESET)"
	@rm -f $(NAME)
	@make fclean -sC $(CORE_ENGINE_DIR)

norme:
	@echo "$(COLOR_BLUE)Norminette...$(COLOR_RESET)"
	@norminette $(SRC) $(INCLUDES) $(CORE_ENGINE_NORME) > $(NORM_LOG) ; \
	if grep -q "Error" $(NORM_LOG); then \
		echo "$(COLOR_RED)Norme : KO!$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_GREEN)Norme : OK!$(COLOR_RESET)"; \
	fi; \

re: fclean all

.PHONY: all clean fclean re norme