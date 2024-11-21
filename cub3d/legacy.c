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

/* this is done and works

void	raycaster_old(t_mlx *win)
{
	int		r = 0;
	int		mx = 0;
	int		my = 0;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	aTan;
	float	nTan;

	ra = win->player->player_angle;
	while (r++ < 1)
	{
		// --- Vertical
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
			dof = 20;
		}
		while (dof < 20)
		{
			mx = (int)(rx / SQUARE_SIZE);
			my = (int)(ry / SQUARE_SIZE);

			// Check if the ray is out of bounds
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
		// Ensure rx and ry are within map boundaries (clamping rx and ry)
		// if axys > max, becomes max value || if if axys < 0 , becomes 0 value
		// Looses precision on some points but no segfaults :D
		rx = fmax(0, fmin(rx, win->map->width * SQUARE_SIZE - 1));
		ry = fmax(0, fmin(ry, win->map->height * SQUARE_SIZE - 1));

		int hx = rx, hy = ry;

		// --- Vertical
		dof = 0;
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

			// Check if the ray is out of bounds
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
		// Ensure rx and ry are within map boundaries (clamping rx and ry)
		// if axys > max, becomes max value || if if axys < 0 , becomes 0 value
		// Looses precision on some points but no segfaults :D
		rx = fmax(0, fmin(rx, win->map->width * SQUARE_SIZE - 1));
		ry = fmax(0, fmin(ry, win->map->height * SQUARE_SIZE - 1));

		int vx = rx, vy = ry;

		int line_h = line_length(win->player->player_x, win->player->player_y, hx, hy);

		int line_v = line_length(win->player->player_x, win->player->player_y, vx, vy);

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

*/