/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:55:31 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/18 12:46:54 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(t_mlx gmlx)
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

void	put_map(t_mlx gmlx)
{
	int	i;
	int	j;
	int	k;

	fill_map(gmlx);
	k = 0;
	i = 0;
	while (i < gmlx.map.height)
	{
		j = 0;
		while (j < gmlx.map.width)
		{
			if (gmlx.map.map_arr[i][j] == '1')
				put_wall(gmlx, i, j);
			else if (gmlx.map.map_arr[i][j] == 'P')
				put_player(gmlx, i, j);
			else if (gmlx.map.map_arr[i][j] == 'C')
				put_coll(gmlx, i, j, &k);
			else if (gmlx.map.map_arr[i][j] == 'E')
				put_exit(gmlx, i, j, 0);
			j++;
		}
		i++;
	}
}
