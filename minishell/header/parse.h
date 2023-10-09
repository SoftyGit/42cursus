/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:17:49 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/24 01:20:46 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define MAX_COMMAND 1024
# include "minishell.h"

typedef struct s_var{
	size_t	temp;
	size_t	type;
	size_t	count;
	int		is_word;
	int		is_quot;
	int		is_file;
	int		is_pipe;
	char	*cmd;
	int		word[MAX_COMMAND][2];
	int		file[4][MAX_COMMAND][2];
}			t_var;

int			get_pipe_status_in_cmd_pipe(t_var *var, char *cmd);
t_job		*get_job(char *cmd);
int			get_status(t_var *var, char *cmd);
int			get_status_in_word(t_var *var, char *cmd);
int			get_status_in_file(t_var *var, char *cmd);
void		*get_pipe_in_word(t_job *job, t_var *n_var, char *cmd);
void		get_pipe_word_in_word(t_var *n_var, t_command *ret);
void		get_pipe_infile_in_word(t_var *n_var, t_command *ret);
void		get_pipe_outfile_in_word(t_var *n_var, t_command *ret);
t_command	*get_pipe_ret_in_word(t_job *job, t_command *ret);

# define SPAC 0
# define CHAR 1
# define QUOT 2
# define IOFI 3
# define PIPE 4
# define FINE 5
# define ERRO 77

#endif
