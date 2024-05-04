/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalles- <rsalles-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:57:08 by relisallesz       #+#    #+#             */
/*   Updated: 2024/05/04 20:26:11 by rsalles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
		fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection,
		fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += (1 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (1 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (1 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (1 * fractal->zoom);
	else if (keysym == XK_plus || keysym == XK_KP_Add)
		fractal->iterations_defintion += 5;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
		fractal->iterations_defintion -= 5;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int __attribute__((unused))x,
	__attribute__((unused))int y, t_fractal *fractal)
{
	if (button == Button5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, WIDTH)
				* fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (map(y, +2, -2, HEIGHT)
				* fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0)
		/ (old_max - 0) + new_min);
}
