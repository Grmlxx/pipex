/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 01:35:16 by alamaoui          #+#    #+#             */
/*   Updated: 2024/04/04 03:14:42 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	char	*file1;
	char	*cmd1;
	char	*cmd2;
	char	*file2;
	char	*cmd1_args[4];
	char	*cmd2_args[4];
	int		fd1;
	int		fd2;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
}			t_data;

void		fork_pid1(t_data data);
void		fork_pid2(t_data data);
void		pid1_checks(t_data data);
void		pid2_checks(t_data data);
void		bye_bye(char *str);
void		setup_cmd_args(char **cmd_args, char *cmd);
void		check_waitpid_close(t_data data);
t_data		initialize_variables(char **av);

#endif