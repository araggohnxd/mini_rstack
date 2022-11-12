/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:17:33 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 14:22:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	destroy_scene(t_rt_scene *scene)
{
	ft_memfree((void *)&scene->camera);
	ft_memfree((void *)&scene->ambient);
	ft_lstclear(&scene->lights, free);
	ft_lstclear(&scene->shapes, destroy_shape);
}

void	destroy_minirt(t_rt_scene *scene, t_minirt *rt)
{
	destroy_world(&rt->world);
	ft_memfree((void *)&scene->camera);
	ft_memfree((void *)&scene->ambient);
}

void	destroy_mlx(void)
{
	mlx_destroy_display(get_mlx()->mlx);
	free(get_mlx()->mlx);
}

void	destroy_shape(void *content)
{
	t_shape	*shape;

	shape = (t_shape *)content;
	if (shape->material.pattern.type == PAT_BUMPMAP)
		destroy_canvas(&shape->material.pattern.canvas);
	free(shape);
}
