/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:33:45 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/12 08:54:27 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

int	ps_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static	int	ps_isblank(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ps_atoi(const char *str)
{
	long long	ret;
	char		sign;

	ret = 0;
	sign = 1;
	while (ps_isblank(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = ',' - *(str++);
	if (!ps_isdigit(*str))
		ps_error();
	while (ps_isdigit(*str))
	{
		ret = ret * 10 + (*(str++) - '0');
		if (ret > 2147483648 - (sign == 1))
			ps_error();
	}
	if (*str)
		ps_error();
	return (sign * ret);
}

size_t	ps_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s++))
		len++;
	return (len);
}

int	ps_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (1);
		else if (*(unsigned char *)s1 < *(unsigned char *)s2)
			return (-1);
		else if (!*s1)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
