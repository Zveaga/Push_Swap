/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 15:09:05 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/06 19:05:13 by raanghel      ########   odam.nl         */
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

	//printf("Reversed print: ");
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

	//printf("Normal print:   ");
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
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		if (temp < INT_MIN || temp > INT_MAX)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		// if (check_duplicate(argv, temp, i) == 0)
		// {
		// 	write(2, "Error\n", 6);
		// 	exit(EXIT_FAILURE);
		// }
		insert_end(head_a ,tail_a, ft_atoi(argv[i]));
		i++;
	}
}

int	main (int argc, char **argv)
{
	stacks_t stacks;

	stacks.a_head = NULL;
	stacks.a_tail = NULL;
	stacks.b_head = NULL;
	stacks.b_tail = NULL;

	parse_input(argc, argv, &stacks.a_head, &stacks.a_tail);
	ft_bubble_sort(&stacks.a_head);
	// if (is_sorted(stacks.a_head) == 0)
	// {
	// 	write(1, "OK\n", 3);
	// 	exit(EXIT_SUCCESS);
	// }
		
	// stacks.a_tail = get_to_tail(stacks.a_head);
	// stacks.b_tail = get_to_tail(stacks.b_head);

	printf("Stack_a head: %d\n", stacks.a_head->data);
	printf("Stack_a tail: %d\n", stacks.a_tail->data);

	//---INSTRUCTIONS---   REMOVE BEFORE SUBMISSION!!!!!
	//swap(&stacks.a_head);
	//swap(&stacks.b_head);

	//push(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);
	//push(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);
	
	//push(&stacks.b_head, &stacks.a_head, &stacks.b_tail, &stacks.a_tail);
	
	//push(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);
	//push(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);
	//push(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);

	//rotate(&stacks.a_head, &stacks.a_tail);
	//rotate(&stacks.a_head, &stacks.a_tail);
	//rotate(&stacks.a_head, &stacks.a_tail);
	
	//rotate(&stacks.b_head, &stacks.b_tail);

	//reverse_rotate(&stacks.a_head, &stacks.a_tail);
	//reverse_rotate(&stacks.b_head, &stacks.b_tail);

	//swap_two(&stacks.b_head, &stacks.b_tail);


	//---PRINT--- REMOVE BEFORE SUBMISSION!!!
	printf("Normal print,   stack_a:  ");
	print_normal(stacks.a_head);

	printf("Reversed print, stack_a:  ");
	print_reversed(stacks.a_tail);
	printf("\n");
	printf("Normal print,   stack_b:  ");
	print_normal(stacks.b_head);

	printf("Reversed print, stack_b:  ");
	print_reversed(stacks.b_tail);
	return (0);
}


