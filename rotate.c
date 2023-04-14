/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:59:39 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/14 16:17:12 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rotate(t_stack **head, t_stack **tail)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = (*head);
	last = (*tail);
	second = (*head)->next;
	first->next = NULL;
	first->previous = last;
	last->next = first;
	second->previous = NULL;
	(*head) = second;
	(*tail) = first;
}

void	rotate_a(t_stack **head_a, t_stack **tail_a)
{
	rotate(head_a, tail_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **head_b, t_stack **tail_b)
{
	rotate(head_b, tail_b);
	write(1, "rb\n", 3);
}

void	rotate_both(t_stack **head_a, t_stack **head_b,
	t_stack **tail_a, t_stack **tail_b)
{
	rotate(head_a, tail_b);
	rotate(head_b, tail_a);
	write(1, "rr\n", 3);
}
