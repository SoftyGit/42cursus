/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:19:13 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/27 20:38:14 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "envp.h"
#include "utils.h"

int	update_oldpwd(void)
{
	char	*temp;

	temp = getcwd(NULL, 0);
	update_envp("OLDPWD", temp);
	free(temp);
	return (EXIT_SUCCESS);
}

int	merge_tilde(char *dir)
{
	char	*new_dir;
	char	*temp;
	char	*home_path;

	home_path = find_envp("HOME");
	if (dir[1] == '\0')
	{
		chdir(home_path);
		temp = getcwd(NULL, 0);
		update_envp("PWD", temp);
		free(temp);
	}
	else
	{
		new_dir = ms_strjoin(home_path, dir + 1);
		if (chdir(new_dir) < 0)
		{
			free(home_path);
			print_error("cd");
		}
		update_envp("PWD", new_dir);
		free(new_dir);
	}
	free(home_path);
	return (EXIT_SUCCESS);
}

int	merge_dot(char *dir)
{
	char	*new_dir;
	char	*pwd_path;

	update_oldpwd();
	if (dir[1] == '\0')
		return (0);
	else
	{
		if (chdir(dir) < 0)
			print_error("cd");
		pwd_path = find_envp("PWD");
		new_dir = ms_strjoin(pwd_path, dir + 1);
		update_envp("PWD", new_dir);
	}
	free(pwd_path);
	return (EXIT_SUCCESS);
}

int	find_end(char *pwd, int pwd_len)
{
	while (pwd_len >= 0)
	{
		if (pwd[pwd_len - 1] == '/')
			break ;
		pwd_len--;
	}
	return (pwd_len);
}

int	merge_dotdot(char *dir)
{
	char	*new_dir;
	char	pwd[1024];
	int		pwd_len;

	update_oldpwd();
	getcwd(pwd, 1024);
	pwd_len = ms_strlen(pwd);
	if (pwd_len == 1)
		return (EXIT_SUCCESS);
	if (pwd[pwd_len - 1] == '/')
		pwd_len--;
	pwd_len = find_end(pwd, pwd_len);
	new_dir = malloc(sizeof(char) * (pwd_len + (ms_strlen(dir) - 2) + 1));
	ms_strlcpy(new_dir, pwd, pwd_len + 1);
	ms_strlcpy(new_dir + pwd_len, dir + 2, ms_strlen(dir) - 1);
	new_dir[pwd_len + ms_strlen(dir) - 2] = '\0';
	if (chdir(new_dir) < 0)
		print_error("cd");
	update_envp("PWD", new_dir);
	free(new_dir);
	return (EXIT_SUCCESS);
}
