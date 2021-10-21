#include "minishell.h"

static void	redir_detected(t_token **test, int *type, t_token **token)
{
	*test = *token;
	*type = (*token)->type;
	if ((*token)->next->type == SPCE)
		*token = (*token)->next;
}

static void	redir_after_add(int type, t_rlist *list, t_token **token, \
int *count)
{
	if (type == DLRD)
		list->tail->prev->count_dlrd = (*count)++;
	*token = (*token)->next->next;
	remove_token((*token)->prev);
}

t_rlist	*redir_detector(t_token *token)
{
	t_rlist	*list;
	int		type;
	t_token	*test;
	int		count;

	list = (t_rlist *)my_malloc(sizeof(t_rlist));
	init_rlist(list);
	count = 1;
	while (token->type != -1 && token->type != PIPE)
	{
		if (token->type == LRED || token->type == RRED
			|| token->type == DLRD || token->type == DRRD)
		{
			redir_detected(&test, &type, &token);
			add_redir(list->tail->prev, my_strdup_len(token->next->str, \
			ft_strlen(token->next->str)), type, -1);
			redir_after_add(type, list, &token, &count);
			remove_token(test);
		}
		else
			token = token->next;
	}
	return (list);
}
