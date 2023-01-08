/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:56:23 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/11/25 12:59:24 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// __UNUSED_RESTRICT__ //
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*ret;

	ret = (char *)src;
	if (!dstsize)
		return (ft_strlen(src));
	while (--dstsize && *src)
		*(dst++) = *(src++);
	*dst = 0;
	return (ft_strlen(ret));
}
