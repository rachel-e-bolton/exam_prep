/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbolton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 19:05:39 by rbolton           #+#    #+#             */
/*   Updated: 2019/08/20 20:46:20 by rbolton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CALC_H
# define RPN_CALC_H
# define t_bool int
# define TRUE 1
# define FALSE 0
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct	s_stack
{
	int				data;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_variables
{
	int				num1;
	int				num2;
	int				*ptr_num1;
	int				*ptr_num2;
	t_stack			*head;
}				variables;

t_bool	is_digit(int c);
t_bool	is_operator(int c);
t_bool	is_valid(char *str);
t_stack	*push(t_stack *head, int data);
t_stack	*pop(t_stack *head, int *data);
int		perform_ops(int *num1, int *num2, int c);

#endif
