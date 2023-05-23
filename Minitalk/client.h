/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:53:30 by yongjale          #+#    #+#             */
/*   Updated: 2023/05/21 16:53:59 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

void	send_signal(int server_pid, char *send_string);
void	send_bitsignal(int server_pid, char send_byte);

#endif