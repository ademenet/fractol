#include "fractol.h"

/*
** Mandelbrot function.
*/

void        mandelbrot(int x, int y, t_mdl *mdl, t_env *env)
{
	int		i;
	float	tmp;

	i = -1;
	mdl->c_r = x / mdl->settings.zoom_x + mdl->x1;
	mdl->c_i = y / mdl->settings.zoom_y + mdl->y1;
	mdl->z_r = 0;
	mdl->z_i = 0;
	while ((mdl->z_r * mdl->z_r + mdl->z_i * mdl->z_i) < 4
			&& ++i < mdl->settings.max_iter) // while(module < 4 and i < max iterations)
	{
		tmp = mdl->z_r;
		mdl->z_r = mdl->z_r * mdl->z_r - mdl->z_i * mdl->z_i + mdl->c_r;
		mdl->z_i = 2 * mdl->z_i * tmp + mdl->c_i;
	}
	if (i == mdl->settings.max_iter)
	{
		put_pixel(env, x, y, 000000000);
	}
	else
	{
		put_pixel(env, x, y, i * 255 / mdl->settings.max_iter);
	}
}
