/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 16:57:29 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/13 13:15:56 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	b_head_is_null(t_stack **head_a, t_stack **head_b, t_stack **tail_b, t_stack **elem1_b, t_stack **elem2_a, t_stack **elem1_a)
{
		*elem1_b = *elem1_a;
		(*elem2_a)->previous = NULL;
		(*elem1_b)->next = NULL;
		(*elem1_b)->previous = NULL;
		*head_a = *elem2_a;
		*head_b = *elem1_b;
		*tail_b = *elem1_b;
}

void	push(t_stack **head_a, t_stack **head_b, \
			t_stack **tail_a, t_stack **tail_b)
{
	t_stack	*elem1_a;
	t_stack	*elem2_a;
	t_stack	*elem1_b;

	if (*head_a == NULL)
		return ;
	elem1_a = *head_a;
	elem1_b = *head_b;
	if ((*head_a)->next == NULL)
		elem2_a = NULL;
	else
		elem2_a = (*head_a)->next;
	if (elem1_b == NULL)
	{
		b_head_is_null(head_a, head_b, tail_b, &elem1_b, &elem2_a, &elem1_a);
		return ;
	}
	elem1_a->next = elem1_b;
	elem1_b->previous = elem1_a;
	if (elem2_a != NULL)
		elem2_a->previous = NULL;
	else if (elem2_a == NULL)
		*tail_a = NULL;
	*head_a = elem2_a;
	*head_b = elem1_a;
}

void	push_to_b(t_stack **head_a, t_stack **head_b, \
					t_stack **tail_a, t_stack **tail_b)
{
	push(head_a, head_b, tail_a, tail_b);
	write(1, "pb\n", 3);
}

void	push_to_a(t_stack **head_b, t_stack **head_a, \
					t_stack **tail_b, t_stack **tail_a)
{
	push(head_b, head_a, tail_b, tail_a);
	write(1, "pb\n", 3);
}
