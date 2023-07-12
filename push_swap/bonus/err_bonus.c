/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:33:38 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/12 09:55:43 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_bonus.h"

void	ps_error(void)
{
	write(2, "Error\n", 6);
	exit(2);
}

void	ps_ko(void)
{
	write(1, "KO\n", 3);
	exit(0);
}

void	ps_ok(void)
{
	write(1, "OK\n", 3);
	exit(0);
}
