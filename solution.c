/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:29:53 by cshawnee          #+#    #+#             */
/*   Updated: 2019/11/15 17:08:25 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tris	*zero_cord(t_tris *block)
{
	int i;
	int miny;
	int minx;
	int size;

	i = 0;
	miny = 1024;
	minx = 1024;
	size = 4;
	while (size)
	{
		if (miny > block->cord[i + 1])
			miny = block->cord[i + 1];
		if (minx > block->cord[i])
			minx = block->cord[i];
		i += 2;
		size--;
	}
	shift_x(block, minx);
	shift_y(block, miny);
	return (block);
}

t_tris	*piecemaker(char *buff, char abc)
{
	t_tris	*block;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 1;
	if (!(block = (t_tris*)malloc(sizeof(t_tris))))
		return (NULL);
	while (i < 20)
	{
		if (buff[i] == '#')
		{
			block->cord[x] = i % 5;
			block->cord[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	block->abc = abc;
	return (zero_cord(block));
}

t_tris	*makeblocks(char *buff, int size)
{
	t_tris	*begin;
	t_tris	*node;
	int		i;
	char	abc;

	i = 0;
	abc = 65;
	while (i < size)
	{
		if (abc == 65)
		{
			begin = piecemaker(buff + i, abc);
			node = begin;
		}
		else
		{
			node->next = piecemaker(buff + i, abc);
			node = node->next;
		}
		abc++;
		i += 21;
	}
	node->next = NULL;
	return (begin);
}

void	solution(t_tris *blockslist)
{
	t_map	*map;
	int		map_size;

	map_size = ft_sqrt(number(blockslist) * 4);
	map = map_maker(map_size);
	while (!answer(map, blockslist, map_size))
	{
		free_map(map, map_size);
		map_size++;
		map = map_maker(map_size);
	}
	print(map, map_size);
	free_map(map, map_size);
}
