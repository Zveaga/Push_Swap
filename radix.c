/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 16:39:21 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/12 17:15:56 by raanghel      ########   odam.nl         */
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

void	radix_sort(t_stack **head_a, t_stack **head_b, t_stack **tail_a, t_stack **tail_b)
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
		while (j < largest)
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

void	sort_3(t_stack **head_a, t_stack **tail_a)
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

void	sort_4(t_stack **head_a, t_stack **head_b, t_stack **tail_a,  t_stack **tail_b)
{
	int		smallest;

	smallest = smallest_number(*head_a);
	
	if ((*head_a)->next->next->next->index == smallest)
		reverse_rotate_a(head_a, tail_a);
	else if ((*head_a)->next->next->index == smallest)
	{
		reverse_rotate_a(head_a, tail_a);
		reverse_rotate_a(head_a, tail_a);
	}
	else if ((*head_a)->next->index == smallest)
		swap_a(head_a);

	push_to_b(head_a, head_b, tail_a, tail_b);
	sort_3(head_a, tail_a);
	push_to_a(head_b, head_a, tail_b, tail_a);
}

void	sort_5(t_stack **head_a, t_stack **head_b, t_stack **tail_a,  t_stack **tail_b)
{
	int	smallest;

	smallest = smallest_number(*head_a);
	if ((*head_a)->next->next->next->next->index == smallest)
		reverse_rotate_a(head_a, tail_a);
	else if ((*head_a)->next->next->next->index == smallest)
	{
		reverse_rotate_a(head_a, tail_a);		
		reverse_rotate_a(head_a, tail_a);
	}	
	else if ((*head_a)->next->next->index == smallest)
	{
		rotate_a(head_a, tail_a);
		rotate_a(head_a, tail_a);
	}
	else if ((*head_a)->next->index == smallest)
		rotate_a(head_a, tail_a);

	push_to_b(head_a, head_b, tail_a, tail_b);
	sort_4(head_a, head_b, tail_a, tail_b);
	push_to_a(head_b, head_a, tail_b, tail_a);
}