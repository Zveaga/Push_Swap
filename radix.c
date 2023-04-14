/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 16:39:21 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/14 13:31:36 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	largest_number(t_stack *head)
{
	t_stack	*tracker;
	int		largest;

	tracker = head;
	largest = head->index;
	while (tracker != NULL)
	{
		if (tracker->index > largest)
			largest = tracker->index;
		tracker = tracker->next;
	}
	return (largest);
}

int	smallest_number(t_stack *head)
{
	t_stack	*tracker;
	int		smallest;

	tracker = head;
	smallest = head->index;
	while (tracker != NULL)
	{
		if (tracker->index < smallest)
			smallest = tracker->index;
		tracker = tracker->next;
	}
	return (smallest);
}

int	max_bits(int largest)
{
	int	bits;

	bits = 0;
	while (largest > 0)
	{
		largest >>= 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stack **head_a, t_stack **head_b,
					t_stack **tail_a, t_stack **tail_b)
{
	int	largest;
	int	largest_bits;
	int	i;
	int	j;

	largest = largest_number(*head_a);
	largest_bits = max_bits(largest);
	i = 0;
	while (i < largest_bits)
	{
		j = 0;
		while (j < largest + 1)
		{
			if ((((*head_a)->index >> i) & 1) == 1)
				rotate_a(head_a, tail_a);
			else
				push_to_b(head_a, head_b, tail_a, tail_b);
			j++;
		}
		while (*head_b)
			push_to_a(head_b, head_a, tail_b, tail_a);
		i++;
	}
}
