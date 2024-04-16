/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:40:44 by alamaoui          #+#    #+#             */
/*   Updated: 2024/04/14 23:38:44 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac != 5)
		bye_bye1("Invalid number of arguments ");
	if (av[2][0] == '\0' || av[2][0] == '\t' || av[2][0] == ' '
		|| av[2][0] == '.' || av[2][0] == '\\' || av[3][0] == '\0'
		|| av[3][0] == '\t' || av[3][0] == ' ' || av[3][0] == '.'
		|| av[3][0] == '\\')
		bye_bye1("There is no such a command ");
	initialize_variables(av, envp, &data);
	if (pipe(data.pipefd) == -1)
		bye_bye("pipe didn't work ", &data);
	fork_pid1(&data);
	fork_pid2(&data);
	close(data.pipefd[1]);
	close(data.pipefd[0]);
	waitpid(data.pid1, NULL, 0);
	waitpid(data.pid2, NULL, 0);
	eraser(&data);
}
