/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:54:27 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/27 21:08:22 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"
#include "prompt.h"
#include "signals.h"

extern int	g_exit_status;

void	set_signal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	signal(SIGINT, get_signal);
	signal(SIGQUIT, get_signal);
}

void	get_signal(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_status = EXIT_FAILURE;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		rl_replace_line("", 0);
	}
	else if (sig == SIGQUIT)
	{
		g_exit_status = SIGQUIT + 127;
		rl_redisplay();
	}
}
