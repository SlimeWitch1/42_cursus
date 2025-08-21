/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:18:42 by turocha-          #+#    #+#             */
/*   Updated: 2025/05/28 16:18:44 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (size / 2))
	{
		j = tab[(size - 1 - i)];
		tab[(size - 1 - i)] = tab[i];
		tab[i] = j;
		i++;
	}
}

/*
int	main(void)
{
	int	t[] = {1, 2, 3, 4, 5};
	int	s = sizeof(t) / sizeof(t[0]);
	int	i;

	ft_rev_int_tab(t, s);
	i = 0;
	while (i < s)
	{
		printf("%d", t[i]);
		i++;
	}
	return (0);
}
*/