/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:15:35 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/19 12:44:06 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **list_a, t_stack **list_b)
{
	int		size;

	size = ft_stksize(*list_a);
	if (size-- > 3 && !issorte(list_a))
		cmd_pb(list_a, list_b);
	if (size-- > 3 && !issorte(list_a))
		cmd_pb(list_a, list_b);
	while (size-- > 3 && !issorte(list_a))
	{
		calc_stack_a(*list_a, *list_b);
		goto_a_b(list_a, list_b);
		
	}
	sort_three(list_a);
	while (*list_b)
	{
		calc_stack_b(*list_a, *list_b);
		goto_b_a(list_a, list_b);
	}
	calc_n_median(*list_a);
	top_min(list_a);
}

void	calc_stack_a(t_stack *list_a, t_stack *list_b)
{
	calc_n_median(list_a);
	calc_n_median(list_b);
	target_a(list_a, list_b);
	cost_a(list_a, list_b);
	cheapest(list_a);
}

void	goto_a_b(t_stack **list_a, t_stack **list_b)
{
	t_stack	*cheapest;

	cheapest = cheapest_define(*list_a);
	if (cheapest->above_median && cheapest->target->above_median)
	{
		while (*list_a != cheapest && *list_b != cheapest->target)
			cmd_rr(list_a, list_b);
		calc_n_median(*list_a);
		calc_n_median(*list_b);
	}
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
	{
		while (*list_a != cheapest && *list_b != cheapest->target)
			cmd_rrr(list_a, list_b);
		calc_n_median(*list_a);
		calc_n_median(*list_b);
	}
	push_preparation(list_a, cheapest, 'a');
	push_preparation(list_b, cheapest->target, 'b');
	cmd_pb(list_a, list_b);
}

void	calc_stack_b(t_stack *list_a, t_stack *list_b)
{
	calc_n_median(list_a);
	calc_n_median(list_b);
	target_b(list_a, list_b);
}

void	goto_b_a(t_stack **list_a, t_stack **list_b)
{
	push_preparation(list_a, (*list_b)->target, 'a');
	cmd_pa(list_a, list_b);
}
