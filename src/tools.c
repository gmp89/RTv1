/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 13:58:11 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/14 21:18:46 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_struct_init(t_data *d)
{
	d->cam = (t_cam *)malloc(sizeof(t_cam));
	d->cam->pos =(t_pos *)malloc(sizeof(t_pos));
	d->obj = (t_pos *)malloc(sizeof(t_pos));
	d->origin = (t_pos *)malloc(sizeof(t_pos));
	d->target = (t_pos *)malloc(sizeof(t_pos));
	d->ray_dir = (t_pos *)malloc(sizeof(t_pos));
	d->ray = (t_pos *)malloc(sizeof(t_pos));
	d->ray->origin = (t_pos *)malloc(sizeof(t_pos));
	d->ray->dir = (t_pos *)malloc(sizeof(t_pos));
	d->light = (t_pos *)malloc(sizeof(t_pos));
}

void	ft_swap_pos(t_pos *a, t_pos *b)
{
	t_pos	tmp;

	tmp.x = a->x;
	tmp.y = a->y;
	a->x = b->x;
	a->y = b->y;
	b->x = tmp.x;
	b->y = tmp.y;
}

void	ft_clean(t_data *d)
{
	int		i;
	int		j;
	i = 0;
	j = 0;
	while (i <= SIZE_WINY)
	{
		while (j <= SIZE_WINX)
		{
			ft_put_pixel_to_img(d, j, i, 0x000000);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_trace_help(t_data *d, t_pos *a, t_pos *b, int color)
{
	if (a->x > b->x)
		ft_swap_pos(a, b);
	d->co->x = a->x;
	while (d->co->x <= b->x)
	{
		d->co->y = a->y + ((b->y - a->y) * (d->co->x - a->x)) / (b->x - a->x);
		ft_put_pixel_to_img(d, d->co->x, d->co->y, color);
		d->co->x++;
	}
}

void	ft_trace_line(t_data *d, t_pos *a, t_pos *b, int color)
{
	d->co = (t_pos *)malloc(sizeof(t_pos));
	if (a->x == b->x && a->y == b->y)
		return ;
	else if (abs(b->x - a->x) >= abs(b->y - a->y))
	{
		ft_trace_help(d, a, b, color);
	}
	else
	{
		if (a->y > b->y)
			ft_swap_pos(a, b);
		d->co->y = a->y;
		while (d->co->y <= b->y)
		{
			d->co->x = a->x + ((b->x - a->x) * (d->co->y - a->y)) / N;
			ft_put_pixel_to_img(d, d->co->x, d->co->y, color);
			d->co->y++;
		}
	}
}
