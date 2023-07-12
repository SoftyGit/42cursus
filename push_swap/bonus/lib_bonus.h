/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:33:29 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/12 09:59:07 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_BONUS_H
# define LIB_BONUS_H

# include "err_bonus.h"

int		ps_atoi(const char *str);
int		ps_isdigit(int c);
size_t	ps_strlen(const char *s);
int		ps_strncmp(const char *s1, const char *s2, size_t n);

#endif