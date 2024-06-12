/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:41:21 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/12 18:53:10 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

#define ERR_INPUT "Error in input\n"
#define ERR_ARGUMENTS "Error in arguments\n"
#define ERR_STACK "Error in creat stack\n"

/*Funtions Stack*/
t_stack		*ft_stknew(int content, int index);
t_stack		*ft_stklast(t_stack *lst);
void		ft_stkadd_back(t_stack **lst, t_stack *new);
void 		ft_stkadd_front(t_stack **lst, t_stack *new);
int			ft_stksize(t_stack *lst);

/*Funtions Main*/
void		free_stack(t_stack **stack);
void		free_push_swap(t_stack **list_a, t_stack **list_b, char **argv, int ac);
int			is_digit_stack(char *str);
void		big_sort(t_stack **list_a, t_stack **list_b);
int			issorte(t_stack **list_a);
t_stack		*max_finder(t_stack **list);

/*Commands*/
void		swap_stack(t_stack **stack);
void		push_stack(t_stack **list_out, t_stack **list_in);
void		rotato_stack(t_stack **stack);
void		reverse_rotato_stack(t_stack **stack);

/*Commands Stack A*/
void		cmd_sa(t_stack **list_a);
void		cmd_pa(t_stack **list_a, t_stack **list_b);
void		cmd_ra(t_stack **list_a);
void		cmd_rra(t_stack **list_a);

/*Commands Stack B*/
void		cmd_sb(t_stack **list_b);
void		cmd_pb(t_stack **list_a, t_stack **list_b);
void		cmd_rb(t_stack **list_b);
void		cmd_rrb(t_stack **list_b);

/*Commands Stack AB*/
void		cmd_ss(t_stack **list_a , t_stack **list_b);
void		cmd_rr(t_stack **list_a, t_stack **list_b);
void		cmd_rrr(t_stack **list_a, t_stack **list_b);