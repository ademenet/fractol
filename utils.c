#include "fractol.h"

void		display_one_point_color(t_env *env, t_fal *fal, int x, int y, int i)
{
	if (i == fal->max_iter)
		put_pixel(env, x, y, 0x0);
	else
		put_pixel(env, x, y, i * 255 / fal->max_iter);
}
