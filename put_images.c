/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:15:02 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/17 13:04:39 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor(t_mlx gmlx, int i, int j)
{
	gmlx.img.floor = mlx_xpm_file_to_image(gmlx.mlx_ptr,
			"tiles/background.xpm", &gmlx.width, &gmlx.height);
	if (!gmlx.img.floor)
	{
		destroy(&gmlx);
		print_error(&gmlx.map, "Invalid Image File");
	}
	mlx_put_image_to_window(gmlx.mlx_ptr, gmlx.wind_ptr,
		gmlx.img.floor, j * 50, i * 50);
	mlx_destroy_image(gmlx.mlx_ptr, gmlx.img.floor);
}

void	put_player(t_mlx gmlx, int i, int j)
{
	gmlx.img.player = mlx_xpm_file_to_image(gmlx.mlx_ptr,
			"tiles/player.xpm", &gmlx.width, &gmlx.height);
	if (!gmlx.img.player)
	{
		destroy(&gmlx);
		print_error(&gmlx.map, "Invalid Image File");
	}
	mlx_put_image_to_window(gmlx.mlx_ptr, gmlx.wind_ptr,
		gmlx.img.player, j * 50, i * 50);
	mlx_destroy_image(gmlx.mlx_ptr, gmlx.img.player);
}

void	put_coll(t_mlx gmlx, int i, int j, int *k)
{
	if (*k == 0)
	{
		gmlx.img.coll = mlx_xpm_file_to_image(gmlx.mlx_ptr,
				"tiles/key.xpm", &gmlx.width, &gmlx.height);
		*k = 1;
	}
	else if (*k == 1)
	{
		gmlx.img.coll = mlx_xpm_file_to_image(gmlx.mlx_ptr,
				"tiles/dim.xpm", &gmlx.width, &gmlx.height);
	}
	if (!gmlx.img.coll)
	{
		destroy(&gmlx);
		print_error(&gmlx.map, "Invalid Image File");
	}
	mlx_put_image_to_window(gmlx.mlx_ptr, gmlx.wind_ptr,
		gmlx.img.coll, j * 50, i * 50);
	mlx_destroy_image(gmlx.mlx_ptr, gmlx.img.coll);
}

void	put_exit(t_mlx gmlx, int i, int j, int stat)
{
	if (stat == 0)
		gmlx.img.ex = mlx_xpm_file_to_image(gmlx.mlx_ptr,
				"tiles/ex_closed.xpm", &gmlx.width, &gmlx.height);
	else if (stat == 1)
	{
		gmlx.img.ex = mlx_xpm_file_to_image(gmlx.mlx_ptr,
				"tiles/ex_open.xpm", &gmlx.width, &gmlx.height);
	}
	if (!gmlx.img.ex)
	{
		destroy(&gmlx);
		print_error(&gmlx.map, "Invalid Image File");
	}
	mlx_put_image_to_window(gmlx.mlx_ptr, gmlx.wind_ptr,
		gmlx.img.ex, j * 50, i * 50);
	mlx_destroy_image(gmlx.mlx_ptr, gmlx.img.ex);
}

void	open_exit(t_mlx gmlx)
{
	int	i;
	int	j;

	i = 0;
	while (gmlx.map.map_arr[i])
	{
		j = 0;
		while (gmlx.map.map_arr[i][j])
		{
			if (gmlx.map.map_arr[i][j] == 'E')
			{
				put_exit(gmlx, i, j, 1);
				return ;
			}
			j++;
		}
		i++;
	}
}
