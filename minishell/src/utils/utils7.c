/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:24:09 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/26 20:46:01 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "envp.h"

static void	get_split_check_in_envp(t_env *env, char *str)
{
	if (*str == '$')
	{
		env->is_word = 0;
		env->temp = find_index(env->envp, MAX_COMMAND);
		env->envp[env->temp][1] = (str - env->str) - 1;
		env->temp = find_index(env->envp, MAX_COMMAND);
		env->envp[env->temp][0] = (str - env->str);
	}
	else if (*str == '\'' || *str == '\"' || *str == '{' || *str == ' ')
	{
		env->is_word = 0;
		env->is_envp = 0;
		env->temp = find_index(env->envp, MAX_COMMAND);
		env->envp[env->temp][1] = (str - env->str) - 1;
	}
}

static void	get_split_check_in_other(t_env *env, char *str)
{
	if (*str == '$')
	{
		env->is_envp = 0;
		env->temp = find_index(env->envp, MAX_COMMAND);
		env->envp[env->temp][0] = (str - env->str);
		env->envp[env->temp][1] = (str - env->str);
	}
	else if (*str == '\'' || *str == '\"' || *str == ' ')
		env->is_envp = 0;
	else if (*str == '{')
	{
		env->is_word = 1;
		env->is_cursh = 1;
		env->temp = find_index(env->envp, MAX_COMMAND);
		env->envp[env->temp][0] = (str - env->str);
	}
	else
	{
		env->is_word = 1;
		env->temp = find_index(env->envp, MAX_COMMAND);
		env->envp[env->temp][0] = (str - env->str);
	}
}

static int	get_check_in_other(t_env *env, char *str)
{
	if (env->is_envp)
	{
		if (*str == 0)
		{
			env->temp = find_index(env->envp, MAX_COMMAND);
			env->envp[env->temp][1] = (str - env->str) - 1;
			return (1);
		}
		else if (env->is_word)
			get_split_check_in_envp(env, str);
		else
			get_split_check_in_other(env, str);
	}
	else if (*str == '$')
		env->is_envp = 1;
	else if (*str == 0)
		return (1);
	return (0);
}

static size_t	get_merge(t_env *env)
{
	size_t	i;

	i = 0;
	while (env->envp[i][0] != -1)
	{
		if (i == 0)
			env->tmp1 = get_string(env->str, 0, env->envp[i][0] - 2, 0);
		else if (env->envp[i][0] - env->envp[i - 1][1] != 1)
			env->tmp1 = get_string
				(env->str, env->envp[i - 1][1] + 1, env->envp[i][0] - 2, 0);
		get_check_before_merge(env);
		env->tmp3 = get_string(env->str, env->envp[i][0], env->envp[i][1], 0);
		env->tmp4 = get_find_envp(env->tmp3);
		env->tmp_str = env->ret_str;
		env->ret_str = ms_strjoin(env->ret_str, env->tmp4);
		if (env->tmp_str != env->tmp_chk)
			free(env->tmp_str);
		get_free_envp(&env->tmp4);
		free(env->tmp3);
		i++;
	}
	return (i);
}

char	*get_check(char *str, t_var *var)
{
	size_t	i;
	t_env	env;

	init_env(&env, str, MAX_COMMAND);
	while (1)
	{
		if (get_quote_check(str - env.str, var))
			init_part_env(&env);
		else if (env.is_cursh)
		{
			if (get_check_in_cursh(&env, str))
				break ;
		}
		else if (get_check_in_other(&env, str))
			break ;
		str++;
	}
	i = get_merge(&env);
	if (i > 0)
		get_merge_last_word(&env, i);
	if (env.ret_str == env.tmp_chk)
		return (env.str);
	if (env.str)
		free(env.str);
	return (env.ret_str);
}
