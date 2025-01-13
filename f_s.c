/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:25:54 by naorakot          #+#    #+#             */
/*   Updated: 2024/11/21 02:26:00 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

void	sa_2(t_main *s)
{
	if (cmpstr("sb", s->last) == 0)
	{
		write(1, "ss\n", 3);
		s->last = NULL;
	}
	else
	{
		print(s->last);
		s->last = "sa";
	}
}

void	sa(t_main *s)
{
	t_lst	*back;
	t_lst	*next;
	t_lst	*tmp;

	back = s->a->back;
	next = s->a->next->next;
	tmp = s->a;
	s->a = s->a->next;
	if (next != tmp && s->a != tmp)
	{
		tmp->back = s->a;
		tmp->next = next;
		s->a->back = back;
		s->a->next = tmp;
		next->back = tmp;
		back->next = s->a;
	}
	sa_2(s);
}

void	sb_2(t_main *s)
{
	if (cmpstr("sa", s->last) == 0)
	{
		write(1, "ss\n", 3);
		s->last = NULL;
	}
	else
	{
		print(s->last);
		s->last = "sb";
	}
}

void	sb(t_main *s)
{
	t_lst	*back;
	t_lst	*next;
	t_lst	*tmp;

	back = s->b->back;
	next = s->b->next->next;
	tmp = s->b;
	s->b = s->b->next;
	if (next != tmp && s->b != tmp)
	{
		tmp->back = s->b;
		tmp->next = next;
		s->b->back = back;
		s->b->next = tmp;
		next->back = tmp;
		back->next = s->b;
	}
	sb_2(s);
}
