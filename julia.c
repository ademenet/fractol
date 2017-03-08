#include "fractol.h"

/*
** Julia set is similar to Mandelbrot except the c part of the sequence is
** fixed.
*/

void		julia(int x, int y, t_fal *fal, t_env *env)
{
	int		i;
	float	tmp;

	i = -1;
	fal->z_r = x / fal->zoom_x + fal->x1;;
	fal->z_i = y / fal->zoom_y + fal->y1;;
	while ((fal->z_r * fal->z_r + fal->z_i * fal->z_i) < 4
			&& ++i < fal->max_iter) // while(module < 4 and i < max iterations)
	{
		tmp = fal->z_r;
		fal->z_r = fal->z_r * fal->z_r - fal->z_i * fal->z_i + fal->c_r;
		fal->z_i = 2 * fal->z_i * tmp + fal->c_i;
	}
	// We test if we reach max_iter or not. If it is the case then the point
	// does not belong to Mandelbrot's set and it's drew in a certain color.
	if (i == fal->max_iter)
	{
		put_pixel(env, x, y, 000000000);
	}
	else
	{
		put_pixel(env, x, y, (i * 255) / fal->max_iter);
	}
}
