/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:42:45 by cshawnee          #+#    #+#             */
/*   Updated: 2019/11/17 16:26:07 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*shift_row(int *tetro)
{
	int i;
	int miny;

	i = 1;
	miny = 1024;
	while (i <= 7)
	{
		if (miny > tetro[i])
			miny = tetro[i];
		i += 2;
	}
	i = 1;
	while (i <= 7)
	{
		tetro[i] -= miny;
		i += 2;
	}
	return (tetro);
}

int		*shift_col(int *tetro)
{
	int i;
	int minx;

	i = 0;
	minx = 1024;
	while (i <= 6)
	{
		if (minx > tetro[i])
			minx = tetro[i];
		i += 2;
	}
	i = 0;
	while (i <= 6)
	{
		tetro[i] -= minx;
		i += 2;
	}
	return (tetro);
}

int		tabcmp(int *tetro, int *arr)
{
	int i;

	i = 0;
	while (i <= 7)
	{
		if (tetro[i] != arr[i])
			return (0);
		i++;
	}
	return (1);
}

int		validator(int *tetro)
{
	int i;

	i = 0;
	tetro = shift_col(tetro);
	tetro = shift_row(tetro);
	return (tabcmp(tetro, I_PIECE) ||
			tabcmp(tetro, IH_PIECE) ||
			tabcmp(tetro, O_PIECE) ||
			tabcmp(tetro, L_PIECE) ||
			tabcmp(tetro, LR_PIECE) ||
			tabcmp(tetro, LD_PIECE) ||
			tabcmp(tetro, LL_PIECE) ||
			tabcmp(tetro, J_PIECE) ||
			tabcmp(tetro, JR_PIECE) ||
			tabcmp(tetro, JD_PIECE) ||
			tabcmp(tetro, JL_PIECE) ||
			tabcmp(tetro, T_PIECE) ||
			tabcmp(tetro, TR_PIECE) ||
			tabcmp(tetro, TD_PIECE) ||
			tabcmp(tetro, TL_PIECE) ||
			tabcmp(tetro, S_PIECE) ||
			tabcmp(tetro, SR_PIECE) ||
			tabcmp(tetro, Z_PIECE) ||
			tabcmp(tetro, ZR_PIECE));
}
