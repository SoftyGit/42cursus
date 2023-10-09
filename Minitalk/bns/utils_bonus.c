/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 10:04:38 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/28 15:28:10 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*mt_itoa(int n)
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
