/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:56:01 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/21 17:13:00 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	ft_vision_angle(t_mlx *win, float px, float py)
{
	float	x_step;
	float	y_step;
	int		max;
	int		end_x;
	int		end_y;

	end_x = px + 5 * win->player->player_delta_x;
	end_y = py + 5 * win->player->player_delta_y;
	x_step = end_x - px;
	y_step = end_y - py;


	max = fmax(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;

	while ((int)(px - end_x) || (int)(py - end_y))
	{
		my_pixel_put(&win->img, px, py, 0xff00ff);
		px += x_step;
		py += y_step;
	}
}


void	ft_bresenhams_alg(t_mlx *win, float end_x, float end_y, int color)
{
	float	x_step;
	float	y_step;
	float	px;
	float	py;
	int		max;

	px = win->player->player_x;
	py = win->player->player_y;
	x_step = end_x - px;
	y_step = end_y - py;


	max = fmax(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;

	while ((int)(px - end_x) || (int)(py - end_y))
	{
		my_pixel_put(&win->img, px, py, color);
		px += x_step;
		py += y_step;
	}
}

float	line_length(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

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
 * - @ntan:(nTan) Negative tangent (used for ray_h direction).
 *
 * This function iterates through rays, calculates their angles and intersections
 * with the map, and determines whether they hit a wall. The results are used for
 * rendering or other purposes.
 */

void get_horizontal_intersection(t_mlx *win, float ra, float *hx, float *hy)
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
	*hx = fmax(0, fmin(rx, win->map->width * SQUARE_SIZE - 1));
	*hy = fmax(0, fmin(ry, win->map->height * SQUARE_SIZE - 1));
}

void get_vertical_intersection(t_mlx *win, float ra, float *vx, float *vy)
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
	*vx = fmax(0, fmin(rx, win->map->width * SQUARE_SIZE - 1));
	*vy = fmax(0, fmin(ry, win->map->height * SQUARE_SIZE - 1));
}

void raycaster(t_mlx *win)
{
	int r = 0;
	float rx, ry, hx, hy, vx, vy, line_h, line_v;
	float ra = win->player->player_angle;

	while (r++ < 1)
	{
		get_horizontal_intersection(win, ra, &hx, &hy);
		get_vertical_intersection(win, ra, &vx, &vy);
		line_h = line_length(win->player->player_x, win->player->player_y, hx, hy);
		line_v = line_length(win->player->player_x, win->player->player_y, vx, vy);
		if (line_h > line_v)
		{
			rx = vx;
			ry = vy;
		}
		else
		{
			rx = hx;
			ry = hy;
		}
		ft_bresenhams_alg(win, rx, ry, 0x0000ff);
	}
}





int	draw(t_mlx *win)
{
	render_background(&win->img, 0xD3D3D3);
	ft_draw_map(win->map, &win->img, win);
	ft_update_player(win->player->player_x, win->player->player_y, &win->img, win);
	ft_vision_angle(win, win->player->player_x, win->player->player_y);
	raycaster(win);
	mlx_put_image_to_window(win->mlx_connect, win->mlx_win,
		win->img.mlx_img, 0, 0);
	return (0);
}

void	render(char **map)
{
	t_mlx	*win;


	win = malloc(sizeof(t_mlx));
	//printf("aqui\n\n\n\n\n");
	set_up_win(win, map);
	win->mlx_connect = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx_connect, WIDTH, HEIGHT, "Cub3D");
	win->img.mlx_img = mlx_new_image(win->mlx_connect, WIDTH, HEIGHT);
	win->img.addr = mlx_get_data_addr(win->img.mlx_img, &win->img.bpp,
			&win->img.line_len, &win->img.endian);
	mlx_loop_hook(win->mlx_connect, &draw, win);
	mlx_key_hook(win->mlx_win, arrow_keys, win);
	mlx_hook(win->mlx_win, KeyPress, KeyPressMask, ft_event_checker, win);
	mlx_hook(win->mlx_win, 17, 0, ft_close, win);
	mlx_loop(win->mlx_connect);
}

int	main(void)
{
	char	*data[] =
	{
	"111111111111111111",
	"100000N00011000001",
	"111100111111110111",
	"111100011111110111",
	"110000001101010111",
	"100000000000000011",
	"100000000000000011",
	"110000011101010111",
	"111101111111010111",
	"111111111111111111"};

	//8:49

	render(data);
	return (0);
}
