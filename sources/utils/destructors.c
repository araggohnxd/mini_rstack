/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:17:33 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/07 12:51:23 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

void	destroy_scene(t_rt_scene *scene)
{
	ft_memfree((void *)&scene->camera);
	ft_memfree((void *)&scene->ambient);
	ft_lstclear(&scene->shapes, free);
	ft_lstclear(&scene->lights, free);
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
