LIBFT_PATH = ./includes/libft/
INCCORE = ./srcs/
MLX_PATH = ./includes/mlx/

INC_SRCH_PATH :=
INC_SRCH_PATH += -I$(MLX_PATH)

NAME = cub3D

SRC = $(INCCORE)cube.c $(INCCORE)start.c $(INCCORE)splitfile.c $(INCCORE)exits.c $(INCCORE)moves.c \
$(INCCORE)utils.c $(INCCORE)raycasting.c $(INCCORE)free.c $(INCCORE)render.c $(INCCORE)texture.c \
$(INCCORE)map.c $(INCCORE)rgb.c $(INCCORE)minimap.c $(INCCORE)setup.c $(INCCORE)utils2.c $(INCCORE)check.c

HEADER = $(LIBFT_PATH)libft.h $(INCCORE)cube.h

FLAGS = -Wall -Werror -Wextra

LFLAGS = -lbsd -L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lXext -lX11 -lm

OBJS = $(SRC:%.c=%.o)

CC = gcc

# ------------------------------ Couleurs ------------------------------

BOLD_BLACK	=	\033[1;30m

BOLD_WHITE	=	\033[1;37m

BOLD_RED	=	\033[1;31m

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_GREEN	=	\033[1;32m

BOLD_YELLOW	=	\033[1;33m

BOLD_BLUE	=	\033[1;34m

RESET	=	\033[0m

# ------------------------------ Messages ------------------------------

HEADER_COMP	=	echo "\n💻 $(BOLD_PURPLE)$(NAME) $(BOLD_WHITE)by $(BOLD_BLUE)hbaduel $(BOLD_WHITE)& $(BOLD_RED)aandrieu\n"

MLX_READY	=	echo "\n✅ $(BOLD_WHITE)Compilation de la $(BOLD_BLUE)MiniLibX$(BOLD_GREEN) réussie !\n"

LIBFT_READY =   echo "\n✅ $(BOLD_WHITE)Compilation de la $(BOLD_RED)Libft $(BOLD_GREEN)réussie !\n\n"

EXE_READY	=	echo "\n\n\n👾 $(BOLD_WHITE)Compilation de $(BOLD_PURPLE)$(NAME)$(BOLD_GREEN) réussie !\n"

CLEANED		=	echo "\n🗑️  $(BOLD_WHITE)Suppression des objets...\n"

FCLEANED	=	echo "\n🗑️  $(BOLD_WHITE)Suppression des objets et de l'exécutable...\n"

NORM		=	echo "\n🖊️  $(BOLD_WHITE)Vérification de la norme de tous les fichiers sources...\n"

NORM_LIB	=	echo "\n🖊️  $(BOLD_WHITE)Vérification de la norme de la Libft...\n"

NORM_H		=	echo "\n🖊️  $(BOLD_WHITE)Vérification de la norme des headers...\n"

# ------------------------------ Regles ------------------------------

MAKEFLAGS += --silent

all: $(NAME)

%.o: %.c
	@printf "$(RESET)🚧 $(BOLD_WHITE)Compilation des fichiers :$(BOLD_PURPLE) %-33.33s\r" $@
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): comp_lib $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_PATH)*.o $(LFLAGS)
	@$(EXE_READY)

comp_lib :
	@$(HEADER_COMP)
	@$(MAKE) -C $(MLX_PATH)
	@$(MLX_READY)
	@$(MAKE) -C $(LIBFT_PATH)
	@$(LIBFT_READY)

norminette:
	$(NORM_LIB)
	norminette -R CheckForbiddenSourceHeader $(LIBFT_PATH)*.c
	$(NORM)
	norminette -R CheckForbiddenSourceHeader $(INCCORE)*.c
	$(NORM_H)
	norminette -R CheckDefine $(HEADER)

clean:
	$(CLEANED)
	rm -rf $(MLX_PATH)obj/*.o $(MLX_PATH)libmlx.a $(MLX_PATH)libmlx_Linux.a
	rm -rf $(LIBFT_PATH)*.o $(LIBFT_PATH)libft.a
	rm -rf $(OBJS)

fclean:
	$(FCLEANED)
	rm -rf $(MLX_PATH)obj/*.o $(MLX_PATH)libmlx.a $(MLX_PATH)libmlx_Linux.a
	rm -rf $(LIBFT_PATH)*.o $(LIBFT_PATH)libft.a
	rm -rf $(NAME) $(OBJS)

re: fclean all

.phony: all clean fclean re norminette
