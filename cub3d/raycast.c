/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:51:00 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/28 21:15:44 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

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
    int line_h;
    int line_start;
   // int line_end;
    int y;
	int tex_x;
	int	tex_y;
	float	y_offset;

	(void)color;
	tex_x = column % win->north_texture.width;
    line_h = (SQUARE_SIZE * HEIGHT) / distance;

	float ty_step = 32 / line_h;
    if (line_h > HEIGHT)
	{
		y_offset = (line_h - HEIGHT) / 2;
		line_h = HEIGHT;
	}
        

    line_start = (HEIGHT / 2) - (line_h / 2);
    //line_end = line_start + line_h;
	tex_y = y_offset * ty_step;
    y = -1;
    while (++y < line_h)
    {
		float t_color = get_pixel_color(&win->north_texture, tex_x, tex_y*32);
		my_pixel_put(&win->img, column, line_start + y, t_color);
		tex_y += ty_step;
    }
}


/*
*	the horizontal lines tell north from south
*	the vertical lines tell east from west
*
*	the directions are inverted
*	South -> North
*	North -> South
*	etc etc
*
*/


void    raycaster(t_mlx *win)
{
	int		r;
	float	hx, hy, vx, vy, ray_h, ray_v, line;
	float	ra;
	int		wall_color;

	r = -1;
	ra = win->player->player_angle - (FOV / 2);
	ft_circle_normalizer(&ra);
	while (++r < WIDTH)
	{
		ft_horizontal_intersection(win, ra, &hx, &hy);
		ft_vertical_intersection(win, ra, &vx, &vy);
		ray_h = line_length(win->player->player_x, win->player->player_y, hx, hy);
		ray_v = line_length(win->player->player_x, win->player->player_y, vx, vy);
		if (ray_h < ray_v) // Horizontal intersection is closer
		{
			if (hy > win->player->player_y) // South wall 
				wall_color = 0xFF0000; // Red
			else // North wall
				wall_color = 0x0000FF; // Blue
			line = ray_h;
		}
		else // Vertical intersection is closer
		{
			if (vx > win->player->player_x) // East wall 
				wall_color = 0x00FF00; // Green
			else // West wall 
				wall_color = 0xFFFF00; // Yellow
			line = ray_v;
		}
		line = line * cos(win->player->player_angle - ra);
		draw_3d_walls(win, line, r, wall_color);
		ra += DR;
		ft_circle_normalizer(&ra);
	}
}
