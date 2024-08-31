/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 02:21:51 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/31 04:12:42 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

static void	free_node(t_env *env)
{
	if (env)
	{
		if (env->data)
			free(env->data);
		free(env);
	}
}

static void	delete_node_util(char *name, t_env *env)
{
	t_env	*temp;
	t_env	*temp2;
	t_env	*delete;

	temp = env->next;
	while (temp && temp->next)
	{
		if (ft_strncmp(name, temp->next->data, ft_strlen(name)) == 0)
		{
			temp2 = temp->next->next;
			delete = temp->next;
			temp->next = temp2;
			free_node(delete);
			break;
		}
		temp = temp->next;
	}
}

static void	delete_node(char *str, t_env *env, int type)
{
	char	*name;
	int		i;
	t_env	*temp;

	i = 0;
	temp = env;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	name = ft_substr(str, 0, i);
	if (type == 0)
	{
		if (ft_strncmp(name, temp->data, ft_strlen(name)) == 0)
		{
			env = temp->next;
			free_node(temp);
		}
	}
	else if (type == 1)
		delete_node_util(name, env);
	free(name);
}

int	ft_unset(t_data data)
{
	t_args	*cur;

	cur = data.args;
	if (cur->next == NULL)
		return (0);
	cur = cur->next;
	delete_node(cur->data, data.env, 0);
	while (cur && cur->token == ARG)
	{
		if (export_exist(cur->data, data.env) == 0)
			delete_node(cur->data, data.env, 1);
		cur = cur->next;
	}
	return (0);
}