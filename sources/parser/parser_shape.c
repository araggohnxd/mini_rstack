/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:16:40 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 15:11:45 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	set_shape_linked_list_node(t_shape *shape, t_rt_scene *s)
{
	t_list	*node;

	node = ft_lstnew(shape);
	if (!node)
		return (error(ERR_SHP_LINKED_LIST));
	ft_lstadd_front(&s->shapes, node);
	return (0);
}

int	set_shape_color(char *token, t_shape *shape)
{
	char	**rgb;
	int		aux[3];

	rgb = ft_split(token, ',');
	if (!rgb || ft_splitsize(rgb) != 3)
		return (ft_free_matrix((void *)&rgb), error(ERR_SHP_COLOR_SETTN));
	if (!ft_isnumber(rgb[0]) || !ft_isnumber(rgb[1]) || !ft_isnumber(rgb[2]))
		return (ft_free_matrix((void *)&rgb), error(ERR_SHP_COLOR_VALUE));
	aux[0] = ft_atoi(rgb[0]);
	aux[1] = ft_atoi(rgb[1]);
	aux[2] = ft_atoi(rgb[2]);
	ft_free_matrix((void *)&rgb);
	if (check_rgb_values(aux[0], aux[1], aux[2]) != 0)
		return (error(ERR_SHP_COLOR_RANGE));
	shape->material.color = create_formatted_color(aux[0], aux[1], aux[2]);
	return (0);
}

int	set_shape_orientation_vector(char *token, t_shape *shape)
{
	char	**vect;
	double	aux[3];

	vect = ft_split(token, ',');
	if (!vect || ft_splitsize(vect) != 3)
		return (ft_free_matrix((void *)&vect), error(ERR_SHP_OVECT_SETTN));
	if (!ft_isfloat(vect[0]) || !ft_isfloat(vect[1]) || !ft_isfloat(vect[2]))
		return (ft_free_matrix((void *)&vect), error(ERR_SHP_OVECT_VALUE));
	aux[0] = ft_atof(vect[0]);
	aux[1] = ft_atof(vect[1]);
	aux[2] = ft_atof(vect[2]);
	ft_free_matrix((void *)&vect);
	if (!ft_isinrange_f(aux[0], -1, 1) \
	|| !ft_isinrange_f(aux[1], -1, 1) \
	|| !ft_isinrange_f(aux[2], -1, 1))
		return (error(ERR_SHP_OVECT_RANGE));
	if (check_vector_normalization(aux[0], aux[1], aux[2]) != 0)
		return (error(ERR_SHP_NOT_NORMALIZED));
	shape->orientation = create_vector(aux[0], aux[1], aux[2]);
	return (0);
}
