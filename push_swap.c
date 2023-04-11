/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 15:09:05 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/11 18:11:05 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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

void	print_reversed(node_t *tail)
{
	node_t	*tracker;

	tracker = tail;
	while (tracker != NULL)
	{
		printf("%d(%d) ", tracker->data, tracker->index);
		tracker = tracker->previous;
	}
	printf("\n");
}

void	print_normal(node_t *head)
{
	node_t	*tracker;

	tracker = head;
	while (tracker != NULL)
	{
		printf("%d(%d) ", tracker->data, tracker->index);
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

void	parse_input(int argc, char **args, node_t **head_a, node_t **tail_a)
{
	int		i;
	char	**argv;
	
	i = 0;
	if (argc == 2)
		argv = ft_split(args[1], ' ');
	else
	{
		i = 1;
		argv = args;
	}
	while (argv[i])
	{
		long	temp;

		temp = ft_atoi(argv[i]);
		if (check_digit(argv[i]) == 0)
			raise_error();
		if (temp < INT_MIN || temp > INT_MAX)
			raise_error();
		if (check_duplicate(argv, i) == 0)
			raise_error();
		insert_end(head_a ,tail_a, ft_atoi(argv[i]));
		i++;
	}
}

void	sorting_selector(node_t **head_a, node_t **head_b, node_t **tail_a, node_t **tail_b)
{
	int	nodes;
	
	nodes = node_count(*head_a);
	printf("nr of nodes: %d\n\n", nodes);
	if (nodes == 3)
		sort_3(head_a, tail_a);
	// else if (nodes == 5)
	// 	sort_5
	else if (is_sorted(*head_a) != 0)
		radix_sort(head_a, head_b, tail_a, tail_b);

	// else
	// free();
	// free();
	
}

int	main (int argc, char **argv)
{
	stacks_t stacks;

	stacks.a_head = NULL;
	stacks.a_tail = NULL;
	stacks.b_head = NULL;
	stacks.b_tail = NULL;
	
	if (argc == 1)
		raise_error();
	parse_input(argc, argv, &stacks.a_head, &stacks.a_tail);
	if (is_sorted(stacks.a_head) == 0)
		exit(EXIT_SUCCESS);
	set_index(stacks.a_head);
	sorting_selector(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);

	stacks.a_tail = get_to_tail(stacks.a_head);
	stacks.b_tail = get_to_tail(stacks.b_head);

	printf("Stack_a head: %d\n", stacks.a_head->data);
	printf("Stack_a tail: %d\n", stacks.a_tail->data);

	//---INSTRUCTIONS---   REMOVE BEFORE SUBMISSION!!!!!
	//swap(&stacks.a_head);
	//swap(&stacks.b_head);
	
	// //push to b
	//push_to_b(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);
	// push_to_b(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);
	// push_to_b(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);
	// push_to_b(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);
	// push_to_b(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);
	
	// //push to a
	// push_to_a(&stacks.b_head, &stacks.a_head, &stacks.b_tail, &stacks.a_tail);

	// swap(&stacks.b_head);

	// //rotate a
	//rotate_a(&stacks.a_head, &stacks.a_tail);
	
	//push_to_a(&stacks.b_head, &stacks.a_head, &stacks.b_tail, &stacks.a_tail);

	// //rotate b
	// rotate_b(&stacks.b_head, &stacks.b_tail);
	
	// //rv rotate a
	// reverse_rotate_a(&stacks.a_head, &stacks.a_tail);
	
	// //rv rotate b
	// reverse_rotate_b(&stacks.b_head, &stacks.b_tail);

	//sort_3(&stacks.a_head, &stacks.a_head);
	
	// //for 2 nodes only!!!
	//swap_two(&stacks.a_head);

	sort_3(&stacks.a_head, &stacks.a_tail);


	//---PRINT--- REMOVE BEFORE SUBMISSION!!!
	printf("Normal print,   stack_a:  ");
	print_normal(stacks.a_head);

	// printf("Reversed print, stack_a:  ");
	// print_reversed(stacks.a_tail);
	
	printf("\n");
	
	printf("Normal print,   stack_b:  ");
	print_normal(stacks.b_head);


	printf("Reversed print, stack_b:  ");
	print_reversed(stacks.b_tail);
	return (0);
}


