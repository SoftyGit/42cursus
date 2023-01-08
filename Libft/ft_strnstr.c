/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 01:18:44 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/11/25 12:58:29 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	chklen;

	if (!haystack && !len)
		return (NULL);
	chklen = ft_strlen(needle);
	while (*haystack && chklen <= len--)
		if (!ft_strncmp(haystack++, needle, chklen))
			return ((char *)--haystack);
	return (NULL);
}
