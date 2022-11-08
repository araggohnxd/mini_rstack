/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:48:59 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/08 17:33:59 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

t_tuple	sum_tuple(t_tuple a, t_tuple b)
{
	return (create_tuple((a.x + b.x), (a.y + b.y), (a.z + b.z), (a.w + b.w)));
}

t_tuple	sub_tuple(t_tuple a, t_tuple b)
{
	return (create_tuple((a.x - b.x), (a.y - b.y), (a.z - b.z), (a.w - b.w)));
}

t_tuple	neg_tuple(t_tuple t)
{
	return (create_tuple(-t.x, -t.y, -t.z, -t.w));
}

t_tuple	smul_tuple(t_tuple t, double m)
{
	return (create_tuple((t.x * m), (t.y * m), (t.z * m), (t.w * m)));
}

t_tuple	sdiv_tuple(t_tuple t, double d)
{
	return (create_tuple((t.x / d), (t.y / d), (t.z / d), (t.w / d)));
}
