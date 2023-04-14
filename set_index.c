/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_index.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 12:05:49 by rares         #+#    #+#                 */
/*   Updated: 2023/04/13 19:01:39 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	raise_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	node_count(t_stack *head)
{
	t_stack	*tracker;
	int		count;

	count = 0;
	tracker = head;
	while (tracker != NULL)
	{
		tracker = tracker->next;
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
			if (tracker->index == 0 && (largest == NULL || tracker->data > largest->data))
				largest = tracker;
			tracker = tracker->next;
		}
		if(largest != NULL)
			largest->index = list_size;
	}
}