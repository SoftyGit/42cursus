/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 03:29:14 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/11/25 12:59:16 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	len;
	char	*ret;
	long	val;

	len = 0;
	val = n;
	while (++len && n)
	{
		n /= 10;
		if (!n)
			break ;
	}
	ret = (char *)malloc(sizeof(char) * (len + (val < 0) + 1));
	if (!ret)
		return (NULL);
	ret[len + (val < 0)] = 0;
	ret[0] = 48 - 3 * (val < 0);
	if (val < 0)
		val *= -1 + ((len++) < 0);
	while (val)
	{
		ret[(--len)] = val % 10 + '0';
		val /= 10;
	}
	return (ret);
}
