/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:09:13 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/05 18:50:57 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void printList(t_stack* lista, t_stack* listb)
{
	t_stack* temp = lista;
	t_stack* temp2 = listb;
	ft_printf("List A --- List B\n");
	while(temp != NULL)
	{
		ft_printf("%d --------- ", temp->value);
		temp = temp->next;
		if (temp2 != NULL)
		{
			ft_printf("%d", temp2->value);
			temp2 = temp2->next;
		}
		ft_printf("\n");
	}
} */

void printList(t_stack **list_a, t_stack **list_b)
{
	t_stack *temp = *list_a;
	t_stack *temp2 = *list_b;
	ft_printf("List A --- List B\n");
	while(temp != NULL)
	{
		ft_printf("%d --------- ", temp->value);
		temp = temp->next;
		if (temp2 != NULL)
		{
			ft_printf("%d", temp2->value);
			temp2 = temp2->next;
		}
		ft_printf("\n");
	}
}

int main(int ac, char **av)
{
	t_stack	**list_a;
	t_stack	**list_b;
	t_stack	*new;
	char	**argv;
	//int		*value;
	int		index;

	if (ac < 2)
	{
		ft_putstr_fd(ERR_INPUT, 2);
		return (1);
	}
	list_a = (t_stack **)ft_calloc(sizeof(t_stack), 1);
	list_b = (t_stack **)ft_calloc(sizeof(t_stack), 1);
	index = 0;
	if (ac == 2)
		argv = ft_split(av[1], ' ');
	else
	{
		index = 1;
		argv = av;
	}
	while (argv[index] != NULL)
	{
/* 		value = ft_calloc(1, sizeof(int));
		*value = ft_atoi(av[index]); */
		new = ft_stknew(ft_atoi(argv[index]), index);
		ft_stkadd_back(list_a, new);
		//list_a = ft_stknew(value, index);
		index++;
	}
	printList(list_a, list_b);
	return (0);
}
