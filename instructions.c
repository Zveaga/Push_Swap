/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 16:18:12 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/04 14:40:36 by rares         ########   odam.nl         */
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
The first element becomes the last one.			---DONE---

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.			---DONE---

rr : ra and rb at the same time.		---DONE---

rra (reverse rotate a): Shift down all elements of stack a by 1.		---DONE---
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.		---DONE---
The last element becomes the first one.

rrr : rra and rrb at the same time.			---DONE---
*/

#include"push_swap.h"

void	swap(node_t **head)
{
	node_t	*elem_1;
	node_t	*elem_2;
	node_t	*elem_3;

	if (*head == NULL || (*head)->next == NULL || (*head)->next->next == NULL)
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

void	swap_both(node_t **head_a, node_t **head_b)
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

void	swap_two(node_t **head, node_t **tail)
{
	node_t	*first;
	node_t	*last;

	first = *head;
	last = *tail;
	(*head)->next = NULL;
	(*head)->previous = (*tail);
	(*tail)->next = (*head);
	(*tail)->previous = NULL;
	*head = last;
	*tail = first;
}

void	rotate(node_t **head, node_t **tail) ///to do: for only 2 elements
{
	node_t	*first;
	node_t	*second;
	node_t	*last;

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

void	rotate_both(node_t **head_a, node_t **head_b, node_t **tail_a, node_t **tail_b)
{
	rotate(head_a, tail_b);
	rotate(head_b, tail_a);
}

void	reverse_rotate(node_t **head, node_t **tail)
{
	node_t	*first;
	node_t	*bf_last;
	node_t	*last;
	
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

void	reverse_rotate_both(node_t **head_a, node_t **head_b, node_t **tail_a, node_t **tail_b)
{
	reverse_rotate(head_a, tail_a);
	reverse_rotate(head_b, tail_b);
}
