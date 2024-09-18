/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2024/09/18 19:36:51 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "../include/minishell.h"

char	**change_mat(char **mat)
{
	char	**src;
	int		i;
	int		j;

	src = ft_calloc(ft_matlen(mat) + 1, sizeof(char *));
	i = -1;
	j = -1;
	src = mini_change_mat(mat, i, j, src);
	return (src);
}

char	**line_split(char *line)
{
	char	*clean;
	char	**mat;
	char	**dollar;

	clean = clean_line(line);
	mat = ft_split(clean, ' ');
	if (!mat)
		ft_error(MALLOC, NULL);
	free(clean);
	dollar = change_mat(mat);
	ft_free(mat);
	return (dollar);
}