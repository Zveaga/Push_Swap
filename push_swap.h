/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 15:03:41 by raanghel      #+#    #+#                 */
/*   Updated: 2023/03/31 15:00:54 by raanghel      ########   odam.nl         */
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

void			sa(node_t **head_a);

void			ss(node_t **head_a, node_t **head_b);

void			push(node_t **head_a, node_t **head_b, node_t **tail_a, node_t **tail_b);

void			pb(node_t **head_a, node_t **head_b, node_t **tail_a, node_t **tail_b);

void			pa(node_t **head_b, node_t **head_a, node_t **tail_b, node_t **tail_a);

void			rotate(node_t **head, node_t **tail);

void			ra(node_t **head_a, node_t **tail_a);

void			rb(node_t **head_b, node_t **tail_b);

void			rr(node_t **head_a, node_t **tail_a, node_t **head_b, node_t **tail_b);

void			reverse_rotate(node_t **head, node_t **tail);

void			rra(node_t **head_a, node_t **tail_a);

void			rrb(node_t **head_b, node_t **tail_b);

void			rrr(node_t **head_a, node_t **tail_a, node_t **head_b, node_t **tail_b);


#endif