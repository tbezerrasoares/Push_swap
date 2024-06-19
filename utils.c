/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:53:46 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/12 14:29:10 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	free(stack);
}

int	is_digit_stack(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

void	free_push_swap(t_stack **list_a, t_stack **list_b, char **argv, int ac)
{
	free_stack(list_a);
	free_stack(list_b);
	if (ac == 2)
		free_ft_split(argv);
}

t_stack	*max_finder(t_stack **list)
{
	t_stack	*temp;
	t_stack	*max;

	temp = *list;
	max = temp;
	while (temp)
	{
		if (temp->value > max->value)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

int	is_repeadt(char *str, t_stack **list_a)
{
	t_stack	*temp;

	temp = *list_a;
	while (temp)
	{
		if (temp->value == ft_atoi(str))
			return (0);
		temp = temp->next;
	}
	return (1);
}
