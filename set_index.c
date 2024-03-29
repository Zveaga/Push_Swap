/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_index.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 12:05:49 by rares         #+#    #+#                 */
/*   Updated: 2023/04/25 15:39:50 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	deallocate_stack(t_stack **head, t_stack **tail)
{
	t_stack	*tracker;

	if (*head == NULL)
		return ;
	tracker = *head;
	while (tracker->next != NULL)
	{
		tracker = tracker->next;
		free(tracker->previous);
	}
	free(tracker);
	(*head) = NULL;
	(*tail) = NULL;
}

void	raise_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	node_count(t_stack *head)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		head = head->next;
		count++;
	}
	return (count);
}

void	set_index(t_stack *head)
{
	t_stack	*tracker;
	t_stack	*largest;
	int		list_size;

	list_size = node_count(head);
	while (list_size-- > 0)
	{
		largest = NULL;
		tracker = head;
		while (tracker != NULL)
		{
			if (tracker->index == 0 && (largest == NULL
					|| tracker->data > largest->data))
				largest = tracker;
			tracker = tracker->next;
		}
		if (largest != NULL)
			largest->index = list_size;
	}
}
