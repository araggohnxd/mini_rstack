/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:27:05 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 22:33:54 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

static t_vector	reflect(t_vector in, t_vector normal)
{
	t_vector	scalar;
	t_vector	reflection;

	scalar = scalar_multiply_tuple(normal, (dot_product(in, normal) * 2));
	reflection = sub_tuple(in, scalar);
	return (reflection);
}

static t_color	get_specular(t_lgt_attr attr, t_vector lightv, double light_dot)
{
	t_vector	reflectv;
	t_color		specular;
	t_color		aux;
	double		reflect_dot;

	if (light_dot < 0)
		return (create_color(0, 0, 0));
	reflectv = reflect(neg_tuple(lightv), attr.normal);
	reflect_dot = dot_product(reflectv, attr.camera);
	if (reflect_dot <= 0)
		return (create_color(0, 0, 0));
	aux = scalar_multiply_color(attr.lp.intensity, attr.material.specular);
	specular = \
	scalar_multiply_color(aux, pow(reflect_dot, attr.material.shininess));
	return (specular);
}

static t_color	get_diffuse(t_color eff, double light_dot, double m_diffuse)
{
	t_color	aux;
	t_color	diffuse;

	if (light_dot < 0)
		return (create_color(0, 0, 0));
	aux = scalar_multiply_color(eff, m_diffuse);
	diffuse = scalar_multiply_color(aux, light_dot);
	return (diffuse);
}

static t_color	get_lighting(t_lgt_attr attr, t_color eff, t_vector lightv)
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	double	light_dot;

	light_dot = dot_product(lightv, attr.normal);
	ambient = multiply_color(eff, attr.material.ambient);
	diffuse = get_diffuse(eff, light_dot, attr.material.diffuse);
	specular = get_specular(attr, lightv, light_dot);
	return (sum_color(ambient, sum_color(diffuse, specular)));
}

t_color	lighting(t_lgt_attr attr)
{
	t_color		eff;
	t_vector	lightv;

	eff = multiply_color(attr.material.color, attr.lp.intensity);
	if (attr.in_shadow)
		return (multiply_color(eff, attr.material.ambient));
	lightv = normalize(sub_tuple(attr.lp.position, attr.position));
	return (get_lighting(attr, eff, lightv));
}
