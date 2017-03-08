#include "fractol.h"

/*
** Mandelbrot function.
** As we know that Mandelbrot's boundaries on y are [-1.2, 1.2] and on y are
** [-2.1, 0.6] we set up these limits.
** This function take a point, represented by its coordinates (x, y) and test if
** it belongs to Mandelbrot's set.
*/

void        mandelbrot(int x, int y, t_fal *fal, t_env *env)
{
	int		i;
	float	tmp;

	i = -1;
	fal->c_r = x / fal->zoom_x + fal->x1;
	fal->c_i = y / fal->zoom_y + fal->y1;
	fal->z_r = 0;
	fal->z_i = 0;
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
		put_pixel(env, x, y, 000000000);
	else
		put_pixel(env, x, y, i * 255 / fal->max_iter);
}
