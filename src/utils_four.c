/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2024/09/16 20:49:45 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_pwd(void)
{
	char	*src;

	src = current_directory();
	if (!src)
		printf("NO PWD\n");
	else
		printf("%s\n", src);
	free(src);
}

char	*search_op(char *src)
{
	if (ft_strnstr(src, "<", ft_strlen(src)))
		return (src);
	if (ft_strnstr(src, ">", ft_strlen(src)))
		return (src);
	if (ft_strnstr(src, "<<", ft_strlen(src)))
		return (src);
	if (ft_strnstr(src, ">>", ft_strlen(src)))
		return (src);
	if (ft_strnstr(src, "|", ft_strlen(src)))
		return (src);
	return (NULL);
}