/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 15:09:05 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/14 10:24:03 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// void	print_reversed(t_stack *tail)
// {
// 	t_stack	*tracker;

// 	tracker = tail;
// 	while (tracker != NULL)
// 	{
// 		printf("%d(%d) ", tracker->data, tracker->index);
// 		tracker = tracker->previous;
// 	}
// 	printf("\n");
// }

void	print_normal(t_stack *head)
{
	t_stack	*tracker;
	//int		i = 0;
	tracker = head;
	
	while (tracker != NULL)
	{
		printf("%d(%d) ",tracker->data, tracker->index);
		// printf("%d ", tracker->data);
		tracker = tracker->next;
	}
	//printf("\n");
}

// void	deallocate_stack(t_stack **head, t_stack **tail)
// {
// 	t_stack	*tracker;

// 	if (*head == NULL)
// 		return ;
// 	tracker = *head;
// 	while (tracker->next != NULL)
// 	{
// 		tracker = tracker->next;
// 		free(tracker->previous);
// 	}
// 	free(tracker);
// 	(*head) = NULL;
// 	(*tail) = NULL;
// }

void	parse_quotes(char **args)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (args[1][i] && flag == 0)
	{
		if (args[1][i] != ' ')
		{
			flag = 1;
			if (check_digit(args[i]) == 1)
				raise_error();
		}
		i++;
	}
	if (flag == 0)
		raise_error();
}

void	parse_input(int argc, char **argv, t_stack **head_a)
{
	int		i;
	long	temp;

	i = 0;
	if (argc == 2)
	{
		parse_quotes(argv);
		argv = ft_split(argv[1], ' ');
	}
	else
		i = 1;
	while (argv[i])
	{
		temp = ft_atoi(argv[i]);
		// if (check_digit(argv[i]) == 0)
		// 	raise_error();
		// if (temp < INT_MIN || temp > INT_MAX)
		// 	raise_error();
		// if (check_duplicate(argv, i) == 0)
		// 	raise_error();
		insert_end(head_a, temp);
		i++;
	}
}

// void	sorting_selector(t_stack **head_a, t_stack **head_b, \
// 						t_stack **tail_a, t_stack **tail_b)
// {
// 	int	nodes;

// 	nodes = node_count(*head_a);
// 	if (nodes == 3)
// 		sort_3(head_a, tail_a);
// 	else if (nodes == 4)
// 		sort_4(head_a, head_b, tail_a, tail_b);
// 	else if (nodes == 5)
// 		sort_5(head_a, head_b, tail_a, tail_b);
// 	else
// 		radix_sort(head_a, head_b);
// }

t_stack *get_to_tail(t_stack *head)
{
	t_stack	*tracker;
	
	if (head == NULL)
		return (NULL);
	tracker = head;
	while (tracker->next != NULL)
		tracker = tracker->next;
	return (tracker);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.a_head = NULL;
	stacks.a_tail = NULL;
	stacks.b_head = NULL;
	stacks.b_tail = NULL;
	parse_input(argc, argv, &stacks.a_head);
	// if (is_sorted(stacks.a_head) == 0)
	// {
	// 	deallocate_stack(&stacks.a_head, &stacks.a_tail);
	// 	deallocate_stack(&stacks.b_head, &stacks.b_tail);
	// 	exit(EXIT_SUCCESS);
	// }
	set_index(stacks.a_head);
	// sorting_selector(&stacks.a_head, &stacks.b_head, \
	// 				&stacks.a_tail, &stacks.b_tail);
	radix_sort(&stacks.a_head, &stacks.b_head);
	//---PRINT--- REMOVE BEFORE SUBMISSION!!!!!!!!!!!!
	printf("After sorting (stack_a):  ");
	print_normal(stacks.a_head);
	printf("\n");
	
	// printf("Reversed print, stack_a:  ");
	// print_reversed(stacks.a_tail);
	// printf("\n");
	if (is_sorted(stacks.a_head) == 0)
		printf("OK");
	else
		printf("Not sorted!");
	// printf("Normal print,   stack_b:  ");
	// print_normal(stacks.b_head);
	// deallocate_stack(&stacks.a_head, &stacks.a_tail);
	// deallocate_stack(&stacks.b_head, &stacks.b_tail);
	return (0);
}
