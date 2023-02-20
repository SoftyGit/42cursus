/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_input_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:59:15 by yongjale          #+#    #+#             */
/*   Updated: 2023/02/20 21:01:32 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit(0);
	else
		sl_control_hook(keycode, vars);
	return (0);
}

int	sl_destroy_hook(int keycode, t_vars *vars)
{
	exit(0);
}
