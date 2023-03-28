/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 15:03:41 by raanghel      #+#    #+#                 */
/*   Updated: 2023/03/27 15:36:31 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>

typedef struct node
{
	int	data;
	struct node *next;
	struct node *previous;
} node_t;

// node_t *stack_a;
// node_t *stack_b;

typedef struct stacks
{
	node_t *stack_a;
	node_t *stack_b;
} stacks_t;

node_t *create_node(int value);

void insert_front(node_t **head, int value);

void	insert_end(node_t **head, int value);

void	sa(node_t *head);

#endif