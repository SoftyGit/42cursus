/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:06:44 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/27 19:48:57 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "prompt.h"
#include "utils.h"
#include "signals.h"
#include "pipex.h"
#include "envp.h"
#include "builtin.h"
#include "execute.h"

char	*get_prompt(void)
{
	char	*temp1;
	char	*temp2;
	char	*ret;

	temp2 = find_envp("USER");
	temp1 = ms_strjoin("{", temp2);
	if (temp2)
		free(temp2);
	temp2 = ms_strjoin(temp1, "}");
	ret = ms_strjoin(temp2, " ▶ ");
	free(temp1);
	free(temp2);
	return (ret);
}

static void	get_null_check(char *cmd)
{
	char	*str;

	if (cmd == NULL)
	{
		str = get_prompt();
		printf("\x1b[A%sexit\n", str);
		free(str);
		exit(0);
	}
}

int	get_interactive(void)
{
	t_job	*job;
	char	*cmd;
	char	*prompt;

	set_signal();
	while (1)
	{
		prompt = get_prompt();
		cmd = readline(prompt);
		free(prompt);
		get_null_check(cmd);
		job = get_job(cmd);
		if (job)
		{
			add_history(cmd);
			if (job->num_command > 0)
				pipex(job);
		}
		free(cmd);
		ms_free(job);
	}
}
