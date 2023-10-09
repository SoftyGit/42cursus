/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:03:55 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/19 18:30:00 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char **s1, char *s2)
{
	char	*arr;
	size_t	len_s1;
	size_t	len_s2;

	if (s2[0] == '\0')
		return (*s1);
	if (*s1 == 0)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(*s1);
	len_s2 = ft_strlen(s2);
	arr = malloc(len_s1 + len_s2 + 1);
	if (arr == 0)
	{
		free_array(s1);
		return (NULL);
	}
	ft_memmove(arr, *s1, len_s1);
	ft_memmove(arr + len_s1, s2, len_s2);
	arr[len_s1 + len_s2] = '\0';
	free(*s1);
	return (arr);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		size++;
		s++;
	}
	return (size);
}

int	ft_streol(char *s)
{
	size_t	len;
	size_t	i;

	if (s == 0)
		return (-1);
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		if (*(s + i) == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	if ((void *)src < dst)
	{
		while (i < len)
		{
			*(unsigned char *)(dst + (len - i - 1)) \
			= *(unsigned char *)(src + (len - i - 1));
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return ((void *)dst);
}

void	free_array(char **arr)
{
	if (*arr != 0)
	{
		free(*arr);
		*arr = (void *)0;
	}
}
