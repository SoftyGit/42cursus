/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:02:16 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/11/25 12:58:27 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*add[3];
	char	*ret;

	add[0] = (char *)s1;
	add[1] = add[0] + ft_strlen(s1);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	add[0] = (char *)s1;
	while (*(s1++))
		if (!ft_strchr(set, *(s1 - 1)) && ft_strchr(set, *s1))
			add[1] = (char *)s1;
	ret = (char *)malloc(sizeof(char) * (add[1] - add[0] + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, add[0], add[1] - add[0] + 1);
	return (ret);
}
