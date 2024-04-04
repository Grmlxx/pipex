/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 03:12:52 by alamaoui          #+#    #+#             */
/*   Updated: 2024/04/04 03:28:08 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fork_pid1(t_data data)
{
	data.pid1 = fork();
	if (data.pid1 == -1)
		bye_bye("fork didn't work ");
	if (data.pid1 == 0)
	{
		pid1_checks(data);
		execve("/bin/sh", data.cmd1_args, NULL);
		bye_bye("execve cmd1 didn't work ");
	}
}

void	fork_pid2(t_data data)
{
	data.pid2 = fork();
	if (data.pid2 == -1)
		bye_bye("fork didn't work ");
	if (data.pid2 == 0)
	{
		pid2_checks(data);
		execve("/bin/sh", data.cmd2_args, NULL);
		bye_bye("execve cmd2 didn't work ");
	}
}
