/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:15:35 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/12 18:55:59 by tbezerra         ###   ########.fr       */
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
	
}