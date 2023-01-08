/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 01:29:14 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/11/25 12:59:13 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isblank(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	ret;
	char	sign;

	ret = 0;
	sign = 1;
	while (ft_isblank(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = ',' - *(str++);
	while (ft_isdigit(*str))
		ret = ret * 10 + (*(str++) - '0');
	return (sign * ret);
}
