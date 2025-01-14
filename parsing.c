/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:53:16 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/13 14:30:50 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

int	*tab_check(char **argv, int argc, int *size)
{
	int	*tab;
	int	i;
	int	j;

	tab = make_tab(argv, argc, size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < (*size - 1))
	{
		j = i + 1;
		while (j < (*size))
		{
			if (tab[i] == tab[j])
			{
				free(tab);
				err_msg();
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	*make_tab(char **argv, int argc, int *size)
{
	int	*tab;
	int	i;

	i = 1;
	tab = NULL;
	while (i < argc)
	{
		tab = char_line(tab, argv[i], size);
		if (!tab)
			return (NULL);
		i++;
	}
	return (tab);
}

int	*char_line(int *tab, char *str, int *size)
{
	int	add;

	add = count_num(str);
	if (!add)
	{
		if (tab)
			free(tab);
		return (NULL);
	}
	tab = add_to_tab(tab, *size, add);
	if (!tab)
		return (NULL);
	tab = fill_tab(tab, str, *size);
	*size = *size + add;
	return (tab);
}

int	*add_to_tab(int *tab, int size, int add)
{
	int	i;
	int	*new_tab;

	new_tab = malloc(sizeof(int) * (size + add));
	if (!new_tab)
	{
		free(tab);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		new_tab[i] = tab[i];
		i++;
	}
	while (i < size + add)
	{
		new_tab[i] = 0;
		i++;
	}
	if (tab)
		free(tab);
	return (new_tab);
}
