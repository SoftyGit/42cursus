/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_other_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:45:37 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/24 21:17:11 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	sl_strncmp(const char *s1, const char *s2, size_t n)
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

size_t	sl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s) != '\n' && *(s++))
		len++;
	return (len);
}

char	*sl_itoa(int n)
{
	size_t	len;
	char	*ret;
	long	val;

	len = 0;
	val = n;
	while (++len && n)
	{
		n /= 10;
		if (!n)
			break ;
	}
	ret = (char *)malloc(sizeof(char) * (len + (val < 0) + 1));
	if (!ret)
		return (NULL);
	ret[len + (val < 0)] = 0;
	ret[0] = 48 - 3 * (val < 0);
	if (val < 0)
		val *= -1 + ((len++) < 0);
	while (val)
	{
		ret[(--len)] = val % 10 + '0';
		val /= 10;
	}
	return (ret);
}

void	sl_free(int err_num, char **map)
{
	int	num;

	num = 0;
	while (num < err_num)
		free(map[num++]);
	sl_error(MALLOC_ERR);
}
