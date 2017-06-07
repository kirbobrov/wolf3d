
#include "wolf.h"

void	ft_draw_text(t_wolf *w, int x)
{
	int i;

	i = w->pl.map[w->pl.mapx][w->pl.mapy] - 1;
	if (w->pl.side == 0)
		w->pl.wall_x = w->pl.rayposy + w->pl.perpwalldist * w->pl.raydiry;
	else
		w->pl.wall_x = w->pl.rayposx + w->pl.perpwalldist * w->pl.raydirx;
	w->pl.wall_x -= floor((w->pl.wall_x));
	w->pl.text_x = (int)(w->pl.wall_x * (double)(w->p_x[i]));
	if (w->pl.side == 0 && w->pl.raydirx > 0)
		w->pl.text_x = w->p_x[i] - w->pl.text_x - 1;
	if (w->pl.side == 1 && w->pl.raydiry < 0)
		w->pl.text_x = w->p_x[i] - w->pl.text_x - 1;
	while (w->pl.drawstart != w->pl.drawend)
	{
		w->d = w->pl.drawstart * 256 - SIZE_Y * 128 + w->pl.wall_height * 128;
		w->pl.text_y = ((w->d * w->p_y[i]) / w->pl.wall_height) / 256;
		if (w->pl.wall_height * w->pl.text_y + w->pl.text_x < 0)
			return ;
		w->cl.color = w->pics[i][w->p_y[i] * w->pl.text_y + w->pl.text_x];
		if (w->pl.side == 1)
			w->cl.color = (w->cl.color >> 1) & 8355711;
		w->data[(int)(x + SIZE_X * w->pl.drawstart)] = w->cl.color;
		w->pl.drawstart++;
	}
}

/*void	ft_draw_text(t_wolf *w)
{
	mlx_string_put(w->mx.mlx, w->mx.win, 10, SIZE_Y - 70, 0x00FFFF00, "arrow to move");
	mlx_string_put(w->mx.mlx, w->mx.win, 10, SIZE_Y - 40, 0x00FFFF00, "ESC to exit");
}*/

void		img_put(t_wolf *w, int x, int y, int color)
{
	int		pix;
	ft_memcpy(w->mx.buf, w->mx.buf2, ft_strlen(w->mx.buf2));
	if (y >= 0 && x >= 0 && y < SIZE_Y && x < SIZE_X)
	{
		pix = y * w->mx.sizel + x * 4;
		if (pix < SIZE_X * SIZE_Y * 4)
		{
			w->mx.buf[pix] = get_blue(color);///w->cl.blue;
			w->mx.buf[pix + 1] = get_green(color);////w->cl.green;
			w->mx.buf[pix + 2] = get_red(color);///w->cl.red;
		}
	}
}

void	ft_wall_color(t_wolf *w)
{
	(w->pl.side == 1) ? w->cl.color = 0x00FF00 : 0;
	(w->pl.side == 2) ? w->cl.color = 0x0000FF : 0;
	(w->pl.side == 3) ? w->cl.color = 0xFF0000 : 0;
	(w->pl.side == 4) ? w->cl.color = 0xFF00FF : 0;
}

void ft_draw(t_wolf *w, int x1, int y1, int x2, int y2)
{
	ft_wall_color(w);
	w->pl.dx = abs(x2 - x1);
	w->pl.dy = abs(y2 - y1);
	w->pl.sx = x1 < x2 ? 1 : -1;;
	w->pl.sy = y1 < y2 ? 1 : -1;
	w->pl.error = w->pl.dx - w->pl.dy;

//	img_put(w, x1, y2, w->cl.color);
	while(y1 != y2)
	{

//		img_put(w, x2, y1, w->cl.color);
		w->pl.error2 = w->pl.error * 2;
		if(w->pl.error2 > -w->pl.dy)
		{
			w->pl.error -= w->pl.dy;
			x1 += w->pl.sx;
			img_put(w, x1, y2, w->cl.color);
		}

		if(w->pl.error2 < w->pl.dx)
		{
			w->pl.error += w->pl.dx;
			y1 += w->pl.sy;
			img_put(w, x2, y1, w->cl.color);
		}

	}
}

/*
void ft_draw(t_wolf *w, int x0, int y0, int x1, int y1)
{
	ft_wall_color(w);

	//Изменения координат
	int dx = (x1 > x0) ? (x1 - x0) : (x0 - x1);
	int dy = (y1 > y0) ? (y1 - y0) : (y0 - y1);
	//Направление приращения
	int sx = (x1 >= x0) ? (1) : (-1);
	int sy = (y1 >= y0) ? (1) : (-1);

	if (dy < dx)
	{
		int d = (dy << 1) - dx;
		int d1 = dy << 1;
		int d2 = (dy - dx) << 1;
		img_put(w, x0, y0, w->cl.color);
		int x = x0 + sx;
		int y = y0;
		for (int i = 1; i <= dx; i++)
		{
			if (d > 0)
			{
				d += d2;
				y += sy;
			}
			else
				d += d1;
			img_put(w, x, y, w->cl.color);
			x+=sx;
		}
	}
	else
	{
		int d = (dx << 1) - dy;
		int d1 = dx << 1;
		int d2 = (dx - dy) << 1;
		img_put(w, x0, y0, w->cl.color);
		int x = x0;
		int y = y0 + sy;
		for (int i = 1; i <= dy; i++)
		{
			if (d > 0)
			{
				d += d2;
				x += sx;
			}
			else
				d += d1;
			img_put(w, x, y, w->cl.color);
			y+=sy;
		}
	}
}*/