/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:09:28 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/19 12:40:54 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_sa(t_stack **list_a)
{
	swap_stack(list_a);
	ft_printf("sa\n");
}

void	cmd_pa(t_stack **list_a, t_stack **list_b)
{
	push_stack(list_b, list_a);
	ft_printf("pa\n");
}

void	cmd_ra(t_stack **list_a)
{
	rotato_stack(list_a);
	ft_printf("ra\n");
}

void	cmd_rra(t_stack **list_a)
{
	reverse_rotato_stack(list_a);
	ft_printf("rra\n");
}
