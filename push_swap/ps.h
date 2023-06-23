/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:36:40 by yongjale          #+#    #+#             */
/*   Updated: 2023/06/23 21:41:56 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

typedef struct	s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
};

typedef struct	s_stack
{
	struct s_node	*top;
	struct s_node	*bot;
};

#endif