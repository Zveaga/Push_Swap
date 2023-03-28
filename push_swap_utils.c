/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 17:37:57 by raanghel      #+#    #+#                 */
/*   Updated: 2023/03/28 16:51:52 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
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

node_t	*create_node(int value)
{
	node_t *new_node;

	new_node = malloc(sizeof(node_t));
	if (new_node == NULL)
		return (NULL);
	new_node->data = value;
	new_node->previous = NULL;
	new_node->next = NULL;
	return (new_node);
}

// void	insert_front(node_t **head, int value)
// {
// 	node_t *new_node;
	
// 	new_node = create_node(value);
// 	if (new_node == NULL)
// 		return ;
// 	new_node->data = value;
// 	new_node->next = *head;
// 	*head = new_node;
// }

void	insert_front(node_t **head, int value)
{
	node_t *new_node;
	
	new_node = create_node(value);
	if (new_node == NULL)
		return ;
	new_node->data = value;
	new_node->next = *head;
	if (*head != NULL)
		(*head)->previous = new_node;
	*head = new_node;
}

// void	insert_end(node_t **head, int value)
// {
// 	node_t *new_node;
// 	node_t *tracker;

// 	new_node = create_node(value);
// 	if (new_node == NULL)
// 		return ;
// 	if (*head ==  NULL)
// 	{
// 		*head = new_node;
// 		return ;
// 	}
// 	tracker = *head;
// 	while (tracker->next != NULL)
// 		tracker = tracker->next;
// 	tracker->next = new_node;
// 	new_node->next = NULL;
// }

void insert_end(node_t **tail, int value)
{
	node_t	*new_node;

	new_node = create_node(value);
	if (new_node == NULL)
		return ;
	if (*tail == NULL)
	{
		*tail = new_node;
		return ;
	}
	new_node->data = value;
	new_node->previous = *tail;
	new_node->next = NULL;
	(*tail)->next = new_node;
	*tail = new_node;
	
}