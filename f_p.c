/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_p.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:29:17 by naorakot          #+#    #+#             */
/*   Updated: 2024/11/21 01:29:23 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

void	pb_pt2(t_main *s, t_lst *tmp)
{
	if (s->b == NULL)
	{
		tmp->next = tmp;
		tmp->back = tmp;
	}
	else
	{
		tmp->back = s->b->back;
		tmp->next = s->b;
		s->b->back->next = tmp;
		s->b->back = tmp;
		if (s->b->next == s->b)
			s->b->next = tmp;
	}
	s->b = tmp;
}

void	pb(t_main *s)
{
	t_lst	*tmp;

	tmp = s->a;
	if (s->a == NULL)
		return ;
	if (s->a->next != s->a)
	{
		s->a = s->a->next;
		s->a->back = tmp->back;
		tmp->back->next = s->a;
	}
	else
		s->a = NULL;
	pb_pt2(s, tmp);
	print(s->last);
	s->last = NULL;
	write(1, "pb\n", 3);
	s->size_b++;
	s->size_a--;
	//disp_tabs(s);
}

void	pa_pt2(t_main *s, t_lst *tmp)
{
	if (s->a == NULL)
	{
		tmp->next = tmp;
		tmp->back = tmp;
	}
	else
	{
		tmp->back = s->a->back;
		tmp->next = s->a;
		s->a->back->next = tmp;
		s->a->back = tmp;
		if (s->a->next == s->a)
			s->a->next = tmp;
	}
	s->a = tmp;
}

void	pa(t_main *s)
{
	t_lst	*tmp;

	tmp = s->b;
	if (s->b)
	{
		if (s->b->next != s->b)
		{
			s->b = s->b->next;
			s->b->back = tmp->back;
			tmp->back->next = s->b;
		}
		else
			s->b = NULL;
	}
	pa_pt2(s, tmp);
	print(s->last);
	s->last = NULL;
	write(1, "pa\n", 3);
	s->size_a++;
	s->size_b--;
	//disp_tabs(s);
}
