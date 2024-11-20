/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:47:44 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/20 17:23:05 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libraries/libft/libft.h"

int	ft_mod(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void	set_up_win(t_mlx *win, char **map)
{
	int	y;

	y = 0;
	win->mlx_connect = 0;
	win->mlx_win = 0;
	win->map = 0;
	win->map = malloc(sizeof(t_map));
	win->player = malloc(sizeof(t_player));
	win->map->height = 10;
	win->map->width = ft_strlen(map[0]);
	win->player->player_angle = 0;
	win->player->player_delta_x = cos(win->player->player_angle) * 5;
	win->player->player_delta_y = sin(win->player->player_angle) * 5;
	win->map->coord = ft_calloc(win->map->height, sizeof(char *));
	while (y < win->map->height)
	{
		win->map->coord[y] = ft_strdup(map[y]);
		y++;
	}
}