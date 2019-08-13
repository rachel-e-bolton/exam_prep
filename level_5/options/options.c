/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:20:00 by rbolton           #+#    #+#             */
/*   Updated: 2019/08/13 15:09:09 by rbolton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	t[32] = {0};

	if (argc == 1)
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		return (-1);
	}
	i = 1;
	while (i < argc)
	{
		j = 1;
		if (argv[i][0] == '-')
		{
			while (argv[i][j] && argv[i][j] >= 'a' && argv[i][j] <= 'z')
			{
				if (argv[i][j] == 'h')
				{
					write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
					return (-1);
				}
				t['z' - argv[i][j] + 6] = 1;
				j++;
			}
			if (argv[i][j])
			{
				write(1, "Invalid Option\n", 15);
				return (-1);
			}
		}
		i++;
	}
	i = 0;
	while (i < 32)
	{
		t[i] = '0' + t[i];
		write (1, &t[i], 1);
		i++;
		if (i == 32)
		{
			write(1, "\n", 1);
			return (0);
		}
		if (i % 8 == 0)
			write(1, " ", 1);
	}
	return (0);
}
