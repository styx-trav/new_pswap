/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:52:33 by naorakot          #+#    #+#             */
/*   Updated: 2025/01/13 16:52:45 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libby.h"

int	count_num(char *str)
{
	int	ct;
	int	i;

	i = 0;
	ct = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			if (i == 0 || str[i - 1] == ' ')
				ct++;
		i++;
	}
	return (ct);
}

int	*fill_tab(int *tab, char *str, int size)
{
	int	i;
	int	j;

	i = size;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] != ' ')
		{
			if (j == 0 || str[j - 1] == ' ')
			{
				j = j + str_to_num_add(&str[j], &tab, i);
				if (j < 0)
				{
					free(tab);
					err_msg();
					return (NULL);
				}
				i++;
			}
		}
		j++;
	}
	return (tab);
}

int	str_to_num_add(char *str, int **tab, int i)
{
	int	j;
	int	sign;
	int	res;

	j = 0;
	sign = 1;
	res = 0;
	if (str[j] == '+' || str[j] == '-')
	{
		if (str[j] == '-')
			sign = -1;
		j++;
	}
	while (str[j] == '0')
		j++;
	j = extended_str_to_num(str, &res, j, sign);
	res = res * sign;
	(*tab)[i] = res;
	return (j);
}

int	extended_str_to_num(char *str, int *res, int j, int sign)
{
	while (str[j] != '\0' && str[j] != ' ')
	{
		if (str[j] < '0' || str[j] > '9')
			return (-1);
		if (j == 9 && check_big(*res, str[j], sign))
			return (-1);
		*res = ((*res) * 10) + str[j] - '0';
		j++;
	}
	return (j);
}
