/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_rr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:32:13 by naorakot          #+#    #+#             */
/*   Updated: 2024/11/21 01:32:20 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

void	rra(t_main *s)
{
	s->a = s->a->back;
	if (cmpstr("rrb", s->last) == 0)
	{
		write(1, "rrr\n", 4);
		s->last = NULL;
	}
	else
	{
		print(s->last);
		s->last = "rra";
	}
}

void	rrb(t_main *s)
{
	s->b = s->b->back;
	if (cmpstr("rra", s->last) == 0)
	{
		write(1, "rrr\n", 4);
		s->last = NULL;
	}
	else
	{
		print(s->last);
		s->last = "rrb";
	}
}
