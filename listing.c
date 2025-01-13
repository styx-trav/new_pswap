/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:18:31 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/13 16:31:38 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

t_main	*make_main(int *tab, int size)
{
	t_main	*s;

	s = (t_main *)malloc(sizeof(t_main));
	if (!s)
		return (NULL);
	s->a = make_lst(tab, size);
	if (!s->a)
	{
		free(s);
		return (NULL);
	}
	s->b = NULL;
	s->last = NULL;
	s->size = size;
	s->size_a = size;
	s->size_b = 0;
	return (s);
}

t_lst	*make_lst(int *tab, int size)
{
	t_lst	*head;
	t_lst	*tmp;
	int		i;

	head = new_lst(tab[0], NULL);
	if (!head)
		return (NULL);
	i = 1;
	tmp = head;
	while (i < size)
	{
		tmp->next = new_lst(tab[i], tmp);
		if (!tmp->next)
			return (free_lst(head));
		tmp = tmp->next;
		i++;
	}
	return (head);
}

t_lst	*new_lst(int n, t_lst *back)
{
	t_lst	*item;

	item = (t_lst *)malloc(sizeof(t_lst));
	if (!item)
		return (NULL);
	item->n = n;
	item->back = back;
	item->next = NULL;
	return (item);
}

t_lst	*free_lst(t_lst *head)
{
	if (head == NULL)
		return (NULL);
	free_lst(head->next);
	free(head);
	return (NULL);
}
