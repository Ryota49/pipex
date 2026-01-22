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

void	initialise_struct(t_pipex *px, char **argv, char **envp)
{
	px->fd_infile = open(argv[1], O_RDONLY);
	if (px->fd_infile < 0)
	{
		perror(argv[1]);
		exit (1);
	}
	px->fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->fd_outfile < 0)
	{
		perror(argv[4]);
		close(px->fd_infile);
		exit (1);
	}
	px->cmd1 = ft_split(argv[2], ' ');
	px->cmd2 = ft_split(argv[3], ' ');
	px->path = find_path(envp);
	if (px->path == NULL)
	{
		write(2, "No path found\n", 15);
		free_struct(px);
		exit(1);
	}
	px->all_path = ft_split(px->path, ':');
	exec_cmd1(envp, px);
}

void	exec_cmd1(char **envp, t_pipex *px)
{
	int		i;

	pipe(px->pipefd);
	px->id = fork();
	i = 0;
	if (px->id == 0)
	{
		close (px->pipefd[0]);
		dup2(px->fd_infile, STDIN_FILENO);
		dup2(px->pipefd[1], STDOUT_FILENO);
		close (px->fd_infile);
		close (px->pipefd[1]);
		while (px->all_path[i])
		{
			px->path = ft_strjoin(px->all_path[i], "/", px->cmd1[0]);
			if (access(px->path, X_OK) == 0)
				execve(px->path, px->cmd1, envp);
			free (px->path);
			i++;
		}
		error_execve(px, "execve cmd1");
	}
	close(px->pipefd[1]);
	close (px->fd_infile);
	exec_cmd2(envp, px);
}

void	exec_cmd2(char **envp, t_pipex *px)
{
	int		i;
	char	*path;

	path = NULL;
	px->id = fork();
	i = 0;
	if (px->id == 0)
	{
		dup2(px->pipefd[0], STDIN_FILENO);
		dup2(px->fd_outfile, STDOUT_FILENO);
		close (px->pipefd[0]);
		close (px->fd_outfile);
		while (px->all_path[i])
		{
			path = ft_strjoin(px->all_path[i], "/", px->cmd2[0]);
			if (access(path, X_OK) == 0)
				execve(path, px->cmd2, envp);
			free (path);
			i++;
		}
		error_execve(px, "execve cmd2");
	}
	close (px->pipefd[0]);
	close (px->fd_outfile);
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
	t_pipex	px;

	if (argc != 5)
		return (0);
	else
	{
		initialise_struct(&px, argv, envp);
		wait (NULL);
		wait (NULL);
		free_struct_full(&px);
	}
	return (0);
}
