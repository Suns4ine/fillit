/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:52:45 by cshawnee          #+#    #+#             */
/*   Updated: 2019/11/15 14:58:22 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	freeman(t_tris *node)
{
	t_tris *temp;

	if (node != NULL)
	{
		while (node)
		{
			temp = node->next;
			free(node);
			node = temp;
		}
		node = NULL;
	}
}

int		number(t_tris *list)
{
	int i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int		ft_sqrt(int nb)
{
	int a;

	a = 2;
	while (a * a < nb)
		a++;
	return (a);
}

void	shift_x(t_tris *node, int n)
{
	int i;

	i = 0;
	while (i <= 6)
	{
		node->cord[i] -= n;
		i += 2;
	}
}

void	shift_y(t_tris *node, int n)
{
	int i;

	i = 1;
	while (i <= 7)
	{
		node->cord[i] -= n;
		i += 2;
	}
}
