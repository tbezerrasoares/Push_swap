/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:09:13 by tbezerra          #+#    #+#             */
/*   Updated: 2024/05/27 18:30:27 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printList(t_list* head) 
{
    t_list* temp = head;
    while(temp != NULL) {
        printf("%d -> ", *((int*)temp->content));
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(int ac, char **av)
{
    t_list *list_a;
    t_list *list_b = NULL;;
    int *value;
    int i;
    
    if (ac < 2)
    {
        ft_putstr_fd(ERR_INPUT, 2);
        return (1);
    }
    i = 1;
    while (i < ac)
    {
        value = ft_calloc(1, sizeof(int));
        *value = ft_atoi(av[i++]);
        list_a = ft_lstnew(value);
    }
    ft_printf("List A: ");
    printList(list_a);
    list_b = NULL;
    ft_printf("List B: ");
    printList(list_b);
    return (0);
}
