/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:23:28 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 15:11:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	set_plane_transformation(t_shape *plane)
{
	t_matrix	trans;
	t_matrix	rotat;

	trans = translate_matrix(
			plane->plane.position.x,
			plane->plane.position.y,
			plane->plane.position.z);
	rotat = full_rotation_matrix(plane->orientation);
	set_shape_transformation(plane, mul_matrix(trans, rotat));
}

static int	set_plane_coordinates(char *token, t_shape *plane)
{
	char	**coord;

	coord = ft_split(token, ',');
	if (!coord || ft_splitsize(coord) != 3)
		return (ft_free_matrix((void *)&coord), error(ERR_PLN_COORD_SETTN));
	if (!ft_isfloat(coord[0]) || !ft_isfloat(coord[1]) || !ft_isfloat(coord[2]))
		return (ft_free_matrix((void *)&coord), error(ERR_PLN_COORD_VALUE));
	plane->plane.position = \
	create_point(ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	ft_free_matrix((void *)&coord);
	return (0);
}

int	parse_plane(char **tokens, t_rt_scene *s)
{
	const size_t	splitsize = ft_splitsize(tokens);
	t_shape			*plane;

	if (splitsize < 4 || splitsize > 6)
		return (error(ERR_PLN_BAD_CONFIGS));
	plane = create_plane();
	if (!plane)
		return (error(ERR_PLN_MALLOC_FAIL));
	if (set_plane_coordinates(tokens[1], plane) != 0)
		return (free(plane), -1);
	if (set_shape_orientation_vector(tokens[2], plane) != 0)
		return (free(plane), -1);
	if (set_shape_color(tokens[3], plane) != 0)
		return (free(plane), -1);
	if (set_shape_pattern(tokens, plane, 4) != 0)
		return (free(plane), -1);
	set_plane_transformation(plane);
	if (set_shape_linked_list_node(plane, s) != 0)
		return (destroy_shape(plane), -1);
	return (0);
}
