/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:40:37 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/14 16:39:04 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_pos	*ft_vect_normalize(t_pos *vector)
{
	double	length;

	length = sqrt((vector->x * vector->x) + (vector->y * vector->y) +
				(vector->z * vector->z));
	vector->x = vector->x / length;
	vector->y = vector->y / length;
	vector->z = vector->z / length;
	return (vector);
}

t_pos	*ft_vector_scalar(t_pos *a, t_pos *b)
{
	t_pos	*scalar;

	scalar = (t_pos *)malloc(sizeof(t_pos));
	scalar->x = a->x * b->x;
	scalar->y = a->y * b->y;
	scalar->z = a->z * b->z;
	return (scalar);
}

t_pos	*ft_vector_copy(t_pos *vector)
{
	t_pos	*copy;

	copy = (t_pos *)malloc(sizeof(t_pos));
	copy->x = vector->x;
	copy->y = vector->y;
	copy->z = vector->z;
	return (copy);
}

t_pos	*ft_vector_substract(t_pos *a, t_pos *b)
{
	t_pos	*result;

	result = (t_pos *)malloc(sizeof(t_pos));
	result->x = a->x - b->x;
	result->y = a->y - b->y;
	result->z = a->z - b->z;
	return (result);
}
