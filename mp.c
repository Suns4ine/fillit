/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:26:08 by cshawnee          #+#    #+#             */
/*   Updated: 2019/11/15 14:57:11 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print(t_map *map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size)
	{
		ft_putstr(map->arr[i]);
		ft_putchar('\n');
		i++;
	}
}

void	free_map(t_map *map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size)
	{
		ft_memdel((void **)&(map->arr[i]));
		i++;
	}
	ft_memdel((void **)&(map->arr));
	ft_memdel((void **)&map);
}

t_map	*map_maker(int size)
{
	t_map	*map;
	int		i;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	map->arr = (char **)malloc(size * sizeof(char *));
	while (i < size)
	{
		map->arr[i] = ft_strnew(size);
		ft_memset(map->arr[i], '.', size);
		i++;
	}
	return (map);
}
