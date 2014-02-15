/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 14:14:49 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/15 19:52:21 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void	ft_init_scene(t_data *d)
{
	d->origin->x = 0;
	d->origin->y = 0;
	d->origin->z = -(SIZE_WINX / (2 * (tan(FOV / 2))));
	d->light->x = -500;
	d->light->y = -500;
	d->light->z = -500;
	d->light_color->x = 0.5;
	d->light_color->y = 0.5;
	d->light_color->z = 0.5;
}

int		ft_insterct_sphere(t_data *d, t_pos *ray)
{
	/* printf("SommeCarre Point %f R2 %f\n", (pow(ray->x - d->obj->x, 2) + pow(ray->y - d->obj->y, 2) + pow(ray->z - d->obj->z, 2)), pow(d->obj->radius, 2)); */
	double	b;
	double	c;
	double	delta;
	double	res1;
	double	res2;
	double	a;

	a = ft_vector_dot(ray, ray);
	d->tmp = ft_vector_substract(d->ray->origin, d->obj);
	b = 2 * ft_vector_dot(d->tmp, ray);
	c = ft_vector_dot(d->tmp, d->tmp) - pow(d->obj->radius, 2);
	delta = pow(b, 2) - 4 * a * c;
	if (delta >= 0)
	{
		res1 = (-b - sqrt(delta)) / (2 * a);
		res2 = (-b + sqrt(delta)) / (2 * a);
		if (res1 > res2 && res1 < d->result)
			return (res1);
		if (res2 < d->result)
			return (res2);
	}
	return (0);
}

void	ft_raytrace(t_data *d)
{
	int		i;
	int		j;
	double	lambert;
	int		red;
	int		green;
	int		blue;
	int		color;
	double	dist;

	i = 0;
	j = 0;
	while(j < SIZE_WINY)
	{
		while (i < SIZE_WINX)
		{
			d->target->x = i - (SIZE_WINX / 2);
			d->target->y = j - (SIZE_WINY / 2);
			d->target->z = 0;
			d->ray_dir = ft_vector_substract(d->target, d->origin);
			d->ray_dir = ft_vect_normalize(d->ray_dir);
			d->ray->origin = ft_vector_copy(d->origin);
			if ((dist = (ft_insterct_sphere(d, d->ray_dir))) != 0)
			{
				d->impact->x = d->ray->origin->x + d->ray_dir->x * dist;
				d->impact->y = d->ray->origin->y + d->ray_dir->y * dist;
				d->impact->z = d->ray->origin->z + d->ray_dir->z * dist;
				d->distance->x = d->impact->x - d->obj->x;
				d->distance->y = d->impact->y - d->obj->y;
				d->distance->z = d->impact->z - d->obj->z;
				d->distance = ft_vect_normalize(d->distance);

				d->light_vec->x = d->light->x - d->impact->x;
				d->light_vec->y = d->light->y - d->impact->y;
				d->light_vec->z = d->light->z - d->impact->z;
				d->light_vec = ft_vect_normalize(d->light_vec);
				lambert = ft_vector_dot(d->light_vec, d->distance);
				red = 150;
				green = 0;
				blue = 0;
				red += red * lambert;
				blue += blue * lambert;
				green += green * lambert;
				if (red < 0)
					red = 0;
				if (green < 0)
					green = 0;
				if (blue < 0)
					blue = 0;
				if (red > 0xFF)
					red = 0xFF;
				if (green > 0xFF)
					green = 0xFF;
				if (blue > 0xFF)
					blue = 0xFF;
				color = (red << 16) + (green << 8) + (blue);
				ft_put_pixel_to_img(d, i, j, (color));
			}
			else
				ft_put_pixel_to_img(d, i, j, 0xFFFFFF);
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
}
