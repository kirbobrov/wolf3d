/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 17:08:43 by kbobrov           #+#    #+#             */
/*   Updated: 2017/05/20 17:08:47 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"



static void	ft_init(t_wolf *w)
{
	w->mx.mlx = mlx_init();
	w->mx.win = mlx_new_window(w->mx.mlx, SIZE_X, SIZE_Y, "wolf3d by kbobrov");
	w->pl.posx = 22;
	w->pl.posy = 12;  //x and y start position
	w->pl.dirx = -1;
	w->pl.diry = 0; //initial direction vector
	w->pl.planex = 0;
	w->pl.planey = 0.66; //the 2d raycaster version of camera plane
	w->pl.time = 0; //time of current frame
	w->pl.oldtime = 0; //time of previous frame
}

void	ft_imageinit(t_wolf *w)
{
	w->mx.img = mlx_new_image(w->mx.mlx, SIZE_X, SIZE_Y);
	w->mx.bpp = 0;
	w->mx.endl = 0;
	w->mx.sizel = 0;
	w->mx.buf = mlx_get_data_addr(w->mx.img, &w->mx.bpp, &w->mx.sizel, &w->mx.endl);
}

void	ft_imageput(t_wolf *w)
{
	mlx_put_image_to_window(w->mx.mlx, w->mx.win, w->mx.img, 0, 0);
	mlx_destroy_image(w->mx.mlx, w->mx.img);
}

int			main(void)
{
	t_wolf w;
//	double posx;
//	double posy;
//	double dirx;
//	double diry;
//	double planex;
//	double planey;
//	double time;
//	double oldtime;
	int			worldmap[24][24] = {
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
			{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
			{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	w.pl.map = (int **) worldmap;
	int 	x;
	double camerax;
	x = -1;
	ft_init(&w);
	ft_imageinit(&w);
//	posx = 22;
//	posy = 12;  //x and y start position
//	dirx = -1;
//	diry = 0; //initial direction vector
//	planex = 0;
//	planey = 0.66; //the 2d raycaster version of camera plane
//	time = 0; //time of current frame
//	oldtime = 0; //time of previous frame

///	screen(512, 384, 0, "Raycaster");
	while()
	{
		x = -1;
		while(++x < SIZE_X)
		{
			//calculate ray position and direction
			camerax = 2 * x / SIZE_Y - 1; //x-coordinate in camera space
			w.pl.rayposx = w.pl.posx;
			w.pl.rayposy = w.pl.posy;
			w.pl.raydirx = w.pl.dirx + w.pl.planex * camerax;
			w.pl.raydiry = w.pl.diry + w.pl.planey * camerax;
			//which box of the map we're in
			w.pl.mapx = w.pl.rayposx;
			w.pl.mapy = w.pl.rayposy;

			//length of ray from current position to next x or y-side
//			double sidedistx;
//			double sidedisty;

			//length of ray from one x or y-side to next x or y-side
			w.pl.deltadistx = sqrt(1 + (w.pl.raydiry * w.pl.raydiry) / (w.pl.raydirx * w.pl.raydirx));
			w.pl.deltadisty = sqrt(1 + (w.pl.raydirx * w.pl.raydirx) / (w.pl.raydiry * w.pl.raydiry));
			w.pl.perpwalldist;

			//what direction to step in x or y-direction (either +1 or -1)
//			int stepx;
//			int stepy;

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?
			//calculate step and initial sideDist
			if (w.pl.raydirx < 0)
			{
				w.pl.stepx = -1;
				w.pl.sidedistx = (w.pl.rayposx - w.pl.mapx) * w.pl.deltadistx;
			}
			else
			{
				w.pl.stepx = 1;
				w.pl.sidedistx = (w.pl.mapx + 1.0 - w.pl.rayposx) * w.pl.deltadistx;
			}
			if (w.pl.raydiry < 0)
			{
				w.pl.stepy = -1;
				w.pl.sidedisty = (w.pl.rayposy - w.pl.mapy) * w.pl.deltadisty;
			}
			else
			{
				w.pl.stepy = 1;
				w.pl.sidedisty = (w.pl.mapy + 1.0 - w.pl.rayposy) * w.pl.deltadisty;
			}
			//perform DDA
			while (hit == 0)
			{
				//jump to next map square, OR in x-direction, OR in y-direction
				if (w.pl.sidedistx < w.pl.sidedisty)
				{
					w.pl.sidedistx += w.pl.deltadistx;
					w.pl.mapx += w.pl.stepx;
					side = 0;
				}
				else
				{
					w.pl.sidedisty += w.pl.deltadisty;
					w.pl.mapy += w.pl.stepy;
					side = 1;
				}
				//Check if ray has hit a wall
				if (worldmap[w.pl.mapx][w.pl.mapy] > 0) hit = 1;
			}
			//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
			if (side == 0)
				w.pl.perpwalldist = (w.pl.mapx - w.pl.rayposx + (1 - w.pl.stepx) / 2) / w.pl.raydirx;
			else
				w.pl.perpwalldist = (w.pl.mapy - w.pl.rayposy + (1 - w.pl.stepy) / 2) / w.pl.raydiry;

			//Calculate height of line to draw on screen
			int lineheight = (int)(SIZE_Y / w.pl.perpwalldist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawstart = -lineheight / 2 + SIZE_Y / 2;
			if(drawstart < 0)drawstart = 0;
			int drawend = lineheight / 2 + SIZE_Y / 2;
			if(drawend >= SIZE_Y)drawend = SIZE_Y - 1;

			//choose wall color
			switch(worldmap[w.pl.mapx][w.pl.mapy])
			{
				w.cl->col1 = RGB_Red;  break; //red
				w.cl->col1 = RGB_Green;  break; //green
				w.cl->col1 = RGB_Blue;   break; //blue
				w.cl->col1 = RGB_White;  break; //white
				w.cl->coldef = RGB_Yellow; break; //yellow
			}

			//give x and y sides different brightness
			if (side == 1) {w.cl->coldef = w.cl->coldef / 2;}

			//draw the pixels of the stripe as a vertical line
			verline(x, drawstart, drawend, color); //// write function that draw vertical lines
		}
		//timing for input and FPS counter
		w.pl.oldtime = w.pl.time;
		w.pl.time = 24;
		double frametime = (w.pl.time - w.pl.oldtime) / 1000.0; //frameTime is the time this frame has taken, in seconds
		printf("%d\n", (1.0 / frametime)); //FPS counter
	///	redraw();
	/// cls();

		//speed modifiers
		w.pl.movespeed = frametime * 5.0; //the constant value is in squares/second
		w.pl.rotspeed = frametime * 3.0; //the constant value is in radians/second


		///// keys function
		//move forward if no wall in front of you
///*		if (keyDown(SDLK_UP))
//		{
//			if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
//			if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
//		}
//		//move backwards if no wall behind you
//		if (keyDown(SDLK_DOWN))
//		{
//			if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
//			if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
//		}
//		//rotate to the right
//		if (keyDown(SDLK_RIGHT))
//		{
//			//both camera direction and camera plane must be rotated
//			double oldDirX = dirX;
//			dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
//			dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
//			double oldPlaneX = planeX;
//			planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
//			planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
//		}
//		//rotate to the left
//		if (keyDown(SDLK_LEFT))
//		{
//			//both camera direction and camera plane must be rotated
//			double oldDirX = dirX;
//			dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
//			dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
//			double oldPlaneX = planeX;
//			planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
//			planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
///		}   */
	}
	///mlx_hook(w->win, 17, 0L, ft_mouse_exit, w);
	///mlx_hook(w->win, 4, 0, ft_mouse_zoom, w);
	mlx_hook(w.mx.win, 2, 5, my_key, &w);
	mlx_loop(w.mx.mlx);
}