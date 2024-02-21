/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:42:03 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/18 12:43:41 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_corners(t_mlx *gmlx, int i, int j)
{
	if (i == 0 && j == 0)
		gmlx->img.wall = mlx_xpm_file_to_image(gmlx->mlx_ptr,
				"tiles/left_top_corn.xpm", &gmlx->width, &gmlx->height);
	else if (i == 0 && j == gmlx->map.width - 1)
		gmlx->img.wall = mlx_xpm_file_to_image(gmlx->mlx_ptr,
				"tiles/right_top_corn.xpm", &gmlx->width, &gmlx->height);
	else if (i == gmlx->map.height - 1 && j == 0)
		gmlx->img.wall = mlx_xpm_file_to_image(gmlx->mlx_ptr,
				"tiles/left_down_corn.xpm", &gmlx->width, &gmlx->height);
	else if (i == gmlx->map.height - 1 && j == gmlx->map.width - 1)
		gmlx->img.wall = mlx_xpm_file_to_image(gmlx->mlx_ptr,
				"tiles/right_down_corn.xpm", &gmlx->width, &gmlx->height);
}

static void	put_h_wall(t_mlx *gmlx, int j)
{
	if (j % 9 == 0)
		gmlx->img.wall = mlx_xpm_file_to_image(gmlx->mlx_ptr,
				"tiles/wall_h_3.xpm", &gmlx->width, &gmlx->height);
	else if (j % 6 == 0)
		gmlx->img.wall = mlx_xpm_file_to_image(gmlx->mlx_ptr,
				"tiles/wall_h_5.xpm", &gmlx->width, &gmlx->height);
	else
		gmlx->img.wall = mlx_xpm_file_to_image(gmlx->mlx_ptr,
				"tiles/wall_h.xpm", &gmlx->width, &gmlx->height);
}

static void	put_v_wall(t_mlx *gmlx, int i)
{
	if (i % 9 == 0)
		gmlx->img.wall = mlx_xpm_file_to_image(gmlx->mlx_ptr,
				"tiles/wall_v_3.xpm", &gmlx->width, &gmlx->height);
	else if (i % 6 == 0)
		gmlx->img.wall = mlx_xpm_file_to_image(gmlx->mlx_ptr,
				"tiles/wall_v_5.xpm", &gmlx->width, &gmlx->height);
	else
		gmlx->img.wall = mlx_xpm_file_to_image(gmlx->mlx_ptr,
				"tiles/wall_v.xpm", &gmlx->width, &gmlx->height);
}

void	put_wall(t_mlx gmlx, int i, int j)
{
	if ((i == 0 && j == 0) || (i == 0 && j == gmlx.map.width - 1)
		|| (i == gmlx.map.height - 1 && j == 0)
		|| (i == gmlx.map.height - 1 && j == gmlx.map.width - 1))
		put_corners(&gmlx, i, j);
	else if (i == 0 || i == gmlx.map.height - 1)
		put_h_wall(&gmlx, j);
	else if (j == 0 || j == gmlx.map.width - 1)
		put_v_wall(&gmlx, i);
	else
		gmlx.img.wall = mlx_xpm_file_to_image(gmlx.mlx_ptr,
				"tiles/mid_wall2.xpm", &gmlx.width, &gmlx.height);
	if (!gmlx.img.wall)
	{
		destroy(&gmlx);
		print_error(&gmlx.map, "Invalid Image File");
	}
	mlx_put_image_to_window(gmlx.mlx_ptr, gmlx.wind_ptr,
		gmlx.img.wall, j * 50, i * 50);
	mlx_destroy_image(gmlx.mlx_ptr, gmlx.img.wall);
}
