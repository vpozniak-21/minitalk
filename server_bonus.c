/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:23:43 by vpozniak          #+#    #+#             */
/*   Updated: 2025/05/07 17:21:40 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_interpretor(int sigsent, siginfo_t *info, void *context)
{
	static unsigned char	character = 0;
	static int				i = 0;

	if (sigsent == SIGUSR1 || sigsent == SIGUSR2)
	{
		(void)context;
		if (sigsent == SIGUSR2)
			character |= (1 << (7 - i));
		i++;
		if (i == 8)
		{
			i = 0;
			if (character == '\0')
			{
				write(1, "\n", 1);
				character = 0;
				kill(info->si_pid, sigsent);
				usleep(50);
				return ;
			}
			write(1, &character, 1);
			character = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	action_config;

	ft_printf("PID is: %i\n", getpid());
	action_config.sa_flags = SA_SIGINFO | SA_RESTART;
	action_config.sa_sigaction = &signal_interpretor;
	sigemptyset(&action_config.sa_mask);
	sigaction(SIGUSR1, &action_config, NULL);
	sigaction(SIGUSR2, &action_config, NULL);
	while (1)
		;
	return (0);
}
