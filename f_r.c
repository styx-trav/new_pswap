/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_r.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:30:43 by naorakot          #+#    #+#             */
/*   Updated: 2024/11/21 01:30:50 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

void	ra(t_main *s)
{
	s->a = s->a->next;
	if (cmpstr("rb", s->last) == 0)
	{
		write(1, "rr\n", 3);
		s->last = NULL;
	}
	else
	{
		print(s->last);
		s->last = "ra";
	}
}

void	rb(t_main *s)
{
	s->b = s->b->next;
	if (cmpstr("ra", s->last) == 0)
	{
		write(1, "rr\n", 3);
		s->last = NULL;
	}
	else
	{
		print(s->last);
		s->last = "rb";
	}
}
