/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rstack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:20:57 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 16:20:53 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RSTACK_H
# define MINI_RSTACK_H

# include <internals.h>

/************************************ TUPLE ***********************************/

/* Tuple constructors */
t_tuple		create_tuple(double x, double y, double z, double w);
t_point		create_point(double x, double y, double z);
t_vector	create_vector(double x, double y, double z);

/* Tuple checkers */
t_bool		is_equal_double(double a, double b);
t_bool		is_equal_tuple(t_tuple a, t_tuple b);
t_bool		is_vector(t_tuple t);
t_bool		is_point(t_tuple t);
t_bool		is_tuple(t_tuple t);

/* Tuple operations */
t_tuple		sum_tuple(t_tuple a, t_tuple b);
t_tuple		sub_tuple(t_tuple a, t_tuple b);
t_tuple		neg_tuple(t_tuple t);
t_tuple		scalar_multiply_tuple(t_tuple t, double m);
t_tuple		scalar_divide_tuple(t_tuple t, double d);

/* Tuple manipulators */
double		dot_product(t_tuple a, t_tuple b);
double		magnitude(t_tuple t);
t_tuple		normalize(t_tuple t);
t_tuple		cross_product(t_tuple a, t_tuple b);

/************************************ COLOR ***********************************/

/* Color constructors */
t_color		create_color(double r, double g, double b);
t_color		create_formatted_color(double r, double g, double b);

/* Color operations */
t_color		sum_color(t_color a, t_color b);
t_color		sub_color(t_color a, t_color b);
t_color		multiply_color(t_color a, t_color b);
t_color		multiply_color(t_color a, t_color b);

/*********************************** CANVAS ***********************************/

int			create_canvas(t_canvas *c, double height, double width);
void		destroy_canvas(t_canvas *canvas);
void		write_to_canvas(t_canvas *canvas, int x, int y, int color);
int			pixel_at(t_canvas *canvas, int x, int y);

/*********************************** MATRIX ***********************************/

/* Matrix constructors */
t_matrix	create_matrix(size_t size, const double m[MAT_MAX][MAT_MAX]);
t_matrix	create_identity_matrix(void);
t_matrix	create_submatrix(t_matrix m, size_t delrow, size_t delcol);

/* Matrix checkers */
double		determinant(t_matrix m);
double		minor(t_matrix m, size_t row, size_t col);
double		cofactor(t_matrix m, size_t row, size_t col);
t_bool		is_equal_matrix(t_matrix a, t_matrix b);

/* Matrix operations */
t_matrix	multiply_matrix(t_matrix a, t_matrix b);
t_tuple		multiply_matrix_tuple(t_matrix m, t_tuple t);
t_matrix	transpose_matrix(t_matrix m);
t_matrix	inverse_matrix(t_matrix m);

/* Matrix transformations */
t_matrix	translate_matrix(double x, double y, double z);
t_matrix	scale_matrix(double x, double y, double z);
t_matrix	rotate_matrix_x(double r);
t_matrix	rotate_matrix_y(double r);
t_matrix	rotate_matrix_z(double r);

/************************************* RAY ************************************/

/* Ray constructor */
t_ray		create_ray(t_point origin, t_vector direction);
t_ray		transform_ray(t_ray r, t_matrix m);

/* Ray operations */
t_point		get_position(t_ray r, double t);
t_intersect	*get_hit(t_intersect *xs);

/* Intersection list handlers */
t_intersect	*create_intersection(double t, t_shape s);
void		intersection_sorted_insert(t_intersect **head, t_intersect *new);
void		intersection_list_clear(t_intersect **list);
size_t		intersection_list_size(t_intersect *list);

/************************************ SHAPE ***********************************/

/* Shape constructors */
t_shape		create_shape(void);
t_shape		create_sphere(void);

/* Shape setters */
void		set_shape_transformation(t_shape *s, t_matrix transformation);

/* Shape intersections */
void		intersect_sphere(t_shape s, t_ray r, t_intersect **head);

#endif /* MINI_RSTACK_H */
