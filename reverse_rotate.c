/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 17:01:02 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/12 17:16:03 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	reverse_rotate(t_stack **head, t_stack **tail)
{
	t_stack	*first;
	t_stack	*bf_last;
	t_stack	*last;
	
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = (*head);
	bf_last = (*tail)->previous;
	last = (*tail);
	last->next = first;
	last->previous = NULL;
	bf_last->next = NULL;
	first->previous = last;
	*head = last;
	*tail = bf_last;
}

void	reverse_rotate_a(t_stack **head_a, t_stack **tail_a)
{
	reverse_rotate(head_a, tail_a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **head_b, t_stack **tail_b)
{
	reverse_rotate(head_b, tail_b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack **head_a, t_stack **head_b, t_stack **tail_a, t_stack **tail_b)
{
	reverse_rotate(head_a, tail_a);
	reverse_rotate(head_b, tail_b);
	write(1, "rrr\n", 4);
}
