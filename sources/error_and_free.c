/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:53:55 by jemonthi          #+#    #+#             */
/*   Updated: 2026/01/22 15:38:34 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_struct(t_pipex *px)
{
	int	i;

	i = 0;
	while (px->cmd1[i] != NULL)
	{
		free (px->cmd1[i]);
		i++;
	}
	free (px->cmd1);
	i = 0;
	while (px->cmd2[i] != NULL)
	{
		free (px->cmd2[i]);
		i++;
	}
	free (px->cmd2);
}

void	error_execve(t_pipex *px, char *msg_error)
{
	int	i;

	i = 0;
	free_struct(px);
	while (px->all_path[i] != NULL)
	{
		free (px->all_path[i]);
		i++;
	}
	free (px->all_path);
	perror(msg_error);
	close (px->pipefd[1]);
	close (px->fd_infile);
	close (px->fd_outfile);
	exit (1);
}

void	free_struct_full(t_pipex *px)
{
	int	i;

	i = 0;
	free_struct(px);
	while (px->all_path[i] != NULL)
	{
		free (px->all_path[i]);
		i++;
	}
	free (px->all_path);
}
