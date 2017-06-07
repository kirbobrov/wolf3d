/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 17:27:20 by kbobrov           #+#    #+#             */
/*   Updated: 2017/04/03 20:55:56 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
typedef union		u_col
{
	int 			color;
	int				c[4];
}					t_col;
*/
char	*ft_color_substr(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
		{
			if (str[i] == 'x' || str[i] == 'X')
				return (str + i + 1);
			else
				i++;
		}
	return ("FFFFFF");
}

t_color	*ft_read_color(int color)
{
	int		red;
	int		green;
	int		blue;
	t_color	*pt;

	pt = (t_color*)malloc(sizeof(t_color));
/*
	t_col	cl;

	cl.color = color;

	blue = cl.c[0];
	green = cl.c[1];
	red = cl.c[2];
	cl.c[3] = 0;
*/
	red = (color >> 16);
	green = (color >> 8) - (red << 8);
	blue = (color) - (red << 16) - (green << 8);
	pt->red = red;
	pt->green = green;
	pt->blue = blue;
	return (pt);
}

void	ft_begin_con(t_fdf *s)
{
	s->xa0 = 48;
	s->ya0 = 0;
	s->za0 = 315;
	s->dx = WEIGHT / 2;
	s->dy = HEIGHT / 2;
	s->mult = 700;
}

int		ft_readmap(const int fd, t_fdf *s)
{
	int		x;
	int		y;
	char	**buf;
	char	*line;

	y = -1;
	s->pt = (t_point**)malloc(sizeof(t_point*) * (s->ymax + 1));
	s->pt[s->ymax] = NULL;
	ft_begin_con(s);
	while (get_next_line(fd, &line) > 0)
	{
		x = -1;
		s->pt[++y] = (t_point*)malloc(sizeof(t_point) * (s->xmax));
		buf = ft_strsplit(line, ' ');
		while (buf[++x])
		{
			s->pt[y][x].x0 = x - (s->xmax / 2);
			s->pt[y][x].y0 = y - (s->ymax / 2);
			s->pt[y][x].z0 = ft_atoi(buf[x]);
			s->pt[y][x].col =
					ft_read_color((ft_atoi_base(ft_color_substr(buf[x]), 16)));
		}
	}
	ft_image(s);
	return (0);
}
