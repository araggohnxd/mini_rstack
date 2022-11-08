/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:32:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/08 14:48:03 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isnumber(const char *str)
{
	if (*str == '+' || *str == '-')
		if (!*(++str))
			return (FALSE);
	while (*str)
		if (!ft_isdigit(*str++))
			return (FALSE);
	return (TRUE);
}
