/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 01:46:41 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/11/25 12:59:15 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	type;
	char	*add;

	type = size;
	add = (char *)malloc(sizeof(char) * count * size);
	if (!(add))
		return (NULL);
	while (count--)
	{
		size = type;
		while (size--)
			*(add + count * type + size) = 0;
	}
	return ((void *)add);
}
