/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:30:43 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/12/04 10:43:53 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_helper(char **s, char **add, char c)
{
	while (**s == c && (**s))
		(*s)++;
	if (!(**s))
		return (0);
	*add = *s;
	while (**s != c && (**s))
		(*s)++;
	return (1);
}

static char	**ft_free(char **ret, size_t len)
{
	while (len)
		free(ret[len--]);
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		len;
	char		*add;
	char		**ret;
	const char	*org;

	len = 0;
	org = s;
	while (ft_helper((char **)&s, &add, c))
		len++;
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	if (!ret)
		return (NULL);
	s = org;
	len = 0;
	while (ft_helper((char **)&s, &add, c))
	{
		ret[len] = (char *)malloc(sizeof(char) * (s - add + 1));
		if (!(*ret))
			return (ft_free(ret, len));
		ft_strlcpy(ret[len++], add, s - add + 1);
	}
	ret[len] = NULL;
	return (ret);
}
