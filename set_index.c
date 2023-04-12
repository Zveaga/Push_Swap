#include"push_swap.h"


void	set_index(t_stack *head)
{
	t_stack	*tracker;
	t_stack	*largest;
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