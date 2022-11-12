/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_tracker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:18:15 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 15:31:37 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_line	*line_tracker(const char *filename)
{
	static t_line	line_number;

	if (filename)
		line_number.filename = filename;
	return (&line_number);
}
