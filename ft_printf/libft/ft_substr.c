/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:04:22 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/11/25 12:58:26 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*add;
	char	*ret;

	if (ft_strlen(s) <= start)
		len = 0;
	add = (char *)malloc(sizeof(char) * (len + 1));
	if (!(add))
		return (NULL);
	ret = add;
	while (*(s + start) && len--)
		*(add++) = *(s + start++);
	*(add) = 0;
	return (ret);
}
