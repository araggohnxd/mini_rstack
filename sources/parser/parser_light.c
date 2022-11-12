/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:39:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 15:11:29 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	set_light_color(char *token, t_lgt_point *lp, t_rt_scene *s)
{
	char	**rgb;
	double	aux[3];
	t_color	tmp;

	rgb = ft_split(token, ',');
	if (!rgb || ft_splitsize(rgb) != 3)
		return (ft_free_matrix((void *)&rgb), error(ERR_LGT_COLOR_SETTN));
	if (!ft_isnumber(rgb[0]) || !ft_isnumber(rgb[1]) || !ft_isnumber(rgb[2]))
		return (ft_free_matrix((void *)&rgb), error(ERR_LGT_COLOR_VALUE));
	aux[0] = ft_atoi(rgb[0]);
	aux[1] = ft_atoi(rgb[1]);
	aux[2] = ft_atoi(rgb[2]);
	ft_free_matrix((void *)&rgb);
	if (check_rgb_values(aux[0], aux[1], aux[2]) != 0)
		return (error(ERR_LGT_COLOR_RANGE));
	tmp = create_formatted_color(aux[0], aux[1], aux[2]);
	lp->intensity = smul_color(tmp, s->brightness);
	return (0);
}

static int	set_light_brightness(char *token, t_rt_scene *s)
{
	if (!ft_isfloat(token))
		return (error(ERR_LGT_BRGHT_VALUE));
	s->brightness = ft_atof(token);
	if (!ft_isinrange_f(s->brightness, 0, 1))
		return (error(ERR_LGT_BRGHT_RANGE));
	return (0);
}

static int	set_light_point_coordinates(char *token, t_lgt_point *lp)
{
	char	**coord;

	coord = ft_split(token, ',');
	if (!coord || ft_splitsize(coord) != 3)
		return (ft_free_matrix((void *)&coord), error(ERR_LGT_POINT_SETTN));
	if (!ft_isfloat(coord[0]) || !ft_isfloat(coord[1]) || !ft_isfloat(coord[2]))
		return (ft_free_matrix((void *)&coord), error(ERR_LGT_POINT_VALUE));
	lp->position = \
	create_point(ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	ft_free_matrix((void *)&coord);
	return (0);
}

int	parse_light(char **tokens, t_rt_scene *s)
{
	t_lgt_point	*light_point;
	t_list		*node;

	if (ft_splitsize(tokens) != 4)
		return (error(ERR_LGT_BAD_CONFIGS));
	light_point = \
	create_light_point(create_point(0, 0, 0), create_color(0, 0, 0));
	if (!light_point)
		return (error(ERR_LGT_MALLOC_FAIL));
	if (set_light_point_coordinates(tokens[1], light_point) != 0)
		return (free(light_point), -1);
	if (set_light_brightness(tokens[2], s) != 0)
		return (free(light_point), -1);
	if (set_light_color(tokens[3], light_point, s) != 0)
		return (free(light_point), -1);
	node = ft_lstnew(light_point);
	if (!node)
		return (free(light_point), error(ERR_LGT_LINKED_LIST));
	ft_lstadd_front(&s->lights, node);
	return (0);
}
