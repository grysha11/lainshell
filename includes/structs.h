/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:21:54 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/26 14:22:48 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_token
{
	CMD,
	ARG,
	QUOTE,
	DOUBLE_QUOTE,
	REDIR_IN,
	REDIR_OUT,
	PIPE,
	HERE_DOC,
	REDIR_APPEND
}		t_token;

typedef struct s_args
{
	char			*data;
	t_token			token;
	struct s_args	*next;
}		t_args;

typedef struct s_env
{
	char			*data;
	struct s_env	*next;
}	t_env;

typedef struct s_exp
{
	int				printed;
	char			*name;
	char			*value;
	struct s_exp	*next;
}	t_exp;
typedef struct s_data
{
	t_env	*env;
	t_args	*args;
	t_exp	*exp;
}	t_data;


#endif