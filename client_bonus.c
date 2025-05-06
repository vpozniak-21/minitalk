/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:24:06 by vpozniak          #+#    #+#             */
/*   Updated: 2025/05/06 14:13:11 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

// volatile sig_atomic_t	ack_received = 0;
// void	signal_ack(int signal)
// {
// 	if (signal == SIGUSR1)
// 	{
// 		ft_printf("ACK received from server\n");
// 		ack_received = 1;
// 	}
// }
void	signal_sender(pid_t pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	temp_char = character;
	i = 7;
	while (i >= 0)
	{
		// ack_received = 0;
		if ((temp_char >> i) & 1)
			kill(pid, SIGUSR2); // send 1
		else
			kill(pid, SIGUSR1); // send 0
		// while (!ack_received)
		// 	pause();
		usleep(420);
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

int main(int argc, char **argv)
{
	if (argc != 3 || argv[2][0] == '\0')
	{
		ft_printf("Incorrect number of arguments or missing message");
		return (1);
	}
	signal(SIGUSR1, signal_ack);
	signal(SIGUSR2, signal_ack);

	pid_t server_pid = ft_atoi(argv[1]);
	char *message = argv[2];
	int i = 0;
	while (message[i])
	{
		signal_sender(server_pid, message[i]);
		i++;
	}
	signal_sender(server_pid, '\0');
	return (0);
}