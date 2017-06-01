/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 18:50:26 by kbobrov           #+#    #+#             */
/*   Updated: 2017/05/21 18:50:29 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void 	ft_move(t_move *move, t_wolf *w, int keycode)
{

//	int posx;
//	int posy;
	if (SDLK_UP)
	{
		if(w->pl.map[int((w->pl.posx + w->pl.dirx) * w->pl.movespeed)][w->pl.posy] == 0)
			w->pl.posx += w->pl.dirx * w->pl.movespeed;
		if(w->pl.map[w->pl.posx][w->pl.posy + w->pl.diry * w->pl.movespeed] == 0)
			w->pl.posy += w->pl.diry * w->pl.movespeed;
	}
//move backwards if no wall behind you
	if (SDLK_DOWN)
	{
		if(w->pl.map[w->pl.posx - w->pl.dirx * w->pl.movespeed][w->pl.posy] == 0)
			w->pl.posx -= w->pl.dirx * w->pl.movespeed;
		if(w->pl.map[w->pl.posx][w->pl.posy - w->pl.diry * w->pl.movespeed] == 0)
			w->pl.posy -= w->pl.diry * w->pl.movespeed;
	}
//rotate to the right
	 if (SDLK_RIGHT)
	{
//both camera direction and camera plane must be rotated
///double oldDirX = dirx;

	w->pl.olddirx = w->pl.dirx;
	w->pl.dirx = w->pl.dirx * cos(-w->pl.rotspeed) - w->pl.diry * sin(-w->pl.rotspeed);
	w->pl.diry = w->pl.olddirx * sin(-w->pl.rotspeed) + w->pl.dirx * cos(-w->pl.rotspeed);
///double oldPlaneX = planeX;
	w->pl.oldplanex = w->pl.planex;
	w->pl.planex = w->pl.planex * cos(-w->pl.rotspeed) - w->pl.planey * sin(-w->pl.rotspeed);
	w->pl.planey = w->pl.oldplanex * sin(-w->pl.rotspeed) + w->pl.planey * cos(-w->pl.rotspeed);
	}
//rotate to the left
	if (SDLK_LEFT)
	{
//both camera direction and camera plane must be rotated
	w->pl.olddirx = w->pl.dirx;
	w->pl.dirx = w->pl.dirx * cos(w->pl.rotspeed) - w->pl.diry * sin(w->pl.rotspeed);
	w->pl.diry = w->pl.olddirx * sin(w->pl.rotspeed) + w->pl.diry * cos(w->pl.rotspeed);
	w->pl.oldplanex = w->pl.planex;
	w->pl.planex = w->pl.planex * cos(w->pl.rotspeed) - w->pl.planey * sin(w->pl.rotspeed);
	w->pl.planey = w->pl.oldplanex * sin(w->pl.rotspeed) + w->pl.planey * cos(w->pl.rotspeed);
	}
}

int		my_key(int keycode, t_wolf *w)
{
	(keycode == 53) ? exit(53) : 0;
	(keycode == 123 || keycode == 124 ||
	 keycode == 125 || keycode == 126) ? ft_move(&w->move, w, keycode) : 0;
	printf("%d\n", keycode);
	return (0);
}