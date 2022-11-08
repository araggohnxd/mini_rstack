/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_to_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:18:05 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/08 18:21:21 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

static void	setup_camera(t_camera *camera, t_rt_camera c)
{
	t_matrix	transform;
	t_vector	aux;
	t_vector	up;

	if (is_equal_double(1, fabs(c.orientation.y)))
		up = create_vector(1, 0, 0);
	else
	{
		aux = crossp(create_vector(0, 1, 0), c.orientation);
		up = crossp(c.orientation, aux);
	}
	transform = view_transform(c.view_point, c.orientation, up);
	set_camera_transformation(camera, transform);
}

static void	setup_lights(t_list **lights, t_rt_scene *s)
{
	*lights = s->lights;
}

static void	setup_shapes(t_list **shapes, t_rt_scene *s)
{
	t_shape	*current_shape;
	t_list	*shape_list;

	shape_list = s->shapes;
	while (shape_list)
	{
		current_shape = (t_shape *)shape_list->content;
		set_shape_material(current_shape, s);
		shape_list = shape_list->next;
	}
	*shapes = s->shapes;
}

static void	setup_world(t_world *world, t_rt_scene *s)
{
	setup_shapes(&world->shapes, s);
	setup_lights(&world->lights, s);
}

int	scene_to_world(t_minirt *rt, t_rt_scene *s)
{
	rt->world = create_world();
	setup_world(&rt->world, s);
	rt->camera = create_camera(RT_WIDTH, RT_HEIGHT, radians(s->camera->fov));
	setup_camera(&rt->camera, *s->camera);
	if (render(&rt->canvas, rt->camera, rt->world) != 0)
		return (-1);
	rt->window = mlx_new_window(get_mlx()->mlx, RT_WIDTH, RT_HEIGHT, NAME);
	if (!rt->window)
	{
		destroy_canvas(&rt->canvas);
		destroy_mlx();
		return (error("Unable to create MLX window."));
	}
	return (0);
}
