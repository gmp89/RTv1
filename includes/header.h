/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 12:39:46 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/15 19:22:16 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define SIZE_WINX 800
# define SIZE_WINY 800
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define RM ((SIZE_WINX / d->p->y) / 5)
# define N (b->y - a->y)
# define COL ((int)pos->y) / SIZE_BLOCK][((int)pos->x) / SIZE_BLOCK
# define MAX_Z 800
# define FOV 30

# include <mlx.h>
# include <math.h>
# include "libft.h"

/*
**	Struct
*/

typedef struct		s_pos
{
	double			x;
	double			y;
	double			z;
	double			radius;
	struct s_pos	*origin;
	struct s_pos	*dir;
}					t_pos;

typedef struct		s_cam
{
	t_pos			*pos;
	double			rot_x;
	double			rot_y;
	int				foc;
	int				res_x;
	int				res_y;
}					t_cam;

typedef struct		s_data
{
	double			result;
	double			result2;
	int				is_sphere;
	int				i;
	t_cam			*cam;
	void			*mlx;
	void			*win;
	void			*img;
	int				bbp;
	int				sizeline;
	int				endian;
	char			*data;
	t_pos			*co;
	t_pos			*obj;
	t_pos			*origin;
	t_pos			*target;
	t_pos			*ray_dir;
	t_pos			*ray;
	t_pos			*light;
	t_pos			*light_color;
	t_pos			*impact;
	t_pos			*distance;
	t_pos			*ray_light_dist;
	t_pos			*ray_light_dir;
	t_pos			*intensity;
	t_pos			*light_vec;
	t_pos			*tmp;
}					t_data;

/*
**	Prototypes
*/

void	ft_struct_init(t_data *d);
void	ft_init_scene(t_data *d);
/* int		ft_insterct_sphere(t_data *d, t_pos *ray); */
void	ft_raytrace(t_data *d);

/*
**	mlx
*/

void	ft_mlx(t_data *d);
void	ft_put_pixel_to_img(t_data *d, int x, int y, int color);
int		expose_hook(t_data *d);
int		mouse_hook(int button, int x, int y, t_data *d);
int		key_hook(int keycode, t_data *d);

/*
**	Draw
*/

void	ft_draw(t_data *d);
void	ft_trace_line(t_data *d, t_pos *a, t_pos *b, int color);
void	ft_clean(t_data *d);
void	ft_trace_help(t_data *d, t_pos *a, t_pos *b, int color);

/*
**	Vectors Operations
*/

t_pos	*ft_vect_normalize(t_pos *vector);
t_pos	*ft_vector_scalar(t_pos *a, t_pos *b);
t_pos	*ft_vector_copy(t_pos *vector);
t_pos	*ft_vector_substract(t_pos *a, t_pos *b);
double	ft_vector_dot(t_pos *a, t_pos *b);

#endif
