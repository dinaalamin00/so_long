/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:41:14 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/18 15:57:06 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	event(int keycode, t_mlx *gmlx)
{
	if (keycode == ESC)
		escape(gmlx);
	else if (keycode == W || keycode == ARROW_UP)
		move_up(gmlx, &gmlx->map);
	else if (keycode == A || keycode == ARROW_LEFT)
		move_left(gmlx, &gmlx->map);
	else if (keycode == S || keycode == ARROW_DOWN)
		move_down(gmlx, &gmlx->map);
	else if (keycode == D || keycode == ARROW_RIGHT)
		move_right(gmlx, &gmlx->map);
	return (0);
}
