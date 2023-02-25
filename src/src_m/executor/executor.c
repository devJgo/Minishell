/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:44:42 by jgo               #+#    #+#             */
/*   Updated: 2023/02/25 21:21:27 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "defines.h"
#include "executor.h"

void	executor_classify_token(t_tree_node	*node)
{
	const t_token *token = (t_token *)(node->value);

	if (token->type == RDR)
		rdr_executor(token->cmd_val.rdr);
	else if (token->type == PIPE)
		pipe_executor(token->cmd_val.pipe);
	else if (token->type == S_CMD)
		s_cmd_executor(token->cmd_val.simple_cmd);
}

t_bool	is_single_built_in(t_tree_node *root)
{
	const t_token_type type = ((t_token *)(root->right->value))->type;

	if (type == PIPE)
		return (FT_FALSE);
	else
		return (FT_TRUE);
}

// S_CMD 실행시에만 fork를 떠보자. 
// 실행 이전에 처리해야 할 것들.
// 부모와 자식 signal 처리.
// abs_path가져오기. 
// 부모는 자식의 pid를 받고 wait, waitpid를 건다. 마지막 자식의 exit_status저장. 
// 그렇다면 pipe는 어떻게 저장할 것인가? -> pipe_lst? 와 같은 자료구조 중에 하나를 사용해서 전달해야할 fd값을 저장한다.
// 그 와중에 rdr이 있다면 handling을 해준다. abs_path를 가져와서 실행가능하다면 실행 아니면 command not found
// 실행 이후 처리해야 할 것들.
// 사용한 pipe의 fd는 close 
// rdr도 close
// 

void    executor(t_tree *tree)
{
	t_bool s_built_in;

	if (tree == NULL || tree->root == NULL)
		return ;
	s_built_in = is_single_built_in(tree->root);
	if (s_built_in)
		tree->pre_order_traversal(tree->root->right, executor_classify_token);
	else
		tree->pre_order_traversal(tree->root, executor_classify_token);
}