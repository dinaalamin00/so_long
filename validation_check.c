/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:23:50 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/17 12:11:04 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_wall(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\0')
		return (0);
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_map(t_map *map)
{
	if (map -> ex != 1)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("More Than One Exit", 2);
		return (0);
	}
	if (map -> coll < 1)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("There shoud be at least ONE collectible", 2);
		return (0);
	}
	if (map -> player != 1)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("More Than One Player", 2);
		return (0);
	}
	return (1);
}

int	valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

int	valid_line(char *line, size_t width)
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
		if (!valid_char(line[i]))
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Invalid Character", 2);
			return (0);
		}
	}
	return (1);
}
