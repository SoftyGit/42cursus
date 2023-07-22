/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:41:58 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/22 14:57:03 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static	int	ph_isblank(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	ph_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ph_atoi(const char *str)
{
	size_t	ret;
	char	sign;

	ret = 0;
	sign = 1;

	while (ph_isblank(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = ',' - *(str++);
	while (ph_isdigit(*str))
		ret = ret * 10 + (*(str++) - '0');
	return (sign * ret);
}