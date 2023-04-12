#include"push_swap.h"

void	swap(node_t **head) ///to do, for 2 elements
{
	node_t	*elem_1;
	node_t	*elem_2;
	node_t	*elem_3;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	if ((*head)->next->next == NULL)
	{
		swap_two(head);
		return ;
	}
	elem_1 = *head;
	elem_2 = (*head)->next;
	elem_3 = (*head)->next->next;
	elem_1->previous = elem_2;
	elem_1->next = elem_3;
	elem_2->previous = NULL;
	elem_2->next = elem_1;
	elem_3->previous = elem_1;
	(*head) = elem_2;
}
