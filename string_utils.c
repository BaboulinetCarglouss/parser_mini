/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfritsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:57:44 by gfritsch          #+#    #+#             */
/*   Updated: 2022/04/07 18:46:50 by gfritsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_quotes(char *str, t_split *split)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i > 0)
		{
			if (str[i] == '\'' && str[i - 1] != '\\')
				split->single_quote++;
			else if (str[i] == '\"' && str[i - 1] != '\\')
				split->double_quote++;
		}
		else
		{
			if (str[i] == '\'')
				split->single_quote++;
			else if (str[i] == '\"')
				split->double_quote++;
		}
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	return (i);
}
