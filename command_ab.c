/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:16:07 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/19 12:44:59 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_ss(t_stack **list_a, t_stack **list_b)
{
	swap_stack(list_a);
	swap_stack(list_b);
	ft_printf("ss\n");
}

void	cmd_rr(t_stack **list_a, t_stack **list_b)
{
	rotato_stack(list_a);
	rotato_stack(list_b);
	ft_printf("rr\n");
}

void	cmd_rrr(t_stack **list_a, t_stack **list_b)
{
	reverse_rotato_stack(list_a);
	reverse_rotato_stack(list_b);
	ft_printf("rrr\n");
}
