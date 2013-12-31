/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 15:01:43 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/31 16:45:38 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_fd	*open_files(char ***param)
{
	t_fd	*fd;

	if (!(fd = (t_fd*) malloc(sizeof(t_fd) * 2)))
		return (NULL);
	if ((fd[0] = open(param[0][0], O_RDONLY)) == -1
		|| (fd[1] = open(param[3][0], O_WRONLY | O_CREAT | O_TRUNC, 420)) == -1)
		return (NULL);
	return (fd);
}
