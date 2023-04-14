/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 17:37:57 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/14 16:00:37 by raanghel      ########   odam.nl         */
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

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->data = value;
	new_node->index = 0;
	new_node->previous = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	insert_end(t_stack **head, t_stack **tail, int value)
{
	t_stack	*new_node;

	new_node = create_node(value);
	if (new_node == NULL)
		return ;
	if (*tail == NULL)
	{
		*head = new_node;
		*tail = new_node;
		return ;
	}
	new_node->data = value;
	new_node->previous = *tail;
	new_node->next = NULL;
	(*tail)->next = new_node;
	*tail = new_node;
}

int	is_sorted(t_stack *head)
{
	t_stack	*tracker;

	tracker = head;
	while (tracker != NULL && tracker->next != NULL)
	{
		if (tracker->index > tracker->next->index)
			return (1);
		tracker = tracker->next;
	}
	return (0);
}

int	check_digit(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (ft_isdigit(num[i]) == 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(char **argv, int i)
{
	int	j;

	j = 1;
	while (argv[j] != NULL)
	{
		if (i != j && ft_atoi(argv[i]) == ft_atoi(argv[j]))
			return (0);
		j++;
	}
	return (1);
}
