/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 12:39:02 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/14 21:12:06 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_sphere(t_data *d)
{
	d->obj->x = SIZE_WINX / 2;
	d->obj->y = SIZE_WINY / 2;
	d->obj->z = MAX_Z / 2;
	d->obj->radius = 200;
	d->is_sphere = 1;
}

int		main(void)
{
	t_data	d;

	ft_struct_init(&d);
	set_sphere(&d);
	ft_mlx(&d);
	ft_putstr("\nHello\n");
	return (0);
}
