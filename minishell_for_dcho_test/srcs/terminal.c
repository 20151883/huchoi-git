/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyelee <soyelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:27:35 by dcho              #+#    #+#             */
/*   Updated: 2021/10/17 21:57:07 by soyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_input_mode(struct termios *org_term)
{
	tcgetattr(STDIN_FILENO, org_term);
}

void	set_input_mode(struct termios *new_term)
{
	tcgetattr(STDIN_FILENO, new_term);
	new_term->c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, new_term);
}

void	reset_input_mode(struct termios *org_term)
{
	tcsetattr(STDIN_FILENO, TCSANOW, org_term);
}
