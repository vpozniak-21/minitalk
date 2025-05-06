#include "minitalk.h"

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bits = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (signum == SIGUSR1)
		c |= (1 << (7 - bits));
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			write(1, "Message received completely!\n", 29);
			kill(client_pid, SIGUSR1);
			client_pid = 0;
		}
		else
			write(1, &c, 1);
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server Process ID (PID): %d\n", pid);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) ==
		-1)
	{
		perror("Error setting up signal handler");
		return (EXIT_FAILURE);
	}
	ft_printf("Server is waiting for signals...\n");
	while (1)
		;
	return (EXIT_SUCCESS);
}

// void	signal_interpretor(int sigsent)
// {
// 	static t_data	sig_intrtrpr = {0, 0};

// 	sig_intrtrpr.character <<= 1;
// 	if (sigsent == SIGUSR1)
// 		sig_intrtrpr.character |= 0;
// 	else if (sigsent == SIGUSR2)
// 		sig_intrtrpr.character |= 1;
// 	sig_intrtrpr.i++;
// 	if (sig_intrtrpr.i == 8)
// 	{
// 		ft_printf("%c", sig_intrtrpr.character);
// 		sig_intrtrpr.character = 0;
// 		sig_intrtrpr.i = 0;
// 	}
// }
// int	main(void)
// {
// 	ft_printf("PID is: %i\n", getpid()); // - Returns the current process ID
// 	signal(SIGUSR1, signal_interpretor);
// 	signal(SIGUSR2, signal_interpretor);
// 	while (1)
// 		pause();
// 	return (0);
// }
