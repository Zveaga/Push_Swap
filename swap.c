/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:57:40 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/14 18:03:07 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*elem_1;
	t_stack	*elem_2;
	t_stack	*elem_3;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	if ((*head)->next->next == NULL)
	{
		swap_two(head);
		return ;
	}
	elem_1 = *head;
	elem_2 = (*head)->next;
	elem_3 = (*head)->next->next;
	elem_1->previous = elem_2;
	elem_1->next = elem_3;
	elem_2->previous = NULL;
	elem_2->next = elem_1;
	elem_3->previous = elem_1;
	(*head) = elem_2;
}

void	swap_a(t_stack **head)
{
	swap(head);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **head)
{
	swap(head);
	write(1, "sb\n", 3);
}

void	swap_both(t_stack **head_a, t_stack **head_b)
{
	swap(head_a);
	swap(head_b);
	write(1, "ss\n", 3);
}

void	swap_two(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	first = *head;
	second = first->next;
	if (*head == NULL)
		return ;
	first->next = NULL;
	first->previous = second;
	second->next = first;
	second->previous = NULL;
	*head = second;
}
