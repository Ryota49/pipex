/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:38:58 by jemonthi          #+#    #+#             */
/*   Updated: 2026/01/14 00:24:59 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

/* My pipex struct */

typedef struct s_pipex
{
	int		fd_infile;
	int		fd_outfile;
	char	**cmd1;
	char	**cmd2;
	char	**all_path;
	char	*path;
	int		pipefd[2];
	int		id;
}	t_pipex;

/* pipex main functions */

void	initialise_struct(t_pipex *px, char **argv, char **envp);
char	*find_path(char **envp);
void	exec_cmd1(char **envp, t_pipex *px);
void	exec_cmd2(char **envp, t_pipex *px);

/* utilities functions */

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2, char *s3);

/* free and error functions */

void	free_struct(t_pipex *px);
void	free_struct_full(t_pipex *px);
void	error_execve(t_pipex *px, char *msg_error);

#endif
