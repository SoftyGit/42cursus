/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:43:31 by yongjale          #+#    #+#             */
/*   Updated: 2022/12/22 12:26:17 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <printf.h>
char *get_next_line(int fd)
{
	static t_list_fd	*list = NULL;
	t_list_fd			*cur_list;

	if (!list) // 초기화가 안 되어 있다면
		list = get_cur_list(fd, list);
	cur_list = get_cur_list(fd, list); // 사용할 리스트 불러오기 (여러 fd 대비)
	if (!cur_list)
		return (NULL);
	cur_list->ret = get_updated_ret(cur_list->ret , cur_list->rd, 0); // 기존 못 읽읕 거 있으면 추가 & 없으면 NULL 초기화
	while (1)
	{
		if (read(fd, cur_list->rd, BUFFER_SIZE) == -1) // END: 파일 끝까지 다 읽었을 때
			return (NULL);
		cur_list->ret = get_updated_ret(cur_list -> ret, cur_list -> rd, 1); // ret 에 새로운 거 추가
		if (get_len(cur_list -> rd, 1) != get_len(cur_list -> rd, 0)) // 개행 있을 때
			return (cur_list -> ret);											// (찌거기 값) 초기화 X + (한 줄 합쳐진 상태)로 종료
	}
	return (NULL);
}

char *get_updated_ret(char *dst, char *src, int mode)
{
	char	*tmp;
	char	*ret;
	size_t	size;

	if (!(*src))
		return (dst);
	else if (!mode)
	{
		size = BUFFER_SIZE - get_len(src, 1);
		dst[size] = 0;
		src += get_len(src, 1);
		while (*src)
			*(dst++) = *(src++);
		return (dst - size);
	}
	size = get_len(dst, 2) + get_len(src, 1);
	ret = (char *)malloc(size + 1);
	ret[size] = 0;
	tmp = dst;
	while (*tmp)
		*(ret++) = *(tmp++);
	while (*src)
	{
		*(ret++) = *(src++);
		if (*(src - 1) == '\n')
			break;
	}
	if (dst)
		free(dst);
	return (ret - size);
}

size_t get_len(char *str, int mode) // mode: 0 (개행 제외 개행까지 길이) / mode: 1 (개행 포함 개행까지 길이) / mode: 2 (그냥 strlen)
{
	char *org;

	org = str;
	if (!str)
		return (0);
	while (*str && ((mode == 2) || (*str != '\n')))
		str++;
	return (str - org + ((mode == 1) && (*str == '\n')));
}

t_list_fd *get_ini_list(int fd)
{
	t_list_fd *new_list;

	new_list = (t_list_fd *)malloc(sizeof(t_list_fd));
	if (!new_list)
		return (NULL);
	new_list -> val = fd;
	new_list -> rd = (char *)malloc(BUFFER_SIZE + 1);
	new_list -> ret = (char *)malloc(BUFFER_SIZE + 1);
	new_list -> ret[BUFFER_SIZE] = 0;
	new_list -> next_fd = NULL;
	return (new_list);
}

t_list_fd *get_cur_list(int fd, t_list_fd *list)
{
	t_list_fd *new_list;

	while (1)
	{
		if (!list)
			return (get_ini_list(fd));
		else if (list->val == fd) // 리스트 돌다가 기존 fd 발견 시
			return (list);
		else if (!(list->next_fd)) // 리스트 다 돌았는데 fd 발견 못할 시
		{
			new_list = (t_list_fd *)malloc(sizeof(t_list_fd));
			if (!new_list)
				return (NULL);
			new_list->val = fd;
			new_list->next_fd = NULL;
			list->next_fd = new_list;
		}
		list = list->next_fd;
	}
}

int main()
{

	int fd;
	fd = open("file", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
