/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:02:10 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/19 10:50:14 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	move_up_b(t_mlx *gmlx, t_map *map)
{
	if (gmlx->map.map_arr [gmlx->map.p_row - 1][gmlx->map.p_col] == '1')
		return ;
	if (gmlx->map.map_arr [gmlx->map.p_row - 1][gmlx->map.p_col] == 'X')
		end_game(gmlx);
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
	put_moves(gmlx, map);
}

void	move_down_b(t_mlx *gmlx, t_map *map)
{
	if (gmlx->map.map_arr [gmlx->map.p_row + 1][gmlx->map.p_col] == '1')
		return ;
	if (gmlx->map.map_arr [gmlx->map.p_row + 1][gmlx->map.p_col] == 'X')
		end_game(gmlx);
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
	put_moves(gmlx, map);
}

void	move_right_b(t_mlx *gmlx, t_map *map)
{
	if (gmlx->map.map_arr [gmlx->map.p_row][gmlx->map.p_col + 1] == '1')
		return ;
	if (gmlx->map.map_arr [gmlx->map.p_row][gmlx->map.p_col + 1] == 'X')
		end_game(gmlx);
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
	put_moves(gmlx, map);
}

void	move_left_b(t_mlx *gmlx, t_map *map)
{
	if (gmlx->map.map_arr [gmlx->map.p_row][gmlx->map.p_col - 1] == '1')
		return ;
	if (gmlx->map.map_arr [gmlx->map.p_row][gmlx->map.p_col - 1] == 'X')
		end_game(gmlx);
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
	put_moves(gmlx, map);
}
