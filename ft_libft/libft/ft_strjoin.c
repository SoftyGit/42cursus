/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:19:43 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/11/25 12:58:31 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*add;
	char	*ret;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	add = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!add)
		return (NULL);
	ret = add;
	while (len1--)
		*(add++) = *(s1++);
	while (len2--)
		*(add++) = *(s2++);
	*(add) = 0;
	return (ret);
}
