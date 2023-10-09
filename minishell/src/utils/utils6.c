/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:33:02 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/24 14:04:42 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "envp.h"
#include "utils.h"

char	*ms_strcat(const char *dst, const char join, const char *src)
{
	int		size_dst;
	int		size_src;
	char	*ret;

	size_dst = ms_strlen(dst);
	size_src = ms_strlen(src);
	ret = malloc(sizeof(char) * (size_dst + size_src + 2));
	if (ret == 0)
		return (0);
	ms_memcpy(ret, dst, size_dst);
	ret[size_dst] = join;
	ms_memcpy(ret + size_dst + 1, src, size_src);
	ret[size_dst + size_src + 1] = '\0';
	return (ret);
}

void	*ms_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == 0 && src == 0)
	{
		return (0);
	}
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return ((void *)dst);
}

static void	ms_red_free(t_red_in *red_in, t_red_out *red_out)
{
	t_red_in	*tmp_in;
	t_red_out	*tmp_out;

	while (red_in)
	{
		tmp_in = red_in->next;
		if (red_in->infile)
			free(red_in->infile);
		free(red_in);
		red_in = tmp_in;
	}
	while (red_out)
	{
		tmp_out = red_out->next;
		if (red_out->outfile)
			free(red_out->outfile);
		free(red_out);
		red_out = tmp_out;
	}
}

void	*ms_free(t_job *job)
{
	t_command	*cmd;
	t_command	*tmp;
	size_t		i;

	if (!job)
		return (NULL);
	cmd = job->command;
	while (cmd)
	{
		tmp = cmd->next_command;
		i = 0;
		if (cmd->args)
		{
			while (cmd->args[i])
				free(cmd->args[i++]);
			free(cmd->args);
		}
		ms_red_free(cmd->infile, cmd->outfile);
		free(cmd);
		cmd = tmp;
	}
	free(job);
	return (NULL);
}

void	init_env(t_env *env, char *str, size_t max)
{
	size_t	i;

	env->temp = 0;
	env->is_envp = 0;
	env->is_word = 0;
	env->is_cursh = 0;
	env->ret_str = "";
	env->tmp_str = NULL;
	env->tmp_chk = env->ret_str;
	env->tmp1 = NULL;
	env->tmp2 = NULL;
	env->tmp3 = NULL;
	env->tmp4 = NULL;
	env->str = str;
	i = 0;
	while (i < max)
	{
		env->envp[i][0] = -1;
		env->envp[i][1] = -1;
		i++;
	}
}
