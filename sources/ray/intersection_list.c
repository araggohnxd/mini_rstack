/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:24:24 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/05 15:51:29 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rstack.h>

t_intersect	*create_intersection(double t, t_shape s)
{
	t_intersect	*intersection;

	intersection = (t_intersect *)malloc(sizeof(t_intersect));
	if (!intersection)
		return (NULL);
	intersection->t = t;
	intersection->s = s;
	intersection->next = NULL;
	return (intersection);
}

void	intersection_sorted_insert(t_intersect **head, t_intersect *new)
{
	t_intersect	*tmp;

	if (!*head || new->t < (*head)->t)
	{
		new->next = *head;
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next && tmp->next->t < new->t)
		tmp = tmp->next;
	new->next = tmp->next;
	tmp->next = new;
}

size_t	intersection_list_size(t_intersect *list)
{
	size_t	size;

	size = 0;
	while (list)
	{
		list = list->next;
		++size;
	}
	return (size);
}

void	intersection_list_clear(t_intersect **list)
{
	t_intersect	*tmp;

	tmp = *list;
	while (tmp)
	{
		tmp = tmp->next;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}
