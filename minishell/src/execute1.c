/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:43:13 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/27 20:56:31 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"
#include "execute.h"
#include "pipex.h"
#include "builtin.h"
#include <errno.h>

int	execve_binary(t_command *command, t_vars *vars)
{
	if (execve(get_cmd_path(command, vars->path), command->args, NULL) == -1)
	{
		dup2(STDERR_FILENO, STDOUT_FILENO);
		printf("%s: command not found\n", command->command);
		exit (EXIT_COMMAND_NOT_FOUND);
	}
	return (EXIT_SUCCESS);
}

int	classify_command(t_command *command, t_vars *vars, int num_commands)
{
	if (command->command[0] == '\0')
		exit(EXIT_SUCCESS);
	else if (ms_strncmp(command->command, "cd\0", 3) == 0)
		exit(ms_cd(command->args + 1, num_commands));
	else if (ms_strncmp(command->command, "echo\0", 5) == 0)
		exit(ms_echo(command->args + 1));
	else if (ms_strncmp(command->command, "env\0", 4) == 0)
		exit(ms_env(command->args + 1));
	else if (ms_strncmp(command->command, "exit\0", 5) == 0)
		exit(ms_exit(command->args + 1));
	else if (ms_strncmp(command->command, "export\0", 7) == 0)
		exit(ms_export(command->args + 1, num_commands));
	else if (ms_strncmp(command->command, "pwd\0", 4) == 0)
		exit(ms_pwd());
	else if (ms_strncmp(command->command, "unset\0", 6) == 0)
		exit(ms_unset(command->args + 1, num_commands));
	else
		execve_binary(command, vars);
	return (0);
}
