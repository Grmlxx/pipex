/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamaoui <alamaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 03:11:41 by alamaoui          #+#    #+#             */
/*   Updated: 2024/04/08 01:17:02 by alamaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	initialize_variables(char **av, char **envp, t_data *data)
{
	data->file1 = av[1];
	data->cmd1 = ft_split(av[2], ' ');
	data->cmd2 = ft_split(av[3], ' ');
	data->file2 = av[4];
	data->envp = envp;
	data->envp_paths = get_paths(envp);
	if (data->envp_paths)
		data->paths = ft_split(data->envp_paths + 5, ':');
	if (!data->envp_paths)
		data->paths = NULL;
	data->cmd1_path = get_cmd_with_path(data->cmd1[0], data);
	data->cmd2_path = get_cmd_with_path(data->cmd2[0], data);
}

void	eraser(t_data *data)
{
	data->i = 0;
	while (data->cmd1[data->i])
		free(data->cmd1[data->i++]);
	free(data->cmd1);
	data->i = 0;
	while (data->cmd2[data->i])
		free(data->cmd2[data->i++]);
	free(data->cmd2);
	data->i = 0;
	if (data->paths)
	{
		while (data->paths[data->i])
			free(data->paths[data->i++]);
		free(data->paths);
	}
	if (data->cmd1_path)
		free(data->cmd1_path);
	if (data->cmd2_path)
		free(data->cmd2_path);
}

char	*joiner(char *full_path, char *cmd)
{
	char	*path_with_slash;
	char	*res;

	path_with_slash = ft_strjoin(full_path, "/");
	res = ft_strjoin(path_with_slash, cmd);
	free(path_with_slash);
	return (res);
}

char	*get_paths(char **envp)
{
	char	*curr_env;
	int		i;

	i = 0;
	if (!envp)
		bye_bye1("PATH environment is not found ");
	while (envp[i] != NULL)
	{
		curr_env = envp[i];
		if (strncmp(envp[i], "PATH=", 5) == 0)
			return (curr_env);
		i++;
	}
	return (NULL);
}

char	*get_cmd_with_path(char *cmd, t_data *data)
{
	char	*full_cmd_path;

	data->i = 0;
	if (!cmd)
		return (NULL);
	if (access(cmd, X_OK) == 0)
	{
		return (ft_strdup(cmd));
	}
	if (cmd[0] == '/')
		return (NULL);
	data->i = 0;
	while (data->paths[data->i] != NULL)
	{
		full_cmd_path = joiner(data->paths[data->i], cmd);
		if (access(full_cmd_path, X_OK) == 0)
			return (full_cmd_path);
		free(full_cmd_path);
		data->i++;
	}
	return (NULL);
}
