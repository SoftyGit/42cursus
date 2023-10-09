/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:03:00 by dojeong           #+#    #+#             */
/*   Updated: 2022/12/24 19:15:37 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*arr;
	char		*buf;
	int			read_num;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == 0)
		return (free_arrays(&arr, &buf));
	while (1)
	{
		if (arr != 0 && ft_streol(arr) >= 0)
			return (check_eol(&arr, &buf));
		read_num = read(fd, buf, BUFFER_SIZE);
		if (read_num == -1)
			return (free_arrays(&arr, &buf));
		buf[read_num] = '\0';
		arr = ft_strjoin(&arr, buf);
		if (arr == 0)
			return (free_arrays(&arr, &buf));
		if (read_num < BUFFER_SIZE)
			return (check_eof(&arr, &buf));
	}
}

char	*check_eof(char **arr, char **buf)
{
	char	*temp;
	int		arr_len;

	arr_len = ft_strlen(*arr);
	temp = malloc(sizeof(char) * (arr_len + 1));
	if (temp == 0)
		return (free_arrays(arr, buf));
	ft_memmove(temp, *arr, arr_len + 1);
	if (ft_streol(*arr) >= 0)
	{
		free_array(&temp);
		return (check_eol(arr, buf));
	}
	free_array(arr);
	free_array(buf);
	return (temp);
}

char	*check_eol(char **arr, char **buf)
{
	char	*temp;
	int		arr_len;
	int		loc;

	free_array(buf);
	loc = ft_streol(*arr);
	arr_len = ft_strlen(*arr);
	if (loc == -1)
		loc = arr_len + 1;
	temp = malloc(sizeof(char) * (loc + 2));
	if (temp == 0)
	{
		free_array(arr);
		return (NULL);
	}
	ft_memmove(temp, *arr, loc + 1);
	temp[loc + 1] = '\0';
	if ((*arr)[loc + 1] == '\0')
		free_array(arr);
	else
	{
		ft_memmove(*arr, *arr + loc + 1, arr_len - loc - 1);
		(*arr)[arr_len - loc - 1] = '\0';
	}
	return (temp);
}

void	*free_arrays(char **arr, char **buf)
{
	free_array(arr);
	free_array(buf);
	return (NULL);
}
