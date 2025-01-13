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

typedef struct s_rotate
{
	int	rra;
	int	i;
}				t_rotate;

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

//from utils_error.c, secondary error functions
t_lst		*err_msg(void);
int			cmp(char *s1, char *s2);
int			too_big(char *str, char *max);

//from if_small.c, small lists func
void			small_lst(t_main *s);
void			small_a(t_main *s);

//from utils.c, ordered checks
int			ordered(t_lst *lst);
int			semi_ordered(t_lst *lst);

//from utilt_lst.c, create and free structures
t_lst		*create_item(int n, t_lst *back);
void		free_lst(t_lst *head);
int			free_main(t_main *s);

//from end.c, the last calls and a cmp + print combo
t_lst		*lst_min(t_lst *fwd, t_lst *bwd);
void		print(char *str);

//from pushb.c
void	make_b(t_main *s);
void	quick_a(t_main *s, int move);
int	find_a(t_main *s);

#endif
