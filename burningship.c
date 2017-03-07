#include "fractol.h"

void        burningship(int x, int y, t_fal *fal, t_env *env)
{
	int		i;
	float	tmp;

	i = -1;
	fal->c_r = x / fal->settings.zoom_x + fal->x1;
	fal->c_i = y / fal->settings.zoom_y + fal->y1;
	fal->z_r = 0;
	fal->z_i = 0;
	while ((fal->z_r * fal->z_r + fal->z_i * fal->z_i) < 4
			&& ++i < fal->settings.max_iter) // while(module < 4 and i < max iterations)
	{
		tmp = fal->z_r;
		fal->z_r = fal->z_r * fal->z_r - fal->z_i * fal->z_i + fal->c_r;
		fal->z_r = fal->z_r < 0 ? -fal->z_r : fal->z_r;
		fal->z_i = 2 * fal->z_i * tmp + fal->c_i;
		fal->z_i = fal->z_i < 0 ? -1 * fal->z_i : fal->z_i;
	}
	// We test if we reach max_iter or not. If it is the case then the point
	// does not belong to Mandelbrot's set and it's drew in a certain color.
	if (i == fal->settings.max_iter)
		put_pixel(env, x, y, 000000000);
	else
		put_pixel(env, x, y, i * 255 / fal->settings.max_iter);
}