
#include "wolf.h"

int	ft_wolf(t_wolf *w)
{
	ft_imageinit(w);
	int x;

	x = 0;
	while (x < SIZE_X)
	{
		w->pl.camerax = 2 * x  / (double)(SIZE_X) - 1;
		w->pl.rayposx = w->pl.posx;
		w->pl.rayposy = w->pl.posy;

		w->pl.raydirx = w->pl.dirx + w->pl.planex * w->pl.camerax;
		w->pl.raydiry = w->pl.diry + w->pl.planey * w->pl.camerax;

		w->pl.mapx = (int)w->pl.rayposx;
		w->pl.mapy = (int)w->pl.raydiry;

		w->pl.deltadistx = sqrt(1 + (w->pl.raydiry * w->pl.raydiry) / (w->pl.raydirx * w->pl.raydirx));
		w->pl.deltadisty = sqrt(1 + (w->pl.raydirx * w->pl.raydirx) / (w->pl.raydiry * w->pl.raydiry));

		w->pl.hit = 0;

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

		while (!w->pl.hit)
		{
			if (w->pl.sidedistx < w->pl.sidedisty)
			{
				w->pl.sidedistx += w->pl.deltadistx;
				w->pl.mapx += w->pl.stepx;
				w->pl.side = 0;
			}
			else
			{
				w->pl.sidedisty += w->pl.deltadisty;
				w->pl.mapy += w->pl.stepy;
				w->pl.side = 1;
			}
			if (w->pl.map[w->pl.mapx][w->pl.mapy] > 0)
				w->pl.hit = 1;
		}

		if (w->pl.side == 0)
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

		ft_draw(w, x, w->pl.drawstart, x, w->pl.drawend);

		w->pl.oldtime = w->pl.time;
		w->pl.time = clock();
		w->pl.frametime = (w->pl.time - w->pl.oldtime) / 1000.0;

		w->pl.movespeed = w->pl.frametime * 5.0;
		w->pl.rotspeed = w->pl.frametime * 3.0;

		printf("%f\n", 1 / w->pl.frametime);
		x++;
	}
	ft_imageput(w);
	return (0);
}
