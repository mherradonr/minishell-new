/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2024/09/18 20:49:10 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

volatile int sig = 0;

int	main(int argn, char **argv, char **env)
{
	char	*here;
	char	*current;
	char	**commands;

	if (argn > 1 || argv[1])
		return (printf("Error: bad number of arguments\n"), 0);
	print_minishell();
	// is_signal();
	
	// ctr c - inter - new line; no inter - se sale y return 130
	// ctr d - inter - se sale; no int - se sale y return 0
	// devuelve 0, 1, 127, 130
	while (1)
	{
		//ft_putstr_fd(current, 1);
		current = first_line();
		here = readline(current);
		if (!here)
			ft_error(MALLOC, NULL);
		if (ft_strncmp(here, "exit", ft_strlen("exit")) == 0)
			break ;
		if (here && *here)
			add_history(here);
		commands = line_split(here);
		if (ft_fullcmp(commands[0], "cd") == 0)
			change_cd(commands);
		else if (search_op(here))
			ft_operator(commands, here, env);
		else if (ft_fullcmp(commands[0], "echo") == 0)
			ft_echo(commands);
		else if (ft_fullcmp(commands[0], "pwd") == 0)
			ft_pwd();
		else if (!commands[0])
		{
			free(here);
			free(current);
			ft_free(commands);
			continue ;
		}
		else
			ft_command(commands, env);
		free(here);
		free(current);
		ft_free(commands);
	}
	free(here);
	free(current);
	clear_history();
	exit(0);
	return (0);
}
