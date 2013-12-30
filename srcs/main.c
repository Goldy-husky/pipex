/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 12:13:58 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/30 17:45:44 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_error	launch_it(char ***param, char **arge, t_fd *fd)
{
	pid_t	father;
	char	*exec_file[2];
	int		*status;
	t_fd	pfd[2];

	status = NULL;
	if (!(exec_file[0] = find_exec(param[1][0], arge))
		|| !(exec_file[1] = find_exec(param[2][0], arge)))
		return (ERROR_EXEC);
	if (pipe(pfd) == -1)
		return (ERROR_PIPE);
	father = fork();
	if (father == 0)
		exec_child(param, arge, fd, fd[1]);
	if (father > 0)
		exec_father(param, arge, fd, fd[0]);
	return (0);
}

static char		**add_param(char *input)
{
	char	**rtn;

	if (!(rtn = (char**) ft_memalloc(sizeof(char*) * 2)))
		return (NULL);
	if (!(rtn[0] = ft_strdup(input)))
		return (NULL);
	return (rtn);
}

static char		***parse_input(char **argv)
{
	char	***rtn;
	int		shift;

	shift = 2;
	if (!(rtn = (char***) malloc(sizeof(char**) * 4)))
		return (NULL);
	if (!(rtn[0] = add_param(argv[1])))
		return (NULL);
	if (!(rtn[1] = ft_strsplit(argv[2], ' ')))
		return (NULL);
	if (!(rtn[2] = ft_strsplit(argv[3], ' ')))
		return (NULL);
	if (!(rtn[3] = add_param(argv[4])))
		return (NULL);
	return (rtn);
}

int				main(int argc, char **argv, char **arge)
{
	char	***param;
	int		error;
	t_fd	*fd;

	if (argc != 5)
		return (error_dsp(ERROR_MISSING_ARGS));
	if (!(param = parse_input(argv)))
		return (error_dsp(ERROR_PARSE));
	if (!(fd = open_files(param)))
		return (error_dsp(ERROR_OPENFILE));
	if ((error = launch_it(param, arge, fd)))
		return (error_dsp(error));
	return (0);
}
