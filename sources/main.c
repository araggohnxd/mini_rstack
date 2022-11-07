/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:23:43 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/07 12:52:37 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

int	main(int argc, char **argv)
{
	t_rt_scene	scene;
	t_minirt	rt;

	get_mlx()->mlx = mlx_init();
	if (!get_mlx()->mlx)
		return (error("Unable to create MLX display."), 1);
	if (check_user_input(argc) != 0)
		return (1);
	ft_bzero(&scene, sizeof(t_rt_scene));
	if (read_rt_file(argv[1], &scene) != 0)
		return (destroy_scene(&scene), 1);
	if (scene_to_world(&rt, &scene) != 0)
		return (destroy_minirt(&scene, &rt), 1);
	destroy_minirt(&scene, &rt);
	setup_visual_environment(&rt);
	return (0);
}
