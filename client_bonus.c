/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:24:06 by vpozniak          #+#    #+#             */
/*   Updated: 2025/05/07 16:14:11 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_sender(pid_t pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	temp_char = character;
	i = 7;
	while (i >= 0)
	{
		if ((temp_char >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(600);
		i--;
	}
}

void	signal_ack(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Received signal SIGUSR1 \n");
	if (signal == SIGUSR2)
		ft_printf("Received signal SIGUSR2 \n");
}

int	main(int argc, char **argv)
{
	int		i;
	char	*message;
	pid_t	server_pid;

	if (argc != 3 || argv[2][0] == '\0')
	{
		ft_printf("Incorrect number of arguments or missing message");
		return (1);
	}
	signal(SIGUSR1, signal_ack);
	signal(SIGUSR2, signal_ack);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		signal_sender(server_pid, message[i]);
		i++;
	}
	signal_sender(server_pid, '\0');
	ft_printf("Message sent.\n");
	return (0);
}
