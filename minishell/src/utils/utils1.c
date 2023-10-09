/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:11:01 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/16 14:32:02 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

int	ms_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (1);
		else if (*(unsigned char *)s1 < *(unsigned char *)s2)
			return (-1);
		else if (!*s1)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

char	*ms_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	while (*s != 0)
		if (*(s++) == c)
			ret = (char *)(s - 1);
	if (c == 0)
		return ((char *)s);
	return (ret);
}

char	*ms_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*add;
	char	*ret;

	len1 = ms_strlen(s1);
	len2 = ms_strlen(s2);
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

size_t	ms_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (*(s++))
		len++;
	return (len);
}
