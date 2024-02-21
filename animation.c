/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:16:02 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/18 15:54:29 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	put_sprite(t_mlx gmlx, int num)
{
	int	i;
	int	j;

	i = -1;
	gmlx.img.floor = mlx_xpm_file_to_image(gmlx.mlx_ptr, "tiles/background.xpm",
			&gmlx.width, &gmlx.height);
	if (!gmlx.img.floor)
	{
		destroy(&gmlx);
		print_error(&gmlx.map, "Invalid Image File");
	}
	while (gmlx.map.map_arr[++i])
	{
		j = -1;
		while (gmlx.map.map_arr[i][++j])
		{
			if (gmlx.map.map_arr[i][j] == 'X')
			{
				mlx_put_image_to_window(gmlx.mlx_ptr, gmlx.wind_ptr,
					gmlx.img.floor, j * 50, i * 50);
				put_enemy(gmlx, i, j, num);
			}
		}
	}
	mlx_destroy_image(gmlx.mlx_ptr, gmlx.img.floor);
}

int	enemy_loop(t_mlx *gmlx)
{
	static int	num;

	if (num <= 10)
		put_sprite(*gmlx, 1);
	else if (num <= 20)
		put_sprite(*gmlx, 2);
	else if (num <= 30)
		put_sprite(*gmlx, 3);
	else if (num <= 40)
		put_sprite(*gmlx, 2);
	else if (num <= 50)
		num = 0;
	num++;
	return (0);
}
