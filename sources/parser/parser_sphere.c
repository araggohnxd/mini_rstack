/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:16:40 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/06 16:13:56 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

#define ERR_SPH_MALLOC_FAIL "Unable to allocate memory for sphere."
#define ERR_SPH_LINKED_LIST "Unable to allocate memory for sphere list node."
#define ERR_SPH_BAD_CONFIGS "Invalid sphere configuration."
#define ERR_SPH_CENTR_SETTN "Invalid sphere center coordinates settings."
#define ERR_SPH_CENTR_VALUE "Invalid sphere center coordinates value."
#define ERR_SPH_DMTER_VALUE "Invalid sphere diameter value."
#define ERR_SPH_DMTER_RANGE "Sphere diameter value must be greater than 0."

static void	set_sphere_transformation(t_shape *sphere)
{
	t_matrix	trans;
	t_matrix	scale;

	trans = translate_matrix(
			sphere->sphere.center.x,
			sphere->sphere.center.y,
			sphere->sphere.center.z);
	scale = scale_matrix(
			sphere->sphere.diameter,
			sphere->sphere.diameter,
			sphere->sphere.diameter);
	set_shape_transformation(sphere, multiply_matrix(trans, scale));
}

static int	set_sphere_diameter(char *token, t_shape *sphere)
{
	if (!ft_isfloat(token))
		return (error(ERR_SPH_DMTER_VALUE));
	sphere->sphere.diameter = ft_atof(token);
	if (sphere->sphere.diameter <= 0.0)
		return (error(ERR_SPH_DMTER_RANGE));
	sphere->sphere.diameter /= 2.0;
	return (0);
}

static int	set_sphere_center_coordinates(char *token, t_shape *sphere)
{
	char	**cntr;

	cntr = ft_split(token, ',');
	if (!cntr || ft_splitsize(cntr) != 3)
		return (ft_free_matrix((void *)&cntr), error(ERR_SPH_CENTR_SETTN));
	if (!ft_isfloat(cntr[0]) || !ft_isfloat(cntr[1]) || !ft_isfloat(cntr[2]))
		return (ft_free_matrix((void *)&cntr), error(ERR_SPH_CENTR_VALUE));
	sphere->sphere.center = create_point(
			ft_atof(cntr[0]), ft_atof(cntr[1]), ft_atof(cntr[2]));
	ft_free_matrix((void *)&cntr);
	return (0);
}

int	parse_sphere(char **tokens, t_rt_scene *s)
{
	t_shape	*sphere;
	t_list	*node;

	if (ft_splitsize(tokens) != 4)
		return (error(ERR_SPH_BAD_CONFIGS));
	sphere = create_sphere();
	if (!sphere)
		return (error(ERR_SPH_MALLOC_FAIL));
	if (set_sphere_center_coordinates(tokens[1], sphere) != 0)
		return (free(sphere), -1);
	if (set_sphere_diameter(tokens[2], sphere) != 0)
		return (free(sphere), -1);
	if (set_shape_color(tokens[3], sphere) != 0)
		return (free(sphere), -1);
	set_sphere_transformation(sphere);
	node = ft_lstnew(sphere);
	if (!node)
		return (free(sphere), error(ERR_SPH_LINKED_LIST));
	ft_lstadd_front(&s->shapes, node);
	return (0);
}
