/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 15:03:41 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/04 15:11:24 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

void			swap(node_t **head);

void			swap_both(node_t **head_a, node_t **head_b);

void			push(node_t **head_a, node_t **head_b, node_t **tail_a, node_t **tail_b);

void			rotate(node_t **head, node_t **tail);

void			rotate_both(node_t **head_a, node_t **tail_a, node_t **head_b, node_t **tail_b);

void			reverse_rotate(node_t **head, node_t **tail);

void			reverse_rotate_both(node_t **head_a, node_t **tail_a, node_t **head_b, node_t **tail_b);

void			swap_two(node_t **head, node_t **tail);


#endif