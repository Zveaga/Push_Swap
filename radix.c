/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 16:39:21 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/14 10:29:26 by rares         ########   odam.nl         */
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

void	radix_sort(t_stack **head_a, t_stack **head_b)
{
	int	largest;
	int	largest_bits;
	int	i;
	int	j;

	largest = largest_number(*head_a);
	//largest_bits = max_bits(largest);
	largest_bits = 7;
	printf("largest bits: %d\n", largest_bits);
	i = 0;
	while (i < largest_bits)
	{
		j = 0;
		while (j < largest)
		{
			if (((*head_a)->index >> i) & 1)
				rotate_a_adri(head_a);
			else
				push_b_adri(head_a, head_b);
			j++;
		}
		while (*head_b)
			push_a_adri(head_a, head_b);
		i++;
	}
}
