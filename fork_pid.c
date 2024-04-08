/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 03:12:52 by alamaoui          #+#    #+#             */
/*   Updated: 2024/04/08 01:16:36 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fork_pid1(t_data *data)
{
	data->pid1 = fork();
	if (data->pid1 == -1)
		bye_bye("fork didn't work for pid1", data);
	if (data->pid1 == 0)
	{
		pid1_checks(data);
		execve(data->cmd1_path, data->cmd1, data->envp);
		bye_bye("execve cmd1 didn't work ", data);
	}
}

void	fork_pid2(t_data *data)
{
	data->pid2 = fork();
	if (data->pid2 == -1)
		bye_bye("fork didn't work for pid2", data);
	if (data->pid2 == 0)
	{
		pid2_checks(data);
		execve(data->cmd2_path, data->cmd2, data->envp);
		bye_bye("execve cmd2 didn't work ", data);
	}
}
