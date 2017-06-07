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

void	ft_init(t_wolf *w)
{
	int 	b;

	w->mx.mlx = mlx_init();
	w->mx.win = mlx_new_window(w->mx.mlx, SIZE_X, SIZE_Y, "wolf3d by kbobrov");
	w->pl.posx = 1;
	w->pl.posy = 1;  //x and y start position
	w->pl.dirx = -1;
	w->pl.diry = 0; //initial direction vector
	w->pl.planex = 0;
	w->pl.planey = 0.66; //the 2d raycaster version of camera plane
	w->pl.time = 0; //time of current frame
	w->pl.oldtime = 0; //time of previous frame
	w->pl.perpwalldist = 0;
	w->pl.camerax = 0;
	w->pl.raydirx = 0;
	w->pl.raydiry = 0;
	w->pl.rayposx = 0;
	w->pl.rayposy = 0;
	///w->pl.side = 0;
	///w->pl.hit = 0;
	w->pl.frametime = 0;
	w->cl.color = 0xFAFF0F;
	w->mx.img2 = mlx_new_image(w->mx.mlx, SIZE_X, SIZE_Y);
	w->mx.buf2 = mlx_get_data_addr(w->mx.img2, &b, &b, &b);


	w->pl.sm = 1.0;

//	void	*temp;
	///int 	b;

//	temp = mlx_xpm_file_to_image(w->mx.mlx, "2.xpm", &(w->p_y[0]), &(w->p_x[0]));
//	w->pics[0] = (int *)mlx_get_data_addr(temp, &b, &b, &b);
//	temp = mlx_xpm_file_to_image(w->mx.mlx, "1.xpm", &(w->p_y[1]), &(w->p_x[1]));
//	w->pics[1] = (int *)mlx_get_data_addr(temp, &b, &b, &b);
//	temp = mlx_xpm_file_to_image(w->mx.mlx, "3.xpm", &(w->p_y[2]), &(w->p_x[2]));
//	w->pics[2] = (int *)mlx_get_data_addr(temp, &b, &b, &b);
//	temp = mlx_xpm_file_to_image(w->mx.mlx, "3.xpm", &(w->p_y[3]), &(w->p_x[3]));
//	w->pics[3] = (int *)mlx_get_data_addr(temp, &b, &b, &b);
//	w->data = (int *)mlx_get_data_addr(w->mx.img, &b, &b, &b);


///	w->pics[0] = (int)mlx_xpm_file_to_image(w->mx.mlx, "./pic/floor.xpm", &(w->p_x[0]), &(w->p_y[0]));
///	w->pics[1] = (int)mlx_xpm_file_to_image(w->mx.mlx, "./pic/wall.xml", &(w->p_x[1]), &(w->p_y[1]));
//	w->pics[2] = (int)mlx_xpm_file_to_image(w->mx.mlx, "./pic/sky.xpm", &(w->p_x[2]), &(w->p_y[2]));

///	printf("after");
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



int			main(int ac, char **av)
{
	t_wolf w;
	ft_init(&w);
	///w->xpm = ft_create_xpm(w)
//
//	if (ac != 2)
//		return (write(1, "set correct map", 15));
//	if (!ft_readmap(&w, av[1]))
//		return (ft_map_error());
//	w.mx.size_x = w.pl.mx;
//	w.mx.size_y = w.pl.my;


	///ft_map_generation(&w);
	///srand(time(0));
//	w.mx.size_x = 10  + rand() % 20;
//	w.mx.size_y = 10 + rand() % 20;
//	printf("%d %d\n", w.mx.size_x, w.mx.size_y);
//	int i;
//	int j;
//
//	w.pl.map = (int **)malloc(sizeof(int *) * w.mx.size_y);
//	j = -1;
//	while (++j < w.mx.size_y)
//	{
//		w.pl.map[j] = (int *)malloc(sizeof(int) * w.mx.size_x);
//		i = -1;
//		while (++i < w.mx.size_x)
//		{
//			if (i == 0 || j == 0 || j == w.mx.size_y -  1 || i == w.mx.size_x - 1)
//				w.pl.map[j][i] = 1;
//			else if (i == (rand() % w.mx.size_x) || j == (rand() % w.mx.size_y))
//				w.pl.map[j][i] = 1;
//			else
//				w.pl.map[j][i] = 0;
//		}
//	}
//	j = 0;
//	while (j < w.mx.size_y)
//	{
//		i = 0;
//		while (i < w.mx.size_x)
//		{
//			printf("%3d", w.pl.map[j][i]);
//			i++;
//		}
//
//		j++;
//		printf("\n");
//	} ///////генератор карты (генерятся только стены по периметру)
///////

	int i;
	int j;

	w.pl.map = (int **)malloc(sizeof(int *) * MY);
	j = -1;
	while (++j < MY)
	{
		w.pl.map[j] = (int *)malloc(sizeof(int) * MX);
		i = -1;
		while (++i < MX)
		{
			if (i == 0 || j == 0 || i == MX - 1 || j == MY - 1)
				w.pl.map[j][i] = 1;
			else
				w.pl.map[j][i] = 0;
			if (i * j == 5 || i * j ==  8 || i * j ==  13 || i * j == 21 || i * j == 35|| i * j == 56 ||
				i * j == 91 || i * j ==  154 || i * j == 237 ||
				i * j ==  375)
				w.pl.map[j][i] = 1;
			if ((j == 5 && (i != 2 && i != 4 && i != 5)))
				w.pl.map[j][i] = 1;
			if (j % 2 == 0 && i < MX/2)
				w.pl.map[j][i] = 1;
		}
	}
	j = 0;
	while (j < MY)
	{
		i = 0;
		while (i < MX)
		{
			printf("%3d", w.pl.map[j][i]);
			i++;
		}

		j++;
		printf("\n");
	}

	w.pl.posx = 20;///w.mx.size_x / 2;
	w.pl.posy = 20;///w.mx.size_y / 2;

	printf("posx == %f posy == %f\n", w.pl.posx, w.pl.posy);


//ft_wolf(&w)
	mlx_hook(w.mx.win, 2, 5, my_key, &w);
	mlx_loop_hook(w.mx.mlx, ft_wolf, &w);
	mlx_loop(w.mx.mlx);
	///mlx_hook(w->win, 17, 0L, ft_mouse_exit, w);
	///mlx_hook(w->win, 4, 0, ft_mouse_zoom, w);
	return (0);
}