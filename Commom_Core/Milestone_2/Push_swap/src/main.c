/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:02:23 by turocha-          #+#    #+#             */
/*   Updated: 2025/11/12 04:02:24 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_final_index(t_stack_node *stack)
{
	t_stack_node	*curr;
	t_stack_node	*cmp;
	int				index;

	curr = stack;
	while (curr)
	{
		index = 0;
		cmp = stack;
		while (cmp)
		{
			if (cmp->value < curr->value)
				index++;
			cmp = cmp->next;
		}
		curr->final_index = index;
		curr = curr->next;
	}
}

void	stack_init(t_stack_node **a, char **argv, int splitted)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, splitted);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, splitted);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, splitted);
		append_node(a, (int)nbr);
		i++;
	}
	if (splitted)
		free_string_array(argv);
}

static void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len;

	if (!stack_sorted(*a))
	{
		len = stack_len(*a);
		if (len == 2)
			sa(a, false);
		else if (len == 3)
			simple_sort(a);
		else
			push_swap(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**numbers;

	a = NULL;
	b = NULL;
	numbers = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc > 2)
		stack_init(&a, argv + 1, 0);
	else
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers)
			return (1);
		stack_init(&a, numbers, 1);
	}
	set_final_index(a);
	sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
