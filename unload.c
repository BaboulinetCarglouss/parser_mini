/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfritsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:26:23 by gfritsch          #+#    #+#             */
/*   Updated: 2022/04/14 13:22:17 by gfritsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unload(t_split *split, t_token *token)
{
	int	i;
	int	j;

	i = 0;
	while (split->split[i] != NULL)
		free(split->split[i++]);
	free(split->split);
	free(split);
	i = 0;
	while (token[i].elem != NULL)
	{
		j = 0;
		while (j < token[i].nb_subtoken)
			free(token[i].subtoken[j++].sub_elem);
		free(token[i].subtoken);
		i++;
	}
	free(token);
}

void	unload_indexer(t_index *index)
{
	free(index->end_word);
	free(index->begin_word);
	free(index);
}
