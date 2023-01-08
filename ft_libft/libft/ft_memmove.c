/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:46:01 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/11/25 12:59:19 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*ret;

	ret = dst;
	if (dst < src)
		while (dst != src && len--)
			*((char *)dst++) = *((char *)src++);
	else
		while (dst != src && len--)
			*((char *)dst + len) = *((char *)src + len);
	return (ret);
}
