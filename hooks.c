#include "fractol.h"
#include "keys.h"

int			events(int keycode, t_env *env)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_PAD_SUB)
	{
		if (env->fal->zoom_x > 1 && env->fal->zoom_y > 1)
		{
			env->fal->zoom_x -= 1;
			env->fal->zoom_y -= 1;
		}
		else
		{
			env->fal->zoom_x = 1;
			env->fal->zoom_y = 1;
		}
	}
	if (keycode == KEY_PAD_ADD)
	{
		env->fal->zoom_x += 1;
		env->fal->zoom_y += 1;
	}
	put_image(env, env->fal);
	return (0);
}
