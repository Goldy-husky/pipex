/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 16:46:05 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/31 16:38:00 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		exec_child(char *exec, char ***param, char **arge, t_fdstruct fd)
{
	t_fd	*pipe;

	pipe = fd.pipe;
	close(pipe[1]);
	dup2(pipe[0], 0);
	dup2(fd.out_file, 1);
	close(pipe[0]);
	return (execve(exec, param[2], arge));
}

int		exec_father(char *exec, char ***param, char **arge, t_fdstruct fd)
{
	t_fd	*pipe;

	pipe = fd.pipe;
	close(pipe[0]);
	dup2(pipe[1], 1);
	dup2(fd.in_file, 0);
	close(pipe[1]);
	return (execve(exec, param[1], arge));
}
