/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:31:13 by yomyom            #+#    #+#             */
/*   Updated: 2023/09/27 20:40:54 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"
#include "envp.h"
#include "get_next_line.h"

int	count_envp_from_file(void)
{
	char	*temp;
	int		i;
	int		fd;

	i = 0;
	fd = open("/var/tmp/.minishellrc", O_RDONLY, 0644);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		free(temp);
		temp = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	*get_find_envp(char *str)
{
	if (str[0] == '{' && str[ms_strlen(str) - 1] == '}')
	{
		str[ms_strlen(str) - 1] = 0;
		return (find_envp(str + 1));
	}
	return (find_envp(str));
}

int	get_quote_check(int c, t_var *var)
{
	size_t	i;

	i = 0;
	while (var->word[i][0] != -1 && var->word[i][1] != -1)
	{
		if (c >= var->word[i][0] && c <= var->word[i][1])
			return (1);
		i++;
	}
	return (0);
}

int	get_check_in_cursh(t_env *env, char *str)
{
	if (*str == '}')
	{
		env->is_cursh = 0;
		env->is_envp = 0;
		env->is_word = 0;
		env->temp = find_index(env->envp, MAX_COMMAND);
		env->envp[env->temp][1] = (str - env->str);
	}
	else if (*str == 0)
	{
		env->temp = find_index(env->envp, MAX_COMMAND);
		env->envp[env->temp][1] = (str - env->str) - 1;
		return (1);
	}
	return (0);
}

void	get_merge_last_word(t_env *env, size_t i)
{
	env->tmp1 = get_string
		(env->str, env->envp[i - 1][1] + 1, ms_strlen(env->str) - 1, 0);
	if (env->tmp1)
	{
		env->tmp_str = env->ret_str;
		env->ret_str = ms_strjoin(env->ret_str, env->tmp1);
		if (env->tmp_str != env->tmp_chk)
			free(env->tmp_str);
		free(env->tmp1);
	}
}
