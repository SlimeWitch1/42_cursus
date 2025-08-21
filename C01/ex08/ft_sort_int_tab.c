/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:38:53 by turocha-          #+#    #+#             */
/*   Updated: 2025/05/29 17:38:57 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size)
	{
		if ((tab[i] > tab[i + 1]) && (tab[i + 1] != '\0'))
		{
		temp = tab[i];
		tab[i] = tab[i + 1];
		tab[i + 1] = temp;
		i = 0;
		}
		else
			i++;
	}
}

/*
int	main(void)
{
	int	t[] = {3, 1, 7, 3, 8, 5, 2, 1, 5, 9, 9};
	int	s = sizeof(t) / sizeof(t[0]);
	int	i;

	ft_sort_int_tab(t, s);
	i = 0;
	while (i < s)
	{
		printf("%d", t[i]);
		i++;
	}
	return (0);
}
*/