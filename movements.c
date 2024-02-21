/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:46:58 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/19 10:52:07 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_mlx *gmlx, t_map *map)
{
	if (gmlx->map.map_arr [gmlx->map.p_row - 1][gmlx->map.p_col] == '1')
		return ;
	if (gmlx->map.map_arr [gmlx->map.p_row - 1][gmlx->map.p_col] == 'E')
	{
		if (map->coll == 0)
		{
			ft_putendl_fd("----- YOU WON -----", 1);
			escape(gmlx);
		}
		return ;
	}
	if (gmlx->map.map_arr[gmlx->map.p_row - 1][gmlx->map.p_col] == 'C')
	{
		map->coll--;
		if (map -> coll == 0)
			open_exit(*gmlx);
		map->map_arr [gmlx->map.p_row - 1][gmlx->map.p_col] = 'P';
		map -> map_arr [gmlx->map.p_row][gmlx->map.p_col] = '0';
	}
	put_player (*gmlx, map -> p_row - 1, map -> p_col);
	put_floor(*gmlx, map->p_row, map->p_col);
	map -> p_row = map -> p_row - 1;
	print_moves(map);
}

void	move_down(t_mlx *gmlx, t_map *map)
{
	if (gmlx->map.map_arr [gmlx->map.p_row + 1][gmlx->map.p_col] == '1')
		return ;
	if (gmlx->map.map_arr [gmlx->map.p_row + 1][gmlx->map.p_col] == 'E')
	{
		if (map->coll == 0)
		{
			ft_putendl_fd("----- YOU WON -----", 1);
			escape(gmlx);
		}
		return ;
	}
	if (gmlx->map.map_arr[gmlx->map.p_row + 1][gmlx->map.p_col] == 'C')
	{
		map->coll--;
		if (map -> coll == 0)
			open_exit(*gmlx);
		map->map_arr[gmlx->map.p_row + 1][gmlx->map.p_col] = 'P';
		map -> map_arr [gmlx->map.p_row][gmlx->map.p_col] = '0';
	}
	put_player (*gmlx, map -> p_row + 1, map -> p_col);
	put_floor(*gmlx, map->p_row, map->p_col);
	map -> p_row = map -> p_row + 1;
	print_moves(map);
}

void	move_right(t_mlx *gmlx, t_map *map)
{
	if (gmlx->map.map_arr [gmlx->map.p_row][gmlx->map.p_col + 1] == '1')
		return ;
	if (gmlx->map.map_arr [gmlx->map.p_row][gmlx->map.p_col + 1] == 'E')
	{
		if (map->coll == 0)
		{
			ft_putendl_fd("----- YOU WON -----", 1);
			escape(gmlx);
		}
		return ;
	}
	if (gmlx->map.map_arr[gmlx->map.p_row][gmlx->map.p_col + 1] == 'C')
	{
		map->coll--;
		if (map -> coll == 0)
			open_exit(*gmlx);
		map->map_arr[gmlx->map.p_row][gmlx->map.p_col + 1] = 'P';
		map -> map_arr [gmlx->map.p_row][gmlx->map.p_col] = '0';
	}
	put_player (*gmlx, map -> p_row, map -> p_col + 1);
	put_floor(*gmlx, map->p_row, map->p_col);
	map -> p_col = map -> p_col + 1;
	print_moves(map);
}

void	move_left(t_mlx *gmlx, t_map *map)
{
	if (gmlx->map.map_arr [gmlx->map.p_row][gmlx->map.p_col - 1] == '1')
		return ;
	if (gmlx->map.map_arr [gmlx->map.p_row][gmlx->map.p_col - 1] == 'E')
	{
		if (map->coll == 0)
		{
			ft_putendl_fd("----- YOU WON -----", 1);
			escape(gmlx);
		}
		return ;
	}
	if (gmlx->map.map_arr[gmlx->map.p_row][gmlx->map.p_col - 1] == 'C')
	{
		map->coll--;
		if (map -> coll == 0)
			open_exit(*gmlx);
		map->map_arr[gmlx->map.p_row][gmlx->map.p_col - 1] = 'P';
		map -> map_arr [gmlx->map.p_row][gmlx->map.p_col] = '0';
	}
	put_player (*gmlx, map -> p_row, map -> p_col - 1);
	put_floor(*gmlx, map->p_row, map->p_col);
	map -> p_col = map -> p_col - 1;
	print_moves(map);
}

void	print_moves(t_map *map)
{
	map -> num_moves++;
	ft_putstr_fd("Moves = ", 1);
	ft_putnbr_fd(map -> num_moves, 1);
	ft_putchar_fd('\n', 1);
}
