/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:03:24 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/27 06:56:05 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse.h"
#include "utils.h"

static int	get_pipe_status_in_quot(t_var *var, char *cmd)
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

static int	get_pipe_status_in_pipe(t_var *var, char *cmd)
{
	if (*cmd == '|' || *cmd == 0)
		return (ERRO);
	else if (*cmd != ' ' && *cmd != '\t')
	{
		var->is_pipe = 0;
		var->count++;
		var->temp = find_index(var->word, MAX_COMMAND);
		var->word[var->temp][0] = (cmd - var->cmd);
		return (CHAR);
	}
	return (SPAC);
}

int	get_pipe_status(t_var *var, char *cmd)
{
	if (var->is_quot)
		return (get_pipe_status_in_quot(var, cmd));
	else if (var->is_pipe)
		return (get_pipe_status_in_pipe(var, cmd));
	else if (*cmd == '\'' || *cmd == '\"')
	{
		var->is_quot = *cmd;
		return (QUOT);
	}
	else if (*cmd == '|')
	{
		var->temp = find_index(var->word, MAX_COMMAND);
		var->word[var->temp][1] = (cmd - var->cmd) - 1;
		var->is_pipe = 1;
	}
	else if (*cmd != ' ' && *cmd != '\t' && *cmd != 0)
		return (CHAR);
	else if (*cmd == 0)
	{
		var->temp = find_index(var->word, MAX_COMMAND);
		var->word[var->temp][1] = (cmd - var->cmd) - 1;
		return (FINE);
	}
	return (SPAC);
}

static t_job	*get_pipe_word(t_job *job, t_var *var, char *std_cmd)
{
	t_command	*ret;
	t_var		n;
	char		*cmd;
	size_t		i;

	i = 0;
	ret = NULL;
	while (i < var->count + 1)
	{
		cmd = get_string(std_cmd, var->word[i][0], var->word[i][1], 0);
		if (!cmd)
			return (ms_free(job));
		init_var(&n, cmd, MAX_COMMAND);
		if (!get_pipe_in_word(job, &n, cmd))
			return (NULL);
		ret = get_pipe_ret_in_word(job, ret);
		init_command(ret);
		ret->command = get_string(n.cmd, n.word[0][0], n.word[0][1], 1);
		get_pipe_word_in_word(&n, ret);
		get_pipe_infile_in_word(&n, ret);
		get_pipe_outfile_in_word(&n, ret);
		free(n.cmd);
		i++;
	}
	return (job);
}

t_job	*get_job(char *cmd)
{
	char	*std_cmd;
	t_job	*job;
	t_var	var;
	int		stat;

	job = (t_job *)malloc(sizeof(t_job));
	init_job(job);
	std_cmd = cmd;
	init_var(&var, std_cmd, MAX_COMMAND);
	var.word[0][0] = 0;
	if (*cmd == '|')
		return (ms_free(job));
	while (1)
	{
		stat = get_pipe_status(&var, cmd);
		if (stat == FINE)
			break ;
		else if (stat == ERRO)
			return (ms_free(job));
		cmd++;
	}
	job->num_command = var.count + 1;
	return (get_pipe_word(job, &var, std_cmd));
}
