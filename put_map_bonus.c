/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:03:46 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/18 15:24:05 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	put_enemy(t_mlx gmlx, int i, int j, int sprite)
{
	if (sprite == 1)
		gmlx.img.enemy = mlx_xpm_file_to_image(gmlx.mlx_ptr,
				"tiles/sprite1.xpm", &gmlx.width, &gmlx.height);
	else if (sprite == 2)
		gmlx.img.enemy = mlx_xpm_file_to_image(gmlx.mlx_ptr,
				"tiles/sprite2.xpm", &gmlx.width, &gmlx.height);
	else if (sprite == 3)
		gmlx.img.enemy = mlx_xpm_file_to_image(gmlx.mlx_ptr,
				"tiles/sprite3.xpm", &gmlx.width, &gmlx.height);
	if (!gmlx.img.enemy)
	{
		destroy(&gmlx);
		print_error(&gmlx.map, "Invalid Image File");
	}
	mlx_put_image_to_window(gmlx.mlx_ptr, gmlx.wind_ptr,
		gmlx.img.enemy, j * 50, i * 50);
	mlx_destroy_image(gmlx.mlx_ptr, gmlx.img.enemy);
}

void	fill_map_b(t_mlx gmlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < gmlx.map.height)
	{
		j = 0;
		while (j < gmlx.map.width)
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
			j++;
		}
		i++;
	}
}

void	put_map_b(t_mlx gmlx)
{
	int	i;
	int	j;
	int	k;

	fill_map_b(gmlx);
	k = 0;
	i = -1;
	while (++i < gmlx.map.height)
	{
		j = -1;
		while (++j < gmlx.map.width)
		{
			if (gmlx.map.map_arr[i][j] == '1')
				put_wall(gmlx, i, j);
			else if (gmlx.map.map_arr[i][j] == 'P')
				put_player(gmlx, i, j);
			else if (gmlx.map.map_arr[i][j] == 'C')
				put_coll(gmlx, i, j, &k);
			else if (gmlx.map.map_arr[i][j] == 'E')
				put_exit(gmlx, i, j, 0);
			else if (gmlx.map.map_arr[i][j] == 'X')
				put_enemy(gmlx, i, j, 2);
		}
	}
	put_black(&gmlx, &gmlx.map);
}
