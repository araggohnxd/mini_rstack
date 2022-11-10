/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:27:05 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/10 10:06:22 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

static t_vector	reflect(t_vector in, t_vector normal)
{
	t_vector	scalar;
	t_vector	reflection;

	scalar = smul_tuple(normal, (dotp(in, normal) * 2));
	reflection = sub_tuple(in, scalar);
	return (reflection);
}

static t_color	get_specular(t_lgt_attr attr, t_vector lightv, double light_dot)
{
	t_vector	reflectv;
	t_color		specular;
	double		reflect_dot;
	double		factor;

	if (light_dot < 0)
		return (create_color(0, 0, 0));
	reflectv = reflect(neg_tuple(lightv), attr.normal);
	reflect_dot = dotp(reflectv, attr.camera);
	if (reflect_dot <= 0)
		return (create_color(0, 0, 0));
	factor = pow(reflect_dot, attr.material.shininess);
	specular = smul_color(attr.lp.intensity, (attr.material.specular * factor));
	return (specular);
}

static t_color	get_diffuse(t_color eff, double light_dot, double m_diffuse)
{
	t_color	diffuse;

	if (light_dot < 0)
		return (create_color(0, 0, 0));
	diffuse = smul_color(eff, light_dot * m_diffuse);
	return (diffuse);
}

static t_color	get_lighting(t_lgt_attr attr, t_color eff, t_vector lightv)
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	double	light_dot;

	light_dot = dotp(lightv, attr.normal);
	ambient = mul_color(eff, attr.material.ambient);
	diffuse = get_diffuse(eff, light_dot, attr.material.diffuse);
	specular = get_specular(attr, lightv, light_dot);
	return (sum_color(ambient, sum_color(diffuse, specular)));
}

t_color	lighting(t_lgt_attr attr)
{
	t_color		eff;
	t_color		color;
	t_vector	lightv;

	if (attr.material.has_pattern)
		color = pattern_at(attr.material.pattern, attr.position, attr.shape);
	else
		color = attr.material.color;
	eff = mul_color(color, attr.lp.intensity);
	if (attr.in_shadow)
		return (mul_color(eff, attr.material.ambient));
	lightv = normalize(sub_tuple(attr.lp.position, attr.position));
	return (get_lighting(attr, eff, lightv));
}
