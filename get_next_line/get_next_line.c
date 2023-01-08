/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:43:31 by yongjale          #+#    #+#             */
/*   Updated: 2023/01/06 23:09:36 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_fd	*t_list = NULL;
	t_fd		*c_list;
	char		*ret;
	int			stat;

	c_list = get_list(fd, &t_list);
	ret = get_ret(0, NULL, c_list);
	while (len(0, ret) == len(1, ret))
	{
		stat = read(fd, c_list->buf, BUFFER_SIZE);
		if (stat <= 0)
			return (get_freed(stat, ret, &t_list, c_list));
		c_list->buf[stat] = 0;
		ret = get_ret(1, ret, c_list);
		if ((len(0, c_list->buf) != len(1, c_list->buf))
			&& len(1, c_list->buf) != BUFFER_SIZE)
			break ;
	}
	return (ret);
}

char	*get_ret(int mode, char *ret, t_fd *c_list)
{
	char	*tmp;
	size_t	size;

	if (mode == 0 && (c_list->buf[0]) && (len(1, c_list->buf) < BUFFER_SIZE))
	{
		size = len(2, c_list->buf) - len(1, c_list->buf) + 1;
		if (size == 1)
			return (ret = NULL);
		ret = (char *)malloc(size);
		lcpy(ret, c_list->buf + len(1, c_list->buf), size);
		size = len(1, c_list->buf);
		lcpy(c_list->buf, c_list->buf + size, BUFFER_SIZE - size + 1);
	}
	else if (mode == 1)
	{
		tmp = ret;
		size = len(1, ret) + len(1, c_list->buf) + 1;
		if (size == 1)
			return (ret = NULL);
		ret = (char *)malloc(size);
		lcpy(ret, tmp, len(1, tmp) + 1);
		lcpy(ret + len(1, tmp), c_list->buf, len(1, c_list->buf) + 1);
		free(tmp);
	}
	return (ret);
}

char	*get_freed(int mode, char *ret, t_fd **t_list, t_fd *c_list)
{
	free(c_list->buf);
	if (*t_list == c_list)
		*t_list = c_list->next;
	else
		c_list->prev->next = c_list -> next;
	free(c_list);
	if (ret && mode == -1)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

t_fd	*get_list(int fd, t_fd **t_list)
{
	t_fd	*c_list;

	if (!(*t_list))
	{
		*t_list = (t_fd *)malloc(sizeof(t_fd));
		return (init_list(0, fd, NULL, *t_list));
	}
	c_list = *t_list;
	while (1)
	{
		if (c_list->val == fd)
			return (c_list);
		else if (c_list->next == NULL)
			return (init_list(1, fd, c_list, c_list->next));
		c_list = c_list->next;
	}
}

t_fd	*init_list(int mode, int fd, t_fd *prev, t_fd *c_list)
{
	if (mode == 1)
	{
		prev->next = (t_fd *)malloc(sizeof(t_fd));
		c_list = prev->next;
	}
	c_list->val = fd;
	c_list->buf = (char *)malloc(BUFFER_SIZE + 1);
	c_list->buf[0] = 0;
	c_list->prev = prev;
	c_list->next = NULL;
	return (c_list);
}
