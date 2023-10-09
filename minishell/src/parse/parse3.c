/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:09:53 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/24 17:00:07 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse.h"
#include "utils.h"

static int	get_status_in_quot(t_var *var, char *cmd)
{
	if (*cmd == var->is_quot)
	{
		var->is_quot = 0;
		return (QUOT);
	}
	else if (*cmd == 0)
		return (ERRO);
	return (CHAR);
}

static int	get_status_in_nothing(t_var *var, char *cmd)
{
	if (*cmd == '\'' || *cmd == '\"')
	{
		var->is_word = 1;
		var->is_quot = *cmd;
		var->temp = find_index(var->word, 1024);
		var->word[var->temp][0] = (cmd - var->cmd);
		return (QUOT);
	}
	else if (*cmd == '<' || *cmd == '>')
	{
		var->is_file = *cmd;
		return (IOFI);
	}
	var->is_word = 1;
	var->temp = find_index(var->word, 1024);
	var->word[var->temp][0] = (cmd - var->cmd);
	return (CHAR);
}

static int	get_status_in_null(t_var *var, char *cmd)
{
	var->temp = find_index(var->word, 1024);
	if (var->word[var->temp][1] == -1 && var->word[var->temp][0] != -1)
		var->word[var->temp][1] = (cmd - var->cmd) - 1;
	return (FINE);
}

int	get_status(t_var *var, char *cmd)
{
	if (var->is_quot)
		return (get_status_in_quot(var, cmd));
	if (var->is_word)
		return (get_status_in_word(var, cmd));
	else if (var->is_file)
		return (get_status_in_file(var, cmd));
	else if (*cmd != ' ' && *cmd != '\t' && *cmd != 0)
		return (get_status_in_nothing(var, cmd));
	else if (*cmd == 0)
		return (get_status_in_null(var, cmd));
	return (SPAC);
}
