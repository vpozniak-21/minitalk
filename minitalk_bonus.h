#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stddef.h>
# include <unistd.h>

// utils.c
int		ft_atoi(const char *str);
// server.c
void	signal_interpretor(int sigsent, siginfo_t *info, void *context);
// client.c
void	signal_ack(int signal);
void signal_sender(pid_t pid, unsigned char character);

typedef struct s_data
{
	unsigned char character;
	int i;
	pid_t client_pid;
}		t_data;
#endif