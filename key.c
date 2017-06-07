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

void	move_forward(t_wolf *w)
{
	if (!w->pl.map[(int)(w->pl.posx + w->pl.dirx * w->pl.movespeed)][(int)(w->pl.posy)])
		w->pl.posx += w->pl.dirx * w->pl.movespeed;
	if (!w->pl.map[(int)(w->pl.posx)][(int)(w->pl.posy + w->pl.diry * w->pl.movespeed)])
		w->pl.posy += w->pl.diry * w->pl.movespeed;
}

void	move_back(t_wolf *w)
{
	if (!w->pl.map[(int)(w->pl.posx - w->pl.dirx * w->pl.movespeed)][(int)(w->pl.posy)])
		w->pl.posx -= w->pl.dirx * w->pl.movespeed;
	if (!w->pl.map[(int)(w->pl.posx)][(int)(w->pl.posy - w->pl.diry * w->pl.movespeed)])
		w->pl.posy -= w->pl.diry * w->pl.movespeed;
}

void	turn_left(t_wolf *w)
{
	w->pl.olddirx = w->pl.dirx;
	w->pl.dirx = w->pl.dirx * cos(0.05) - w->pl.diry * sin(0.05);
	w->pl.diry = w->pl.olddirx * sin(0.05) + w->pl.diry * cos(0.05);
	w->pl.oldplanex = w->pl.planex;
	w->pl.planex = w->pl.planex * cos(0.05) - w->pl.planey * sin(0.05);
	w->pl.planey = w->pl.oldplanex * sin(0.05) + w->pl.planey * cos(0.05);
}

void	turn_right(t_wolf *w)
{
	w->pl.olddirx = w->pl.dirx;
	w->pl.dirx = w->pl.dirx * cos(-0.05) - w->pl.diry * sin(-0.05);
	w->pl.diry = w->pl.olddirx * sin(-0.05) + w->pl.diry * cos(-0.05);
	w->pl.oldplanex = w->pl.planex;
	w->pl.planex = w->pl.planex * cos(-0.05) - w->pl.planey * sin(-0.05);
	w->pl.planey = w->pl.oldplanex * sin(-0.05) + w->pl.planey * cos(-0.05);
}

int		my_key(int keycode, t_wolf *w)
{
	(keycode == 53) ? exit(53) : 0;
	(keycode == 123) ? turn_left(w) : 0;
	(keycode == 124) ? turn_right(w) : 0;
	(keycode == 125) ? move_back(w) : 0;
	(keycode == 126) ? move_forward(w) : 0;
	if (keycode == 69)
		w->pl.sm += 0.2;
	if (keycode == 78)
		w->pl.sm -= 0.2;
	printf("keycode == %d\n", keycode);
	return (0);
}

















