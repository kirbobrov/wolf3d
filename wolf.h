/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 17:09:09 by kbobrov           #+#    #+#             */
/*   Updated: 2017/05/20 17:09:14 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"
# define SIZE_Y 576
# define SIZE_X 768

typedef struct	s_move
{
	int		forward;
	int 	back;
	int 	left;
	int 	right;
	int 	turn;
	float	v;
	float	t_speed;
	float	speed_up;
	float	speed_down;
}				t_move;

typedef struct	s_color
{
	int	col1;
	int	col2;
	int	col3;
	int	col4;
	int	coldef;
}				t_color;

typedef struct	s_player
{
	int 	**map;
	double posx;
	double posy;
	double dirx;
	double diry;
	double planex;
	double planey;
	double time;
	double oldtime;
	double rayposx;
	double rayposy;
	double raydirx;
	double raydiry;
	int mapx;
	int mapy;
	double sidedistx;
	double sidedisty;
	double deltadistx;
	double deltadisty;
	double perpwalldist;
	int stepx;
	int stepy;
	double movespeed;
	double olddirx;
	double oldplanex;
	double rotspeed;
//	int posx;
//	int posy;

}				t_player;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		bpp;
	int		endl;
	int		sizel;
}				t_mlx;

typedef struct	s_wolf
{
	t_mlx		mx;
	t_player	pl;
	t_color		cl;
	t_move		move;
}				t_wolf;

int			my_key(int keycode, t_wolf *w)

#endif