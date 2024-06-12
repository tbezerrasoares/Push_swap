/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:19:57 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/12 13:00:01 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;
	t_stack	*temp3;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	temp2 = temp->next;
	temp3 = temp2->next;
	*stack = temp2;
	temp2->next = temp;
	temp->next = temp3;
}

void	push_stack(t_stack **list_out, t_stack **list_in)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*list_out == NULL)
		return;
	temp = *list_out;
	temp2 = temp->next;
	*list_out = temp2;
	temp->next = *list_in;
	*list_in = temp;
}

void	rotato_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	temp2 = ft_stklast(*stack);
	*stack = temp->next;
	temp->next = NULL;
	temp2->next = temp;
}

void	reverse_rotato_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = ft_stklast(*stack);
	temp2 = *stack;
	while (temp2->next != temp)
		temp2 = temp2->next;
	temp2->next = NULL;
	temp->next = *stack;
	*stack = temp;
}