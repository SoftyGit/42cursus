/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:33:29 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/12 08:47:44 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "err.h"

int		ps_atoi(const char *str);
int		ps_isdigit(int c);
size_t	ps_strlen(const char *s);

#endif