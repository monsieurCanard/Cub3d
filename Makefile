# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 15:47:28 by anthony           #+#    #+#              #
#    Updated: 2024/06/12 11:22:01 by Monsieur_Ca      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################
##  COMPILE	  ##
################

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

##----------------------------------------------------------------------------------##
##									MANDATORY PART									##
##----------------------------------------------------------------------------------##

################
##   LIBS	  ##
################
MANDATORY_DIR	=	Cub3d_mandatory/

CORE_ENGINE_DIR	=	$(MANDATORY_DIR)Core-Engine/
CORE_ENGINE		=	$(CORE_ENGINE_DIR)core_engine.a
CORE_ENGINE_INC	=	$(CORE_ENGINE_DIR)includes/
CORE_ENGINE_NORME = $(CORE_ENGINE_DIR)includes/ $(CORE_ENGINE_DIR)sources/ $(CORE_ENGINE_DIR)libs/libft/ $(CORE_ENGINE_DIR)libs/vectorft/

LIBFT_INC		= $(CORE_ENGINE_DIR)libs/libft/includes/

MLX_INC			= $(CORE_ENGINE_DIR)libs/minilibx/

VECTORFT_INC	= $(CORE_ENGINE_DIR)libs/vectorft/includes/

LDFLAGS			= $(CORE_ENGINE) -lX11 -lXext -lm

#----------------------------------------------------------------------------------##

BONUS_DIR		=	Cub3d_bonus/

CORE_ENGINE_BONUS_DIR	=	$(BONUS_DIR)Core-Engine/
CORE_ENGINE_BONUS		=	$(CORE_ENGINE_BONUS_DIR)core_engine.a
CORE_ENGINE_BONUS_INC	=	$(CORE_ENGINE_BONUS_DIR)includes/
CORE_ENGINE_BONUS_NORME =	$(CORE_ENGINE_BONUS_DIR)includes/ $(CORE_ENGINE_BONUS_DIR)sources/ $(CORE_ENGINE_BONUS_DIR)libs/libft/ $(CORE_ENGINE_BONUS_DIR)libs/vectorft/

LIBFT_BONUS_INC		= $(CORE_ENGINE_BONUS_DIR)libs/libft/includes/

MLX_BONUS_INC		= $(CORE_ENGINE_BONUS_DIR)libs/minilibx/

VECTORFT_BONUS_INC	= $(CORE_ENGINE_BONUS_DIR)libs/vectorft/includes/

LDFLAGS_BONUS		= $(CORE_ENGINE_BONUS) -lX11 -lXext -lm

#################
##   INCLUDE   ##
#################

INCLUDE_NORME	= $(MANDATORY_DIR)includes/ $(CORE_ENGINE_NORME)

INCLUDE_LIST	=	$(MANDATORY_DIR)includes/				\
					./$(LIBFT_INC)			\
					./$(MLX_INC)			\
					./$(VECTORFT_INC)		\
					./$(CORE_ENGINE_INC)
INCLUDE			=	$(addprefix -I, $(INCLUDE_LIST))

INCLUDE_BONUS_NORME	=	$(BONUS_DIR)includes/ $(CORE_ENGINE_BONUS_NORME)

INCLUDE_BONUS_LIST	=	$(BONUS_DIR)includes/				\
						./$(LIBFT_BONUS_INC)			\
						./$(MLX_BONUS_INC)			\
						./$(VECTORFT_BONUS_INC)		\
						./$(CORE_ENGINE_BONUS_INC)
INCLUDE_BONUS		=	$(addprefix -I, $(INCLUDE_BONUS_LIST))
##----------------------------------------------------------------------------------##
##									SOURCES PARTS									##
##----------------------------------------------------------------------------------##

#######################
##   SOURCES FILES   ##
#######################

SRC_DIR				=	$(MANDATORY_DIR)sources/

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

##----------------------------------------------------------------------------------##

SRC_LIST			=	main.c				\
						utils.c				\
						$(SRC_PLAYER)		\
						$(SRC_PARSER)		\
						$(SRC_GAME)		\
						$(SRC_RAYCAST)		\
						$(SRC_UPDATE_GAME)
SRC					=	$(addprefix $(SRC_DIR), $(SRC_LIST))

##----------------------------------------------------------------------------------##
##									BONUS PART									##
##----------------------------------------------------------------------------------##

#######################
##   SOURCES FILES   ##
#######################

SRC_BONUS_DIR				=	$(BONUS_DIR)sources/


##----------------------------------------------------------------------------------##
##									SOURCES PARTS									##
##----------------------------------------------------------------------------------##

SRC_BONUS_PARSER_DIR		=	parser/

SRC_BONUS_PARSER_LIST		=	take_map.c			\
								open_map.c			\
								read_files_utils.c	\
								read_files.c		\
								split_color.c		\
								take_data.c			\
								verif_map.c			\
								verif_map_utils.c
SRC_BONUS_PARSER			=	$(addprefix $(SRC_BONUS_PARSER_DIR), $(SRC_BONUS_PARSER_LIST))

SRC_BONUS_PLAYER_DIR		=	player/

SRC_BONUS_PLAYER_LIST		=	get_player.c	\
								player_action.c	\
								player_angle.c	\
								player_create.c	\
								player_draw.c	\
								player_move.c	\
								player_update.c
SRC_BONUS_PLAYER			=	$(addprefix $(SRC_BONUS_PLAYER_DIR), $(SRC_BONUS_PLAYER_LIST))

