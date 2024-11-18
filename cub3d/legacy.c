void	ft_draw_player(int px, int py, t_img *img, t_mlx *win)
{
	int	y;
	int	x;
	int	size;

	px += win->posx;
	py += win->posy;
	win->player_x = px;
	win->player_y = py;
	size = PLAYER_SIZE;
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

void	ft_update_player(int px, int py, t_img *img, t_mlx *win)
{
	int	y;
	int	x;
	int	size;

	px += win->posx;
	py += win->posy;
	win->player_x = px;
	win->player_y = py;
	size = PLAYER_SIZE;
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

/*
void	ft_bresenhams_alg(t_mlx *win, t_point p1, t_point p2)
{
	float	x_step;
	float	y_step;
	int		max;


	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;


	max = fmax(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;

	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		my_pixel_put(&win->img, p1.x, p1.y, 0xffff00);
		p1.x += x_step;
		p1.y += y_step;
	}
}
*/