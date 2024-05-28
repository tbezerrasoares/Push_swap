/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:41:21 by tbezerra          #+#    #+#             */
/*   Updated: 2024/05/27 19:02:36 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_stack
{
    int	            valeu;
    int	            index;
    struct s_stack	*next;
}	t_stack;

#define ERR_INPUT "Error in input\n"

/*Funtions*/
