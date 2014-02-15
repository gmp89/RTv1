/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 12:39:02 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/15 19:48:51 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_sphere(t_data *d)
{
	d->obj->x = 0;
	d->obj->y = 0;
	d->obj->z = 0;
	d->obj->radius = 200;
	d->is_sphere = 1;
	d->result = 20000;
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
