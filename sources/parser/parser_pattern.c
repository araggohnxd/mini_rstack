/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:59:33 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 15:11:37 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	set_shape_bump_map(char **tokens, t_shape *shape, int offset)
{
	t_pattern	bump_map;
	char		*filename;

	if (!tokens[offset + 1])
		return (error(ERR_PAT_BUMPMAP_NOXPM));
	if (check_file_extension(tokens[offset + 1], ".xpm") != 0)
		return (error(ERR_PAT_BUMPMAP_NOEXT));
	filename = tokens[offset + 1];
	bump_map.canvas.image = mlx_xpm_file_to_image(
			get_mlx()->mlx, filename, &bump_map.width, &bump_map.height);
	if (!bump_map.canvas.image)
		return (error(ERR_PAT_BUMPMAP_IMAGE));
	bump_map.canvas.address = mlx_get_data_addr(
			bump_map.canvas.image,
			&bump_map.canvas.bits_per_pixel,
			&bump_map.canvas.line_length,
			&bump_map.canvas.endianness);
	shape->material.specular = 0;
	shape->material.pattern = bump_map;
	shape->material.pattern.type = PAT_BUMPMAP;
	return (0);
}

static void	set_shape_checkerboard_size(t_shape *shape)
{
	if (shape->type == ID_CYLINDER)
		shape->material.pattern.width *= shape->cylinder.diameter * 2;
	else if (shape->type == ID_CONE)
		shape->material.pattern.width *= shape->cone.diameter * 3;
}

static int	set_shape_checkerboard(char **tokens, t_shape *shape, int offset)
{
	char	**rgb;
	int		aux[3];
	t_color	color;

	if (!tokens[offset + 1])
		return (error(ERR_PAT_CHECKER_COLOR));
	rgb = ft_split(tokens[offset + 1], ',');
	if (!rgb || ft_splitsize(rgb) != 3)
		return (ft_free_matrix((void *)&rgb), error(ERR_PAT_CHECKER_SETTN));
	if (!ft_isnumber(rgb[0]) || !ft_isnumber(rgb[1]) || !ft_isnumber(rgb[2]))
		return (ft_free_matrix((void *)&rgb), error(ERR_PAT_CHECKER_VALUE));
	aux[0] = ft_atoi(rgb[0]);
	aux[1] = ft_atoi(rgb[1]);
	aux[2] = ft_atoi(rgb[2]);
	ft_free_matrix((void *)&rgb);
	if (check_rgb_values(aux[0], aux[1], aux[2]) != 0)
		return (error(ERR_PAT_CHECKER_RANGE));
	color = create_formatted_color(aux[0], aux[1], aux[2]);
	shape->material.pattern = uv_checkers(
			shape->material.pattern.width,
			shape->material.pattern.height,
			shape->material.color, color);
	shape->material.pattern.type = PAT_CHECKERS;
	set_shape_checkerboard_size(shape);
	return (0);
}

int	set_shape_pattern(char **tokens, t_shape *shape, int offset)
{
	if (!tokens[offset])
		return (0);
	if (ft_strcmp(tokens[offset], "checkerboard") == 0)
		return (set_shape_checkerboard(tokens, shape, offset));
	if (ft_strcmp(tokens[offset], "bumpmap") == 0)
		return (set_shape_bump_map(tokens, shape, offset));
	return (error(ERR_PAT_INVALID_FEAT));
}
