/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:44:12 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/18 15:53:02 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy(t_mlx *gmlx)
{
	if (gmlx->wind_ptr)
		mlx_destroy_window(gmlx->mlx_ptr, gmlx->wind_ptr);
	if (gmlx->mlx_ptr)
		free(gmlx->mlx_ptr);
}

int	escape(t_mlx *gmlx)
{
	destroy(gmlx);
	ft_free(gmlx->map.map_arr);
	exit (0);
}

void	print_error(t_map *map, char *errmsg)
{
	if (map -> fd > 2)
		close (map -> fd);
	if (map -> map_arr)
		ft_free(map->map_arr);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(errmsg, 2);
	exit(EXIT_FAILURE);
}

char	**ft_free(char **ptr)
{
	size_t	i;

	if (!ptr)
		return (NULL);
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}
