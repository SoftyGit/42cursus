/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 01:30:18 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/24 12:58:32 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parse.h"

void	get_string_single_quote(t_var *var, char *ret, char *cmd, int mode)
{
	size_t	temp;

	if (var->is_quot == '\'' && mode)
	{
		temp = find_index(var->word, MAX_COMMAND);
		var->word[temp][1] = var->temp - 1;
	}
	else if (var->is_quot == '\'')
		ret[(var->temp)++] = cmd[var->count];
	else if (var->is_quot == '\"' && !mode)
		ret[(var->temp)++] = cmd[var->count];
	var->is_quot = 0;
}

void	get_string_other(t_var *var, char *ret, char *cmd, int mode)
{
	size_t	temp;

	var->is_quot = cmd[var->count];
	if (cmd[var->count] == '\'' && mode)
	{
		temp = find_index(var->word, MAX_COMMAND);
		var->word[temp][0] = var->temp;
	}
	else if (cmd[var->count] == '\'')
		ret[(var->temp)++] = cmd[var->count];
	else if (cmd[var->count] == '\"' && !mode)
		ret[(var->temp)++] = cmd[var->count];
}

void	get_check_before_merge(t_env *env)
{
	if (env->tmp1)
	{
		env->tmp_str = env->ret_str;
		env->ret_str = ms_strjoin(env->ret_str, env->tmp1);
		if (env->tmp_str != env->tmp_chk)
			free(env->tmp_str);
		free(env->tmp1);
	}
}

int	count_envp_from_array(char **envp)
{
	int	num_envp;

	num_envp = 0;
	if (envp == NULL)
		return (0);
	while (envp[num_envp])
		num_envp++;
	return (num_envp);
}

void	get_free_envp(char **str)
{
	free(*str);
	*str = NULL;
}
