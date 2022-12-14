/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:25:20 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 15:11:06 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	set_ambient_color(char *token, t_rt_scene *s)
{
	char	**rgb;
	int		aux[3];

	rgb = ft_split(token, ',');
	if (!rgb || ft_splitsize(rgb) != 3)
		return (ft_free_matrix((void *)&rgb), error(ERR_AMB_COLOR_SETTN));
	if (!ft_isnumber(rgb[0]) || !ft_isnumber(rgb[1]) || !ft_isnumber(rgb[2]))
		return (ft_free_matrix((void *)&rgb), error(ERR_AMB_COLOR_VALUE));
	aux[0] = ft_atoi(rgb[0]);
	aux[1] = ft_atoi(rgb[1]);
	aux[2] = ft_atoi(rgb[2]);
	ft_free_matrix((void *)&rgb);
	if (check_rgb_values(aux[0], aux[1], aux[2]) != 0)
		return (error(ERR_AMB_COLOR_RANGE));
	s->ambient->color = create_formatted_color(aux[0], aux[1], aux[2]);
	return (0);
}

static int	set_ambient_ratio(char *token, t_rt_scene *s)
{
	if (!ft_isfloat(token))
		return (error(ERR_AMB_RATIO_VALUE));
	s->ambient->ratio = ft_atof(token);
	if (!ft_isinrange_f(s->ambient->ratio, 0, 1))
		return (error(ERR_AMB_RATIO_RANGE));
	return (0);
}

int	parse_ambient(char **tokens, t_rt_scene *s)
{
	if (s->ambient)
		return (error(ERR_AMB_ALREADY_SET));
	if (ft_splitsize(tokens) != 3)
		return (error(ERR_AMB_BAD_CONFIGS));
	s->ambient = (t_rt_ambient *)ft_calloc(1, sizeof(t_rt_ambient));
	if (!s->ambient)
		return (error(ERR_AMB_MALLOC_FAIL));
	if (set_ambient_ratio(tokens[1], s) != 0)
		return (-1);
	if (set_ambient_color(tokens[2], s) != 0)
		return (-1);
	return (0);
}
