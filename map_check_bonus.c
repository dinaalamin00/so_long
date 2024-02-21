/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:43:20 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/19 13:30:14 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	valid_char_b(char c)
{
	if (ft_strchr("01CEPX", c))
		return (1);
	return (0);
}

static int	valid_line_b(char *line, size_t width)
{
	int	i;

	i = -1;
	if (ft_strlen(line) != width)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Map is not a rectangular", 2);
		return (0);
	}
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Invalid Wall", 2);
		return (0);
	}
	while (line[++i])
	{
		if (!valid_char_b(line[i]))
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Invalid Character", 2);
			return (0);
		}
	}
	return (1);
}

void	assign_map_b(char *line, t_map *map)
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
		else if (line[i] == 'X')
			map -> enemy++;
		i++;
	}
}

void	iteri_map_b(t_map *map)
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
		else if (!valid_line_b(map->map_arr[i], map->width))
		{
			ft_free(map->map_arr);
			exit(EXIT_FAILURE);
		}
		assign_map_b(map->map_arr[i], map);
		i++;
	}
	map->map_arr[i] = NULL;
}

void	check_map_b(char **argv, t_map *map)
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
	iteri_map_b(map);
	if (!valid_map(map))
	{
		ft_free(map->map_arr);
		exit(EXIT_FAILURE);
	}
	if (!valid_path_b(map))
		print_error(map, "Invalid Path");
	if (map->width > 51 || map->height > 28)
		print_error(map, "Map is too big");
}
