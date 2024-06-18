/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:23:46 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/18 22:59:52 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_n_median(t_stack *list_a)
{
	int		i;
	int		median;

	i = 0;
	if (!list_a)
		return ;
	median = ft_stksize(list_a) / 2;
	while (list_a)
	{
		if (i <= median)
			list_a->above_median = true;
		else
			list_a->above_median = false;
		list_a = list_a->next;
		i++;
	}
}

void	target_a(t_stack *list_a, t_stack *list_b)
{
	t_stack	*now_stack_b;
	t_stack	*target_stack;
	int		best;

	while (list_a)
	{
		best = INT_MIN;
		now_stack_b = list_b;
		while (now_stack_b)
		{
			if (now_stack_b->value > best && now_stack_b->value < list_a->value)
			{
				best = now_stack_b->value;
				target_stack = now_stack_b;
			}
			now_stack_b = now_stack_b->next;
		}
	}
	if (best == INT_MIN)
		list_a->target = max_finder(&list_b);
	else
		list_a->target = target_stack;
	list_a = list_a->next;
}

void	cost_a(t_stack *list_a, t_stack *list_b)
{
	int		size_a;
	int		size_b;

	size_a = ft_stksize(list_a);
	size_b = ft_stksize(list_b);
	while (list_a)
	{
		list_a->push_cost = list_a->index;
		if (!(list_a->above_median))
			list_a->push_cost = size_a - (list_a->index);
		if (list_a->target->above_median)
			list_a->push_cost += list_a->target->index;
		else
			list_a->push_cost += size_b - (list_a->target->index);
		list_a = list_a->next;
	}
}

void	cheapest(t_stack *list)
{
	t_stack	*cheapest_stack;
	int		cost_cheapest;

	if (!list)
		return ;
	cost_cheapest = INT_MAX;
	while (list)
	{
		if (list->push_cost < cost_cheapest)
		{
			cost_cheapest = list->push_cost;
			cheapest_stack = list;
		}
		list = list->next;
	}
	cheapest_stack->cheapest = true;
}

void	push_preparation(t_stack **list, t_stack *stack_point, char stack_name)
{
	while (list != stack_point)
	{
		if (stack_name == 'a')
		{
			if (stack_point->above_median)
				cmd_ra(list);
			else
				cmd_rra(list);
		}
		if (stack_name == 'b')
		{
			if (stack_point->above_median)
				cmd_rb(list);
			else
				cmd_rrb(list);
		}
	}
}
