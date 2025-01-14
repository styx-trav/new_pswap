/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:26:38 by naorakot          #+#    #+#             */
/*   Updated: 2024/11/21 02:26:44 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

void	small_a(t_main *s)
{
	t_lst	*lst;

	lst = s->a;
	if (ordered(s->a))
		return ;
	if (lst->n < lst->next->n && lst->n > lst->back->n)
	{
		rra(s);
		small_a(s);
		return ;
	}
	if (lst->n < lst->back->n)
	{
		sa(s);
		small_a(s);
		return ;
	}
	ra(s);
	small_a(s);
}

void	small_lst(t_main *s)
{
	if (s->size == 0 || s->size == 1)
		return ;
	if (s->size == 2)
		if (!ordered(s->a))
			sa(s);
	if (s->size == 3)
		small_a(s);
}
