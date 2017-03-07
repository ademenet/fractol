#include "fractol.h"

/*
** `fal` stands for fractal, it refers to everything specific to one fractal:
** Mandelbrot, Julia, etc.
*/

/*
** Set the limit for better display.
*/

void		set_limits(t_env *env, t_fal *fal)
{
	if (env->arg[0] == 1)
	{
		fal->x1 = -2.1;
		fal->x2 = 0.6;
		fal->y1 = -1.2;
		fal->y2 = 1.2;
	}
	else if (env->arg[1] == 1)
	{
		fal->x1 = -1;
		fal->x2 = 1;
		fal->y1 = -1.2;
		fal->y2 = 1.2;
	}
	else if (env->arg[2] == 1)
	{
		// TODO: limits for last fractal
		fal->x1 = -1;
		fal->x2 = 1;
		fal->y1 = -1.2;
		fal->y2 = 1.2;
	}
}

/*
** Skim the complete plan in order to compute if each point of coordinates
** (x, y) belongs to the given fractal set.
*/

void        fractals_compute(t_env *env)
{
	int		x;
	int		y;
	t_fal	fal;

	x = -1;
	set_limits(env, &fal);
	fal.settings.zoom_x = WIN_WIDTH / (fal.x2 - fal.x1);
	fal.settings.zoom_y = WIN_HEIGHT / (fal.y2 - fal.y1);
	// TODO: set max_iter as a variable
	fal.settings.max_iter = 100; // Also called "rang" in french
	// In the following loops we are going to compute for each point if it
	// belongs to the corresponding fractal set.
	while(++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
		{
			// TODO: call the right function according to the user preferences
			// mandelbrot(x, y, &fal, env);
			// julia(x, y, &fal, env);
			burningship(x, y, &fal, env);
		}
	}
}
