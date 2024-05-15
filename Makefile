# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 15:47:28 by anthony           #+#    #+#              #
#    Updated: 2024/05/15 16:00:47 by antgabri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################
##  COMPILE	  ##
################

CC			=	cc
CFLAGS		=	-Wall -Wextra  -g3

################
##   LIBS	  ##
################

CORE_ENGINE		=	$(CORE_ENGINE_DIR)core_engine.a
CORE_ENGINE_DIR	=	Core-Engine/
CORE_ENGINE_INC	=	$(CORE_ENGINE_DIR)includes/

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

SRC_PARSER_LIST		=	map/take_map.c		\
						open_map.c			\
						read_files_utils.c	\
						read_files.c		\
						split_color.c		\
						take_data.c
SRC_PARSER			=	$(addprefix $(SRC_PARSER_DIR), $(SRC_PARSER_LIST))

SRC_RAYCAST_DIR		=	raycast/

SRC_RAYCAST_LIST	=	cast_ray_v.c	\
						cast_ray_h.c	
SRC_RAYCAST			=	$(addprefix $(SRC_RAYCAST_DIR), $(SRC_RAYCAST_LIST))

SRC_START_DIR		=	start_game/
SRC_START_LIST		=	start_game.c \
						event.c
SRC_START			=	$(addprefix $(SRC_START_DIR), $(SRC_START_LIST))

SRC_UPDATE_GAME_DIR	=	update_game/
SRC_UPDATE_GAME_LIST	=	get_raycast.c
SRC_UPDATE_GAME		=	$(addprefix $(SRC_UPDATE_GAME_DIR), $(SRC_UPDATE_GAME_LIST))

SRC_DEBUG_DIR		=	debug/
SRC_DEBUG_LIST		=	draw_2d_map.c	\
						player_angle.c	\
						player_move.c	\
						debug_line.c
SRC_DEBUG			=	$(addprefix $(SRC_DEBUG_DIR), $(SRC_DEBUG_LIST))

##----------------------------------------------------------------------------------##
SRC_LIST			=	main.c				\
						$(SRC_PARSER)		\
						$(SRC_DEBUG)		\
						$(SRC_START)		\
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
		printf "$(COLOR_BLUE)Compiling: $(BOLD)$(1)/$(2)$(COLOR_RESET)$(COLOR_GREEN) $(notdir $(3))$(COLOR_RESET)\r"; \
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

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@$(eval COMPILED_SRCS=$(shell expr $(COMPILED_SRCS) + 1))
	@$(call print_progress,$(COMPILED_SRCS),$(TOTAL_SRCS), $<)


$(NAME): $(call $(RQ_SRC)) $(OBJ_LIST)
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
	@norminette $(SRC) $(INCLUDES) $(LIBFT_DIR) > $(NORM_LOG) ; \
	if grep -q "Error" $(NORM_LOG); then \
		echo "$(COLOR_RED)Norme : KO!$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_GREEN)Norme : OK!$(COLOR_RESET)"; \
	fi; \

re: fclean all

.PHONY: all clean fclean re norme