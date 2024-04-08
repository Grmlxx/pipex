/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 03:10:45 by alamaoui          #+#    #+#             */
/*   Updated: 2024/04/08 00:50:34 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pid1_checks(t_data *data)
{
	data->fd1 = open(data->file1, O_RDONLY, 0666);
	if (data->fd1 == -1)
		bye_bye("Error open file1 ", data);
	if (data->cmd1_path == NULL)
		bye_bye("Wrong command ", data);
	dup2(data->fd1, STDIN_FILENO);
	dup2(data->pipefd[1], STDOUT_FILENO);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	close(data->fd1);
}

void	pid2_checks(t_data *data)
{
	data->fd2 = open(data->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd2 == -1)
		bye_bye("open file2 didn't work ", data);
	if (data->cmd2_path == NULL)
		bye_bye("Wrong command ", data);
	close(data->pipefd[1]);
	dup2(data->fd2, STDOUT_FILENO);
	dup2(data->pipefd[0], STDIN_FILENO);
	close(data->fd2);
	close(data->pipefd[0]);
}
