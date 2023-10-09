/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:11:39 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/27 19:10:38 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "minishell.h"
# include "utils.h"

typedef struct s_vars
{
	int			**fds;
	int			*pids;
	char		*limiter;
	char		**path;
}				t_vars;

//pipex.c
int		pipex(t_job *job);
void	write_pipe(t_vars *vars);
void	read_pipe(t_vars *vars);

//input.c
t_vars	*get_vars(t_job *job);
char	**get_path(void);
void	get_fds(t_vars *vars, t_job *job);

//utils.c
void	open_pipes(t_vars *vars, t_job *job);
void	close_pipes(t_vars *vars, t_job *job);
int		count_words(char const *s, char c);
void	wait_pids(t_vars *var, t_job *job);

//utils_2.c
void	free_vars(t_vars *vars, t_job *job);
void	free_arrarr(char **arrarr);
void	free_temp(char **temp, char **first, char **last);
char	*get_cmd_path(t_command *command, char **path);

//bonus.c
int		multi_pipe(t_vars *vars, t_job *job, t_command *command, int i);
void	here_doc(t_red_in *red);

#endif
