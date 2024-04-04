/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 03:10:45 by alamaoui          #+#    #+#             */
/*   Updated: 2024/04/04 03:26:42 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pid1_checks(t_data data)
{
	if (close(data.pipefd[0]) == -1)
		bye_bye("close didn't work ");
	if (dup2(data.pipefd[1], STDOUT_FILENO) == -1)
		bye_bye("dup2 didn't work ");
	if (close(data.pipefd[1]) == -1)
		bye_bye("close didn't work ");
	if (dup2(data.fd1, STDIN_FILENO) == -1)
		bye_bye("dup2 didn't work ");
	if (close(data.fd1) == -1)
		bye_bye("close didn't work ");
}

void	pid2_checks(t_data data)
{
	if (close(data.pipefd[1]) == -1)
		bye_bye("close didn't work ");
	if (dup2(data.pipefd[0], STDIN_FILENO) == -1)
		bye_bye("dup2 didn't work ");
	if (close(data.pipefd[0]) == -1)
		bye_bye("close didn't work ");
	data.fd2 = open(data.file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data.fd2 == -1)
		bye_bye("open file2 didn't work ");
	if (dup2(data.fd2, STDOUT_FILENO) == -1)
		bye_bye("dup2 didn't work ");
}
