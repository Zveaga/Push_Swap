/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 15:03:41 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/21 16:26:26 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<limits.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

typedef struct s_stacks
{
	t_stack		*a_head;
	t_stack		*a_tail;
	t_stack		*b_head;
	t_stack		*b_tail;
}				t_stacks;

t_stack			*create_node(int value);

void			insert_front(t_stack **head, int value);

void			insert_end(t_stack **head, t_stack **tail, int value);

void			swap_a(t_stack **head);

void			swap_b(t_stack **head);

void			swap_both(t_stack **head_a, t_stack **head_b);

void			push_to_b(t_stack **head_a, t_stack **head_b, \
							t_stack **tail_a, t_stack **tail_b);

void			push_to_a(t_stack **head_b, t_stack **head_a, \
							t_stack **tail_b, t_stack **tail_a);

void			rotate_a(t_stack **head_a, t_stack **tail_a);

void			rotate_b(t_stack **head_b, t_stack **tail_b);

void			swap(t_stack **head);

void			reverse_rotate_a(t_stack **head_a, t_stack **tail_a);

void			reverse_rotate_b(t_stack **head_b, t_stack **tail_b);

void			swap_both(t_stack **head_a, t_stack **head_b);

void			push(t_stack **head_a, t_stack **head_b, \
					t_stack **tail_a, t_stack **tail_b);

void			rotate(t_stack **head, t_stack **tail);

void			rotate_both(t_stack **head_a, t_stack **tail_a, \
							t_stack **head_b, t_stack **tail_b);

void			reverse_rotate(t_stack **head, t_stack **tail);

void			reverse_rotate_both(t_stack **head_a, t_stack **tail_a, \
									t_stack **head_b, t_stack **tail_b);

void			swap_two(t_stack **head);

void			set_index(t_stack *head);

void			raise_error(void);

void			sort_3(t_stack **head_a, t_stack **tail_a);

void			sort_4(t_stack **head_a, t_stack **head_b, \
						t_stack **tail_a, t_stack **tail_b);

void			sort_5(t_stack **head_a, t_stack **head_b, \
						t_stack **tail_a, t_stack **tail_b);

void			radix_sort(t_stack **head_a, t_stack **head_b, \
							t_stack **tail_a, t_stack **tail_b);

int				is_sorted(t_stack *head);

int				node_count(t_stack *head);

int				check_digit(char *num);

int				check_duplicate(char **argv, int i);

int				largest_number(t_stack *head);

int				max_bits(int largest);

int				smallest_number(t_stack *head);

#endif