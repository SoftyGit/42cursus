/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:51:04 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/11/25 12:58:33 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	char	*add;

	add = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!(add))
		return (NULL);
	ret = add;
	while (*s1)
		*(add++) = *(s1++);
	*add = 0;
	return (ret);
}
