/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 16:39:21 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/10 13:32:40 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	largest_number(node_t *head)
{
	node_t	*tracker;
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

// void	radix_sort(node_t **head_a, node_t **tail_a)
// {
// }

void	sort_3(node_t **head_a, node_t **tail_a)
{
	int	largest;
	
	largest = largest_number(*head_a);
	if ((*head_a)->index == largest)
	{
		rotate_a(head_a, tail_a);
		swap_a(head_a);
	}
	if ((*head_a)->next->index == largest)
		reverse_rotate_a(head_a, tail_a);
	if ((*head_a)->index > (*head_a)->next->index)
		swap_a(head_a);
}

void	sort_5(node_t **head_a, node_t **head_b, node_t tail_a,  node_t tail_b)
{
		
}