/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:22:09 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 16:10:11 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	error(const char *warning)
{
	const size_t	line_number = line_tracker(NULL)->line_number;
	const char		*filename = line_tracker(NULL)->filename;

	if (line_number != 0)
		ft_dprintf(STDERR, ERROR "miniRT: %s: line %d: %s.\n",
			filename, line_number, warning);
	else
		ft_dprintf(STDERR, ERROR "miniRT: %s.\n", warning);
	return (-1);
}
