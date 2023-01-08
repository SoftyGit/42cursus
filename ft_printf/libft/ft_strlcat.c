/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:35:14 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/11/25 12:57:53 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// __UNUSED_RESTRICT__ //
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;

	if (!dstsize)
		return (ft_strlen(src));
	ret = ft_strlen(dst) + ft_strlen(src);
	while (--dstsize && *dst)
		dst++;
	if (!(dstsize))
		return (ret - ft_strlen(dst + 1));
	while (dstsize-- && *src)
		*(dst++) = *(src++);
	*dst = 0;
	return (ret);
}
