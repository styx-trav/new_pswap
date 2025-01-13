/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:50:32 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/13 13:42:07 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

void	make_b(t_main *s)
{
	int	move;

	while (!semi_ordered(s->a) && s->size_a > 3)
		push_b(s);
	if (s->size_a == 3)
		small_a(s);
	while (s->b)
	{
		move = find_a(s);
		quick_a(s, move);
		pa(s);
	}
}

t_lst	*lst_min(t_lst *lst)
{
	t_lst	*min;
	t_lst	*end;

	min = lst;
	end = lst;
	lst = lst->next;
	while (lst != end)
	{
		if (lst->n < min->n)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

int	find_a(t_main *s)
{
	t_lst	*end;
	t_lst	*tmp;
	int		move;

	end = s->a->back;
	tmp = s->a;
	move = 0;
	while (tmp != end)
	{
		if (tmp->back->n < s->b->n && s->b->n > tmp->n)
			return (move);
		if (tmp->back->n > tmp->n)
			if (s->b->n > tmp->back->n || s->b->n < tmp->n)
				return (move);
		tmp = tmp->next;
		move++;
	}
	return (move);
}

void	quick_a(t_main *s, int move)
{
	int	i;

	i = 0;
	if (move <= s->size_a / 2 + s->size_a % 2)
	{
		while (i < move)
		{
			i++;
			ra(s);
		}
		return ;
	}
	move = s->size_a - move;
	while (i < move)
	{
		i++;
		rra(s);
	}
}
