/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 16:18:12 by raanghel      #+#    #+#                 */
/*   Updated: 2023/03/30 10:59:18 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
sa (swap a): Swap the first 2 elements at the top of stack a. 	---DONE---
Do nothing if there is only one or no elements.
               
sb (swap b): Swap the first 2 elements at the top of stack b.	---DONE---
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.	---DONE---

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

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

void	pa(node_t **head_a, node_t **head_b)
{
	node_t	*elem1_a;
	node_t	*elem1_b;
	node_t	*elem2_b;
	
	if (*head_b == NULL)
		return ;
	elem1_a = *head_a;
	elem1_b = *head_b;
	elem2_b = (*head_b)->next;

	elem1_b->next = elem1_a;
	elem1_b->previous = NULL;
	
	elem1_a->previous = elem1_b;
	
	elem2_b->previous = NULL;

	*head_a = elem1_b;
	*head_b = elem2_b;
}

void	pb(node_t **head_a, node_t **head_b)
{
	node_t	*elem1_a;
	node_t	*elem2_a;
	node_t	*elem1_b;
	
	if (*head_a == NULL)
		return ;
	if (*head_b == NULL)
		*head_b = malloc(sizeof(node_t));
	elem1_a = *head_a;
	elem2_a = (*head_a)->next;
	elem1_b = *head_b;

	elem1_a->next = elem1_b;
	elem1_a->previous = NULL;
	
	elem1_b->previous = elem1_a;

	elem2_a->previous = NULL;

	*head_a = elem2_a;
	*head_b = elem1_a;
}
