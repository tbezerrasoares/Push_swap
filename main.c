/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:09:13 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/26 13:02:23 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	printList(t_stack **list_a, t_stack **list_b)
{
	t_stack *temp = *list_a;
	t_stack *temp2 = *list_b;
	ft_printf("A --- B\n");
	while(temp != NULL)
	{
		ft_printf("%d --- ", temp->value);
		temp = temp->next;
		if (temp2 != NULL)
		{
			ft_printf("%d", temp2->value);
			temp2 = temp2->next;
		}
		ft_printf("\n");
	}
} */

int	issorte(t_stack **list_a)
{
	t_stack	*temp;

	temp = *list_a;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	benning_stack(t_stack **list_a, t_stack **list_b, char **argv, int ac)
{
	t_stack	*new;
	int		index;

	if (ac == 2)
		index = 0;
	else
		index = 1;
	while (argv[index] != NULL)
	{
		if (is_digit_stack(argv[index]) == 0 || is_repeadt(argv[index], list_a)
			== 0)
		{
			ft_putstr_fd(ERR_ARGUMENTS, 2);
			free_push_swap(list_a, list_b, argv, ac);
			return (1);
		}
		new = ft_stknew(ft_atoi(argv[index]), index);
		ft_stkadd_back(list_a, new);
		index++;
	}
	return (0);
}

void	sorte_main(t_stack **list_a, t_stack **list_b)
{
	if (issorte(list_a) == 0)
	{
		if (ft_stksize(*list_a) == 2)
			cmd_sa(list_a);
		else if (ft_stksize(*list_a) == 3)
			sort_three(list_a);
		else
			big_sort(list_a, list_b);
	}
}

char	**in_char(char **av, int ac)
{
	char	**argv;

	if (ac == 2)
		argv = ft_split(av[1], ' ');
	else
		argv = av;
	return (argv);
}

int	main(int ac, char **av)
{
	t_stack	**list_a;
	t_stack	**list_b;
	char	**argv;

	if (ac < 2)
		return (1);
	list_a = (t_stack **)ft_calloc(sizeof(t_stack), 1);
	list_b = (t_stack **)ft_calloc(sizeof(t_stack), 1);
	if ((!list_a) || (!list_b))
	{
		ft_putstr_fd(ERR_STACK, 2);
		return (1);
	}
	argv = in_char(av, ac);
	if (argv[0] == NULL)
	{
		free_push_swap(list_a, list_b, argv, ac);
		ft_putstr_fd(ERR_STACK, 2);
		return (0);
	}
	if (benning_stack(list_a, list_b, argv, ac) == 1)
		return (1);
	sorte_main(list_a, list_b);
	free_push_swap(list_a, list_b, argv, ac);
	return (0);
}
