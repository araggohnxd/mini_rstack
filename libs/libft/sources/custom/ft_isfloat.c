/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:48:36 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/08 01:39:43 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	check_start(const char *str, size_t *index, t_bool *dot)
{
	if (str[0] == '.' || str[0] == '-' || str[0] == '+')
	{
		if (!str[1])
			return (FALSE);
		if (str[0] == '.')
			*dot = TRUE;
		++(*index);
	}
	return (TRUE);
}

static t_bool	check_dot(const char *str, size_t *index, t_bool *dot)
{
	if (*dot)
		return (FALSE);
	if (!ft_isdigit(str[*index + 1]))
		if (!ft_isdigit(str[*index - 1]))
			return (FALSE);
	++(*index);
	*dot = TRUE;
	return (TRUE);
}

t_bool	ft_isfloat(const char *str)
{
	size_t	index;
	t_bool	dot;

	index = 0;
	dot = FALSE;
	if (!check_start(str, &index, &dot))
		return (FALSE);
	while (str[index])
	{
		if (str[index] == '.')
			if (!check_dot(str, &index, &dot))
				return (FALSE);
		if (str[index] && !ft_isdigit(str[index]))
			return (FALSE);
		if (!str[index])
			break ;
		++index;
	}
	return (TRUE);
}
