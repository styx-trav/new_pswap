/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:46:35 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/13 16:46:37 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

int	semi_ordered(t_lst *lst)
{
	t_lst	*min;

	min = lst_min(lst);
	if (ordered(min))
		return (1);
	return (0);
}

int	ordered(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst->next;
	while (tmp != lst && tmp->n > tmp->back->n)
		tmp = tmp->next;
	if (tmp == lst)
		return (1);
	return (0);
}

void	print(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	if (str)
		write(1, "\n", 1);
}

void	err_msg(void)
{
	write(1, "Error\n", 6);
}

int	check_big(int num, char end, int sign)
{
	if (num < 214748364)
		return (0);
	if (num > 214748364)
		return (1);
	if (end > '7' && sign == 1)
		return (1);
	if (end > '8' && sign == -1)
		return (1);
	return (0);
}
