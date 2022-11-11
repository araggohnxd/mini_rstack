/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rstack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:20:57 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/11 17:30:28 by maolivei         ###   ########.fr       */
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
t_tuple		smul_tuple(t_tuple t, double m);
t_tuple		sdiv_tuple(t_tuple t, double d);

/* Tuple manipulators */
double		dotp(t_tuple a, t_tuple b);
double		magnitude(t_tuple t);
t_tuple		normalize(t_tuple t);
t_tuple		crossp(t_tuple a, t_tuple b);

/************************************ COLOR ***********************************/

/* Color constructors */
t_color		create_color(double r, double g, double b);
t_color		create_formatted_color(double r, double g, double b);

/* Color operations */
t_color		sum_color(t_color a, t_color b);
t_color		sub_color(t_color a, t_color b);
t_color		mul_color(t_color a, t_color b);
t_color		smul_color(t_color a, double m);

/* Color patterns */
t_color		pattern_at(t_point point, t_shape *shape);
t_color		bump_at(t_point point, t_shape *shape);
t_pattern	uv_checkers(double width, double height, t_color a, t_color b);

/* Color mapping */
t_uv		map_sphere(t_point point);
t_uv		map_plane(t_point point);
t_uv		map_cylinder(t_point point);
t_uv		map_cone(t_point point);

/*********************************** CANVAS ***********************************/

/* Canvas operations */
void		write_to_canvas(t_canvas *canvas, int x, int y, int color);
int			pixel_at(t_pattern pattern, int x, int y);

/* Canvas constructor */
int			create_canvas(t_canvas *c, double width, double height);

/* Canvas destructor */
void		destroy_canvas(t_canvas *canvas);

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
t_matrix	mul_matrix(t_matrix a, t_matrix b);
t_tuple		mul_matrix_tuple(t_matrix m, t_tuple t);
t_matrix	transpose_matrix(t_matrix m);
t_matrix	inverse_matrix(t_matrix m);

/* Matrix transformations */
t_matrix	translate_matrix(double x, double y, double z);
t_matrix	scale_matrix(double x, double y, double z);
t_matrix	rotate_matrix_x(double r);
t_matrix	rotate_matrix_y(double r);
t_matrix	rotate_matrix_z(double r);
t_matrix	view_transform(t_point from, t_point to, t_vector up);
t_matrix	full_rotation_matrix(t_vector vector);

/************************************* RAY ************************************/

/* Ray constructor */
t_ray		create_ray(t_point origin, t_vector direction);
t_ray		transform_ray(t_ray r, t_matrix m);

/* Ray operations */
t_point		get_position(t_ray r, double t);
t_intersect	*get_hit(t_intersect *xs);
t_color		shade_hit(t_world world, t_comps comps, t_list *lights);
t_bool		is_shadowed(t_world world, t_point point, t_lgt_point lp);
t_color		color_at(t_world world, t_ray ray);

/* Intersection list handlers */
t_intersect	*create_intersection(double t, t_shape *s);
void		intersection_sorted_insert(t_intersect **head, t_intersect *new);
void		intersection_list_clear(t_intersect **list);
size_t		intersection_list_size(t_intersect *list);

/************************************ SHAPE ***********************************/

/* Shape constructors */
t_shape		*create_shape(void);
t_shape		*create_sphere(void);
t_shape		*create_plane(void);
t_shape		*create_cylinder(void);
t_shape		*create_cone(void);

/* Shape setters */
void		set_shape_transformation(t_shape *s, t_matrix transform);

/* Shape intersections */
void		intersect_sphere(t_shape *sphere, t_ray ray, t_intersect **head);
void		intersect_cylinder(t_shape *cyl, t_ray ray, t_intersect **head);
void		intersect_plane(t_shape *plane, t_ray ray, t_intersect **head);
void		intersect_cone(t_shape *cone, t_ray ray, t_intersect **head);

/* Shape normal */
t_vector	normal_at_sphere(t_shape *sphere, t_point point);
t_vector	normal_at_cylinder(t_shape *cyl, t_point point);
t_vector	normal_at_plane(t_shape *plane, t_point point);
t_vector	normal_at_cone(t_shape *cone, t_point point);

/************************************ LIGHT ***********************************/

/* Light operations */
t_color		lighting(t_lgt_attr attr);

/* Light constructors */
t_material	create_material(void);
t_pos_attr	create_pos_attr(t_vector camera, t_vector normal, t_point pos);
t_lgt_point	*create_light_point(t_point position, t_color intensity);
t_lgt_attr	create_light_attr(t_lgt_point lp, t_pos_attr pos, t_material m);

/************************************ WORLD ***********************************/

/* World operations */
t_vector	normal_at(t_shape *s, t_point p);
t_comps		prepare_computation(t_intersect *i, t_ray ray);
void		intersect_world(t_world world, t_ray ray, t_intersect **head);

/* World constructor */
t_world		create_world(void);

/* World destructor */
void		destroy_world(t_world *w);

/*********************************** CAMERA ***********************************/

/* Camera operations */
t_ray		ray_for_pixel(t_camera camera, double x, double y);
int			render(t_canvas *canvas, t_camera camera, t_world world);

/* Camera constructor */
t_camera	create_camera(double h_size, double v_size, double field_of_view);

/* Camera setter */
void		set_camera_transformation(t_camera *camera, t_matrix transform);

/*********************************** PARSER ***********************************/

/* Paresr handlers */
int			scene_to_world(t_minirt *rt, t_rt_scene *s);
int			read_rt_file(char *filename, t_rt_scene *s);
int			parse_ambient(char **tokens, t_rt_scene *s);
int			parse_camera(char **tokens, t_rt_scene *s);
int			parse_light(char **tokens, t_rt_scene *s);
int			parse_sphere(char **tokens, t_rt_scene *s);
int			parse_plane(char **tokens, t_rt_scene *s);
int			parse_cylinder(char **tokens, t_rt_scene *s);
int			parse_cone(char **tokens, t_rt_scene *s);

/* Parser setters */
int			set_shape_color(char *token, t_shape *shape);
int			set_shape_orientation_vector(char *token, t_shape *shape);
int			set_shape_linked_list_node(t_shape *shape, t_rt_scene *s);
int			set_shape_pattern(char **tokens, t_shape *shape, int offset);

/* Checkers */
int			check_user_input(int argc);
int			check_file_extension(const char *filename, const char *expected);
int			check_scene_elements(t_rt_scene *s);
int			check_rgb_values(double r, double g, double b);
int			check_vector_normalization(double x, double y, double z);

/* Utils */
int			error(const char *warning);
double		radians(double degrees);
void		destroy_shape(void *content);
void		destroy_scene(t_rt_scene *scene);
void		destroy_minirt(t_rt_scene *scene, t_minirt *rt);
void		destroy_mlx(void);

/************************************* MLX ************************************/

/* Setup */
t_mlx		*get_mlx(void);
void		setup_visual_environment(t_minirt *rt);

/* Hooks */
int			end_program(t_minirt *rt);
int			keypress_handler(int keysym, t_minirt *rt);

#endif /* MINI_RSTACK_H */
