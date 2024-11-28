/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:32:11 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/28 17:04:58 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libraries/printf/ft_printf.h"

void	free_map(t_map *map)
{
	int	c;

	c = 0;
	while (map->height > c)
	{
		free(map->coord[c]);
		c++;
	}
	free(map->coord);
	free(map);
}

void	ft_cleanup_and_exit(t_mlx *mlx)
{
	if (mlx->mlx_connect != NULL)
	{
		mlx_destroy_image(mlx->mlx_connect, mlx->img.mlx_img);
		if (mlx->mlx_win != NULL)
			mlx_destroy_window(mlx->mlx_connect, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_connect);
		free(mlx->mlx_connect);
	}
	if (mlx->map != NULL)
		free_map(mlx->map);
	if (mlx->player != NULL)
		free(mlx->player);
	free(mlx);
	exit(0);
}

int	ft_close(t_mlx *mlx)
{
	ft_cleanup_and_exit(mlx);
	return (0);
}

int	ft_event_checker(int Key, t_mlx *mlx)
{
	if (Key == XK_Escape)
		ft_cleanup_and_exit(mlx);
	return (0);
}

int	get_pixel_color(t_tex *img, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (-1);
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(int *)pixel);
}


/*
int	check_collision_x(t_mlx *mlx, int pos_x, int pos_y, int direction)
{
	int	x;
	int	y;

	if (direction == XK_Right)
	{
		x = pos_x + PLAYER_SIZE + 1;
		y = pos_y;
		while (y < pos_y + PLAYER_SIZE)
		{
			if (get_pixel_color(&mlx->img, x, y++) == OBSTACLE_COLOR)
				return (FAILURE);
		}
	}
	else if (direction == XK_Left)
	{
		x = pos_x - 1;
		y = pos_y;
		while (y < pos_y + PLAYER_SIZE)
		{
			if (get_pixel_color(&mlx->img, x, y++) == OBSTACLE_COLOR)
				return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	check_collision_y(t_mlx *mlx, int pos_x, int pos_y, int direction)
{
	int	x;
	int	y;

	if (direction == XK_Up)
	{
		x = pos_x;
		y = pos_y - 1;
		while (x < pos_x + PLAYER_SIZE)
		{
			if (get_pixel_color(&mlx->img, x++, y) == OBSTACLE_COLOR)
				return (FAILURE);
		}
	}
	else if (direction == XK_Down)
	{
		x = pos_x;
		y = pos_y + PLAYER_SIZE + 1;
		while (x < pos_x + PLAYER_SIZE)
		{
			if (get_pixel_color(&mlx->img, x++, y) == OBSTACLE_COLOR)
				return (FAILURE);
		}
	}
	return (SUCCESS);
}
*/

int	arrow_keys(int Key, t_mlx *mlx)
{
	if (Key == XK_Left)
	{
		mlx->player->player_angle -= 0.1;
		if (mlx->player->player_angle < 0)
		{
			mlx->player->player_angle += 2 * PI;
		}
		mlx->player->player_delta_x = cos(mlx->player->player_angle) * 5;
		mlx->player->player_delta_y = sin(mlx->player->player_angle) * 5;
	}

	if (Key == XK_Right)
	{
		mlx->player->player_angle += 0.1;
		if (mlx->player->player_angle > 2 * PI)
		{
			mlx->player->player_angle -= 2 * PI;
		}
		mlx->player->player_delta_x = cos(mlx->player->player_angle) * 5;
		mlx->player->player_delta_y = sin(mlx->player->player_angle) * 5;
	}

	if (Key == XK_Up)
	{
		mlx->player->player_x += mlx->player->player_delta_x;
		mlx->player->player_y += mlx->player->player_delta_y;
	}

	if (Key == XK_Down)
	{
		mlx->player->player_x -= mlx->player->player_delta_x;
		mlx->player->player_y -= mlx->player->player_delta_y;
	}
	if (Key == XK_x)
		ft_println("y: %i  ,  x: %i ",
			mlx->player->player_y, mlx->player->player_x);
	return (0);
}








