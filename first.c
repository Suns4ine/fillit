/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:27:36 by cshawnee          #+#    #+#             */
/*   Updated: 2019/11/17 16:26:36 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_tris *blockslist;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(1);
	}
	if ((blockslist = checker(argv[1])) == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	solution(blockslist);
	freeman(blockslist);
	return (0);
}
