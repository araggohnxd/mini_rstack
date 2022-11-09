/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:01:39 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/09 10:09:28 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

#define ERR_CON_MALLOC_FAIL "Unable to allocate memory for cone."
#define ERR_CON_BAD_CONFIGS "Invalid cone configuration."
#define ERR_CON_COORD_SETTN "Invalid cone coordinates settings."
#define ERR_CON_COORD_VALUE "Invalid cone coordinates value."
#define ERR_CON_DMTER_VALUE "Invalid cone diameter value."
#define ERR_CON_DMTER_RANGE "Cone diameter value must be greater than 0."
#define ERR_CON_HEIGHT_VALUE "Invalid cone height value."
#define ERR_CON_HEIGHT_RANGE "cone height value must be greater than 0."

static void	set_cone_transformation(t_shape *cone)
{
	t_matrix	trans;
	t_matrix	rotat;
	t_matrix	scale;
	t_matrix	final;

	trans = translate_matrix(
			cone->cone.position.x,
			cone->cone.position.y,
			cone->cone.position.z);
	rotat = full_rotation_matrix(cone->orientation);
	scale = scale_matrix(cone->cone.diameter, 1, cone->cone.diameter);
	final = mul_matrix(mul_matrix(trans, rotat), scale);
	set_shape_transformation(cone, final);
}

static int	set_cone_height(char *token, t_shape *cone)
{
	double	height;
	double	half;

	if (!ft_isfloat(token))
		return (error(ERR_CON_HEIGHT_VALUE));
	height = ft_atof(token);
	if (height <= 0)
		return (error(ERR_CON_HEIGHT_RANGE));
	half = height / 2;
	cone->cone.min = -half;
	cone->cone.max = half;
	return (0);
}

static int	set_cone_diameter(char *token, t_shape *cone)
{
	if (!ft_isfloat(token))
		return (error(ERR_CON_DMTER_VALUE));
	cone->cone.diameter = ft_atof(token);
	if (cone->cone.diameter <= 0)
		return (error(ERR_CON_DMTER_RANGE));
	return (0);
}

static int	set_cone_coordinates(char *token, t_shape *cone)
{
	char	**coord;

	coord = ft_split(token, ',');
	if (!coord || ft_splitsize(coord) != 3)
		return (ft_free_matrix((void *)&coord), error(ERR_CON_COORD_SETTN));
	if (!ft_isfloat(coord[0]) || !ft_isfloat(coord[1]) || !ft_isfloat(coord[2]))
		return (ft_free_matrix((void *)&coord), error(ERR_CON_COORD_VALUE));
	cone->cone.position = \
	create_point(ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	ft_free_matrix((void *)&coord);
	return (0);
}

int	parse_cone(char **tokens, t_rt_scene *s)
{
	const size_t	splitsize = ft_splitsize(tokens);
	t_shape			*cone;

	if (splitsize < 6 || splitsize > 8)
		return (error(ERR_CON_BAD_CONFIGS));
	cone = create_cone();
	if (!cone)
		return (error(ERR_CON_MALLOC_FAIL));
	if (set_cone_coordinates(tokens[1], cone) != 0)
		return (free(cone), -1);
	if (set_shape_orientation_vector(tokens[2], cone) != 0)
		return (free(cone), -1);
	if (set_cone_diameter(tokens[3], cone) != 0)
		return (free(cone), -1);
	if (set_cone_height(tokens[4], cone) != 0)
		return (free(cone), -1);
	if (set_shape_color(tokens[5], cone) != 0)
		return (free(cone), -1);
	set_cone_transformation(cone);
	if (set_shape_checkerboard(tokens, cone, 6) != 0)
		return (free(cone), -1);
	if (set_shape_linked_list_node(cone, s) != 0)
		return (free(cone), -1);
	return (0);
}
