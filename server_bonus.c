/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:23:43 by vpozniak          #+#    #+#             */
/*   Updated: 2025/05/06 14:13:35 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_interpretor(int sigsent, siginfo_t *info, void *context)
{
	static unsigned char	character = 0;
	static int				i = 0;
	static pid_t			client_pid = 0;

	// static t_data	sig_intrtrpr = {0, 0, 0};
	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (sigsent == SIGUSR1)
		character |= (1 << (7 - i));
	i++;
	if (i == 8)
	{
		if (character == '\0')
		{
			ft_printf("\n");
			// ft_printf("\nMessage sent by: %d\n", client_pid);
			// client_pid = 0;
		}
		else
			ft_printf("%c", character);
		character = 0;
		i = 0;
	}
	if (sigsent == SIGUSR1)
		kill(client_pid, SIGUSR1);
	else if (sigsent == SIGUSR2)
		kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction action_config;

	ft_printf("PID is: %i\n", getpid()); // - Returns the current process ID
	action_config.sa_flags = SA_SIGINFO | SA_RESTART;
	action_config.sa_sigaction = &signal_interpretor;
	sigemptyset(&action_config.sa_mask);

	sigaction(SIGUSR1, &action_config, NULL);
	sigaction(SIGUSR2, &action_config, NULL);

	while (1)
		pause();
	return (0);
}