/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:53:29 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/18 15:56:23 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	check_path_b(t_map *map, t_map *temp_map, int i, int j)
{
	if ((i < 0 || i >= map->height) || (j < 0 || j >= map -> width))
		return ;
	if (temp_map->map_arr[i][j] == 'E')
	{
		temp_map -> ex++;
		temp_map->map_arr[i][j] = '1';
	}
	if (temp_map->map_arr[i][j] != '1' && temp_map->map_arr[i][j] != 'X')
	{
		check_char(temp_map, map->map_arr[i][j]);
		temp_map->map_arr[i][j] = '1';
		check_path_b(map, temp_map, i - 1, j);
		check_path_b(map, temp_map, i + 1, j);
		check_path_b(map, temp_map, i, j - 1);
		check_path_b(map, temp_map, i, j + 1);
	}
}

int	valid_path_b(t_map *map)
{
	t_map	temp_map;
	int		i;
	int		j;

	init_temp(map, &temp_map);
	i = 0;
	j = 0;
	while (map->map_arr[i])
	{
		j = find_player(map->map_arr[i]);
		if (j >= 0)
			break ;
		i++;
	}
	map -> p_row = i;
	map -> p_col = j;
	check_path_b(map, &temp_map, i, j);
	if (!(temp_map.ex == 1 && temp_map.coll == map->coll))
	{
		ft_free(temp_map.map_arr);
		return (0);
	}
	ft_free(temp_map.map_arr);
	return (1);
}
