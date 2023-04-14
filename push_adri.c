
#include"push_swap.h"

void	push_adriii(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*tmp;

	if (stack_from == NULL || *stack_from == NULL)
		return ;
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (stack_to == NULL)
		*stack_to = tmp;
	else
	{
		tmp->next = *stack_to;
		*stack_to = tmp;
	}
}

void	push_a_adri(t_stack **stack_a, t_stack **stack_b)
{
	push_adriii(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b_adri(t_stack **stack_a, t_stack **stack_b)
{
	push_adriii(stack_a, stack_b);
	write(1, "pb\n", 3);
}