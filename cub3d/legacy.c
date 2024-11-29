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

/* isto e para depis fazer o minimap
void    raycaster(t_mlx *win)
{
	int r;
	float hx, hy, vx, vy, ray_h, ray_v, line;
	float ra;
	int wall_color;

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
*/


/* before norminete

void	draw_3d_walls(t_mlx *win, float distance, int column, float hx)
{
	int	line_h;
	int	line_start;
	int	y;
	//int	color;
	t_tex texture_to_use;
	
	//-----texture----
	float ty;
	float tx;
	float ty_step;
	float ty_offset;
	//---------------

	line_h = (SQUARE_SIZE * HEIGHT) / distance;
	ty_step = 64 / (float)line_h;
	ty_offset = 0;
	if (line_h > HEIGHT)
	{
		ty_offset = ((float)line_h - HEIGHT) / 2;
		line_h = HEIGHT;
	}
	//ft_wall_limits(&line_h, &ty_offset);
	line_start = (HEIGHT / 2) - (line_h / 2);
	y = -1;
	ty = ty_step * ty_offset;
	tx = (int)(hx) % 64;
	ft_texture_setter(win, &texture_to_use, &tx);
	while (++y < line_h)
	{
		//color = get_pixel_color(&texture_to_use, ((int)tx) % SQUARE_SIZE, (int)(ty));
		my_pixel_put(&win->img, column, line_start + y, get_pixel_color(&texture_to_use, ((int)tx) % SQUARE_SIZE, (int)(ty)));
		ty += ty_step;
	}
}
*/
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

/*before norm
void    raycaster(t_mlx *win)
{
	int		r;
	float	hx, hy, vx, vy, ray_h, ray_v, line;
	float	ra;
	float	wall_x;

	r = -1;
	ra = win->player->player_angle - (FOV / 2);
	ft_circle_normalizer(&ra);
	while (++r < WIDTH)
	{
		ft_horizontal_intersection(win, ra, &hx, &hy);
		ft_vertical_intersection(win, ra, &vx, &vy);
		ray_h = line_length(win->player->player_x, win->player->player_y, hx, hy);
		ray_v = line_length(win->player->player_x, win->player->player_y, vx, vy);
		if (ray_h < ray_v)
		{
			if (hy > win->player->player_y) // South wall 
				win->texture_nbr = 0;
			else // North wall
				win->texture_nbr = 1;
			wall_x = hx;
			line = ray_h;
		}
		else
		{
			if (vx > win->player->player_x) // East wall 
				win->texture_nbr = 2;
			else // West wall 
				win->texture_nbr = 3;
			line = ray_v;
			wall_x = vy;
		}
		line = line * cos(win->player->player_angle - ra);
		draw_3d_walls(win, line, r, wall_x);
		ra += DR;
		ft_circle_normalizer(&ra);
	}
}
*/