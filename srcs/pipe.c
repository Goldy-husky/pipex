/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 16:46:05 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/30 17:12:17 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		exec_child(char ***param, char **arge, t_fd *pfd, t_fd fd)
{
	close(pfd[1]);
	dup2(pfd[0], 0);
	dup2(fd, 1);
	close(pfd[0]);
	execve(param[2][0], param[2], arge);
	return (0);
}

int		exec_father(char ***param, char **arge, t_fd *pfd, t_fd fd)
{
	close(pfd[0]);
	dup2(pfd[1], 1);
	dup2(fd, 0);
	close(pfd[1]);
	execve(param[1][0], param[1], arge);
	return (0);
}
