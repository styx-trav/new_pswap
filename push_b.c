/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:26:49 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/13 18:22:24 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

void	push_b(t_main *s)
{
	int	move;
	int	i;

	if (s->size_b < 2)
	{
		pa(s);
		return ;
	}
	move = find_b(s);
	i = 0;
	if (move > s->size_b / 2 + s->size_b % 2)
		move = s->size_b - move;
	while (i < move)
	{
		i++;
		if (move > s->size_b / 2 + s->size_b % 2)
			rrb(s);
		else
			rb(s);
	}
	pb(s);
}

int	find_b(t_main *s)
{
	int		move;
	t_lst	*tmp;

	tmp = s->b;
	move = 0;
	while (tmp != s->b->back)
	{
		if (tmp->back->n > s->a->n && tmp->n < s->a->n)
			return (move);
		if (tmp->back->n < tmp->n)
			if (tmp->back->n > s->a->n || tmp->n < s->a->n)
				return (move);
		move++;
		tmp = tmp->next;
	}
	return (move);
}