SRC_BONUS_RAYCAST_DIR		=	raycaster/

SRC_BONUS_RAYCAST_LIST		=	raycast_init.c	\
								raycast_cal.c	\
								raycaster.c
SRC_BONUS_RAYCAST			=	$(addprefix $(SRC_BONUS_RAYCAST_DIR), $(SRC_BONUS_RAYCAST_LIST))

SRC_BONUS_GAME_DIR			=	game/
SRC_BONUS_GAME_LIST			=	init_game.c		\
								start_game.c 	\
								stop_game.c		\
								event/key.c		\
								event/event.c	\
								event/mouse.c
SRC_BONUS_GAME				=	$(addprefix $(SRC_BONUS_GAME_DIR), $(SRC_BONUS_GAME_LIST))

SRC_BONUS_UPDATE_GAME_DIR	=	update_game/
SRC_BONUS_UPDATE_GAME_LIST	=	update.c	\
								draw_floor_ceil.c
SRC_BONUS_UPDATE_GAME		=	$(addprefix $(SRC_BONUS_UPDATE_GAME_DIR), $(SRC_BONUS_UPDATE_GAME_LIST))

SRC_BONUS_HUD_DIR			=	hud/
SRC_BONUS_HUD_LIST			=	init_minimap.c	\
								hud.c			\
								update_minimap.c
SRC_BONUS_HUD				=	$(addprefix $(SRC_BONUS_HUD_DIR), $(SRC_BONUS_HUD_LIST))

##----------------------------------------------------------------------------------##
SRC_BONUS_LIST				=	main.c				\
								utils.c				\
								$(SRC_BONUS_PLAYER)		\
								$(SRC_BONUS_PARSER)		\
								$(SRC_BONUS_GAME)			\
								$(SRC_BONUS_HUD)			\
								$(SRC_BONUS_RAYCAST)		\
								$(SRC_BONUS_UPDATE_GAME)
SRC_BONUS					=	$(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS_LIST))

##################
##   OBJ/NAME   ##
##################

NAME		=	cub3D

NAME_BONUS	=	cub3D_bonus

NORM_LOG	:=	norme_log

OBJ_DIR		=	objects/
OBJ_LIST	=	$(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))

OBJ_BONUS_DIR	=	objects_bonus/
OBJ_BONUS_LIST	=	$(addprefix $(OBJ_BONUS_DIR), $(SRC_BONUS_LIST:.c=.o))

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

all: $(NAME)

$(CORE_ENGINE):
	@make -sC $(CORE_ENGINE_DIR)

$(CORE_ENGINE_BONUS):
	@make -sC $(CORE_ENGINE_BONUS_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@$(eval COMPILED_SRCS=$(shell expr $(COMPILED_SRCS) + 1))
	@$(call print_progress,$(COMPILED_SRCS),$(TOTAL_SRCS), $<)

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE_BONUS) -c $< -o $@
	@$(eval COMPILED_SRCS=$(shell expr $(COMPILED_SRCS) + 1))
	@$(call print_progress,$(COMPILED_SRCS),$(TOTAL_SRCS), $<)

$(NAME): $(CORE_ENGINE) $(OBJ_LIST)
	@echo "\033[2K$(COLOR_ORANGE)$(BOLD)Compilation complete ! $(COLOR_BLUE)Cub3d is Ready !$(COLOR_RESET)"
	@$(CC) $(CFLAGS) $^ $(INCLUDE) $(LDFLAGS) -o $@


bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(CORE_ENGINE_BONUS) $(OBJ_BONUS_LIST)
	@echo "\033[2K$(COLOR_ORANGE)$(BOLD)Compilation complete ! $(COLOR_BLUE)Cub3d is Ready !$(COLOR_RESET)"
	@$(CC) $(CFLAGS) $^ $(INCLUDE_BONUS) $(LDFLAGS_BONUS) -o $@

clean:
	@echo "$(COLOR_RED)$(BOLD)Delete $(NAME) objects$(COLOR_RESET)"
	@rm -rf $(OBJ_DIR) $(NORM_LOG)
	@make clean -sC $(CORE_ENGINE_DIR)

fclean: clean
	@echo "$(COLOR_RED)$(BOLD)Delete Cub3d$(COLOR_RESET)"
	@rm -f $(NAME)
	@make fclean -sC $(CORE_ENGINE_DIR)

clean_bonus:
	@echo "$(COLOR_RED)$(BOLD)Delete $(NAME_BONUS) objects$(COLOR_RESET)"
	@rm -rf $(OBJ_BONUS_DIR) $(NORM_LOG)
	@make clean -sC $(CORE_ENGINE_BONUS_DIR)

fclean_bonus: clean_bonus
	@echo "$(COLOR_RED)$(BOLD)Delete Cub3d_bonus$(COLOR_RESET)"
	@rm -f $(NAME_BONUS)
	@make fclean -sC $(CORE_ENGINE_BONUS_DIR)

norme:
	@echo "$(COLOR_BLUE)Norminette...$(COLOR_RESET)"
	@norminette $(SRC) $(SRC_BONUS) $(INCLUDE_BONUS_NORME) $(INCLUDE_NORME) > $(NORM_LOG) ; \
	if grep -q "Error" $(NORM_LOG); then \
		echo "$(COLOR_RED)Norme : KO!$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_GREEN)Norme : OK!$(COLOR_RESET)"; \
	fi; \

re: fclean all

.PHONY: all clean fclean re norme bonus