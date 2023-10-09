/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 01:18:55 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/24 17:00:06 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	get_pipe_status_in_cmd_pipe(t_var *var, char *cmd)
{
	var->is_pipe = *cmd;
	if ((cmd - var->cmd) - 1 < 0)
		return (ERRO);
	var->temp = find_index(var->word, MAX_COMMAND);
	var->word[var->temp][1] = (cmd - var->cmd) - 1;
	return (PIPE);
}
