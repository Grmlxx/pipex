/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:40:44 by alamaoui          #+#    #+#             */
/*   Updated: 2024/04/04 03:26:11 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5)
		bye_bye("./pipex file1 cmd1 cmd2 file2 ");
	data = initialize_variables(av);
	setup_cmd_args(data.cmd1_args, data.cmd1);
	setup_cmd_args(data.cmd2_args, data.cmd2);
	data.fd1 = open(data.file1, O_RDONLY);
	if (data.fd1 == -1)
		bye_bye("Error open file1 ");
	if (pipe(data.pipefd) == -1)
		bye_bye("pipe didn't work ");
	fork_pid1(data);
	fork_pid2(data);
	check_waitpid_close(data);
}
