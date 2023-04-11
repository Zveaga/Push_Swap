/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 15:03:41 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/10 12:35:55 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>

typedef struct node
{
	int				data;
	int				index;
	struct node 	*next;
	struct node 	*previous;
} node_t;

typedef struct stacks
{
	node_t	*a_head;
	node_t	*a_tail;
	node_t	*b_head;
	node_t	*b_tail;
} stacks_t;

node_t			*create_node(int value);

void			insert_front(node_t **head, int value);

void 			insert_end(node_t **head, node_t **tail, int value);

void			swap_a(node_t **head);

void			swap_b(node_t **head);

void			swap_both(node_t **head_a, node_t **head_b);

void			push_to_b(node_t **head_a, node_t **head_b, node_t **tail_a, node_t **tail_b);

void			push_to_a(node_t **head_b, node_t **head_a, node_t **tail_b, node_t **tail_a);

void			rotate_a(node_t **head_a, node_t **tail_a);

void			rotate_b(node_t **head_b, node_t **tail_b);

void			swap(node_t **head);

void			reverse_rotate_a(node_t **head_a, node_t **tail_a);

void			reverse_rotate_b(node_t **head_b, node_t **tail_b);

void			swap_both(node_t **head_a, node_t **head_b);

void			push(node_t **head_a, node_t **head_b, node_t **tail_a, node_t **tail_b);

void			rotate(node_t **head, node_t **tail);

void			rotate_both(node_t **head_a, node_t **tail_a, node_t **head_b, node_t **tail_b);

void			reverse_rotate(node_t **head, node_t **tail);

void			reverse_rotate_both(node_t **head_a, node_t **tail_a, node_t **head_b, node_t **tail_b);

void			swap_two(node_t **head);

int				is_sorted(node_t *head);

int				check_digit(char *num);

int				check_duplicate(char **argv, int i);

node_t 			*get_to_tail(node_t *head);

int				node_count(node_t *lst);

void			set_index(node_t *head);

void			raise_error();

void			sort_3(node_t **head_a, node_t **tail_a);

int				largest_number(node_t *head);

int				max_bits(int largest);


#endif