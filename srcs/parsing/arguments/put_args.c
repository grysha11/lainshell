/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:34:48 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/23 12:11:09 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

int	putcmd(t_args **list, char *line, int *i)
{
	t_args	*new;
	char	*cmd;

	if (line[*i] == '\'' || line[*i] == '\"')
		cmd = ft_substr(line, *i, quotelen(line + *i, line[*i]));
	else
		cmd = ft_substr(line, *i, wordlen(line + *i));
	new = ft_lstnew(cmd, CMD);
	ft_lstadd_back(list, new);
	if (line[*i] == '\'' || line[*i] == '\"')
		*i += quotelen(line + *i, line[*i]);
	else
		*i += wordlen(line + *i);
	return (0);
}

int	quotecheck(char *line, int i, char quote)
{
	i++;
	while (line[i] && line[i] != quote)
		i++;
	if (!line[i])
		return (0);
	return (1);
}

int	quotelen(char *line, char quote)
{
	int	len;

	len = 1;
	while (line[len] && line[len] != quote)
		len++;
	len++;
	return (len);
}

int	putquote(t_args **list, char *line, int i, char quote)
{
	t_args	*new;
	char	*cmd;

	cmd = ft_substr(line, i, quotelen(line + i, quote));
	new = ft_lstnew(cmd, check_quote(quote));
	ft_lstadd_back(list, new);
	i += quotelen(line + i, quote);
	return (i);
}

int	check_redir(char *line, int i)
{
	if (line[i] == '<' || line[i] == '>')
		return (1);
	return (0);
}
