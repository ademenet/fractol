#include "fractol.h"

void        fractals_compute(t_env *env)
{
	int		x;
	int		y;
	t_mdl	mdl;

	x = -1;
	// TODO: those (x1, x2, y1, y2) depends on fractal to display, need to put
	// them in variables
	mdl.x1 = -2.1;
	mdl.x2 = 0.6;
	mdl.y1 = -1.2;
	mdl.y2 = 1.2;
	mdl.settings.zoom_x = WIN_WIDTH / (mdl.x2 - mdl.x1);
	mdl.settings.zoom_y = WIN_HEIGHT / (mdl.y2 - mdl.y1);
	// TODO: set max_iter as a variable
	mdl.settings.max_iter = 50; // Also called "rang" in french
	// In the following loops we are going to compute for each point if it
	// belongs to the corresponding fractal set.
	while(++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
		{
			// TODO: call the right function according to the user preferences
			mandelbrot(x, y, &mdl, env);
		}
	}
}
