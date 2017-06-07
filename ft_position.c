//
// Created by Kyrylo Bobrov on 06.06.17.
//

#include "wolf.h"


void	ft_map_generation(t_wolf *w)
{
//	srand(time(0));
//	w->mx.size_x = 10  + rand() % 20;
//	w->mx.size_y = 10 + rand() % 20;
	printf("%d %d\n", w->mx.size_x, w->mx.size_y);
	int i;
	int j;

	w->pl.map = (int **)malloc(sizeof(int *) * w->mx.size_y);
	j = -1;
	while (++j < w->mx.size_y)
	{
		w->pl.map[j] = (int *)malloc(sizeof(int) * w->mx.size_x);
		i = -1;
		while (++i < w->mx.size_x)
		{
			if (i == 0 || j == 0 ||
					i == MY - 1 || j == MX - 1)
				w->pl.map[i][j] = 1;
			else
				w->pl.map[i][j] = 0;
			if (i * j == 5 || i * j ==  8 || i * j ==  13
				|| i * j == 21 || i * j == 34|| i * j == 55 ||
					i * j == 89 || i * j ==  144 || i * j == 233 ||
					i * j ==  377)
				w->pl.map[i][j] = 1;
			if ((i == 5 && (j != 2 ||  j != 3 || j != 4 || j != 5)))
				w->pl.map[i][j] = 1;
			if (i % 2 == 0 && j < MX/2)
				w->pl.map[i][j] = 1;
		}
	}
	j = 0;
	while (j < w->mx.size_y)
	{
		i = 0;
		while (i < w->mx.size_x)
		{
			printf("%3d", w->pl.map[j][i]);
			i++;
		}

		j++;
		printf("\n");
	} ///////генератор карты (генерятся только стены по периметру)
/////
}

void	ft_start_position(t_wolf *w)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while ((j < w->mx.size_y) && (w->pl.map[j][i] != 0))
	{
		i = 0;
		while ((i < w->mx.size_x) && (w->pl.map[j][i] != 0))
			i++;

		if (w->pl.map[j][i] == 0)
		{
			w->pl.posx = i;
			w->pl.posy = j;
		}
		j++;
	}
///	printf("posx == %f posy == %f\n", w->pl.posx, w->pl.posy);
}
