
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

static int	g_client_pid = 0;

int	handle_pid_bit(int signal)
{
	static int	bit_index = 0;

	g_client_pid <<= 1;
	if (signal == SIGUSR1)
		g_client_pid |= 1;
	bit_index++;
	if (bit_index == 32)
	{
		bit_index = 0;
		return (1);
	}
	return (0);
}

int	handle_char_bit(int signal)
{
	static char	c = 0;
	static int	bit = 0;

	c <<= 1;
	if (signal == SIGUSR1)
		c |= 1;
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if (c == '\0')
		{
			write(1, "\n", 1);
			usleep(10);
			kill(g_client_pid, SIGUSR2);
			kill(g_client_pid, SIGUSR1);
			g_client_pid = 0;
			return (1);
		}
		write(1, &c, 1);
		c = 0;
	}
	usleep(10);
	kill(g_client_pid, SIGUSR2);
	return (0);
}

void	handle_signal(int signal)
{
	static int	got_full_pid = 0;
	static int	got_full_message = 0;

	if (!got_full_pid)
		got_full_pid = handle_pid_bit(signal);
	else
		got_full_message = handle_char_bit(signal);
	if (got_full_message == 1)
	{
		got_full_pid = 0;
		got_full_message = 0;
		return ;
	}
}

int	main(void)
{
	ft_printf("Server Process ID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
