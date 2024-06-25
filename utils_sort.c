/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:51:11 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/25 22:13:23 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*cheapest_define(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list)
	{
		if (list->cheapest == true)
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_stack	*min_finder(t_stack *list)
{
	long	min;
	t_stack	*current;

	if (!list)
		return (NULL);
	min = INT_MAX;
	while (list)
	{
		if (list->value < min)
		{
			min = list->value;
			current = list;
		}
		list = list->next;
	}
	return (current);
}

void	target_b(t_stack *list_a, t_stack *list_b)
{
	t_stack	*now_stack;
	t_stack	*target_stack;
	long	best;

	while (list_b)
	{
		best = INT_MAX;
		now_stack = list_a;
		while (now_stack)
		{
			if (now_stack->value < best && now_stack->value > list_b->value)
			{
				best = now_stack->value;
				target_stack = now_stack;
			}
			now_stack = now_stack->next;
		}
		if (best == INT_MAX)
			list_b->target = min_finder(list_a);
		else
			list_b->target = target_stack;
		list_b = list_b->next;
	}
}

void	top_min(t_stack **list)
{
	while ((*list)->value != min_finder(*list)->value)
	{
		if (min_finder(*list)->above_median)
			cmd_ra(list);
		else
			cmd_rra(list);
	}
}

void	sort_three(t_stack **list_a)
{
	t_stack	*temp;

	temp = max_finder(*list_a);
	if (temp == *list_a)
		cmd_ra(list_a);
	else if ((*list_a)->next == temp)
		cmd_rra(list_a);
	if ((*list_a)->value > (*list_a)->next->value)
		cmd_sa(list_a);
}
