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
		env->fal->zoom_x -= 10;
		env->fal->zoom_y -= 10;
	}
	if (keycode == KEY_PAD_ADD)
	{
		env->fal->zoom_x += 10;
		env->fal->zoom_y += 10;
	}
	put_image(env, env->fal);
	return (0);
}

int			params(int x, int y, t_env *env)
{
	env->fal->c_r = (float)x / (float)WIN_WIDTH;
	env->fal->c_i = (float)y / (float)WIN_HEIGHT;
	put_image(env, env->fal);
	return(0);
}
