
#include "wolf.h"


//void	create_win_and_text(t_env *w)
//{
//	void	*temp;
//	int		b;
//
//	w->mlx = mlx_init();
//	w->win = mlx_new_window(w->mlx, WIDTH, HEIGHT, "Wolf3D");
//	w->img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
//	w->text = (int **)malloc(sizeof(int *) * 4);
//	temp = mlx_xpm_file_to_image(w->mlx, "2.xpm", &(w->t_h[0]), &(w->t_w[0]));
//	w->text[0] = (int *)mlx_get_data_addr(temp, &b, &b, &b);
//	temp = mlx_xpm_file_to_image(w->mlx, "1.xpm", &(w->t_h[1]), &(w->t_w[1]));
//	w->text[1] = (int *)mlx_get_data_addr(temp, &b, &b, &b);
//	temp = mlx_xpm_file_to_image(w->mlx, "3.xpm", &(w->t_h[2]), &(w->t_w[2]));
//	w->text[2] = (int *)mlx_get_data_addr(temp, &b, &b, &b);
//	temp = mlx_xpm_file_to_image(w->mlx, "3.xpm", &(w->t_h[3]), &(w->t_w[3]));
//	w->text[3] = (int *)mlx_get_data_addr(temp, &b, &b, &b);
//	w->data = (int *)mlx_get_data_addr(w->img, &b, &b, &b);
//}


t_xpm	*ft_create_xpm(t_wolf *w, char *file)
{
	t_xpm	*new;

	new = (t_xpm*)malloc(sizeof(t_xpm));
	new->size_x = 0;
	new->size_y = 0;
	new->bpp = 0;
	new->sizel = 0;
	new->endl = 0;
	new->xpm = mlx_xpm_file_to_image(w->mx.mlx, file, &new->size_x, &new->size_y);
	new->buf = mlx_get_data_addr(new->xpm, &new->bpp, &new->sizel, &new->endl);
	return (new);
}