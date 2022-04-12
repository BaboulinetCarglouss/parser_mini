/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_indexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfritsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:37:19 by gfritsch          #+#    #+#             */
/*   Updated: 2022/04/12 16:53:03 by gfritsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	subindexing_loop_instructions(char *str, t_token *token,
		t_index *subindex, int i)
{
}

t_index	*subindexing(t_token *token, int i_tok)
{
	int	i;
	t_index	*subindex;

	i = 0;
	subindex = init_indexer(str);
	if (subindex == NULL)
	{
		perror("subindexing(): Error intializing subindex");
		return (NULL);
	}
	i = skip_space(str);
	subindexing_loop_instructions(str, token, subindex, i);
	return (subindex);
}
