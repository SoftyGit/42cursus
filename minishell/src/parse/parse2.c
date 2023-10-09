/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:06:27 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/27 06:56:25 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse.h"
#include "utils.h"

void	*get_pipe_in_word(t_job *job, t_var *n_var, char *cmd)
{
	int		stat;

	while (1)
	{
		stat = get_status(n_var, cmd);
		if (stat == FINE)
			break ;
		else if (stat == ERRO)
			return (ms_free(job));
		cmd++;
	}
	return (cmd);
}

void	get_pipe_word_in_word(t_var *n_var, t_command *ret)
{
	size_t	size;
	size_t	i;

	size = find_index(n_var->word, MAX_COMMAND);
	if (n_var->word[0][0] == -1)
	{
		size = 1;
		ret->command = (char *)malloc(1);
		ret->command[0] = 0;
	}
	if (size > 0)
	{
		ret->args = (char **)malloc(sizeof(char *) * (size + 1));
		ret->args[0] = ret->command;
		ret->args[size] = NULL;
		i = 1;
		while (i < size)
		{
			ret->args[i] = get_string(n_var->cmd,
					n_var->word[i][0], n_var->word[i][1], 1);
			i++;
		}
	}
}

void	get_pipe_infile_in_word(t_var *n_var, t_command *ret)
{
	t_red_in	*red_in;
	size_t		size;
	size_t		i;

	red_in = NULL;
	size = find_index(n_var->file[0], MAX_COMMAND);
	i = 0;
	while (i < size)
	{
		red_in = make_in_index(ret, red_in);
		red_in->infile = get_string(n_var->cmd,
				n_var->file[0][i][0], n_var->file[0][i][1], 1);
		red_in->type = REDIRECTION_IN;
		i++;
	}
	size = find_index(n_var->file[1], MAX_COMMAND);
	i = 0;
	while (i < size)
	{
		red_in = make_in_index(ret, red_in);
		red_in->infile = get_string(n_var->cmd,
				n_var->file[1][i][0], n_var->file[1][i][1], 1);
		red_in->type = REDIRECTION_HEREDOC;
		i++;
	}
}

t_command	*get_pipe_ret_in_word(t_job *job, t_command *ret)
{
	if (!ret)
	{
		job->command = (t_command *)malloc(sizeof(t_command));
		ret = job->command;
	}
	else
	{
		ret->next_command = (t_command *)malloc(sizeof(t_command));
		ret = ret->next_command;
	}
	return (ret);
}

void	get_pipe_outfile_in_word(t_var *n_var, t_command *ret)
{
	t_red_out	*red_out;
	size_t		size;
	size_t		i;

	red_out = NULL;
	size = find_index(n_var->file[2], MAX_COMMAND);
	i = 0;
	while (i < size)
	{
		red_out = make_out_index(ret, red_out);
		red_out->outfile = get_string(n_var->cmd,
				n_var->file[2][i][0], n_var->file[2][i][1], 1);
		red_out->type = REDIRECTION_OUT;
		i++;
	}
	size = find_index(n_var->file[3], MAX_COMMAND);
	i = 0;
	while (i < size)
	{
		red_out = make_out_index(ret, red_out);
		red_out->outfile = get_string(n_var->cmd,
				n_var->file[3][i][0], n_var->file[3][i][1], 1);
		red_out->type = REDIRECTION_APPEND;
		i++;
	}
}
