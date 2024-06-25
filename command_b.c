/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:12:30 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/19 12:40:44 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_sb(t_stack **list_b)
{
	swap_stack(list_b);
	ft_printf("sb\n");
}

void	cmd_pb(t_stack **list_a, t_stack **list_b)
{
	push_stack(list_a, list_b);
	ft_printf("pb\n");
}

void	cmd_rb(t_stack **list_b)
{
	rotato_stack(list_b);
	ft_printf("rb\n");
}

void	cmd_rrb(t_stack **list_b)
{
	reverse_rotato_stack(list_b);
	ft_printf("rrb\n");
}
