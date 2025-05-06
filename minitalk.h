#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// utils.c
int					ft_atoi(const char *str);
// server.c
void				signal_interpretor(int sigsent);
// client.c
void				signal_ack(int signal);
void				signal_sender(pid_t pid, unsigned char character);

typedef struct s_data
{
	unsigned char	character;
	int				i;
}					t_data;
#endif