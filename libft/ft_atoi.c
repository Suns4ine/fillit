/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:28:30 by cshawnee          #+#    #+#             */
/*   Updated: 2019/09/24 16:47:05 by cshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_neg(unsigned long long nb, int sign, const char *str)
{
	int count;

	count = 0;
	while (*str <= '0' || *str >= '9')
		str++;
	while (ft_isdigit(*(str + count)))
		count++;
	if (count >= 19)
		return (sign == -1 ? 0 : -1);
	if (nb > 9223372036854775807)
		return (sign == -1 ? 0 : -1);
	else
		return (nb * sign);
}

int			ft_atoi(const char *str)
{
	unsigned long long	nb;
	int					len;
	int					i;
	int					sign;

	sign = 1;
	i = -1;
	len = 0;
	nb = 0;
	while (ft_isspace(*str))
		str++;
	while (str[len])
		len++;
	while (++i <= len)
	{
		if (ft_isdigit(str[i]))
			nb = (nb * 10) + (str[i] - '0');
		else if (i == 0 && (str[i] == '-' || str[i] == '+'))
			sign = str[i] == '-' ? -1 : 1;
		else
			return (ft_neg(nb, sign, str));
	}
	return (ft_neg(nb, sign, str));
}
