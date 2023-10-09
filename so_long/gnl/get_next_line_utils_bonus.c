/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:50:34 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/24 21:18:17 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	len(int mode, const char *str)
{
	const char	*org;

	org = str;
	if (!str)
		return (0);
	while (*str && ((mode >= 2) || !(*str == '\n')))
	{
		if ((*str == '\n') && (mode == 2))
			mode--;
		str++;
	}
	return (str - org + ((mode != 0) && (*str == '\n')));
}

void	lcpy(char *dst, const char *src, size_t dstsize)
{
	if (!dstsize)
		return ;
	while (--dstsize && *src)
		*(dst++) = *(src++);
	*dst = 0;
}
