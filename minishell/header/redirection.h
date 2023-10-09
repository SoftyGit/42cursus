/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:50:35 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/16 16:57:30 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "minishell.h"

//redirection1.c
int	redirection_command(t_command *command);
int	redirection_infile(t_red_in *red);
int	redirection_outfile(t_red_out *red);

#endif
