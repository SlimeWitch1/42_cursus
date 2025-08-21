/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:25:42 by turocha-          #+#    #+#             */
/*   Updated: 2025/07/07 18:25:43 by turocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_params(char *params)
{
	int	i;

	i = 0;
	while (params[i] != '\0')
	{
		ft_putchar(params[i]);
		i++;
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	int	q;

	q = 1;
	while (q < argc)
	{
		ft_print_params(argv[q]);
		q++;
	}
	return (0);
}
