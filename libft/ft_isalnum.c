/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:36:53 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/09 14:19:01 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int r;
	int t;

	r = ft_isdigit(c);
	t = ft_isalpha(c);
	if (r > 0 || t > 0)
		return (1);
	return (0);
}
