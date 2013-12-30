/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 12:16:11 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/30 16:54:18 by cmehay           ###   ########.fr       */
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
	ERROR_PIPE
}				t_error;

#endif
