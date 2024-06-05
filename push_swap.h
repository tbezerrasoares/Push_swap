/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:41:21 by tbezerra          #+#    #+#             */
/*   Updated: 2024/06/05 18:51:44 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_stack
{
    int	            value;
    int	            index;
    struct s_stack	*next;
}	t_stack;

#define ERR_INPUT "Error in input\n"

/*Funtions*/
t_stack		*ft_stknew(int content, int index);
void		ft_stkadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_stklast(t_stack *lst);