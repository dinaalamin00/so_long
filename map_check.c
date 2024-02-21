/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:37:44 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/19 13:31:23 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_map *map)
{
	int	i;

	i = 0;
	map->map_arr[i] = get_next_line(map->fd);
	if (!map->map_arr[i])
		print_error(map, "Empty File");
	map->width = ft_strlen(map->map_arr[i]);
	while (map->map_arr[i])
	{
		i++;
		map->map_arr[i] = get_next_line(map->fd);
	}
	map->map_arr[i] = NULL;
	close(map->fd);
}

static void	assign_map(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			map -> emp++;
		else if (line[i] == '1')
			map -> wall++;
		else if (line[i] == 'C')
			map -> coll++;
		else if (line[i] == 'E')
			map -> ex++;
		else if (line[i] == 'P')
			map -> player++;
		i++;
	}
}

static void	iteri_map(t_map *map)
{
	int		i;

	i = 0;
	if (!map->map_arr[i])
		print_error(map, "Empty File");
	if (!valid_wall(map->map_arr[i]))
		print_error(map, "Invalid Wall");
	while (map->map_arr[i])
	{
		if (!map->map_arr[i + 1])
		{
			if (!valid_wall(map->map_arr[i])
				|| (int)ft_strlen(map->map_arr[i]) != map->width)
				print_error(map, "Invalid Wall");
		}
		else if (!valid_line(map->map_arr[i], map->width))
		{
			ft_free(map->map_arr);
			exit(EXIT_FAILURE);
		}
		assign_map(map->map_arr[i], map);
		i++;
	}
	map->map_arr[i] = NULL;
}

void	check_map(char **argv, t_map *map)
{
	char	*temp;

	temp = argv[1] + (ft_strlen(argv[1]) - 4);
	if (ft_strncmp(temp, ".ber", 4) != 0)
	{
		ft_putendl_fd("Error\nInvalid File", 2);
		exit(EXIT_FAILURE);
	}
	init_map(argv, map);
	read_map(map);
	iteri_map(map);
	if (!valid_map(map))
	{
		ft_free(map->map_arr);
		exit(EXIT_FAILURE);
	}
	if (!valid_path(map))
		print_error(map, "Invalid Path");
	if (map->width > 51 || map->height > 28)
		print_error(map, "Map is too big");
}
