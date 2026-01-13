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

/* creating file to test*/

int		test2(void);
int		test(void);

/* parsing function */

void	check_existing_file(char **argv);
void	check_existing_command_line(char **argv, char **envp);
char	*find_path(char **envp);
void	join_and_execve(char **all_path, char **cmd, char **envp, char *path);

/* utilities functions */

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
