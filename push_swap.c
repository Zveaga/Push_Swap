/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 15:09:05 by raanghel      #+#    #+#                 */
/*   Updated: 2023/04/04 13:56:47 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.
*/

#include"push_swap.h"
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number * sign);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	int				i;
	unsigned int	len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (len_s <= start)
		len = 0;
	else if (len_s - start < len)
		len = len_s - start;
	sub_str = (char *) malloc ((len + 1) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	while (len > 0 && start < len_s)
	{
		sub_str[i] = s[start];
		i++;
		start++;
		len--;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

static int	_sub_str_count(char const *s, char c)
{
	int	i;
	int	len_s;
	int	count;

	i = 0;
	count = 0;
	len_s = ft_strlen(s);
	while (s[i] == c)
		i++;
	while (i < len_s)
	{
		if (s[i] != c)
			i++;
		if (s[i] == c && s[i])
		{
			count++;
			i++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	if (i > 0 && s[len_s - 1] != c)
		count++;
	return (count);
}

static int	_sub_str_len(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c)
	{
		if (s[i] != c)
			len++;
		i++;
		if (s[i] == '\0')
			break ;
	}
	return (len);
}

void	_free(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free (matrix);
}

static char	**process(char **str_split, char const *s, char c)
{
	int	row;
	int	i;

	i = 0;
	row = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			str_split[row] = ft_substr(s, i, _sub_str_len((s + i), c));
			if (str_split[row] == NULL)
			{
				_free(str_split);
				return (NULL);
			}
			row++;
			i = i + _sub_str_len((s + i), c);
		}
		else
			i++;
	}
	str_split[row] = NULL;
	return (str_split);
}

char	**ft_split(char	const *s, char c)
{
	char	**str_split;
	int		nr_of_substr;

	nr_of_substr = _sub_str_count(s, c);
	str_split = (char **)malloc (sizeof(char *) * (nr_of_substr + 1));
	if (str_split == NULL)
		return (NULL);
	str_split = process(str_split, s, c);
	return (str_split);
}


int	ft_strchr(char *str, char c)
{	
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

void	init(node_t **head, node_t **tail, int value)
{
	node_t	*new_node;
	
	new_node = create_node(value);
	if (new_node == NULL)
		return ;
	new_node->data = value;
	new_node->previous = NULL;
	new_node->next = NULL;
	*head = new_node;
	*tail = new_node;
}

void	print_reversed(node_t *tail)
{
	node_t	*tracker;

	//printf("Reversed print: ");
	tracker = tail;
	while (tracker != NULL)
	{
		printf("%d", tracker->data);
		tracker = tracker->previous;
	}
	printf("\n");
}

void	print_normal(node_t *head)
{
	node_t	*tracker;

	//printf("Normal print:   ");
	tracker = head;
	while (tracker != NULL)
	{
		printf("%d", tracker->data);
		tracker = tracker->next;
	}
	printf("\n");
}

node_t *get_to_tail(node_t *head)
{
	node_t	*tracker;
	
	if (head == NULL)
		return (NULL);
	tracker = head;
	while (tracker->next != NULL)
		tracker = tracker->next;
	return (tracker);
}

void	parse_input(int argc, char **args, node_t **head_a, node_t **tail_a)
{
	int		i;
	char	**argv;
	
	i = 0;
	if (argc == 2)
		argv = ft_split(args[1], ' ');
	else
	{
		i = 1;
		argv = args;
	}
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == 0)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		insert_end(head_a ,tail_a, ft_atoi(argv[i]));
		i++;
	}
}

int	main (int argc, char **argv)
{
	stacks_t stacks;

	stacks.a_head = NULL;
	stacks.a_tail = NULL;
	stacks.b_head = NULL;
	stacks.b_tail = NULL;

	parse_input(argc, argv, &stacks.a_head, &stacks.a_tail);
		
	stacks.a_tail = get_to_tail(stacks.a_head);
	stacks.b_tail = get_to_tail(stacks.b_head);

	printf("Stack_a head: %d\n", stacks.a_head->data);
	printf("Stack_a tail: %d\n", stacks.a_tail->data);

	//---INSTRUCTIONS---   REMOVE BEFORE SUBMISSION!!!!!
	//swap(&stacks.a_head);
	//swap(&stacks.b_head);

	//push(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);
	//push(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);
	
	//push(&stacks.b_head, &stacks.a_head, &stacks.b_tail, &stacks.a_tail);
	
	//push(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);
	//push(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);
	//push(&stacks.a_head, &stacks.b_head, &stacks.a_tail, &stacks.b_tail);

	//rotate(&stacks.a_head, &stacks.a_tail);
	//rotate(&stacks.a_head, &stacks.a_tail);
	//rotate(&stacks.a_head, &stacks.a_tail);
	
	//rotate(&stacks.b_head, &stacks.b_tail);

	reverse_rotate(&stacks.a_head, &stacks.a_tail);
	//reverse_rotate(&stacks.b_head, &stacks.b_tail);

	//swap_two(&stacks.b_head, &stacks.b_tail);


	//---PRINT--- REMOVE BEFORE SUBMISSION!!!
	printf("Normal print,   stack_a:  ");
	print_normal(stacks.a_head);

	printf("Reversed print, stack_a:  ");
	print_reversed(stacks.a_tail);
	printf("\n");
	printf("Normal print,   stack_b:  ");
	print_normal(stacks.b_head);

	printf("Reversed print, stack_b:  ");
	print_reversed(stacks.b_tail);
	return (0);
}


