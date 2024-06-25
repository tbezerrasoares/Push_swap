/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:53:46 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/20 14:26:37 by tbezerra         ###   ########.fr       */
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
	if (ft_atoi_long(str) > 2147483647 || ft_atoi_long(str) < -2147483648)
		return (0);
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

t_stack	*max_finder(t_stack *list)
{
	long	max;
	t_stack	*current;

	if (!list)
		return (NULL);
	max = INT_MIN;
	while (list)
	{
		if (list->value > max)
		{
			max = list->value;
			current = list;
		}
		list = list->next;
	}
	return (current);
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
