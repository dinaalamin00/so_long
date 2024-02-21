/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:38:05 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/18 15:58:03 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "so_long.h"

//map
void	check_map_b(char **argv, t_map *map);

//images
void	put_map_b(t_mlx gmlx);
void	fill_map_b(t_mlx gmlx);
void	put_enemy(t_mlx gmlx, int i, int j, int sprite);
//path
int		valid_path_b(t_map *map);

//events
int		event_b(int keycode, t_mlx *gmlx);
void	move_up_b(t_mlx *gmlx, t_map *map);
void	move_down_b(t_mlx *gmlx, t_map *map);
void	move_right_b(t_mlx *gmlx, t_map *map);
void	move_left_b(t_mlx *gmlx, t_map *map);

void	end_game(t_mlx *gmlx);
void	put_moves(t_mlx *gmlx, t_map *map);
void	put_black(t_mlx *gmlx, t_map *map);
int		enemy_loop(t_mlx *gmlx);

#endif