###############
## 	COMPILE	 ##
###############

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I

##############
##  SOURCE	##
##############

SRC_DIR	=	sources/

SRC_CHAIN_LIST_DIR		=	chain_list/
SRC_CHAIN_LIST_LIST		=	ft_lstadd_back.c	\
							ft_lstadd_front.c	\
							ft_lstclear.c		\
							ft_lstdelone.c		\
							ft_lstdetach.c		\
							ft_lstiter.c		\
							ft_lstlast.c		\
							ft_lstmap.c			\
							ft_lstnew.c 		\
							ft_lstsize.c		\
							ft_lstsort.c
SRC_CHAIN_LIST			=	$(addprefix $(SRC_CHAIN_LIST_DIR), $(SRC_CHAIN_LIST_LIST))

SRC_CHAR_DIR			=	char/
SRC_CHAR_LIST			=	ft_tolower.c		\
							ft_toupper.c
SRC_CHAR				=	$(addprefix $(SRC_CHAR_DIR), $(SRC_CHAR_LIST))

SRC_COMPARE_DIR			=	compare/
SRC_COMPARE_LIST		=	ft_isalnum.c 		\
							ft_isalpha.c 		\
							ft_isascii.c		\
							ft_isdigit.c 		\
							ft_isprint.c		\
							ft_iswhitespace.c
SRC_COMPARE				=	$(addprefix $(SRC_COMPARE_DIR), $(SRC_COMPARE_LIST))

SRC_GNL_DIR				=	gnl/
SRC_GNL_LIST			=	get_next_line.c		\
							get_next_line_utils.c
SRC_GNL					=	$(addprefix $(SRC_GNL_DIR), $(SRC_GNL_LIST))

SRC_INTEGER_DIR			=	integer/
SRC_INTEGER_LIST		=	ft_atoi.c 			\
							ft_atol.c 			\
							ft_itoa.c			\
							ft_strtod.c
SRC_INTEGER				=	$(addprefix $(SRC_INTEGER_DIR), $(SRC_INTEGER_LIST))	

SRC_MEM_DIR				=	memory/
SRC_MEM_LIST			=	ft_bzero.c 			\
							ft_calloc.c 		\
							ft_memchr.c 		\
							ft_memcmp.c 		\
							ft_memcpy.c 		\
							ft_memmove.c 		\
							ft_memset.c
SRC_MEM					=	$(addprefix $(SRC_MEM_DIR), $(SRC_MEM_LIST))

SRC_PRINTF_DIR			=	printf/
SRC_PRINTF_LIST			=	flags_utils.c		\
							ft_printf.c			\
							utils.c				\
							format_function.c	\
							format_ptr.c		\
							format_hex.c		\
							format_unsigned.c	\
							specifier_utils.c
SRC_PRINTF				=	$(addprefix $(SRC_PRINTF_DIR), $(SRC_PRINTF_LIST))

SRC_QUEUE_DIR			=	queue/
SRC_QUEUE_LIST			=	ft_clear_queue.c		\
							ft_dequeue.c			\
							ft_display_queue.c		\
							ft_dup_queue.c			\
							ft_enqueue.c			\
							ft_init_queue.c			\
							ft_is_empty_queue.c		\
							ft_peek_queue.c			\
							ft_peekat_queue.c
SRC_QUEUE				=	$(addprefix $(SRC_QUEUE_DIR), $(SRC_QUEUE_LIST))

SRC_STRING_DIR			=	string/
SRC_STRING_LIST			=	ft_copy_tab.c			\
							ft_findstr.c			\
							ft_insert_str.c			\
							ft_rm_split.c			\
							ft_skip_whitespaces.c	\
							ft_split.c				\
							ft_strchr.c 			\
							ft_strdup.c				\
							ft_striteri.c			\
							ft_strjoin4.c			\
							ft_strjoin.c			\
							ft_strlcat.c 			\
							ft_strlcpy.c 			\
							ft_strlen.c				\
							ft_strmapi.c			\
							ft_strncmp.c			\
							ft_strndup.c			\
							ft_strnstr.c			\
							ft_strrchr.c			\
							ft_strtrim.c			\
							ft_substr.c				\
							ft_tablen.c
SRC_STRING				=	$(addprefix $(SRC_STRING_DIR), $(SRC_STRING_LIST))

SRC_WRITE_DIR			=	write/
SRC_WRITE_LIST			=	ft_putchar_fd.c		\
							ft_putendl_fd.c		\
							ft_putnbr_fd.c		\
							ft_putstr_fd.c
SRC_WRITE				=	$(addprefix $(SRC_WRITE_DIR), $(SRC_WRITE_LIST))

SRC_LIST				=	$(SRC_CHAIN_LIST)	\
							$(SRC_CHAR)			\
							$(SRC_COMPARE)		\
							$(SRC_GNL)			\
							$(SRC_INTEGER)		\
							$(SRC_MEM)			\
							$(SRC_PRINTF)		\
							$(SRC_QUEUE)		\
							$(SRC_STRING)		\
							$(SRC_WRITE)
SRC						=	$(addprefix $(SRC_DIR), $(SRC_LIST))

################
##	INCLUDES  ##
################

INCLUDES	=	includes/

################
##	OBJ/NAME  ##
################

NAME		=	libft.a

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
	@echo "\033[2K$(COLOR_ORANGE)$(BOLD)Compilation complete ! $(COLOR_BLUE)$(BOLD)Libft is Ready !$(COLOR_RESET)"

clean: 
	@rm -rf $(OBJ_DIR)
	@rm -f norme_log
	@echo "$(COLOR_RED)$(BOLD)Delete libft objects$(COLOR_RESET)"

fclean: clean cleanso 
	@rm -f $(NAME)
	@echo "$(COLOR_RED)$(BOLD)Delete Libft$(COLOR_RESET)"

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

norme:
	@echo "$(COLOR_BLUE)Norminette...$(COLOR_RESET)"
	@norminette $(SRC) $(INCLUDES) > norme_log ; \
	if grep -q "Error" norme_log; then \
		echo "$(COLOR_RED)Norme : KO!$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_GREEN)Norme : OK!$(COLOR_RESET)"; \
	fi; \
	
cleanso:
	@rm -f libft.so

.PHONY: all clean fclean re