/*
void	move_forward(t_player *pl, int **map)
{
	if (!map[(int)(pl->player_x + pl->dir_x * pl->speed)][(int)(pl->player_y)])
		pl->player_x += pl->dir_x * pl->speed;
	if (!map[(int)(pl->player_x)][(int)(pl->player_y + pl->dir_y * pl->speed)])
		pl->player_y += pl->dir_y * pl->speed;
}

void	move_back(t_player *pl, int **map)
{
	if (!map[(int)(pl->player_x - pl->dir_x * pl->speed)][(int)(pl->player_y)])
		pl->player_x -= pl->dir_x * pl->speed;
	if (!map[(int)(pl->player_x)][(int)(pl->player_y - pl->dir_y * pl->speed)])
		pl->player_y -= pl->dir_y * pl->speed;
}

void	turn_left(t_player *pl)
{
	pl->old_dir_x = pl->dir_x;
	pl->dir_x = pl->dir_x * cos(0.05) - pl->dir_y * sin(0.05);
	pl->dir_y = pl->old_dir_x * sin(0.05) + pl->dir_y * cos(0.05);
	pl->old_plane_x = pl->plane_x;
	pl->plane_x = pl->plane_x * cos(0.05) - pl->plane_y * sin(0.05);
	pl->plane_y = pl->old_plane_x * sin(0.05) + pl->plane_y * cos(0.05);
}

void	turn_right(t_player *pl)
{
	pl->old_dir_x = pl->dir_x;
	pl->dir_x = pl->dir_x * cos(-0.05) - pl->dir_y * sin(-0.05);
	pl->dir_y = pl->old_dir_x * sin(-0.05) + pl->dir_y * cos(-0.05);
	pl->old_plane_x = pl->plane_x;
	pl->plane_x = pl->plane_x * cos(-0.05) - pl->plane_y * sin(-0.05);
	pl->plane_y = pl->old_plane_x * sin(-0.05) + pl->plane_y * cos(-0.05);
}void	move_forward(t_player *pl, int **map)
{
	if (!map[(int)(pl->player_x + pl->dir_x * pl->speed)][(int)(pl->player_y)])
		pl->player_x += pl->dir_x * pl->speed;
	if (!map[(int)(pl->player_x)][(int)(pl->player_y + pl->dir_y * pl->speed)])
		pl->player_y += pl->dir_y * pl->speed;
}

void	move_back(t_player *pl, int **map)
{
	if (!map[(int)(pl->player_x - pl->dir_x * pl->speed)][(int)(pl->player_y)])
		pl->player_x -= pl->dir_x * pl->speed;
	if (!map[(int)(pl->player_x)][(int)(pl->player_y - pl->dir_y * pl->speed)])
		pl->player_y -= pl->dir_y * pl->speed;
}

void	turn_left(t_player *pl)
{
	pl->old_dir_x = pl->dir_x;
	pl->dir_x = pl->dir_x * cos(0.05) - pl->dir_y * sin(0.05);
	pl->dir_y = pl->old_dir_x * sin(0.05) + pl->dir_y * cos(0.05);
	pl->old_plane_x = pl->plane_x;
	pl->plane_x = pl->plane_x * cos(0.05) - pl->plane_y * sin(0.05);
	pl->plane_y = pl->old_plane_x * sin(0.05) + pl->plane_y * cos(0.05);
}

void	turn_right(t_player *pl)
{
	pl->old_dir_x = pl->dir_x;
	pl->dir_x = pl->dir_x * cos(-0.05) - pl->dir_y * sin(-0.05);
	pl->dir_y = pl->old_dir_x * sin(-0.05) + pl->dir_y * cos(-0.05);
	pl->old_plane_x = pl->plane_x;
	pl->plane_x = pl->plane_x * cos(-0.05) - pl->plane_y * sin(-0.05);
	pl->plane_y = pl->old_plane_x * sin(-0.05) + pl->plane_y * cos(-0.05);
}void	move_forward(t_player *pl, int **map)
{
	if (!map[(int)(pl->player_x + pl->dir_x * pl->speed)][(int)(pl->player_y)])
		pl->player_x += pl->dir_x * pl->speed;
	if (!map[(int)(pl->player_x)][(int)(pl->player_y + pl->dir_y * pl->speed)])
		pl->player_y += pl->dir_y * pl->speed;
}

void	move_back(t_player *pl, int **map)
{
	if (!map[(int)(pl->player_x - pl->dir_x * pl->speed)][(int)(pl->player_y)])
		pl->player_x -= pl->dir_x * pl->speed;
	if (!map[(int)(pl->player_x)][(int)(pl->player_y - pl->dir_y * pl->speed)])
		pl->player_y -= pl->dir_y * pl->speed;
}

void	turn_left(t_player *pl)
{
	pl->old_dir_x = pl->dir_x;
	pl->dir_x = pl->dir_x * cos(0.05) - pl->dir_y * sin(0.05);
	pl->dir_y = pl->old_dir_x * sin(0.05) + pl->dir_y * cos(0.05);
	pl->old_plane_x = pl->plane_x;
	pl->plane_x = pl->plane_x * cos(0.05) - pl->plane_y * sin(0.05);
	pl->plane_y = pl->old_plane_x * sin(0.05) + pl->plane_y * cos(0.05);
}

void	turn_right(t_player *pl)
{
	pl->old_dir_x = pl->dir_x;
	pl->dir_x = pl->dir_x * cos(-0.05) - pl->dir_y * sin(-0.05);
	pl->dir_y = pl->old_dir_x * sin(-0.05) + pl->dir_y * cos(-0.05);
	pl->old_plane_x = pl->plane_x;
	pl->plane_x = pl->plane_x * cos(-0.05) - pl->plane_y * sin(-0.05);
	pl->plane_y = pl->old_plane_x * sin(-0.05) + pl->plane_y * cos(-0.05);
}
 *//////