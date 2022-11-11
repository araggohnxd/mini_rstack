/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checkers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:46:58 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/10 10:46:29 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

#define ERR_UNDEF_AMB "Undefined ambient."
#define ERR_UNDEF_CAM "Undefined camera."
#define ERR_UNDEF_LGT "At least one light spot is required."
#define ERR_UNDEF_OBJ "At least one object is required."

int	check_user_input(int argc)
{
	if (argc != 2)
	{
		if (argc > 2)
			error("miniRT: too many arguments");
		if (argc < 2)
			error("miniRT: too few arguments");
		error("usage: ./miniRT <map file>.rt");
		return (-1);
	}
	return (0);
}

int	check_file_extension(const char *filename, const char *expected)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension)
		return (-1);
	else if (ft_strcmp(expected, extension) != 0)
		return (-1);
	return (0);
}

int	check_scene_elements(t_rt_scene *s)
{
	int	status;

	status = 0;
	if (!s->ambient)
		status += error(ERR_UNDEF_AMB);
	if (!s->camera)
		status += error(ERR_UNDEF_CAM);
	if (!s->lights)
		status += error(ERR_UNDEF_LGT);
	if (!s->shapes)
		status += error(ERR_UNDEF_OBJ);
	return (status);
}

int	check_vector_normalization(double x, double y, double z)
{
	if (!is_equal_double(1, magnitude(create_vector(x, y, z))))
		return (-1);
	return (0);
}

int	check_rgb_values(double r, double g, double b)
{
	if (!ft_isinrange_f(r, 0, 255) \
	|| !ft_isinrange_f(g, 0, 255) \
	|| !ft_isinrange_f(b, 0, 255))
		return (-1);
	return (0);
}
