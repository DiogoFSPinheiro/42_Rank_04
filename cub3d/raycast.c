/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:51:00 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/26 18:51:39 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * raycaster - Casts rays to determine intersections with the map.
 *
 * Variables used:
 * - @r: Number of rays to cast.
 * - @mx: Map index on the x-axis (integer grid coordinate).
 * - @my: Map index on the y-axis (integer grid coordinate).
 * - @dof: Depth of field (maximum number of steps to check for collisions).
 * - @rx: X-coordinate of the ray endpoint on the rendered map.
 * - @ry: Y-coordinate of the ray endpoint on the rendered map.
 * - @ra: Ray angle (starts as the player's angle, varies per ray).
 * - @xo: X-offset for stepping to the next grid cell.
 * - @yo: Y-offset for stepping to the next grid cell.
 * - @atan:(aTan) Inverse of tangent (used for ray_h direction).
 * - @ntan:(nTan) Negative tangent (used for ray_v direction).
 *
**/

void	ft_horizontal_intersection(t_mlx *win, float ra, float *hx, float *hy)
{
	int mx, my, dof = 0;
	float rx, ry, xo, yo, aTan;

	aTan = -1 / tan(ra);
	if (ra > PI)
	{
		ry = (((int)win->player->player_y / SQUARE_SIZE) * SQUARE_SIZE) - 0.0001;
		rx = (win->player->player_y - ry) * aTan + win->player->player_x;
		yo = -SQUARE_SIZE;
		xo = -yo * aTan;
	}
	else if (ra < PI)
	{
		ry = (((int)win->player->player_y / SQUARE_SIZE) * SQUARE_SIZE) + SQUARE_SIZE;
		rx = (win->player->player_y - ry) * aTan + win->player->player_x;
		yo = SQUARE_SIZE;
		xo = -yo * aTan;
	}
	else if (ra == 0 || ra == PI)
	{
		rx = win->player->player_x;
		ry = win->player->player_y;
		dof = 20;
	}
	while (dof < 20)
	{
		mx = (int)(rx / SQUARE_SIZE);
		my = (int)(ry / SQUARE_SIZE);

		if (mx < 0 || mx >= win->map->width || my < 0 || my >= win->map->height)
			break ;

		if (win->map->coord[my][mx] == '1')
			break ;
		else
		{
			rx += xo;
			ry += yo;
			dof++;
		}
	}
	*hx = rx;
	*hy = ry;
}

void	ft_vertical_intersection(t_mlx *win, float ra, float *vx, float *vy)
{
	int mx, my, dof = 0;
	float rx, ry, xo, yo, nTan;

	nTan = -tan(ra);
	if (ra > P2 && ra < P3)
	{
		rx = (((int)win->player->player_x / SQUARE_SIZE) * SQUARE_SIZE) - 0.0001;
		ry = (win->player->player_x - rx) * nTan + win->player->player_y;
		xo = -SQUARE_SIZE;
		yo = -xo * nTan;
	}
	else if (ra < P2 || ra > P3)
	{
		rx = (((int)win->player->player_x / SQUARE_SIZE) * SQUARE_SIZE) + SQUARE_SIZE;
		ry = (win->player->player_x - rx) * nTan + win->player->player_y;
		xo = SQUARE_SIZE;
		yo = -xo * nTan;
	}
	else if (ra == 0 || ra == PI)
	{
		rx = win->player->player_x;
		ry = win->player->player_y;
		dof = 20;
	}
	while (dof < 20)
	{
		mx = (int)(rx / SQUARE_SIZE);
		my = (int)(ry / SQUARE_SIZE);

		if (mx < 0 || mx >= win->map->width || my < 0 || my >= win->map->height)
			break ;

		if (win->map->coord[my][mx] == '1')
			break ;
		else
		{
			rx += xo;
			ry += yo;
			dof++;
		}
	}
	*vx = rx;
	*vy = ry;
}

void	ft_value_setter(float *rx, float *ry, float x, float y)
{
	*rx = x;
	*ry = y;
}

/*
	this places the angle on the right position (value) 
	of ra on the trignometric circle
	if ra = -180{ (-180) + 2PI } ra = 180
	if ra = 390{ 390 - 2PI } ra = 30
*/
void	ft_circle_normalizer(float *ra)
{
	if (*ra < 0)
		*ra += 2 * PI;
	if (*ra > 2 * PI)
		*ra -= 2 * PI;
}

void	ft_vertical_line(t_mlx *win, int x, int start, int end, int color)
{
	int y;

	y = start;
	while (y < end)
	{
		mlx_pixel_put(win->mlx_connect, win->mlx_win, x, y, color);
		y++;
	}
}


void    raycaster(t_mlx *win)
{
	int r;
	float rx, ry, hx, hy, vx, vy, ray_h, ray_v, line;
	float ra;

	r = 0;
	ra = win->player->player_angle - DR * 30;
	ft_circle_normalizer(&ra);
	while (r++ < 60)
	{
		ft_horizontal_intersection(win, ra, &hx, &hy);
		ft_vertical_intersection(win, ra, &vx, &vy);
		ray_h = line_length(win->player->player_x, win->player->player_y, hx, hy);
		ray_v = line_length(win->player->player_x, win->player->player_y, vx, vy);
		if (ray_h > ray_v)
		{
			ft_value_setter(&rx, &ry, vx, vy);
			line = ray_v;
		}
		else
		{
			ft_value_setter(&rx, &ry, hx, hy);
			line = ray_h;
		}
		ft_bresenhams_alg(win, rx, ry, 0x0000ff);
		int line_h = HEIGHT / line;
		int top_pixel = -line_h / 2 + HEIGHT / 2;
		int bot_pixel = line_h / 2 + HEIGHT / 2;
		if (top_pixel < 0)
			top_pixel = 0;
		if (bot_pixel >= HEIGHT)
			bot_pixel = HEIGHT - 1;
		ra += DR;
		ft_circle_normalizer(&ra);
	}
}




