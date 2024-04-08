/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 01:35:16 by alamaoui          #+#    #+#             */
/*   Updated: 2024/04/07 20:47:41 by alamaoui         ###   ########.fr       */
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
	char	**cmd1;
	char	**cmd2;
	char	*file2;
	char	*path;
	char	**paths;
	char	**envp;
	char	*cmd1_path;
	char	*cmd2_path;
	char	*envp_paths;
	char	*full_cmd_path;
	int		fd1;
	int		fd2;
	int		pipefd[2];
	int		i;
	pid_t	pid1;
	pid_t	pid2;
}			t_data;

void		fork_pid1(t_data *data);
void		fork_pid2(t_data *data);
void		pid1_checks(t_data *data);
void		pid2_checks(t_data *data);
void		bye_bye(char *str, t_data *data);
void		bye_bye1(char *str);
char		*get_cmd_with_path(char *cmd, t_data *data);
void		check_waitpid_close(t_data *data);
void		initialize_variables(char **av, char **envp, t_data *data);
char		*get_paths(char **envp);

char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
void		eraser(t_data *data);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif