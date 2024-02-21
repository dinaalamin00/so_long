/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:17:57 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/18 11:28:28 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_temp(t_map *map, t_map *temp_map)
{
	int	i;

	temp_map -> emp = 0;
	temp_map -> coll = 0;
	temp_map -> wall = 0;
	temp_map -> ex = 0;
	temp_map -> player = 0;
	temp_map -> width = 0;
	temp_map ->height = 0;
	temp_map -> map_arr = NULL;
	temp_map -> map_arr = ft_calloc(map -> height + 1, sizeof(char *));
	if (!temp_map->map_arr)
		return ;
	i = 0;
	while (i < map->height)
	{
		temp_map->map_arr[i] = ft_strdup(map->map_arr[i]);
		i++;
	}
}

void	check_char(t_map *temp_map, char c)
{
	if (c == 'C')
		temp_map -> coll++;
	else if (c == 'E')
		temp_map -> ex++;
}

static void	check_path(t_map *map, t_map *temp_map, int i, int j)
{
	if ((i < 0 || i >= map->height) || (j < 0 || j >= map -> width))
		return ;
	if (temp_map->map_arr[i][j] == 'E')
	{
		temp_map -> ex++;
		temp_map->map_arr[i][j] = '1';
	}
	if (temp_map->map_arr[i][j] != '1')
	{
		check_char(temp_map, map->map_arr[i][j]);
		temp_map->map_arr[i][j] = '1';
		check_path(map, temp_map, i - 1, j);
		check_path(map, temp_map, i + 1, j);
		check_path(map, temp_map, i, j - 1);
		check_path(map, temp_map, i, j + 1);
	}
}

int	find_player(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			return (i);
		i++;
	}
	return (-1);
}

int	valid_path(t_map *map)
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
	check_path(map, &temp_map, i, j);
	if (!(temp_map.ex == 1 && temp_map.coll == map->coll))
	{
		ft_free(temp_map.map_arr);
		return (0);
	}
	ft_free(temp_map.map_arr);
	return (1);
}
