/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:27:31 by cshawnee          #+#    #+#             */
/*   Updated: 2019/11/18 15:41:13 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		charchecker(char *buff)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (i < 19)
	{
		if (buff[i] && buff[i] != '\n' && buff[i] != '#' && buff[i] != '.')
			return (0);
		if (buff[i] == '\n' && ((i + 1) % 5) != 0)
			return (0);
		if (buff[i] == '#')
			ret++;
		i++;
	}
	if (!buff[i] || buff[i] != '\n')
		return (0);
	return (ret);
}

int		*ttcheck(char *buff, int *map)
{
	int pos;
	int col;
	int row;
	int i;

	i = 0;
	pos = 0;
	while (pos < 19)
	{
		col = pos % 5;
		row = pos / 5;
		if (buff[pos] == '#')
		{
			map[i] = col;
			i++;
			map[i] = row;
			i++;
		}
		pos++;
	}
	return (map);
}

int		maincheck(char *buff, int size)
{
	int i;
	int *map;
	int c;

	i = 0;
	map = (int *)malloc(8 * sizeof(int*));
	while (i <= size)
	{
		if (charchecker(buff + i) != 4)
			return (0);
		i += 21;
	}
	i = 0;
	while (i <= size)
	{
		if (!(c = validator(ttcheck(buff + i, map))))
			return (0);
		c = 0;
		i += 21;
	}
	free(map);
	map = NULL;
	return (1);
}

t_tris	*checker(char *file)
{
	int		fd;
	char	buff[546];
	int		bytecount;

	fd = open(file, O_RDONLY);
	bytecount = read(fd, buff, 546);
	close(fd);
	if (bytecount > 545 || bytecount < 19)
		return (0);
	buff[bytecount] = '\0';
	if (!maincheck(buff, bytecount))
		return (0);
	return (makeblocks(buff, bytecount));
}
