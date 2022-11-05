/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rstack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:20:57 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 13:01:43 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RSTACK_H
# define MINI_RSTACK_H

# include <internals.h>

/************************************* TUPLE **********************************/

/* Tuple constructors */
t_tuple		create_tuple(double x, double y, double z, double w);
t_point		create_point(double x, double y, double z);
t_vector	create_vector(double x, double y, double z);

/* Tuple checkers */
t_bool		is_equal_double(double a, double b);
t_bool		is_equal_tuple(t_tuple a, t_tuple b);
t_bool		is_vector(t_tuple t);
t_bool		is_point(t_tuple t);
t_bool		is_tuple(t_tuple t);

/* Tuple operations */
t_tuple		sum_tuple(t_tuple a, t_tuple b);
t_tuple		sub_tuple(t_tuple a, t_tuple b);
t_tuple		neg_tuple(t_tuple t);
t_tuple		scalar_multiply_tuple(t_tuple t, double m);
t_tuple		scalar_divide_tuple(t_tuple t, double d);

/* Tuple manipulators */
double		dot_product(t_tuple a, t_tuple b);
double		magnitude(t_tuple t);
t_tuple		normalize(t_tuple t);
t_tuple		cross_product(t_tuple a, t_tuple b);

#endif /* MINI_RSTACK_H */
