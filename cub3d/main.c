/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:56:01 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/18 16:33:59 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mod(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void	ft_bresenhams_alg(t_mlx *win, float px, float py)
{
	float	x_step;
	float	y_step;
	int		max;
	int		end_x;
    int		end_y;

	end_x = px + 5 * win->player_delta_x;
	end_y = py + 5 * win->player_delta_y;
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

void	set_up_win(t_mlx *win, char **map)
{
	int	y;

	y = 0;
	win->mlx_connect = 0;
	win->mlx_win = 0;
	win->map = 0;
	win->posx = 0;
	win->posy = 0;
	win->map = malloc(sizeof(t_map));
	win->map->height = 14;
	win->map->width = 33;
	win->player_angle = 0;
	win->player_delta_x = cos(win->player_angle) * 5;
	win->player_delta_y = sin(win->player_angle) * 5;
	win->map->coord = ft_calloc(14, sizeof(char *));
	while (y < win->map->height)
	{
		win->map->coord[y] = ft_strdup(map[y]);
		y++;
	}
}

void	draw_square(t_img *img, int x, int y, int color)
{
	int	start_x;
	int	start_y;
	int	i;
	int	j;

	start_x = x * SQUARE_SIZE;
	start_y = y * SQUARE_SIZE;
	i = 0;
	while (i < SQUARE_SIZE)
	{
		j = 0;
		while (j < SQUARE_SIZE)
		{
			if (i > 0 && j > 0)
				my_pixel_put(img, start_x + j, start_y + i, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_map(t_map *map, t_img *img, t_mlx *win)
{
	int	y;
	int	x;
	static int v;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width && map->coord[y][x] != '\0')
		{
			if (map->coord[y][x] == '1')
				draw_square(img, x, y, 0x000000);
			else if (map->coord[y][x] == '0')
				draw_square(img, x, y, 0xFFFFFF);
			else if (map->coord[y][x] == 'N')
			{
				draw_square(img, x, y, 0xFFFFFF);
				if (v == 0)
				{
					win->player_x = x * SQUARE_SIZE;
					win->player_y = y * SQUARE_SIZE;
					v++;
				}
			}
			x++;
		}
		y++;
	}
}

void	ft_update_player(int px, int py, t_img *img, t_mlx *win)
{
	float	y;
	float	x;
	int		size;

	(void)win;
	size = PLAYER_SIZE;
	y = 0;
	while (y < size && y + py < HEIGHT)
	{
		x = 0;
		while (x < size && x + px < WIDTH)
		{
			if (x > 0 && y > 0)
				my_pixel_put(img, x + px, y + py, 0x0000F0);
			x++;
		}
		y++;
	}
}


int	draw(t_mlx *win)
{
	render_background(&win->img, 0xD3D3D3);
	ft_draw_map(win->map, &win->img, win);
	ft_update_player(win->player_x, win->player_y, &win->img, win);
	ft_bresenhams_alg(win, win->player_x + (PLAYER_SIZE/2), win->player_y + (PLAYER_SIZE/2));
	mlx_put_image_to_window(win->mlx_connect, win->mlx_win,
		win->img.mlx_img, 0, 0);
	return (0);
}

void	render(char **map)
{
	t_mlx	*win;

	(void)map;
	win = malloc(sizeof(t_mlx));
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
	"        1111111111111111111111111",
	"        1000000000110000000000001",
	"        1011000001110000000000001",
	"        1001000000000000000000001",
	"111111111011000001110000000000001",
	"100000000011000001110111101111111",
	"11110111111111011100000010001",
	"11110111111111011101010010001",
	"11000000110101011100000010001",
	"10000000000000001100000010001",
	"10000000000000001101010010001",
	"11000001110101011101011010N0111",
	"11110111 1110101 101111010001",
	"11111111 1111111 111111111111"};

	render(data);
	return (0);
}
