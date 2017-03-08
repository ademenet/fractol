#include "fractol.h"

/*
** Manage image buffer pixels by pixels, with RGB color coded into an int. For
** instance, RGB color 156-89-213 will be RGB hex 9C-59-D5 or RGB int 10246613.
** On our computer, pixels are stored in BGR. This function, may only work in
** our endian case.
*/

void		put_pixel(t_env *env, int x, int y, int color)
{
	int		i;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return;
	i = x * env->bpp / 8 + y * env->sl;
	env->im_buf[i] = color & 0xFF; // Blue
	env->im_buf[i + 1] = (color & 0xFF00) >> 8; // Green
	env->im_buf[i + 2] = (color & 0xFF0000) >> 16; // Red
}

/*
** Skim the complete plan in order to compute if each point of coordinates
** (x, y) belongs to the given fractal set.
*/

void        fractals_compute(t_env *env, t_fal *fal)
{
	int		x;
	int		y;

	x = -1;
	// In the following loops we are going to compute for each point if it
	// belongs to the corresponding fractal set.
	while(++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
			fal->ptr(x, y, fal, env);
	}
}

/*
** Create a new image, get image buffer and compute fractals stored
** into image buffer (im_buf). Then, dump to window and destroy image from
** memory.
*/

int			put_image(t_env *env, t_fal *fal)
{
	env->im = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT); // create a new image in memory
	env->im_buf = mlx_get_data_addr(env->im, &(env->bpp), &(env->sl),
		&(env->endian)); // get image buffer (char*)
	fractals_compute(env, fal); // compute image
	mlx_put_image_to_window(env->mlx, env->win, env->im, 0, 0); // dump image to window
	mlx_destroy_image(env->mlx, env->im); // destroy image from memory
	return (0);
}
