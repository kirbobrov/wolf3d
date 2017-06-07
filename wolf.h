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
# include <time.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"
# define SIZE_Y 576
# define SIZE_X 768
# define MX 24
# define MY 24
///# define SIZE_Y 600
///# define SIZE_X 800


typedef struct	s_color
{
	int	color;
	int red;
	int green;
	int blue;
}				t_color;

typedef struct	s_player
{
	int		**map;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	time;
	double	oldtime;
	double	rayposx;
	double	rayposy;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	double	movespeed;
	double	olddirx;
	double	oldplanex;
	double	rotspeed;
	double	camerax;
	///int		hit;
	int		side;
	double	frametime;
	double	drawstart;
	double	drawend;
	double	lineheight;

	double	sm;

	int		dx;
	int 	dy;
	int 	sx;
	int 	sy;
	int 	error;
	int 	error2;
	int mx;
	int my;


	int		wall_height;
	int 	text_x;
	int 	text_y;
	double		wall_x;


}				t_player;

typedef struct	s_mlx
{

	int		size_x;
	int 	size_y;
	void	*mlx;
	void	*win;
	void	*img;
	void	*img2;
	char 	*buf2;
	char	*buf;
	int		bpp;
	int		endl;
	int		sizel;

}				t_mlx;

typedef struct	s_xpm
{
	int		size_x;
	int		size_y;
	int		bpp;
	int		sizel;
	int		endl;
	char	*buf;
	void	*xpm;
}				t_xpm;

typedef struct	s_wolf
{
	t_mlx		mx;
	t_player	pl;
	t_color		cl;
//	t_xpm		xpm[3];
	int			**pics;
	int 		p_y[3];
	int 		p_x[3];
	int 		*data;
	int			d;

}				t_wolf;

int		my_key(int keycode, t_wolf *w);
void	ft_draw(t_wolf *w, int x0,int y0, int x1, int y1);
int		ft_wolf(t_wolf *w);
void	img_put(t_wolf *w, int x, int y, int color);
void	ft_imageput(t_wolf *w);
void	ft_imageinit(t_wolf *w);
int		get_red(int color);
int		get_green(int color);
int		get_blue(int color);
void	color_floor_celing(t_wolf *w, int x);
t_xpm	*ft_create_xpm(t_wolf *w, char *file);
int		ft_readmap(t_wolf *w, char *av);
int		ft_map_error(void);
//void	ft_draw_text(t_wolf *w);
void	ft_draw_text(t_wolf *w, int x);
void	ft_start_position(t_wolf *w);
void	ft_map_generation(t_wolf *w);

#endif