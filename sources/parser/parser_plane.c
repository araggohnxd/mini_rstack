/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:23:28 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/07 12:36:40 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

#define ERR_PLN_MALLOC_FAIL "Unable to allocate memory for plane."
#define ERR_PLN_LINKED_LIST "Unable to allocate memory for plane list node."
#define ERR_PLN_BAD_CONFIGS "Invalid plane configuration."
#define ERR_PLN_COORD_SETTN "Invalid plane coordinates settings."
#define ERR_PLN_COORD_VALUE "Invalid plane coordinates value."

static void	set_plane_transformation(t_shape *plane)
{
	t_matrix	trans;
	t_matrix	rotat;

	trans = translate_matrix(
			plane->plane.position.x,
			plane->plane.position.y,
			plane->plane.position.z);
	rotat = full_rotation_matrix(plane->orientation);
	set_shape_transformation(plane, multiply_matrix(trans, rotat));
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
	set_plane_transformation(plane);
	if (set_shape_checkerboard(tokens, plane, 4) != 0)
		return (free(plane), -1);
	if (set_shape_linked_list_node(plane, s) != 0)
		return (free(plane), -1);
	return (0);
}
