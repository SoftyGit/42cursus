/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:33:18 by yongjale          #+#    #+#             */
/*   Updated: 2023/06/28 11:24:47 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "ps.h"
# include <stdio.h>

void	ps_printer(int	data);
void	ps_lstiter(t_node *lst, void (*f)(int));
void	ps_lstreviter(t_node *lst, void (*f)(int));

#endif