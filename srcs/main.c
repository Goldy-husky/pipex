/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 12:13:58 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/30 15:59:15 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	launch_it(char ***param, char **arge)
{
	pid_t	father;
	char	*exec_file[2];
	int		*status;

	status = NULL;
	if (!(exec_file[0] = find_exec(param[1][0], arge))
		|| !(exec_file[1] = find_exec(param[2][0], arge)))
		return (ERROR_EXEC);

}

static char	**add_param(char *input);
{
	char	**rtn;

	if (!(rtn = (char**) ft_memalloc(sizeof(char*) * 2)))
		return (NULL);
	if (!(rtn[0] = ft_strdup(input)))
		return (NULL);
	return (rtn);
}

static char	***parse_input(int argc, char **argv)
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
}

int			main(int argc, char **argv, char **arge)
{
	char	***param;
	int		error;
	t_fd	*fd;

	if (argc < 5)
		return (error_dsp(ERROR_MISSING_ARGS));
	if (!(param = parse_input(argc, argv)))
		return (error_dsp(ERROR_PARSE));
	if (!(fd = open_files(param)))
		return (error_dsp(ERROR_OPENFILE))
	if ((error = launch_it(param, arge, fd)))
		return (error_dsp(error));
	return (0);
}
