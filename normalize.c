#include"push_swap.h"

void	ft_bubble_sort(node_t **head)
{
	node_t	*tracker;
	
	tracker = (*head);
	if ((*head)->next->next == NULL) // only 2 elements
		return ;
	while (tracker->next != NULL)
	{
		if (tracker->data > tracker->next->data)
		{
			if (tracker->previous == NULL)
			{
				tracker->next->previous = NULL;
			}
			else
			{
				tracker->next->previous = tracker->previous;
			}

			tracker->next = tracker->next->next;
			tracker->next->previous = tracker->previous;
			if (tracker->next->next != NULL)
				tracker->next->next->previous = tracker;
			
			tracker->previous = tracker->next;
		}
		else
			return ;
		tracker = tracker->next;
	}
}