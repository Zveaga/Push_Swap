/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rares <rares@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 12:08:29 by rares         #+#    #+#                 */
/*   Updated: 2023/04/14 18:01:48 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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

void	sort_4(t_stack **head_a, t_stack **head_b,
				t_stack **tail_a, t_stack **tail_b)
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

void	sort_5(t_stack **head_a, t_stack **head_b,
				t_stack **tail_a, t_stack **tail_b)
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
