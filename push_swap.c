/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 15:09:05 by raanghel      #+#    #+#                 */
/*   Updated: 2023/03/27 15:39:25 by rares         ########   odam.nl         */
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

int	main (int argc, char **argv)
{
	int	i;
	stacks_t stacks;

	i = 0;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;

	if (argc < 2)
	{
		printf("Invalid argument count!");
		exit(EXIT_FAILURE);
	}
	while (i++ < argc - 1)
	{
		insert_end(&stacks.stack_a, atoi(argv[i]));
		
		//printf ("Number: %d\n", atoi(argv[i]));
	}
	sa(stacks.stack_a);
	node_t *tracker;
	tracker = stacks.stack_a ;
	while (tracker != NULL)
	{
		printf("%d ", tracker->data);
		tracker = tracker->next;
	}
	return (0);
}


