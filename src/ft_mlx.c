/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 14:12:44 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/11 14:33:30 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_put_pixel_to_img(t_data *d, int x, int y, int color)
{
	unsigned int	new_color;
	int	i;

	new_color = mlx_get_color_value(d->mlx, color);
	i = x * 4 + y * d->sizeline;
	d->data[i] = (new_color & 0xFF);
	d->data[i + 1] = (new_color & 0xFF00) >> 8;
	d->data[i + 2] = (new_color & 0xFF0000) >> 16;
}

int		expose_hook(t_data *d)
{
	ft_draw(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_data *d)
{
	d->i = 0;
	ft_putstr("Keycode : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 65307)
		exit(0);
	if (keycode == UP)
		ft_putstr("[UP]\n");
	if (keycode == DOWN)
		ft_putstr("[DOWN]\n");
	if (keycode == RIGHT)
		ft_putstr("RIGHT\n");
	if (keycode == LEFT)
		ft_putstr("LEFT\n");
	expose_hook(d);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_data *d)
{
	d->i = 0;
	ft_putstr("button : ");
	ft_putnbr(button);
	ft_putstr(" (");
	ft_putnbr(x);
	ft_putstr(":");
	ft_putnbr(y);
	ft_putstr(")\n");
	return (0);
}

void	ft_mlx(t_data *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, SIZE_WINX, SIZE_WINY, "RTv1");
	d->img = mlx_new_image(d->mlx, SIZE_WINX, SIZE_WINY);
	d->data = mlx_get_data_addr(d->img, &d->bbp, &d->sizeline, &d->endian);
	mlx_expose_hook(d->win, expose_hook, d);
	mlx_hook(d->win, 2, (1L << 0), key_hook, d);
	mlx_mouse_hook(d->win, mouse_hook, d);
	mlx_loop(d->mlx);
}
