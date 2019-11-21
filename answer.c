/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:36:28 by cshawnee          #+#    #+#             */
/*   Updated: 2019/11/15 14:53:43 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		collisions(t_map *map, t_tris *block)
{
	int i;
	int x;
	int y;

	i = 0;
	x = block->x_shift + block->cord[i];
	y = block->y_shift + block->cord[i + 1];
	while (i <= 6 && map->arr[y][x] == '.')
	{
		i += 2;
		x = block->cord[i] + block->x_shift;
		y = block->cord[i + 1] + block->y_shift;
	}
	return (i != 8);
}

void	replace(t_tris *block, t_map *map, char abc)
{
	int i;
	int y;
	int x;

	i = 0;
	while (i <= 6)
	{
		x = block->cord[i] + block->x_shift;
		y = block->cord[i + 1] + block->y_shift;
		map->arr[y][x] = abc;
		i += 2;
	}
}

int		border(t_tris *block, int map_size, char z)
{
	int i;

	if (z == 'x')
	{
		i = 0;
		while (i <= 6)
		{
			if (block->cord[i] + block->x_shift >= map_size)
				return (0);
			i += 2;
		}
	}
	if (z == 'y')
	{
		i = 1;
		while (i <= 7)
		{
			if (block->cord[i] + block->y_shift >= map_size)
				return (0);
			i += 2;
		}
	}
	return (1);
}

int		answer(t_map *map, t_tris *block, int map_size)
{
	if (!block)
		return (1);
	block->x_shift = 0;
	block->y_shift = 0;
	while (border(block, map_size, 'y'))
	{
		while (border(block, map_size, 'x'))
		{
			if (!collisions(map, block))
			{
				replace(block, map, block->abc);
				if (answer(map, block->next, map_size))
					return (1);
				else
					replace(block, map, '.');
			}
			block->x_shift++;
		}
		block->x_shift = 0;
		block->y_shift++;
	}
	return (0);
}
