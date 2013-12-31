/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 12:16:11 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/31 16:20:44 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef int	t_fd;

typedef enum	e_error
{
	ERROR_PARSE,
	ERROR_MISSING_ARGS,
	ERROR_EXEC,
	ERROR_OPENFILE,
	ERROR_PIPE,
	ERROR_LAUNCH
}				t_error;

typedef struct	s_fdstruct
{
	t_fd	pipe[2];
	t_fd	in_file;
	t_fd	out_file;
}				t_fdstruct;

char	*find_exec(char *str, char **arge);

char	*get_env(char *key, char **arge);

int		error_dsp(t_error idx);

t_fd	*open_files(char ***param);

void	free_str_array(char **arge);

int		exec_child(char *exec, char ***param, char **arge, t_fdstruct fd);
int		exec_father(char *exec, char ***param, char **arge, t_fdstruct fd);

#endif
