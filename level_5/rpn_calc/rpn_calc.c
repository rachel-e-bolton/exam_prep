/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 19:04:38 by rbolton           #+#    #+#             */
/*   Updated: 2019/08/20 20:46:14 by rbolton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

t_bool		is_digit(int c)
{
	return (c >= 48 && c <= 57 ? TRUE : FALSE);
}

t_bool		is_operator(int c)
{
	return (c == 43 || c == 45 || c == 42 || c == 47 || c == 37 ? TRUE : FALSE);
}

t_bool		is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || (is_digit(str[i]) == TRUE) || (is_operator(str[i]) == TRUE)))
	{
		i++;
	}
	return (str[i] == '\0' ? TRUE : FALSE);
}

t_stack		*push(t_stack *head, int data)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(1 * sizeof(tmp));
	if (tmp == NULL)
		return (NULL);
	tmp->data = data;
	tmp->next = head;
	head = tmp;
	free(tmp);
	return (head);
}

t_stack		*pop(t_stack *head, int *data)
{
	t_stack	*tmp;

	tmp = head;
	*data = head->data;
	head = head->next;
	free(tmp);
	return (head);
}

int			perform_ops(int *num1, int *num2, int c)
{
	int	ans;

	if (c == 43)
		return (ans = *num1 + *num2);
	if (c == 45)
		return (ans = *num1 - *num2);
	if (c == 42)
		return (ans = *num1 * *num2);
	if (c == 47)
		return (ans = *num1 / *num2);
	if (c == 37)
		return (ans = *num1 % *num2);
	return (0);
}

int			main(int ac, char **av)
{
	int			i;
	int 		k;
	variables	*var;

	if (ac == 2)
	{
		if	(is_valid(av[1]) == FALSE)
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		if (!(var = (variables *)malloc(1 * sizeof(var))))
			return (-1);
		var->num1 = 0;
		var->num2 = 0;
		var->ptr_num1 = &var->num1;
		var->ptr_num2 = &var->num2;
		var->head = NULL;
		i = 0;
		while (av[1][i] != '\0')
		{
			if (av[1][i] == ' ')
				i++;
			if (is_digit(av[1][i]) == TRUE)
			{
				k = i;
				var->num1 = atoi(*(av + 1 + k));
				if (!(push(var->head, var->num1)))
					return (-1);
				while (is_digit(av[1][i]) == TRUE)
					i++;
			}
			if (is_operator(av[1][i]) == TRUE)
			{
				if (var->head->next == NULL)
				{
					write(1, "Error\n", 6);
					return (-1);
				}
				pop(var->head, var->ptr_num1);
				pop(var->head, var->ptr_num2);
				var->num1 = perform_ops(var->ptr_num1, var->ptr_num2, av[1][i]);
				push(var->head, var->num1);
			}
		}
		if (var->head == NULL || var->head->next != NULL)
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		else
		{
			printf("%d\n", var->head->data);
			printf("%d\n", var->num1);
		}
	}
	else
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (0);
}
