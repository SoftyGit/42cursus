/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:01:12 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/12/17 14:12:05 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_helper_hex_hig(unsigned long long val, size_t *len)
{
	char	ret;

	if (val)
	{
		ret = val % 16;
		ret = (ret < 10) * (ret + 48) + (ret >= 10) * (ret + 55);
		ft_helper_hex_hig((val - (val % 16)) / 16, len);
		write(1, &ret, 1);
		(*len)++;
	}
}

void	ft_helper_hex_low(unsigned long long val, size_t *len)
{
	char	ret;

	if (val)
	{
		ret = val % 16;
		ret = (ret < 10) * (ret + 48) + (ret >= 10) * (ret + 87);
		ft_helper_hex_low((val - (val % 16)) / 16, len);
		write(1, &ret, 1);
		(*len)++;
	}
}

char	*ft_itoa_unsigned(unsigned int n)
{
	size_t			len;
	char			*ret;
	unsigned long	val;

	len = 0;
	val = n;
	while (++len && n)
	{
		n /= 10;
		if (!n)
			break ;
	}
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = 0;
	ret[0] = 48;
	while (val)
	{
		ret[(--len)] = val % 10 + '0';
		val /= 10;
	}
	return (ret);
}
