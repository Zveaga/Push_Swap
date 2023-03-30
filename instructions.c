/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 16:18:12 by raanghel      #+#    #+#                 */
/*   Updated: 2023/03/30 18:05:15 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
sa (swap a): Swap the first 2 elements at the top of stack a. 	---DONE---
Do nothing if there is only one or no elements.
               
sb (swap b): Swap the first 2 elements at the top of stack b.	---DONE---
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.	---DONE---

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.		---DONE---

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.		---DONE---

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.
*/

#include"push_swap.h"

void	swap(node_t **head)
{
	node_t	*elem_1;
	node_t	*elem_2;
	node_t	*elem_3;

	if (*head == NULL | (*head)->next == NULL | (*head)->next->next == NULL)
		return ;
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

void	sa(node_t **head_a)
{
	swap(head_a);
}

void	sb(node_t **head_b)
{
	swap(head_b);
}

void	ss(node_t **head_a, node_t **head_b)
{
	swap(head_a);
	swap(head_b);
}

void	b_head_is_null(node_t **head_a, node_t **head_b, node_t **tail_b, node_t **elem1_b, node_t **elem2_a, node_t **elem1_a)
{
		*elem1_b = *elem1_a;
		(*elem2_a)->previous = NULL;
		
		(*elem1_b)->next = NULL;
		(*elem1_b)->previous = NULL;
		
		*head_a = *elem2_a;
		*head_b = *elem1_b;
		*tail_b = *elem1_b;
}

void	push(node_t **head_a, node_t **head_b, node_t **tail_a, node_t **tail_b)
{
	node_t	*elem1_a;
	node_t	*elem2_a;
	node_t	*elem1_b;
	
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
		return;
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

void	pb(node_t **head_a, node_t **head_b, node_t **tail_a, node_t **tail_b)
{
	push(head_a, head_b, tail_a, tail_b);
}

void	pa(node_t **head_b, node_t **head_a, node_t **tail_b, node_t **tail_a)
{
	push(head_b, head_a, tail_b, tail_a);
}

void	rotate(node_t **head, node_t **tail) ///to do: for only 3 elements
{
	node_t	*first;
	node_t	*second;
	node_t	*bf_last;
	node_t	*last;

	if (*head == NULL)
		return ;
	first = (*head);
	second = (*head)->next;
	bf_last = (*tail)->previous;
	last = (*tail);
	
	first->next = NULL;
	first->previous = bf_last;
	
	last->next = second;
	last->previous = NULL;
	
	second->previous = last;
	bf_last->next = first;

	(*head) = last;
	(*tail) = first;
	
}