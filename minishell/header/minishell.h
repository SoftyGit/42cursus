/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:43:48 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/27 19:02:50 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <termios.h>

# define REDIRECTION_IN 0
# define REDIRECTION_HEREDOC 1
# define REDIRECTION_OUT 2
# define REDIRECTION_APPEND 3

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define EXIT_COMMAND_NOT_FOUND 127
# define EXIT_NONNUMERIC 255

int							g_exit_status;

typedef struct s_red_in		t_red_in;
struct s_red_in{
	char		*infile;
	int			type;
	t_red_in	*next;
};

typedef struct s_red_out	t_red_out;
struct s_red_out{
	char		*outfile;
	int			type;
	t_red_out	*next;
};

typedef struct s_command	t_command;
struct s_command{
	char		*command;
	char		**args;
	t_red_in	*infile;
	t_red_out	*outfile;
	t_command	*next_command;
};

typedef struct s_job{
	int			num_command;
	t_command	*command;
}t_job;

#endif
