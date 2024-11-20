/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:56:01 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/20 21:37:57 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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


void	ft_bresenhams_alg(t_mlx *win, float end_x, float end_y)
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
		my_pixel_put(&win->img, px, py, 0x0000ff);
		px += x_step;
		py += y_step;
	}
}
/*
void	raycaster(t_mlx *win)
{
	int	r = 0, mx, my, mp, dof;
	float rx, ry, ra, xo, yo;
	float aTan;

	ra = win->player->player_angle;
	while (r++ < 1)
	{
		dof = 0;
		aTan = -1 / tan(ra);
		if (ra > PI)
		{
			ry = (((int)win->player->player_y / SQUARE_SIZE) * SQUARE_SIZE) - 0.0001;
			rx = (win->player->player_y - ry) * aTan + win->player->player_x;
			yo = -SQUARE_SIZE;
			xo = -yo * aTan;
		}
		if (ra < PI)
		{
			ry = (((int)win->player->player_y / SQUARE_SIZE) * SQUARE_SIZE) + SQUARE_SIZE;
			rx = (win->player->player_y - ry) * aTan + win->player->player_x;
			yo = SQUARE_SIZE;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = win->player->player_x;
			ry = win->player->player_y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)rx / SQUARE_SIZE;
			my = (int)ry / SQUARE_SIZE;
			mp = my * win->map->width + mx;
			printf("mp: %i\n", mp);
			if (mx < 0 || mx >= win->map->width || my < 0 || my >= win->map->height)
				break ;
			if (mp < win->map->width * win->map->height && win->map->coord[my][mx] == '1')
				dof = 8;
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		if (rx >= 0 && rx < win->map->width * SQUARE_SIZE && ry >= 0 && ry < win->map->height * SQUARE_SIZE)
			ft_bresenhams_alg(win, rx, ry);

	}
}*/

void raycaster(t_mlx *win)
{
    int r = 0, mx, my, mp, dof;
    float rx, ry, ra, xo, yo;
    float aTan;

    ra = win->player->player_angle;
    while (r++ < 1)
    {
        dof = 0;
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
            dof = 8;
        }
        while (dof < 8)
        {
            mx = (int)rx / SQUARE_SIZE;
            my = (int)ry / SQUARE_SIZE;
            mp = my * win->map->width + mx;
			(void)mp;
            // Check if the ray is out of bounds
            if (mx < 0 || mx >= win->map->width || my < 0 || my >= win->map->height)
				break ;

            // Check if the ray hits a wall
            if (mx < win->map->width && my < win->map->height && win->map->coord[my][mx] == '1')
				dof = 8;
            else
            {
                rx += xo;
                ry += yo;
                dof++;
            }
        }
        // Ensure rx and ry are within map boundaries before calling ft_bresenhams_alg
        if (rx < 0)
			rx = 0;
        if (rx >= win->map->width * SQUARE_SIZE)
			rx = win->map->width * SQUARE_SIZE - 1;
        if (ry < 0)
			ry = 0;
        if (ry >= win->map->height * SQUARE_SIZE)
			ry = win->map->height * SQUARE_SIZE - 1;
        ft_bresenhams_alg(win, rx, ry);
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
