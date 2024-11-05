/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:56:01 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/05 16:31:14 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_up_win(t_mlx *win)
{
	win->mlx_connect = 0;
	win->mlx_win = 0;
	win->map = 0;
	win->posx = 0;
	win->posy = 0;
}

void	ft_draw_player(int px, int py, t_img *img, t_mlx *win)
{
	int	y;
	int	x;
	int	size;

	px += win->posx;
	py += win->posy;
	size = 25;
	y = 0;
	while (y < size && y + py < HEIGHT)
	{
		x = 0;
		while (x < size && x + px < WIDTH)
		{
			my_pixel_put(img, x + px, y + py, 0xFFFF00);
			x++;
		}
		++y;
	}
}
void	ft_draw_map(void)
{
	
}

int	draw(t_mlx *win)
{
	render_background(&win->img, 0x905af0);
	ft_draw_map();
	ft_draw_player(400, 150, &win->img, win);
	mlx_put_image_to_window(win->mlx_connect, win->mlx_win,
		win->img.mlx_img, 0, 0);
	return (0);
}

void	ft_read_map(int map)
{
	char	*line;

	line = get_next_line(map);
	while (line != NULL)
	{
		ft_printf(line);
		free(line);
		line = get_next_line(map);
	}
}



void	render(int map)
{
	t_mlx	*win;

	//ft_read_map(map);
	(void)map;
	win = malloc(sizeof(t_mlx));
	set_up_win(win);
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
	int	map;

	map = open("map.txt", O_RDONLY);
	render(map);
	close(map);
	return (0);
}
