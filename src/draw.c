/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 14:14:49 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/14 21:11:53 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void	ft_draw_sq(t_data *d)
{
	t_pos	a;
	t_pos	b;
	int		i;
	int		j;
	int		col;

	col = 0xFFFFFF;
	i = 0;
	j = 0;
	a.x = 0;
	a.x = 0;
	b.x = 500;
	b.y = 0;
	while (b.y <= 500)
	{
		ft_trace_line(d, &a, &b, col);
		b.y++;
		a.y++;
	}
}

void	ft_init_scene(t_data *d)
{
	d->origin->x = 0;
	d->origin->y = 0;
	d->origin->z = 0;
}

int		ft_insterct_sphere(t_data *d, t_pos *ray)
{
	/* printf("SommeCarre Point %f R2 %f\n", (pow(ray->x - d->obj->x, 2) + pow(ray->y - d->obj->y, 2) + pow(ray->z - d->obj->z, 2)), pow(d->obj->radius, 2)); */
	if ((pow(ray->x - d->obj->x, 2) + pow(ray->y - d->obj->y, 2) +
		pow(ray->z - d->obj->z, 2)) <= pow(d->obj->radius, 2))
		return (0);
	else
		return (1);
}

/* int		ft_insterct_sphere(t_data *d, double x, double y, double z) */
/* { */
/* 	if ((pow(x - d->obj->x, 2) + pow(y - d->obj->y, 2) + */
/* 		pow(z - d->obj->z, 2)) == pow(d->obj->radius, 2)) */
/* 		return (0); */
/* 	else */
/* 		return (1); */
/* } */


void	ft_raytrace(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(j < SIZE_WINY)
	{
		while (i < SIZE_WINX)
		{
			d->target->x = i - (SIZE_WINX / 2);
			d->target->y = j - (SIZE_WINY / 2);
			d->target->z = -(SIZE_WINX / (2 * (tan(FOV / 2))));
			d->target = ft_vect_normalize(d->target);
			d->ray_dir = ft_vector_substract(d->target, d->origin);
			d->ray_dir = ft_vect_normalize(d->ray_dir);
			d->ray->origin = ft_vector_copy(d->origin);
			d->ray->dir = ft_vector_copy(d->ray_dir);
			/* printf("%f\n%f\n%f\n\n", d->ray->dir->x, d->ray->dir->y, d->ray->dir->z); */
			d->ray->dir->x += i;
			d->ray->dir->y += j;
			d->ray->dir->z += d->obj->z;
			if (ft_insterct_sphere(d, d->ray->dir) == 0)
			{
				ft_put_pixel_to_img(d, i, j, 0x1BFFFF);
				/* ft_putstr("OK\n"); */
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_draw(t_data *d)
{
	(void)d;
	ft_init_scene(d);
	ft_raytrace(d);
	/* ft_draw_sq(d); */
}
