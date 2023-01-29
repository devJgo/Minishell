/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:53:21 by jgo               #+#    #+#             */
/*   Updated: 2023/01/29 15:06:17 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "defines.h"
#include "utils.h"

int main(int argc, char **argv, char **envp)
{
    t_tree  *tree;

    ft_bzero(get_meta(), sizeof(t_meta));
	signal(SIGQUIT, signal_process);
    signal(SIGINT, signal_process);
    envp_init(envp);
    prompt();
    
    return (EXIT_SUCCESS);
}