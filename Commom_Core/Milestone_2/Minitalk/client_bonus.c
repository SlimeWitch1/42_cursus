
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

volatile sig_atomic_t	g_ack_count = 1;

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("Got the message!\n");
		exit(0);
	}
	if (signal == SIGUSR2)
		g_ack_count = 0;
}

void	send_pid(int server_pid)
{
	int	client_pid;
	int	i;

	client_pid = getpid();
	i = 32;
	while (i > 0)
	{
		i--;
		if ((client_pid >> i) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(200);
	}
}

void	send_signal(int pid, unsigned char character, int i)
{
	unsigned char	bit;

	bit = 0;
	while (i > 0)
	{
		i--;
		bit = (character >> i & 1);
		if (bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_ack_count)
			usleep(200);
		g_ack_count = 1;
	}
}

int	main(int argc, char *argv[])
{
	int			server_pid;
	int			i;

	if (argc != 3)
	{
		ft_printf("Syntax: %s <PID> <Message>\n", argv[0]);
		return (1);
	}
	signal(SIGUSR2, signal_handler);
	signal(SIGUSR1, signal_handler);
	server_pid = ft_atoi(argv[1]);
	send_pid(server_pid);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_signal(server_pid, (unsigned char) argv[2][i], 8);
		i++;
	}
	send_signal(server_pid, argv[2][i], 8);
	return (0);
}
