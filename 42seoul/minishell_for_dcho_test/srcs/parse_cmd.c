/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:05:58 by soyelee           #+#    #+#             */
/*   Updated: 2021/10/20 03:26:30 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	join_char(t_tlist *tlist)
{
	t_token	*cur;
	char	*tmp;

	cur = tlist->head->next;
	while (cur->type != -1)
	{
		if (cur->type == CHAR && cur->next->type == CHAR)
		{
			tmp = cur->str;
			cur->str = ft_strjoin(cur->str, cur->next->str);
			free(tmp);
			tmp = NULL;
			remove_token(cur->next);
			continue ;
		}
		cur = cur->next;
	}
}

static int	count_argc(t_token *cur)
{
	int		count;

	count = 0;
	while (cur->type != PIPE && cur->type != -1)
	{
		if (cur->type == LRED || cur->type == RRED || cur->type == DLRD || \
		cur->type == DRRD)
		{
			while (cur->next->type == SPCE)
				cur = cur->next;
			cur = cur->next;
			if (cur->type == CHAR)
				cur = cur->next;
		}
		if (cur->type == CHAR)
			count++;
		if (cur->type != -1)
			cur = cur->next;
	}
	return (count);
}

static t_clist	*setting_cmd(t_clist *cmdlist, t_cmd *cmd)
{
	int		i;
	int		count;

	if (cmdlist->tail->prev->is_pipe)
		cmdlist->head->next->is_pipe = TRUE;
	count = 1;
	while (cmd->is_pipe != -1)
	{
		cmd->count = count++;
		cmd->argc = count_argc(cmd->token);
		cmd->redir = redir_detector(cmd->token);
		cmd->argv = (char **)my_malloc(sizeof(char *) * (cmd->argc + 1));
		i = 0;
		while (cmd->token->type != PIPE && cmd->token->type != -1)
		{
			if (cmd->token->type == CHAR)
				cmd->argv[i++] = ft_strdup(cmd->token->str);
			cmd->token = cmd->token->next;
		}
		cmd->argv[i] = NULL;
		cmd = cmd->next;
	}
	return (cmdlist);
}

t_clist	*cmdizer(t_tlist *token)
{
	t_clist	*cmdlist;
	t_cmd	*cur_cmd;
	t_token	*cur_token;

	join_char(token);
	cmdlist = (t_clist *)my_malloc(sizeof(t_clist));
	init_clist(cmdlist);
	cur_token = token->head->next;
	add_cmd(cmdlist->head, cur_token, FALSE);
	cur_cmd = cmdlist->head->next;
	cur_token = cur_token->next;
	while (cur_token->type != -1)
	{
		if (cur_token->type == PIPE)
		{
			if (cur_token->next->type == -1 || (cur_token->next->type == SPCE \
			&& cur_token->next->next->type == -1))
				return (NULL);
			cur_token = cur_token->next;
			add_cmd(cur_cmd, cur_token, TRUE);
			cur_cmd = cur_cmd->next;
		}
		cur_token = cur_token->next;
	}
	return (setting_cmd(cmdlist, cmdlist->head->next));
}
