#include "fractol.h"

void        fractals_compute(t_env *env)
{
	int		x;
	int		y;
	t_mdl	mdl;

	x = -1;
	y = -1;
	mdl.settings.zoom_x = WIN_WIDTH / (mdl.x2 - mdl.x1);
	mdl.settings.zoom_y = WIN_HEIGHT / (mdl.y2 - mdl.y1);
	mdl.settings.max_iter = 50;
	while(++x < WIN_WIDTH)
	{
		while (++y < WIN_HEIGHT)
		{
			mandelbrot(x, y, &mdl, env);
		}
	}
}
