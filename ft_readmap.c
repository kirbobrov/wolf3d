#include "wolf.h"

int	ft_map_error(void)
{
	ft_putstr("bad map set correct map\n");
	return (0);
}

static int		corect_map(t_wolf *w)
{
	int i;

	i = -1;
	while (++i < w->pl.mx)
		if (w->pl.map[0][i] <= 0)
			w->pl.map[0][i] = 1;
	i = 0;
	while (i < w->pl.my)
		if (w->pl.map[i++][0] <= 0)
			w->pl.map[i - 1][0] = 1;
	i = 0;
	while (i < w->pl.mx)
		if (w->pl.map[w->pl.my - 1][i++] <= 0)
			w->pl.map[w->pl.my - 1][i - 1] = 1;
	i = 0;
	while (i < w->pl.my)
		if (w->pl.map[i++][w->pl.mx - 1] <= 0)
			w->pl.map[i - 1][w->pl.mx - 1] = 1;
	return (0);
}

static int map_pars(t_wolf *w, int	f)
{
	int i;
	int j;
	char *line;
	char *buf;

	i = -1;
	w->pl.map = (int **)malloc(sizeof(int *) * (w->pl.my + 1));
	while (++i < w->pl.my)
	{
		if (get_next_line(f, &line) == 0)
			line = NULL;
		j = 0;
		buf = line;
		w->pl.map[i] = (int *)malloc(sizeof(int) * (w->pl.mx + 1));
		while (j < w->pl.mx)
		{
			w->pl.map[i][j++] = ft_atoi(line);
			if (line)
				line = ft_strchr(line + 1, ' ');
		}
		if (buf)
			free(buf);
	}
	return (corect_map(w));
}

int ft_readmap(t_wolf *w, char *av)
{
	int i;
	char *line;
	char *buf;

	printf("readmap\n");
	i = open(av, O_RDONLY);
	printf("readmap2\n");
	get_next_line(i, &line);
	printf("readmap3\n");
	w->pl.mx = ft_atoi(line);
	printf("readmap4\n");
	w->pl.my = ft_atoi(ft_strchr(line, ' '));
	printf("readmap5\n");
//	if ((get_next_line(i, &line) < 1))
//		return (1);
//	printf("readmap3\n");
//	if ((w->pl.mx = ft_atoi(line)) <= 0 ||
//			(w->pl.my = ft_atoi(ft_strchr(line, ' '))) <=0)
//		return (1);
//	printf("w->pl.mx = %d\tw->pl.my = %d\t\n",w->pl.mx, w->pl.mx);
//	free(line);
//	if (w->pl.mx >= 100 || w->pl.my >= 100)
//		return (1);
	return (map_pars(w, i));
}