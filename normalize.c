#include"push_swap.h"

void	ft_bubble_sort(node_t **head)
{
	node_t	*tracker;
	node_t	*elem1;
	node_t	*elem2;
	node_t	*elem3;

	if (*head == NULL || (*head)->next == NULL || (*head)->next->next == NULL)
		return ;
	tracker = *head;
	elem1 = tracker;
	elem2 = tracker->next;
	elem3 = tracker->next->next;
	while (tracker->next != NULL)
	{
		printf("%d\n", tracker->data);
		if (elem1->data > elem2->data)
		{
			if (elem1->previous == NULL)
			{
				elem2->previous = NULL;
				(*head) = elem2;

			}
			else
			{
				elem2->previous = elem1->previous;
				elem1->previous->next = elem2;
			}

			elem2->next = elem1;
			elem1->next = elem3;
			
			if (elem1->previous != NULL)
				elem1->previous = elem2;
		}
		// else
		// 	return ;
		
		tracker = tracker->next;
	}

}