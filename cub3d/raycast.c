/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:51:00 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/27 18:40:16 by diogosan         ###   ########.fr       */
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

void draw_3d_walls(t_mlx *win, float distance, int column, int color)
{
	float	lineH;
	float	line_start;
	float	line_end;

	// Calculate wall height based on distance
	lineH = (SQUARE_SIZE * HEIGHT) / distance;
	if (lineH > HEIGHT)
		lineH = HEIGHT;

	// Calculate start and end positions
	line_start = (HEIGHT / 2) - (lineH / 2);
	line_end = line_start + lineH;

	// Draw vertical line for the wall
	while (line_start < line_end)
	{
		my_pixel_put(&win->img, column, (int)line_start, color);
		line_start++;
	}
}


void    raycaster(t_mlx *win)
{
	int r;
	float hx, hy, vx, vy, ray_h, ray_v, line;
	float ra;
	int wall_color;

	r = -1;
	ra = win->player->player_angle - (FOV / 2);//DR * 30;
	ft_circle_normalizer(&ra);
	while (++r < WIDTH)
	{
		ft_horizontal_intersection(win, ra, &hx, &hy);
		ft_vertical_intersection(win, ra, &vx, &vy);
		ray_h = line_length(win->player->player_x, win->player->player_y, hx, hy);
		ray_v = line_length(win->player->player_x, win->player->player_y, vx, vy);
		if (ray_h < ray_v) // Horizontal intersection is closer
		{
			//ft_value_setter(&rx, &ry, hx, hy);
			if (hy > win->player->player_y) // South wall (yo > 0)// North wall (inverso)
				wall_color = 0xFF0000; // Red
			else // North wall (yo < 0)
				wall_color = 0x0000FF; // Blue
			line = ray_h;
		}
		else // Vertical intersection is closer
		{
			//ft_value_setter(&rx, &ry, vx, vy);
			if (vx > win->player->player_x) // East wall (xo > 0)
				wall_color = 0x00FF00; // Green
			else // West wall (xo < 0)
				wall_color = 0xFFFF00; // Yellow
			line = ray_v;
		}
		//ft_bresenhams_alg(win, rx, ry, 0x0000ff);
		line = line * cos(win->player->player_angle - ra);
		draw_3d_walls(win, line, r, wall_color);
		ra += DR;
		ft_circle_normalizer(&ra);
	}
}

/*

		if (ray_h > ray_v)
		{
			ft_value_setter(&rx, &ry, vx, vy);
			if (ra < PI) // Facing North
				wall_color = 0x0000FF; // Blue
			else // Facing South
				wall_color = 0xFF0000; // Red
			line = ray_v;
		}
		else
		{
			ft_value_setter(&rx, &ry, hx, hy);
			if (ra > P2 && ra < P3) // Facing West
				wall_color = 0xFFFF00; // Yellow
			else if (ra < P2 || ra > P3)  // Facing East
				wall_color = 0x00FF00; // Green
			line = ray_h;
		}

*/
