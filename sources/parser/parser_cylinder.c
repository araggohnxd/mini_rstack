/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:01:39 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/08 17:37:07 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

#define ERR_CYL_MALLOC_FAIL "Unable to allocate memory for cylinder."
#define ERR_CYL_LINKED_LIST "Unable to allocate memory for cylinder list node."
#define ERR_CYL_BAD_CONFIGS "Invalid cylinder configuration."
#define ERR_CYL_COORD_SETTN "Invalid cylinder coordinates settings."
#define ERR_CYL_COORD_VALUE "Invalid cylinder coordinates value."
#define ERR_CYL_DMTER_VALUE "Invalid cylinder diameter value."
#define ERR_CYL_DMTER_RANGE "Cylinder diameter value must be greater than 0."
#define ERR_CYL_HEIGHT_VALUE "Invalid cylinder height value."
#define ERR_CYL_HEIGHT_RANGE "Cylinder height value must be greater than 0."

static void	set_cylinder_transformation(t_shape *cyl)
{
	t_matrix	trans;
	t_matrix	rotat;
	t_matrix	scale;
	t_matrix	final;

	trans = translate_matrix(
			cyl->cylinder.position.x,
			cyl->cylinder.position.y,
			cyl->cylinder.position.z);
	rotat = full_rotation_matrix(cyl->orientation);
	scale = scale_matrix(cyl->cylinder.diameter, 1, cyl->cylinder.diameter);
	final = mul_matrix(mul_matrix(trans, rotat), scale);
	set_shape_transformation(cyl, final);
}

static int	set_cylinder_height(char *token, t_shape *cyl)
{
	double	height;
	double	half;

	if (!ft_isfloat(token))
		return (error(ERR_CYL_HEIGHT_VALUE));
	height = ft_atof(token);
	if (height <= 0)
		return (error(ERR_CYL_HEIGHT_RANGE));
	half = height / 2;
	cyl->cylinder.min = -half;
	cyl->cylinder.max = half;
	return (0);
}

static int	set_cylinder_diameter(char *token, t_shape *cyl)
{
	if (!ft_isfloat(token))
		return (error(ERR_CYL_DMTER_VALUE));
	cyl->cylinder.diameter = ft_atof(token);
	if (cyl->cylinder.diameter <= 0)
		return (error(ERR_CYL_DMTER_RANGE));
	cyl->cylinder.diameter /= 2;
	return (0);
}

static int	set_cylinder_coordinates(char *token, t_shape *cyl)
{
	char	**coord;

	coord = ft_split(token, ',');
	if (!coord || ft_splitsize(coord) != 3)
		return (ft_free_matrix((void *)&coord), error(ERR_CYL_COORD_SETTN));
	if (!ft_isfloat(coord[0]) || !ft_isfloat(coord[1]) || !ft_isfloat(coord[2]))
		return (ft_free_matrix((void *)&coord), error(ERR_CYL_COORD_VALUE));
	cyl->cylinder.position = \
	create_point(ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	ft_free_matrix((void *)&coord);
	return (0);
}

int	parse_cylinder(char **tokens, t_rt_scene *s)
{
	const size_t	splitsize = ft_splitsize(tokens);
	t_shape			*cylinder;

	if (splitsize < 6 || splitsize > 8)
		return (error(ERR_CYL_BAD_CONFIGS));
	cylinder = create_cylinder();
	if (!cylinder)
		return (error(ERR_CYL_MALLOC_FAIL));
	if (set_cylinder_coordinates(tokens[1], cylinder) != 0)
		return (free(cylinder), -1);
	if (set_shape_orientation_vector(tokens[2], cylinder) != 0)
		return (free(cylinder), -1);
	if (set_cylinder_diameter(tokens[3], cylinder) != 0)
		return (free(cylinder), -1);
	if (set_cylinder_height(tokens[4], cylinder) != 0)
		return (free(cylinder), -1);
	if (set_shape_color(tokens[5], cylinder) != 0)
		return (free(cylinder), -1);
	set_cylinder_transformation(cylinder);
	if (set_shape_checkerboard(tokens, cylinder, 6) != 0)
		return (free(cylinder), -1);
	if (set_shape_linked_list_node(cylinder, s) != 0)
		return (free(cylinder), -1);
	return (0);
}
