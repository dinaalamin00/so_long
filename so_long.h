/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:51:41 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/19 12:46:18 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <errno.h>
# include "minilibx/mlx.h"

typedef struct s_image
{
	void	*wall;
	void	*player;
	void	*coll;
	void	*floor;
	void	*ex;
	void	*enemy;
	void	*black;
}	t_image;
typedef struct s_map
{
	char	**map_arr;
	int		fd;
	int		height;
	int		width;
	int		emp;
	int		coll;
	int		wall;
	int		ex;
	int		player;
	int		enemy;
	int		p_row;
	int		p_col;
	int		num_moves;
}	t_map;
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*wind_ptr;
	t_image	img;
	t_map	map;
	int		height;
	int		width;
}	t_mlx;

//map parsing
void	check_map(char **argv, t_map *map);
void	init_map(char **argv, t_map *map);
void	read_map(t_map *map);
int		valid_path(t_map *map);

//validation check
int		valid_wall(char *line);
int		valid_map(t_map *map);
int		valid_char(char c);
int		valid_line(char *line, size_t width);

//path_check
void	init_temp(t_map *map, t_map *temp_map);
int		find_player(char *line);
void	check_char(t_map *temp_map, char c);

//put image
void	put_map(t_mlx gmlx);
void	fill_map(t_mlx gmlx);
void	put_floor(t_mlx gmlx, int i, int j);
void	put_wall(t_mlx gmlx, int i, int j);
void	put_player(t_mlx gmlx, int i, int j);
void	put_coll(t_mlx gmlx, int i, int j, int *k);
void	put_exit(t_mlx gmlx, int i, int j, int stat);

//events
int		event(int keycode, t_mlx *gmlx);
int		escape(t_mlx *gmlx);
void	move_up(t_mlx *gmlx, t_map *map);
void	move_down(t_mlx *gmlx, t_map *map);
void	move_right(t_mlx *gmlx, t_map *map);
void	move_left(t_mlx *gmlx, t_map *map);
void	open_exit(t_mlx gmlx);
void	print_moves(t_map *map);

//error
void	print_error(t_map *map, char *errmsg);
char	**ft_free(char **ptr);
void	destroy(t_mlx *gmlx);

#endif