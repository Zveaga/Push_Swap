/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 17:37:57 by raanghel      #+#    #+#                 */
/*   Updated: 2023/03/24 17:55:05 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

node_t *create_node(int content)
{
	node_t *head;

	head = malloc(sizeof(node_t));
	if (head == NULL)
		return (NULL);
	head->data = content;
	head->previous = NULL;
	head->next = NULL;
}

void insert_front(node_t **head, node_t *new_node, int content)
{
	new_node = create_node();
}