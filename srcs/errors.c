/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:47:48 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/30 15:54:17 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_dsp(t_error idx)
{
	char	*errors[]
	{
		"Parse error",
		"Args missing",
		"Error while parsing executables",
		"Error while open files"
	}

	ft_putchar_fd(errors[idx], 2);
	ft_putchar_fd("\n", 2);
	return (1);
}
