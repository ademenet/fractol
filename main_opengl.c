/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_opengl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 09:14:54 by ademenet          #+#    #+#             */
/*   Updated: 2017/03/07 09:48:35 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/gl.h>
#include <GL/glut.h>
// #include "fractol.h"
#include <stdio.h>

typedef struct		s_rgb
{
	float			r;
	float			g;
	float			b;
}					t_rgb;

t_rgb				pixels[841 * 1440], pattern[999];

void				mandelbrotset(void)
{
	float			x0, y0, x, y, xtmp;
	int				iter, maxiter, loc=0;

	for(y0 = -1; y0 < 1.1; y0 = y0 + 0.0025)
	{
		for(x0 = -2.5; x0 < 1.1; x0 = x0 + 0.0025)
		{
			x = 0;
			y = 0;
			iteration = 0;
			max_iteration = 1000;
			while((x * x) + (y * y) < 4 && iteration < max_iteration)
			{
				xtemp = (x * x) - (y * y) + x0;
				y = (2 * x * y) + y0;
				x = xtemp;
				iteration++;
			}
			if(iteration >= 999)
			{
				pixels[loc].r = 0;
				pixels[loc].g = 0;
				pixels[loc].b = 0;
			}
			else
			{
				pixels[loc].r = pattern[iteration].r;
				pixels[loc].g = pattern[iteration].g;
				pixels[loc].b = pattern[iteration].b;
			}
			loc++;
		}
	}
}

void				init(void)
{
	glViewport(0, 0, 1440, 841);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1440, 0, 841);

	int i;
	float r, g, b;
	for(i = 0; i < 841*1440; i++)
	{
		pixels[i].r = 1;
		pixels[i].g = 1;
		pixels[i].b = 1;
	}
	for(r = 0.1; r <= 0.9; r= r+0.1)
	{
		for(g = 0.1; g <= 0.9; g = g+0.1)
		{
			for(b = 0.1; b <= 0.9; b = b+0.1)
			{
				pattern[i].r = b;
				pattern[i].g = r;
				pattern[i].b = g;
				i++;
			}
		}
	}
	for(i = 0 ;i <= 999; i++)
	{
		pattern[i].r = 1;
		pattern[i].g = 1;
		pattern[i].b = 1;
	}
	mandelbrotset();
}

void onDisplay()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(1440, 841, GL_RGB, GL_FLOAT, pixels);
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize (1440, 841);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Mandelbrotset OpenGL test");

	Init ();
	glutDisplayFunc(onDisplay);
	glutMainLoop();
	return 0;
}