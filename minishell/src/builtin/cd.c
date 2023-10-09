/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:33:06 by yomyom            #+#    #+#             */
/*   Updated: 2023/09/27 20:40:57 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "envp.h"
#include "utils.h"

int	cd_no_args(char **args)
{
	char	*home_path;
	char	*temp;

	temp = getcwd(NULL, 0);
	home_path = find_envp("HOME");
	if (args == NULL || args[0] == NULL)
	{
		if (chdir(home_path) < 0)
		{
			free(home_path);
			print_error("cd");
		}
		update_envp("OLDPWD", temp);
		update_envp("PWD", home_path);
		free(home_path);
		free(temp);
		return (EXIT_SUCCESS);
	}
	else if (args[0] != NULL && args[1] != NULL)
	{
		free(home_path);
		print_error("cd");
	}
	free(home_path);
	return (EXIT_FAILURE);
}

int	cd_old(void)
{
	char	*temp;
	char	*old_path;

	old_path = find_envp("OLDPWD");
	if (old_path == 0)
		return (EXIT_SUCCESS);
	printf("%s\n", old_path);
	temp = getcwd(NULL, 0);
	chdir(old_path);
	update_envp("OLDPWD", temp);
	free(temp);
	temp = getcwd(NULL, 0);
	update_envp("PWD", temp);
	free(old_path);
	free(temp);
	return (EXIT_SUCCESS);
}

int	ms_cd(char **args, int num_commands)
{
	char	*temp;

	if (cd_no_args(args) == EXIT_SUCCESS || num_commands > 1)
		return (EXIT_SUCCESS);
	if (args[0][0] == '-')
		return (cd_old());
	else if (args[0][0] == '~')
		return (merge_tilde(args[0]));
	else if (args[0][0] == '.')
	{
		if (args[0][1] == '.')
			return (merge_dotdot(args[0]));
		else
			return (merge_dot(args[0]));
	}
	else
	{
		update_oldpwd();
		if (chdir(args[0]) < 0)
			print_error("cd");
		temp = getcwd(NULL, 0);
		update_envp("PWD", getcwd(NULL, 0));
		free(temp);
	}
	return (EXIT_SUCCESS);
}
