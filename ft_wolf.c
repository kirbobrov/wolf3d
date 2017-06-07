
#include "wolf.h"

int	ft_wolf(t_wolf *w)
{
	int hit;
	ft_imageinit(w);
	///ft_start_position(w);
	int x;

	x = -1;
	while (++x < SIZE_X)
	{
		//printf("ft_wolf\n");
		w->pl.camerax = 2 * x  / (double)(SIZE_X) - 1;
		w->pl.rayposx = w->pl.posx;
		w->pl.rayposy = w->pl.posy;

		w->pl.raydirx = w->pl.dirx + w->pl.planex * w->pl.camerax;
		w->pl.raydiry = w->pl.diry + w->pl.planey * w->pl.camerax;

		w->pl.mapx = (int)w->pl.rayposx;
		w->pl.mapy = (int)w->pl.rayposy;

		w->pl.deltadistx = sqrt(1 + (w->pl.raydiry * w->pl.raydiry) / (w->pl.raydirx * w->pl.raydirx));
		w->pl.deltadisty = sqrt(1 + (w->pl.raydirx * w->pl.raydirx) / (w->pl.raydiry * w->pl.raydiry));

		hit = 0;

		if (w->pl.raydirx < 0)
		{
			w->pl.stepx = -1;
			w->pl.sidedistx = (w->pl.rayposx - w->pl.mapx) * w->pl.deltadistx;
		}
		else
		{
			w->pl.stepx = 1;
			w->pl.sidedistx = (w->pl.mapx + 1.0 - w->pl.rayposx) * w->pl.deltadistx;
		}
		if (w->pl.raydiry < 0)
		{
			w->pl.stepy = -1;
			w->pl.sidedisty = (w->pl.rayposy - w->pl.mapy) * w->pl.deltadisty;
		}
		else
		{
			w->pl.stepy = 1;
			w->pl.sidedisty = (w->pl.mapy + 1.0 - w->pl.rayposy) * w->pl.deltadisty;
		}

		while (hit == 0)
		{
			if (w->pl.sidedistx < w->pl.sidedisty)
			{
				w->pl.sidedistx += w->pl.deltadistx;
				w->pl.mapx += w->pl.stepx;
				w->pl.side = (w->pl.sidedistx >= 0) ? 1 : 2;
			///	printf("side xxxxxxx == %d\n", w->pl.side);
			}
			else
			{
				w->pl.sidedisty += w->pl.deltadisty;
				w->pl.mapy += w->pl.stepy;
				w->pl.side = (w->pl.sidedisty >= 0) ? 3 : 4;
			///	printf("side == %d\n", w->pl.side);
			}
			if (w->pl.map[w->pl.mapx][w->pl.mapy] > 0)
				hit = 1;
		}

		if (w->pl.side == 1 || w->pl.side == 2)
			w->pl.perpwalldist = (w->pl.mapx - w->pl.rayposx + (1 - w->pl.stepx) / 2) / w->pl.raydirx;
		else
			w->pl.perpwalldist = (w->pl.mapy - w->pl.rayposy + (1 - w->pl.stepy) / 2) / w->pl.raydiry;

		w->pl.lineheight = (int)(SIZE_Y / w->pl.perpwalldist);
		w->pl.drawstart = SIZE_Y / 2 - (w->pl.lineheight / 2);

		if (w->pl.drawstart < 0)
			w->pl.drawstart = 0;
		w->pl.drawend = w->pl.lineheight / 2 + SIZE_Y / 2;
		if (w->pl.drawend >= SIZE_Y)
			w->pl.drawend = SIZE_Y - 1;

//		if (w->pl.side == 1)
//			w->cl.color =  w->cl.color % 2;
		color_floor_celing(w, x);
		ft_draw(w, x, w->pl.drawstart, x, w->pl.drawend);

		w->pl.oldtime = w->pl.time;
		w->pl.time = clock();
		w->pl.frametime = (w->pl.time - w->pl.oldtime) / 1000.0;

		w->pl.movespeed = (w->pl.frametime * 5.0) * w->pl.sm;
		w->pl.rotspeed = (w->pl.frametime * 3.0) * w->pl.sm;

		//printf("frametime == %f\n", 1 / w->pl.frametime);
		//x++;
		///ft_draw_text(w, x);
	}
	ft_imageput(w);
//	printf("w->pl.mapx == %d\tw->pl.mapy == %d\n", w->pl.mapx, w->pl.mapy);
//	printf("w-.pl.map[x][y] === %d\n", w->pl.map[w->pl.mapx][w->pl.mapx]);

	return (0);
}
