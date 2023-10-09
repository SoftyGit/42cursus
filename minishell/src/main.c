/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:05:12 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/27 21:07:25 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"
#include "envp.h"
#include "prompt.h"

extern int	g_exit_status;

int	main(int argc, char **argv, char **envp)
{
	int	exit_status;

	if (argc != 1 || argv == 0)
		print_error("Argument Input");
	if (envp[0] == NULL)
		print_error("No envp input");
	init_minishell();
	init_envp(envp);
	get_interactive();
	exit_status = g_exit_status;
	unlink("/var/tmp/.minishellrc");
	return (exit_status);
}
