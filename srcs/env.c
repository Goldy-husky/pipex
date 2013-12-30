/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 14:28:30 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/30 14:31:23 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env(char *key, char **arge)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	tmp = ft_strjoin(key, "=");
	len = ft_strlen(tmp);
	while (arge[i] != NULL)
	{
		if (ft_strncmp(tmp, arge[i], len) == 0)
		{
			free(tmp);
			return (arge[i] + len);
		}
		i++;
	}
	free(tmp);
	return (NULL);
}
