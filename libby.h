/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libby.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naorakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:34:11 by naorakot          #+#    #+#             */
/*   Updated: 2024/11/21 02:34:19 by naorakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBY_H
# define LIBBY_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	int				n;
	int				ll;
	struct s_lst	*next;
	struct s_lst	*back;
}				t_lst;

typedef struct s_main
{
	t_lst	*a;
	t_lst	*b;
	char	*last;
	int		size;
	int		size_a;
	int		size_b;
}				t_main;

//basic functions in f_*.c
void		sa(t_main *s);
void		sb(t_main *s);
void		ra(t_main *s);
void		rb(t_main *s);
void		rra(t_main *s);
void		rrb(t_main *s);
void		pb(t_main *s);
void		pa(t_main *s);

//disp from disp.c, to delete later (dead code) and temporary stuff
void		disp_tabs(t_main *s);

//from if_small.c, small lists func
void		small_lst(t_main *s);
void		small_a(t_main *s);

//from utils.c, ordered checks, print and error messages
int			ordered(t_lst *lst);
int			semi_ordered(t_lst *lst);
void		print(char *str);
void		err_msg(void);
int			check_big(int num, char end, int sign);

//from make_b.c
void		make_b(t_main *s);
void		quick_a(t_main *s, int move);
int			find_a(t_main *s);
t_lst		*lst_min(t_lst *lst);

//from listing.c
t_main		*make_main(int *tab, int size);
t_lst		*make_lst(int *tab, int size);
t_lst		*new_lst(int n, t_lst *back);
t_lst		*free_lst(t_lst *head);

//from parsing.c
int			*tab_check(char **argv, int argc, int *size);
int			*make_tab(char **argv, int argc, int *size);
int			*char_line(int *tab, char *str, int *size);
int			*add_to_tab(int *tab, int size, int add);

//from parsing_2.c
int			count_num(char *str);
int			*fill_tab(int *tab, char *str, int size);
int			str_to_num_add(char *str, int **tab, int i);
int			extended_str_to_num(char *str, int *res, int j, int sign);

//from main.c
int			cmpstr(char *s1, char *s2);

#endif
