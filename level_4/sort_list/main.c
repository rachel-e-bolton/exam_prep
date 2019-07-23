/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:19:13 by rbolton           #+#    #+#             */
/*   Updated: 2019/07/23 15:24:01 by rbolton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int		ascending(int a, int b);
int 	descending(int a, int b);
t_list	*create_elem(int data);
void	add_node(t_list **lst, t_list *new);
size_t	ft_strlen(const char *str);
t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

int		(*cmp)(int, int);

int		ascending(int a, int b)
{
	return (a <= b);
}

int 	descending(int a, int b)
{
	return (a >= b);
}

t_list	*create_elem(int data)
{
	t_list	*elem;

	if (!data)
		return (NULL);
	if (!(elem = (t_list *)malloc(1 * sizeof(elem))))
		return (NULL);
	if (!(elem->data = (int)malloc(1 * sizeof(data))))
	{
		free(elem);
		return (NULL);
	}
	elem->data = data;
	elem->next = NULL;
	return(elem);
}

void	add_node(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

int		main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*new;
	t_list	*current_node;
	int		data;
	int		i;

	if (argc >= 3)
	{
		if ((ft_strlen(argv[1]) != 1) && (argv[1][0] != 'A' || argv[1][0] != 'D'))
		{
			printf("Please try again using either \"A\" for ascending sort or \"D\" for descending sort as your first parameter...");
			return (-1);
		}
		i = 2;
		lst = NULL;
		while (argv[i] != NULL)
		{
			data = atoi(argv[i]);
			if (!data)
			{
				printf("It appears the parameter entered at position %d is not valid. Please try again with valid integer input for sorting.", i);
				return (-1);
			}
			new = create_elem(data);
			add_node(&lst, new);
			i++;
			printf("The current node's data is: %d\n", lst->data);
		}
		current_node = lst;
		printf("The unsorted list is as follows:\n");
		while (current_node->next != NULL)
		{
			printf("%d\n", current_node->data);
			current_node = current_node->next;
		}
		printf("%d\n", current_node->data);
		if (argv[1][0] == 'A')
			cmp = &ascending;
		if (argv[1][0] == 'D')
			cmp = &descending;
		current_node = sort_list(lst, cmp);
		printf("The sorted list is as follows:\n");
		while (current_node->next != NULL)
		{
			printf("%d\n", current_node->data);
			current_node = current_node->next;
		}
		printf("%d\n", current_node->data);
	}
	return (0);
}
