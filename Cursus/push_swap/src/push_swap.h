/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:21:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/11/04 16:58:39 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_list
{
	int				index;
	int				value;
	int				pos;
	int				cost;
	int				prev;
	char			box;
	struct s_list	*next;
}	t_list;

//Instructions
int				first_step(t_list **a, t_list **b, t_list **c_a, t_list **c_b);
void			sort_three(t_list **x, t_list **c);
int				ft_mov(t_list **x, t_list **y, t_list **c_x, t_list **c_y);
int				ft_last_rotation(t_list **x, t_list **c_x);
int				ft_push_swap(t_list **a, t_list **b);
int				ft_rotate(t_list **list, t_list **c, int a);
int				ft_rot_rot(t_list **x, t_list **y, t_list **c_x, t_list **c_y);
int				ft_rrotate(t_list **list, t_list **c, int a);
int				ft_rrot_rrot(t_list **x, t_list **y, t_list **c_x, \
t_list **c_y);
int				ft_push(t_list **x, t_list **y, t_list **c_x, t_list **c_y);
//Index
int				max_index(t_list *x);
int				min_index(t_list *x);
int				min_cost(t_list *x);
int				min_cost_min_index(t_list *x, int c);
int				ft_size(t_list *list);
//Position
void			position(t_list **list, t_list **c);
int				min(int a, int b);
int				max(int a, int b);
void			ft_prev_pos(t_list **x, int *p);
void			ft_free(t_list **x);
//Utilities
long			ft_atoi(const char *str);
char			**fill_split(char **ssplit, char const *s, char c);
unsigned int	malloc_size(char const *s, char c);
void			*free_split(char **ssplit, int k);
char			**ft_split(char const *s, char c);
//Verify
int				ft_valid_arg(int ac, char **av);
int				initialize_and_validate(int ac, char **av, char ***res);
int				is_invalid_format(const char *arg);
void			ft_first_validation(t_list **a, char **res, int ac, \
char **av);
//Algorithm
char			**ft_creator(int ac, char **av);
t_list			*new_num(int val, int index, int pos, char box);
int				ft_not_alpha(char **res);
int				ft_number(char **res);
void			fill_sort_index_a(t_list **a, char **res, int ac, \
char **av);
t_list			*sort_pos(t_list *list, t_list *list2, t_list *temp);
t_list			*sort_neg(t_list *list, t_list *list2, t_list *temp);
void			sort_index(t_list *list);
int				ft_swap(t_list **list, t_list **c, int a);
int				ft_swap_swap(t_list **x, t_list **y, t_list **c_x, \
t_list **c_y);
void			ft_prep_cost_no_max(t_list *x, t_list *y);
void			ft_prep_cost(t_list *x, t_list *y);
void			ft_cost(t_list *x, t_list *y);
int				ft_mov1_1(t_list **x, int *m);
int				ft_mov1(t_list **x, t_list **y, int *p, int *s);
int				ft_mov2(t_list **x, t_list **y, int *p, int *s);
int				ft_mov3(t_list **x, t_list **y, int *p, int *s);
int				ft_mov4_1(t_list **x, int *m);
int				ft_mov4(t_list **x, t_list **y, int *p, int *s);
int				ft_prep_mov_2(t_list **x, t_list **y);

#endif
