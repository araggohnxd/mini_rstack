/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:57:37 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/08 18:04:30 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

void	set_camera_transformation(t_camera *camera, t_matrix transform)
{
	camera->transform = transform;
	camera->inverse_transform = inverse_matrix(transform);
}
