/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 03:11:41 by alamaoui          #+#    #+#             */
/*   Updated: 2024/04/04 03:26:50 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	bye_bye(char *str)
{
	perror(str);
	exit(1);
}

t_data	initialize_variables(char **av)
{
	t_data	data;

	data = (t_data){0};
	data.file1 = av[1];
	data.cmd1 = av[2];
	data.cmd2 = av[3];
	data.file2 = av[4];
	return (data);
}

void	setup_cmd_args(char **cmd_args, char *cmd)
{
	cmd_args[0] = "sh";
	cmd_args[1] = "-c";
	cmd_args[2] = cmd;
	cmd_args[3] = NULL;
}

void	check_waitpid_close(t_data data)
{
	if (close(data.pipefd[0]) == -1 || close(data.pipefd[1]) == -1)
		bye_bye("close didn't work ");
	if (waitpid(data.pid1, NULL, 0) == -1 || waitpid(data.pid2, NULL, 0) == -1)
		bye_bye("waitpid didn't work ");
}
