/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 03:37:31 by naorakot          #+#    #+#             */
/*   Updated: 2024/11/21 03:37:39 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

void	disp_tabs(t_main *s)
{
	t_lst	*tmp;
	char	a;
	int		n;

	write(1, "\na:\n", 4);
	if (s->a != NULL)
	{
		tmp = s->a->next;
		n = s->a->n;
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		a = n / 100 + 48;
		write(1, &a, 1);
		a = (n % 100) / 10 + 48;
		write(1, &a, 1);
		a = n % 10 + 48;
		write(1, &a, 1);
		write(1, "\n", 1);
		while (tmp != s->a)
		{
			n = tmp->n;
			if (n < 0)
			{
				write(1, "-", 1);
				n = -n;
			}
			a = n / 100 + 48;
			write(1, &a, 1);
			a = (n % 100) / 10 + 48;
			write(1, &a, 1);
			a = n % 10 + 48;
			write(1, &a, 1);
			write(1, "\n", 1);
			tmp = tmp->next;
		}
	}
	write(1, "b:\n", 3);
	if (s->b != NULL)
	{
		tmp = s->b->next;
		n = s->b->n;
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		a = n / 100 + 48;
		write(1, &a, 1);
		a = (n % 100) / 10 + 48;
		write(1, &a, 1);
		a = n % 10 + 48;
		write(1, &a, 1);
		write(1, "\n", 1);
		while (tmp != s->b)
		{
			n = tmp->n;
			if (n < 0)
			{
				write(1, "-", 1);
				n = -n;
			}
			a = n / 100 + 48;
			write(1, &a, 1);
			a = (n % 100) / 10 + 48;
			write(1, &a, 1);
			a = n % 10 + 48;
			write(1, &a, 1);
			write(1, "\n", 1);
			tmp = tmp->next;
		}
	}
	write(1, "\n", 1);
}
