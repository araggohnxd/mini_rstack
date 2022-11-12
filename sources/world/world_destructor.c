/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_destructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:47:36 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 14:22:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	destroy_world(t_world *w)
{
	ft_lstclear(&w->lights, free);
	ft_lstclear(&w->shapes, destroy_shape);
}
