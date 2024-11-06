/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:56:01 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/06 16:57:28 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	win->player_x = 1315;
	win->player_y = 565;
	win->map->coord = ft_calloc(14, sizeof(char *));
	while (y < win->map->height)
	{
		win->map->coord[y] = ft_strdup(map[y]);
		y++;
	}
}

void	ft_draw_player(int px, int py, t_img *img, t_mlx *win)
{
	int	y;
	int	x;
	int	size;

	px += win->posx;
	py += win->posy;
	win->player_x = px;
	win->player_y = py;
	size = 20;
	y = 0;
	while (y < size && y + py < HEIGHT)
	{
		x = 0;
		while (x < size && x + px < WIDTH)
		{
			my_pixel_put(img, x + px, y + py, 0x0000FF);
			x++;
		}
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
			my_pixel_put(img, start_x + j, start_y + i, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_map(t_map *map, t_img *img)
{
	int	y;
	int	x;

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
				draw_square(img, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

int	draw(t_mlx *win)
{
	render_background(&win->img, 0x905af0);
	ft_draw_map(win->map, &win->img);
	ft_draw_player(1315, 565, &win->img, win);
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
	//draw(win);
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
