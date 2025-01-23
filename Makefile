# Options de compilation
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
INCLUDES := -Iincludes -Ilibft/includes -Imlx/include -Imlx/include/MLX42
INCLUDES_BONUS := -Iincludes_bonus -Ilibft/includes -Imlx/include -Imlx/include/MLX42
NAME := so_long
NAME_BONUS := so_long_bonus

SRCS :=	srcs/so_long.c \
	srcs/parsing/check_chars.c \
	srcs/parsing/check_too_large.c \
	srcs/parsing/check_walls.c \
	srcs/parsing/flood_fill.c \
	srcs/parsing/flood_fill_exit.c \
	srcs/parsing/parsing_map.c \
	srcs/errors/errors.c \
	srcs/errors/frees.c \
	srcs/map/get_pos.c \
	srcs/map/map_utils.c \
	srcs/map/map_utils2.c \
	srcs/rendering/rendering.c \
	srcs/rendering/draw_map.c \
	srcs/rendering/check_draw.c \
	srcs/rendering/player_reverse.c \
	srcs/game/player_movements.c \
	srcs/game/mlx_hooks.c \

SRCS_BONUS := srcs_bonus/so_long_bonus.c \
	srcs_bonus/parsing_bonus/check_chars_bonus.c \
	srcs_bonus/parsing_bonus/check_too_large_bonus.c \
	srcs_bonus/parsing_bonus/check_walls_bonus.c \
	srcs_bonus/parsing_bonus/flood_fill_bonus.c \
	srcs_bonus/parsing_bonus/flood_fill_exit_bonus.c \
	srcs_bonus/parsing_bonus/parsing_map_bonus.c \
	srcs_bonus/errors_bonus/errors_bonus.c \
	srcs_bonus/errors_bonus/frees_bonus.c \
	srcs_bonus/errors_bonus/frees2_bonus.c \
	srcs_bonus/map_bonus/get_pos_bonus.c \
	srcs_bonus/map_bonus/map_utils_bonus.c \
	srcs_bonus/map_bonus/map_utils2_bonus.c \
	srcs_bonus/rendering_bonus/rendering_bonus.c \
	srcs_bonus/rendering_bonus/draw_map_bonus.c \
	srcs_bonus/rendering_bonus/check_draw_bonus.c \
	srcs_bonus/rendering_bonus/player_reverse_bonus.c \
	srcs_bonus/rendering_bonus/rendering_coins_bonus.c \
	srcs_bonus/rendering_bonus/rendering_moves_bonus.c \
	srcs_bonus/game_bonus/player_movements_bonus.c \
	srcs_bonus/game_bonus/mlx_hooks_bonus.c \
	srcs_bonus/enemy_bonus/enemy_bonus.c \
	srcs_bonus/enemy_bonus/enemy_path_bonus.c \
	srcs_bonus/enemy_bonus/enemy_path2_bonus.c \
	srcs_bonus/enemy_bonus/DDA_bonus.c \

OBJ_DIR := objs/
OBJ := $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)

OBJ_DIR_BONUS := objs_bonus/
OBJ_BONUS := $(SRCS_BONUS:srcs_bonus/%.c=$(OBJ_DIR_BONUS)/%.o)

# Librairies
MLX_DIR := mlx
MLX := $(MLX_DIR)/build/libmlx42.a

LIBS := $(MLX) -ldl -lglfw -pthread -lm

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a


all: $(NAME)
	@echo "Compilation of $(NAME) : \033[1;32mOK\033[0m"

# === Compilation === #

$(NAME): $(MLX) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(LIBFT) $(LIBS)

$(OBJ_DIR)/%.o: srcs/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# === Compilation Bonus === #

bonus: $(NAME_BONUS)
	@echo "Compilation of $(NAME_BONUS) : \033[1;32mOK\033[0m"

$(NAME_BONUS): $(MLX) $(OBJ_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) $(OBJ_BONUS) -o $(NAME_BONUS) $(LIBFT) $(LIBS)

$(OBJ_DIR_BONUS)/%.o: srcs_bonus/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

# === MLX === #

$(MLX): $(MLX_DIR)
	@if [ ! -d "$(MLX_DIR)/build" ]; then \
		echo "Building MLX42..."; \
		cd $(MLX_DIR) && cmake -B build && cmake --build build -j4; \
	else \
		echo "MLX42 already built."; \
	fi

$(MLX_DIR):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Cloning MLX42..."; \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
	fi

clean_mlx:
	@rm -rf $(MLX_DIR)/build
	@echo "Clean of MLX42 : \033[1;32mOK\033[0m"

fclean_mlx: clean_mlx

re_mlx: fclean_mlx $(MLX)

# === Libft === #

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

clean_libft:
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean_libft:
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re_libft:
	@$(MAKE) -C $(LIBFT_DIR) re --no-print-directory

# === Nettoyage === #

clean: clean_libft
	@rm -rf $(OBJ_DIR)
	@echo "Clean de $(NAME) : \033[1;32mOK\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "Fclean de $(NAME) : \033[1;32mOK\033[0m"

re: fclean fclean_libft fclean_bonus all

# === Nettoyage Bonus === #

clean_bonus: clean_libft
	@rm -rf $(OBJ_DIR_BONUS)
	@echo "Clean de $(NAME_BONUS) : \033[1;32mOK\033[0m"

fclean_bonus: clean_bonus
	@rm -f $(NAME_BONUS)
	@echo "Fclean de $(NAME_BONUS) : \033[1;32mOK\033[0m"

re_bonus: fclean_bonus fclean_libft bonus

# === Phony === #

.PHONY: all clean fclean re clean_libft fclean_libft re_libft clean_mlx fclean_mlx re_mlx bonus clean_bonus fclean_bonus re_bonus
