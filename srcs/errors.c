/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:47:48 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/30 17:25:34 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_dsp(t_error idx)
{
	char	*errors[] =
	{
		"Parse error",
		"Args missing",
		"Error while parsing executables",
		"Error while open files",
		"Error while creating pipe"
	};

	ft_putstr_fd(errors[idx], 2);
	ft_putstr_fd("\n", 2);
	return (1);
}
