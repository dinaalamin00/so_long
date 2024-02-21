SRC = main.c errors.c map_check.c init.c gnl/get_next_line_utils.c gnl/get_next_line.c\
	  validation_check.c put_wall.c path_check.c put_images.c events.c put_map.c movements.c
BONUS = bonus.c events_bonus.c map_check_bonus.c movements_bonus.c path_check_bonus.c put_map_bonus.c\
	errors.c init.c map_check.c path_check.c put_images.c put_wall.c validation_check.c\
	gnl/get_next_line.c gnl/get_next_line_utils.c put_map.c animation.c 
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = ${SRC:.c=.o}
BONOBJ = ${BONUS:.c=.o}
LIBFTA = Libft/libft.a
MLXLIB = minilibx/libmlx.a
NAME = so_long
BNAME = game


all: $(NAME)

$(NAME): $(OBJ)
	make all -C libft
	make all -C minilibx
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTA) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
bonus: $(BONOBJ)
	make all -C libft
	make all -C minilibx
	$(CC) $(CFLAGS) $(BONOBJ) $(LIBFTA) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(BNAME)

clean:
	make clean -C libft
	make clean -C minilibx
	rm -f $(OBJ) $(BONOBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME) $(BNAME)

re: fclean all

reb: fclean bonus
