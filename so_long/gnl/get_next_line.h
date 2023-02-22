/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:20:19 by yongjale          #+#    #+#             */
/*   Updated: 2023/01/06 23:09:56 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*** __HEADER__START **********************************************************/
# include <stdlib.h>
# include <unistd.h>
/*** __HEADER__END ************************************************************/

/*** __CONST+MACROS+TYPEDEF__START ********************************************/
typedef struct list_fd
{
	int				val;
	char			*buf;
	struct list_fd	*prev;
	struct list_fd	*next;
}t_fd;
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
/*** __CONST+MACROS+TYPEDEF__END **********************************************/

/*** __FUNCTION__START ********************************************************/

/* __FUNCTION__START */
char	*get_next_line(int fd);
char	*get_ret(int mode, char *ret, t_fd *c_list);
char	*get_freed(int mode, char *ret, t_fd **t_list, t_fd *c_list);
t_fd	*get_list(int fd, t_fd **t_list);
t_fd	*init_list(int mode, int fd, t_fd *prev, t_fd *c_list);
/* __FUNCTION__END */

/* UTILS__FUNCTION__START */
size_t	len(int mode, const char *str);
void	lcpy(char *dst, const char *src, size_t dstsize);
/* UTILS__FUNCTION__END */

/*** __FUNCTION__END **********************************************************/

#endif
