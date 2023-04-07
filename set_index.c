#include"push_swap.h"


void	set_index(node_t *head)
{
	node_t	*tracker;
	node_t	*largest;
	int		list_size;

	list_size = node_count(head);
	while (list_size-- > 0)
	{
		largest = NULL;
		tracker = head;
		while (tracker != NULL)
		{
			if (tracker->index == 0 && (largest == NULL || tracker->data > largest->data))
				largest = tracker;
			tracker = tracker->next;
		}
		if(largest != NULL)
			largest->index = list_size;
	}
}