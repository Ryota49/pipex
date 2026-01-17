/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:38:58 by jemonthi          #+#    #+#             */
/*   Updated: 2026/01/14 00:22:42 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_existing_file(char **argv)
{
	if (access(argv[1], F_OK) != 0)
	{
		write(2, "Infile doesn't exist\n", 22);
		exit (1);
	}
	if (access(argv[4], F_OK) != 0)
	{
		write(2, "Outfile doesn't exist\n", 23);
		exit (1);
	}
}

void	check_existing_command_line(char **argv, char **envp)
{
	char	**command_line;
	char	**all_path;
	char	*path;

	command_line = ft_split(argv[2], ' ');
	path = find_path(envp);
	if (!path)
	{
		write(2, "No path found\n", 15);
		exit(1);
	}
	all_path = ft_split(path, ':');
	join_and_execve(all_path, command_line, envp, path);
}

void	join_and_execve(char **all_path, char **cmd, char **envp, char *path)
{
	int		pipefd[2];
	char	*tmp;
	int		i;
	int		id;

	pipe(pipefd);
	id = fork();
	i = 0;
	if (id == 0)
	{
		close (pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		while (all_path[i])
			{
				tmp = ft_strjoin(all_path[i], "/");
				path = ft_strjoin(tmp, cmd[0]);
				free (tmp);
				if (access(path, X_OK) == 0)
					execve(path, cmd, envp);
				free (path);
				i++;
			}
		perror("execve");
		exit (1);
	}
	close(pipefd[1]);
}

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (0);
	else
	{
		check_existing_file(argv);
		check_existing_command_line(argv, envp);
	}
	return (0);
}
