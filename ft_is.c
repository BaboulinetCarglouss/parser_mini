/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfritsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:54:14 by gfritsch          #+#    #+#             */
/*   Updated: 2022/04/08 15:48:48 by gfritsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_defined(t_token *token, int i)
{
	if (token[i].is_redirection_input == 1
		|| token[i].is_redirection_output == 1 || token[i].is_here_doc == 1
		|| token[i].is_append_output == 1 || token[i].is_cmd == 1
		|| token[i].is_arg == 1 || token[i].is_single_quoted == 1
		|| token[i].is_double_quoted == 1 || token[i].is_pipe == 1)
		return (1);
	else
		return (0);
}

int	is_meta_char(t_token *token, int i)
{
	if (token[i].elem[0] == '<' && token[i].elem[1] == 0)
		return (token[i].is_redirection_input = 1);
	else if (token[i].elem[0] == '>' && token[i].elem[1] == 0)
		return (token[i].is_redirection_output = 1);
	else if (token[i].elem[0] == '|' && token[i].elem[1] == 0)
		return (token[i].is_pipe = 1);
	else if (token[i].elem[0] == '<' && token[i].elem[1] == '<'
		&& token[i].elem[2] == 0)
		return (token[i].is_here_doc = 1);
	else if (token[i].elem[0] == '>' && token[i].elem[1] == '>'
		&& token[i].elem[2] == 0)
		return (token[i].is_append_output = 1);
	else
		return (0);
}

void	is_command(t_token *token, int i)
{
	if (is_meta_char(token, i - 1) == 1)
	{
		if (token[i - 1].is_append_output == 1
			|| token[i - 1].is_redirection_output == 1)
			token[i].is_arg = 1;
		else
			token[i].is_cmd = 1;
	}
	else
		token[i].is_arg = 1;
}

void	which_is(t_token *token, int i)
{
	if (is_meta_char(token, i) == 0)
	{
		if (token[i].elem[0] == '\"')
			token[i].is_double_quoted = 1;
		else if (token[i].elem[0] == '\'')
			token[i].is_single_quoted = 1;
		else
		{
			if (i == 0 && is_defined(token, i) == 0)
				token[i].is_cmd = 1;
			else
				is_command(token, i);
		}
	}
}
