/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:35:03 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/16 14:32:32 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

size_t static	count_words(char const *s, char c)
{
	size_t	i;
	size_t	cnt_words;

	i = 0;
	cnt_words = 0;
	while (*(s + i))
	{
		while (*(s + i) == c && *(s + i) != 0)
		{
			i++;
		}
		if (*(s + i))
		{
			cnt_words += 1;
		}
		while (*(s + i) != c && *(s + i) != 0)
		{
			i++;
		}
	}
	return (cnt_words);
}

void static	freearr(char **arrarr, size_t found_word)
{
	size_t	i;

	i = 0;
	while (i < found_word)
	{
		free(arrarr[i]);
		i++;
	}
}

char static	*put_word(const char *s, char c, char ***arrarr, size_t found_word)
{
	char	*arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(s + j) != c && *(s + j) != 0)
		j++;
	arr = malloc(sizeof(char) * (j + 1));
	if (arr == 0)
	{
		freearr(*arrarr, found_word);
		return (0);
	}
	while (i < j)
	{
		arr[i] = *(s + i);
		i++;
	}
	arr[j] = 0;
	return (arr);
}

int static	assign_word(char const *s, size_t cnt_words, char ***arrarr, char c)
{
	size_t	found_word;
	size_t	i;

	i = 0;
	found_word = 0;
	while (found_word < cnt_words)
	{
		while (*(s + i) == c && *(s + i) != 0)
			i++;
		if (*(s + i))
		{
			(*arrarr)[found_word] = put_word((s + i), c, arrarr, found_word);
			if ((*arrarr)[found_word] == 0)
				return (0);
			found_word++;
		}
		while (*(s + i) != c && *(s + i) != 0)
			i++;
	}
	return (1);
}

char	**ms_split(char const *s, char c)
{
	char	**arrarr;
	size_t	cnt_words;

	if (s == 0)
		return (NULL);
	cnt_words = count_words(s, c);
	arrarr = malloc(sizeof(char *) * (cnt_words + 1));
	if (arrarr == NULL)
		return (NULL);
	arrarr[cnt_words] = 0;
	if (assign_word(s, cnt_words, &arrarr, c) == 0)
	{
		free(arrarr);
		return (0);
	}
	return (arrarr);
}
