/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:45:05 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 14:22:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_world	create_world(void)
{
	t_world	world;

	world.lights = NULL;
	world.shapes = NULL;
	return (world);
}
