/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:34:22 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/13 16:42:57 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

int	main(int argc, char **argv)
{
	int		*tab;
	int		size;
	t_main	*s;

	size = 0;
	tab = tab_check(argv, argc, &size);
	if (!tab)
		return (0);
	s = make_main(tab, size);
	if (!s)
		return (0);
	//disp_tabs(s);
	if (s->size <= 3)
		small_lst(s);
	else
		make_b(s);
	print(s->last);
	//disp_tabs(s);
	s->a->back->next = NULL;
	free_lst(s->a);
	free(s);
	return (0);
}

int	cmpstr(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s2[i] != '\0')
		return (-1);
	return (0);
}
