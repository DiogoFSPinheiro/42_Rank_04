/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:51:00 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/29 23:37:28 by diogosan         ###   ########.fr       */
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

void	ft_texture_setter(t_mlx *win, t_tex *texture_to_use, float *tx)
{
	if (win->texture_nbr == 0)
	{
		*texture_to_use = win->north_texture;
		*tx = 63 - *tx;
	}
	else if (win->texture_nbr == 1)
		*texture_to_use = win->south_texture;
	else if (win->texture_nbr == 2)
		*texture_to_use = win->west_texture;
	else if (win->texture_nbr == 3)
	{
		*texture_to_use = win->east_texture;
		*tx = 63 - *tx;
	}
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

void	ft_wall_limits(int *line_h, float *ty_offset)
{
	if (*line_h > HEIGHT)
	{
		*ty_offset = ((float)*line_h - HEIGHT) / 2;
		*line_h = HEIGHT;
	}
}

void	draw_3d_walls(t_mlx *win, float distance, int column, float hx)
{
	int	line_h;
	int	line_start;
	t_tex texture_to_use;
	t_texture_vars vars;
	
	line_h = (SQUARE_SIZE * HEIGHT) / distance;
	vars.ty_step = 64 / (float)line_h;
	vars.ty_offset = 0;
	ft_wall_limits(&line_h, &vars.ty_offset);
	line_start = (HEIGHT / 2) - (line_h / 2);
	vars.y = -1;
	vars.ty = vars.ty_step * vars.ty_offset;
	vars.tx = (int)(hx) % 64;
	ft_texture_setter(win, &texture_to_use, &vars.tx);
	while (++vars.y < line_h)
	{
		my_pixel_put(&win->img, column, line_start + vars.y, get_pixel_color(&texture_to_use,
			((int)vars.tx) % SQUARE_SIZE, (int)(vars.ty)));
		vars.ty += vars.ty_step;
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
void	ft_texture_picker(t_mlx *win, float ray_point, char c)
{
	if (c == 'h')
	{
		if (ray_point > win->player->player_y) // South wall 
			win->texture_nbr = 0;
		else // North wall
			win->texture_nbr = 1;
	}
	else
	{
		if (ray_point > win->player->player_x) // East wall 
			win->texture_nbr = 2;
		else // West wall 
			win->texture_nbr = 3;
	}
}

void	ft_value_setter(float *val1, float *set1, float *val2, float *set2)
{
	*val1 = *set1;
	*val2 = *set2;
}

void	raycaster(t_mlx *win)// TODO place the vals in a struct
{
	int		r;
	float	hx, hy, vx, vy, ray_h, ray_v, line, ra, wall_x;

	r = -1;
	ra = win->player->player_angle - (FOV / 2);
	while (++r < WIDTH && ft_circle_normalizer(&ra) == SUCCESS)
	{
		ft_horizontal_intersection(win, ra, &hx, &hy);
		ft_vertical_intersection(win, ra, &vx, &vy);
		ray_h = line_length(win->player->player_x, win->player->player_y, hx, hy);
		ray_v = line_length(win->player->player_x, win->player->player_y, vx, vy);
		if (ray_h < ray_v)
		{
			ft_texture_picker(win, hy, 'h');
			ft_value_setter(&wall_x, &hx, &line, &ray_h);
		}
		else
		{
			ft_texture_picker(win, vx, 'v');
			ft_value_setter(&wall_x, &vy, &line, &ray_v);
		}
		line = line * cos(win->player->player_angle - ra);
		draw_3d_walls(win, line, r, wall_x);
		ra += DR;
	}
}



