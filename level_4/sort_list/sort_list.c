/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:15:49 by rbolton           #+#    #+#             */
/*   Updated: 2019/07/23 12:45:55 by rbolton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		count;
	int		temp;
	t_list	*current_node;

	count = 1;
	current_node = lst;
	if (!current_node)
		return (NULL);
	if (current_node->next == NULL)
		return (lst);
	while (current_node->next != NULL)
	{
		count++;
		current_node = current_node->next;
	}
	while (count--)
	{
		current_node = lst;
		while (current_node->next != NULL)
		{
			if (cmp(current_node->data, current_node->next->data) == 0)
			{
				temp = current_node->data;
				current_node->data = current_node->next->data;
				current_node->next->data = temp;
			}
			current_node = current_node->next;
		}
	}
	return (lst);
}
