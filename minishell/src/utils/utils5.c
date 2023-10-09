/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:49:11 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/24 01:01:56 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

void	init_command(t_command *cmd)
{
	cmd->args = NULL;
	cmd->command = NULL;
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->next_command = NULL;
}

void	init_job(t_job *job)
{
	job->num_command = 0;
	job->command = NULL;
}

t_red_in	*make_in_index(t_command *command, t_red_in *red_in)
{
	if (!red_in)
	{
		command->infile = (t_red_in *)malloc(sizeof(t_red_in));
		red_in = command->infile;
	}
	else
	{
		red_in->next = (t_red_in *)malloc(sizeof(t_red_in));
		red_in = red_in->next;
	}
	red_in->infile = NULL;
	red_in->type = -1;
	red_in->next = NULL;
	return (red_in);
}

t_red_out	*make_out_index(t_command *command, t_red_out *red_out)
{
	if (!red_out)
	{
		command->outfile = (t_red_out *)malloc(sizeof(t_red_out));
		red_out = command->outfile;
	}
	else
	{
		red_out->next = (t_red_out *)malloc(sizeof(t_red_out));
		red_out = red_out->next;
	}
	red_out->outfile = NULL;
	red_out->type = -1;
	red_out->next = NULL;
	return (red_out);
}

void	init_part_env(t_env *env)
{
	env->is_cursh = 0;
	env->is_envp = 0;
	env->is_word = 0;
}
