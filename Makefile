NAME = cub3D

SRC =	src/main.c src/parse/parse.c src/parse/parse_utils.c src/parse/process.c src/parse/process_map.c\
	src/execution/execution.c src/execution/keyboard.c\


CC = gcc
RM = rm -f
FLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address

LIBFT_PATH = libft/
LIBFT = libft/libft.a
MINILIBX = minilibx/libmlx.a
MINIFLG = -L./minilibx -lmlx -framework OpenGL -framework AppKit

GNL_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c
GNL_PATH = gnl/bonus/
GNL = $(addprefix $(GNL_PATH), $(GNL_SRC))
GNL_OBJ = $(GNL:.c=.o)

OBJS = $(SRC:.c=.o)

RED	= '\033[1;31m'
GREEN	= '\033[1;32m'
PINK	= '\033[1;35m'
NO_COLOR	= '\033[0m'

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS) $(GNL_OBJ)
	@echo $(PINK)"Generating executable..."$(NO_COLOR)
	@make -C minilibx
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(GNL_OBJ) -I $(LIBFT_PATH) $(MINILIBX) $(MINIFLG) -o $(NAME)
	@echo $(PINK)"$(NAME) Generated!"$(NO_COLOR)

%.o: %.c
	@echo $(GREEN)"[OK]"$(NO_COLOR) "\c"
	$(CC) $(FLAGS) -I $(LIBFT_PATH) -c $< -o $@

clean:
	@make clean -C minilibx/
	@echo $(RED)"Minilibx OBJS deleted"$(NO_COLOR)
	@make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)
	$(RM) $(GNL_OBJ)
	@echo $(RED)"cub3D OBJS deleted"$(NO_COLOR)

fclean: clean
	$(RM) $(LIBFT)
	@echo $(RED)"libft.a deleted"$(NO_COLOR)
	$(RM) $(NAME)
	@echo $(RED)"$(NAME) deleted"$(NO_COLOR)

re: fclean all

n: 
	"norminette" $(SRC) cub3D.h

.PHONY: all clean fclean re n
