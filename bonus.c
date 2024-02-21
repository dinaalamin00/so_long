/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:37:23 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/18 15:37:54 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	main(int argc, char **argv)
{
	t_mlx	gmlx;

	if (argc == 2)
	{
		check_map_b(argv, &gmlx.map);
		gmlx.mlx_ptr = mlx_init();
		if (!gmlx.mlx_ptr)
			print_error(&gmlx.map, "Display Error");
		gmlx.wind_ptr = mlx_new_window(gmlx.mlx_ptr, gmlx.map.width * 50,
				gmlx.map.height * 50, "So_Long");
		put_map_b(gmlx);
		mlx_hook(gmlx.wind_ptr, 2, 0, event_b, &gmlx);
		mlx_hook(gmlx.wind_ptr, 17, 0, escape, &gmlx);
		mlx_loop_hook(gmlx.mlx_ptr, enemy_loop, &gmlx);
		mlx_loop(gmlx.mlx_ptr);
		mlx_destroy_window(gmlx.mlx_ptr, gmlx.wind_ptr);
		free (gmlx.mlx_ptr);
		ft_free(gmlx.map.map_arr);
	}
	return (0);
}
