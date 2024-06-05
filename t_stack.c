/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:38:32 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/05 18:49:48 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stknew(int content, int index)
{
	t_stack	*newele;

	newele = (t_stack *)ft_calloc(sizeof(*newele), 1);
	if (!newele)
		return (NULL);
	newele->value = content;
	newele->index = index;
	newele->next = NULL;
	return (newele);
}

t_stack	*ft_stklast(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_stkadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_stklast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}