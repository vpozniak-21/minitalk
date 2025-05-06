#include "minitalk.h"

void	handle_ack(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, "Acknowledgment received from server!\n", 36);
	}
}

static void	send_bit(pid_t pid, int bit)
{
	if (bit)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Error sending SIGUSR1\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Error sending SIGUSR2\n");
			exit(EXIT_FAILURE);
		}
	}
	usleep(50);
}

void	send_message(pid_t pid, const char *message)
{
	unsigned char	c;
	int				i;

	while (*message)
	{
		c = (unsigned char)*message++;
		i = 8;
		while (i--)
			send_bit(pid, (c >> i) & 1);
	}
	c = '\0';
	i = 8;
	while (i--)
		send_bit(pid, (c >> i) & 1);
}



int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf("Usage: %s <PID> <MESSAGE>\n", av[0]);
		return (EXIT_FAILURE);
	}
	pid = (pid_t)ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID: %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	if (signal(SIGUSR1, handle_ack) == SIG_ERR)
	{
		ft_printf("Error setting up acknowledgment handler\n");
		return (EXIT_FAILURE);
	}
	send_message(pid, av[2]);
	return (EXIT_SUCCESS);
}

// void	signal_sender(pid_t pid, unsigned char character)
// {
// 	int	i;

// 	i = 7;
// 	// unsigned char temp = character;
// 	while (i >= 0)
// 	{
// 		if (character >> i & 1)
// 			kill(pid, SIGUSR2); // SIGUSR 2 is 1
// 		else
// 			kill(pid, SIGUSR1); // SIGUSR 1 is 0
// 		usleep(700);          // play around with the miliseconds
// 		i--;
// 	}
// }
// int	main(int argc, char **argv)
// {
// 	if (argc != 3 || argv[2][0] == '\0')
// 	{
// 		ft_printf("Incorrect number of arguments or missing message");
// 		return (1); // maybe exit(1) here?
// 	}

// 	pid_t server_pid = ft_atoi(argv[1]);
// 	char *message = argv[2];
// 	int i = 0;
// 	while (message[i])
// 	{
// 		signal_sender(server_pid, (unsigned char)message[i]);
// 		i++;
// 	}
// 	signal_sender(server_pid, '\0');
// 	return (0);
// }