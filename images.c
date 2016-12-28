#include "fractol.h"

void		put_pixel(t_env *env, int x, int y, int color)
{
	int		i;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return;
	i = x * env->bpp / 8 + y * env->sl;
	env->im_buf[i] = color & 0xFF;
	env->im_buf[i + 1] = (color & 0xFF00) >> 8;
	env->im_buf[i + 2] = (color & 0xFF0000) >> 16;
}

int			put_image(t_env *env)
{
	env->im = mlx_put_image(env->mlx, WIN_X, WIN_Y);
	env->im_buf = mlx_get_data_addr(env->im, &(env->bpp), &(env->sl),
		&(env->endian));
	fract_ol(env);
	mlx_put_image_to_window(env->mlx, env->win, env->im, 0, 0);
	mlx_destroy_image(env->mlx, env->im);
	return (0);
}
