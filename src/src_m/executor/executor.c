/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:44:42 by jgo               #+#    #+#             */
/*   Updated: 2023/02/22 16:12:27 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "defines.h"
#include "executor.h"
// RDR = 0,
// PIPE = 1,
// S_CMD = 4,
void    rdr_executor(t_)

void    executor(t_tree_node *node)
{
    if (node == NULL)
        return ;

    
    if (is_built_in_cmd())


    executor(node->left);
    executor(node->right);
}