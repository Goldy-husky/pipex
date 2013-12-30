/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldy <goldy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 14:25:01 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/30 23:45:54 by goldy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*is_exec(char *path, char *file)
{
	char		*tmp_path;
	char		*tmp_file;
	struct stat	buf;
	int			fd;

	tmp_path = ft_strjoin(path, "/");
	tmp_file = ft_strjoin(tmp_path, file);
	free(tmp_path);
	if ((fd = open(tmp_file, O_RDONLY)) == -1)
		return (NULL);
	fstat(fd, &buf);
	close(fd);
	if (!S_ISDIR(buf.st_mode))
		return (tmp_file);
	free(tmp_file);
	return (NULL);
}

static char	*test_exec(char **path, char *str)
{
	int		i;
	char	*file;

	i = 0;
	while (path[i])
	{
		if ((file = is_exec(path[i++], str)))
			return (file);
	}
	return (NULL);
}

char		*find_exec(char *str, char **arge)
{
	char	**path;
	char	*rtn;

	if ((ft_strchr(str, '/')))
	{
		path = (char**) ft_memalloc(sizeof(char*) * 2);
		path[0] = (str[0] == '/')
			? ft_strnew(0) : ft_strdup(get_env("PWD", arge));
	}
	else if (get_env("PATH", arge) != NULL)
		path = ft_strsplit(get_env("PATH", arge), ':');
	else
		return (NULL);
	rtn = test_exec(path, str);
	free_str_array(path);
	return (rtn);
}
