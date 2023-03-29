/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 15:09:05 by raanghel      #+#    #+#                 */
/*   Updated: 2023/03/29 17:21:41 by raanghel      ########   odam.nl         */
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

void	print_reversed(node_t *tail)
{
	node_t	*tracker;

	printf("Reversed print: ");
	tracker = tail;
	while (tracker != NULL)
	{
		printf("%d", tracker->data);
		tracker = tracker->previous;
	}
	printf("\n");
}
void	print_normal(node_t *head)
{
	node_t	*tracker;

	printf("Normal print:   ");
	tracker = head;
	while (tracker != NULL)
	{
		printf("%d", tracker->data);
		tracker = tracker->next;
	}
	printf("\n");
}

node_t *get_to_tail(node_t *head)
{
	node_t	*tracker;
	
	if (head == NULL)
		return (NULL);
	tracker = head;
	while (tracker->next != NULL)
		tracker = tracker->next;
	return (tracker);
}
void	init(node_t **head, node_t **tail, int value)
{
	node_t	*new_node;
	
	new_node = create_node(value);
	if (new_node == NULL)
		return ;
	new_node->data = value;
	new_node->previous = NULL;
	new_node->next = NULL;
	*head = new_node;
	*tail = new_node;
}

int	main (int argc, char **argv)
{
	int	i;
	stacks_t stacks;

	i = 1;
	stacks.a_head = NULL;
	stacks.a_tail = NULL;
	stacks.b_head = NULL;
	stacks.b_tail = NULL;

	if (argc < 2)
	{
		printf("Invalid argument count!");
		exit(EXIT_FAILURE);
	}
	init(&stacks.a_head, &stacks.a_tail, atoi(argv[1]));
	while (i++ < argc - 1)
		insert_end(&stacks.a_tail, atoi(argv[i]));
		
	stacks.a_tail = get_to_tail(stacks.a_head);
	stacks.b_tail = get_to_tail(stacks.b_head);

	printf("Stack_a head: %d\n", stacks.a_head->data);
	printf("Stack_a tail: %d\n", stacks.a_tail->data);

	// ---swap---
	//sa(&stacks.a_head);
	pa(&stacks.a_head, &stacks.b_head);
	pb(&stacks.a_head, &stacks.b_head);


	//-print- REMOVE BEFORE SUBMISSION!!!
	print_normal(stacks.a_head);
	print_normal(stacks.b_head);
	//print_reversed(stacks.a_tail);
	return (0);
}


