/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:59:30 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/27 07:03:27 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse.h"
#include "utils.h"

static int	get_file_status_in_word(t_var *var, char *cmd)
{
	var->count++;
	var->is_word = 0;
	var->is_file = (*cmd);
	var->temp = find_index(var->word, 1024);
	var->word[var->temp][1] = (cmd - var->cmd) - 1;
	return (IOFI);
}

static int	get_space_status_in_word(t_var *var, char *cmd)
{
	if (var->is_file)
	{
		var->type = (var->is_file % '>' == 0) * 2 + (var->is_file > '>');
		var->temp = find_index(var->file[var->type], 1024);
		var->file[var->type][var->temp][1] = (cmd - var->cmd) - 1;
		var->is_file = 0;
	}
	else
	{
		var->temp = find_index(var->word, 1024);
		var->word[var->temp][1] = (cmd - var->cmd) - 1;
	}
	var->is_word = 0;
	var->count++;
	if (*cmd == 0)
		return (FINE);
	return (SPAC);
}

int	get_status_in_word(t_var *var, char *cmd)
{
	if (*cmd == ' ' || *cmd == '\t' || *cmd == 0)
		return (get_space_status_in_word(var, cmd));
	else if (*cmd == '<' || *cmd == '>')
		return (get_file_status_in_word(var, cmd));
	else if (*cmd == '\'' || *cmd == '\"')
	{
		var->is_word = 1;
		var->is_quot = *cmd;
		return (QUOT);
	}
	return (CHAR);
}

static int	get_file_status_in_file(t_var *var, char *cmd)
{
	if (var->is_file != *cmd)
		return (ERRO);
	else if (*(cmd -1) != *cmd)
	{
		if (var->is_word)
		{
			var->is_word = 0;
			var->temp = find_index(var->file
				[(var->is_file % '>' == 0) * 2 + (var->is_file > '>')], 1024);
			var->file[(var->is_file % '>' == 0) * 2 + (var->is_file > '>')]
			[var->temp][1] = (cmd - var->cmd) - 1;
			var->is_file = *cmd;
			var->count++;
			return (IOFI);
		}
		return (ERRO);
	}
	var->is_file += (*cmd);
	return (IOFI);
}

int	get_status_in_file(t_var *var, char *cmd)
{
	if (*cmd == '<' || *cmd == '>')
		return (get_file_status_in_file(var, cmd));
	else if (*cmd == 0)
		return (FINE);
	else if (*cmd != ' ' && *cmd != '\t')
	{
		var->is_word = 1;
		var->temp = find_index(var->file
			[(var->is_file % '>' == 0) * 2 + (var->is_file > '>')], 1024);
		var->file[(var->is_file % '>' == 0) * 2 + (var->is_file > '>')]
		[var->temp][0] = (cmd - var->cmd);
		if (*cmd == '\'' || *cmd == '\"')
		{
			var->is_quot = *cmd;
			return (QUOT);
		}
		return (CHAR);
	}
	return (SPAC);
}
