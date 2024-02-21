/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:11:05 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/19 10:51:06 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	event_b(int keycode, t_mlx *gmlx)
{
	if (keycode == ESC)
		escape(gmlx);
	else if (keycode == W || keycode == ARROW_UP)
		move_up_b(gmlx, &gmlx->map);
	else if (keycode == A || keycode == ARROW_LEFT)
		move_left_b(gmlx, &gmlx->map);
	else if (keycode == S || keycode == ARROW_DOWN)
		move_down_b(gmlx, &gmlx->map);
	else if (keycode == D || keycode == ARROW_RIGHT)
		move_right_b(gmlx, &gmlx->map);
	return (0);
}

void	put_black(t_mlx *gmlx, t_map *map)
{
	gmlx->img.black = mlx_xpm_file_to_image(gmlx->mlx_ptr, "tiles/black.xpm",
			&gmlx->width, &gmlx->height);
	if (!gmlx->img.black)
	{
		destroy(gmlx);
		print_error(map, "Invalid Image File");
	}
	mlx_put_image_to_window(gmlx->mlx_ptr, gmlx->wind_ptr,
		gmlx->img.black, 40, 10);
	mlx_put_image_to_window(gmlx->mlx_ptr, gmlx->wind_ptr,
		gmlx->img.black, 80, 10);
	mlx_put_image_to_window(gmlx->mlx_ptr, gmlx->wind_ptr,
		gmlx->img.black, 120, 10);
	mlx_destroy_image(gmlx->mlx_ptr, gmlx->img.black);
	mlx_string_put(gmlx->mlx_ptr, gmlx->wind_ptr, 50, 30, 0xFFFFFF, "MOVES = ");
	mlx_string_put(gmlx->mlx_ptr, gmlx->wind_ptr, 110,
		30, 0xFFFFFF, ft_itoa(map -> num_moves));
}

void	put_moves(t_mlx *gmlx, t_map *map)
{
	++map -> num_moves;
	put_black(gmlx, map);
}

void	end_game(t_mlx *gmlx)
{
	ft_putendl_fd("----- GAME OVER -----", 1);
	escape(gmlx);
}
