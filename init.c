/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:02:49 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/18 13:15:47 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(int fd, char *filename)
{
	char	*line;
	int		cnt;

	cnt = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (!line)
		return (cnt);
	while (line)
	{
		cnt++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (cnt);
}

void	init_map(char **argv, t_map *map)
{
	map -> emp = 0;
	map -> coll = 0;
	map -> wall = 0;
	map -> ex = 0;
	map -> player = 0;
	map -> num_moves = 0;
	map -> width = 0;
	map ->height = count_lines(map->fd, argv[1]);
	map -> map_arr = NULL;
	map -> map_arr = (char **)ft_calloc((map -> height + 1), sizeof(char *));
	if (!map->map_arr)
		print_error(map, "malloc error");
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd < 0)
	{
		free(map->map_arr);
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
}
