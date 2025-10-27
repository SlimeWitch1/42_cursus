
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

//We declare a global variable to store the Client PID we're going to build
	//each time we run the Client program.
static int	g_client_pid = 0;

int	handle_pid_bit(int signal)
{
	//Each time we receive a signal for the Client PID, the program calls this function.
		//We declare one static variable to navigate the logic.
	static int	bit_index = 0; //This will tell how many signals we already received, until 32.
							   //32 is the number of bits we need for any PID we have to build.

	//We open space to put a bit in the bit  for the PID.
	g_client_pid = g_client_pid << 1; //Moving every bit one to the left.
	if (signal == SIGUSR1) //If the signal received was 1.
		g_client_pid = g_client_pid | 1; //We put one on the bit space we opened.
	bit_index++; //Increase the index to mark the first signal received.
	if (bit_index == 32) //When we receive 32 signals, the PID is complete.
	{
		bit_index = 0; //We restart the index to prepare for the next PID.
		//Then we return one to tell handle_signal that we finished the PID.
		return (1);
	}
	//Otherwise we return 0 to tell handle_signal that we still have
		// to finish the PID.
	return (0);
}

int	handle_char_bit(int signal)
{
	//Each time we receive a signal for the message, the program calls this function.
		//We declare two static variables to navigate the logic.
	static char	c = 0; //We will build the character received here every 8 signals.
	static int	bit_index = 0; //This will tell how many signals we already received, until 8.

	//We open space to put a bit in the bit for the char.
	c = c << 1; //Moving every bit one to the left.
	if (signal == SIGUSR1) //If the signal received was 1.
		c = c | 1; //We put one on the bit space we opened.
	bit_index++; //Increase the index to mark the first signal received.
	if (bit_index == 8) //When we receive 8 signals, the character is complete.
	{
		bit_index = 0; //We restart the index to prepare for the next character.
		if (c == '\0') //If it's the end of the message.
		{
			ft_printf("\n"); //Skip a line in the terminal.
			usleep(10); //Wait a little time to send the signal to the client.
			//Send a 0 signal to the client, to confirm the server received the signal.
			kill(g_client_pid, SIGUSR2);
			//We restart the Client PID to prepare for a next client and message.
			g_client_pid = 0;
			//Then we return one to tell handle_signal that we finished the message.
			return (1);
		}
		ft_printf("%c", c);//If it's not the end of the message, we print the character we built.
		c = 0; //We restart the character to prepare for the next one.
	}
	usleep(1); //Wait a little time to send the signal to the client.
	//Send a 0 signal to the client, to confirm the server received the signal.
	kill(g_client_pid, SIGUSR2);
	//Otherwise we return 0 to tell handle_signal that we still have
		// to finish the message.
	return (0);
}

void	handle_signal(int signal)
{
	//Each time we receive a signal (1 or 0), the program sends it to handle_signal().
		//We declare two static variables to check each time we receive a signal if:
	static int	got_full_pid = 0; //We finished to build the Client PID.
	static int	got_full_message = 0; //We finished building and printing the message.

	//If we're still on the first 32 signals, still building the Client PID:
	if (!got_full_pid) //The program calls the handle_pid_bit function to build the Client PID.
		got_full_pid = handle_pid_bit(signal); //And the return tells it if we're finished or not.
	//If we're already done with the Client PID, we start working in the message.
	else //The program calls the handle_char_bit function to receive and print the message.
		got_full_message = handle_char_bit(signal); //And the return tells it if we're finished or not.
	//Only after we finish printing the message, we restart the value of the two
		//static variables, to prepare for a new client and message.
	if (got_full_message == 1)
	{
		got_full_pid = 0;
		got_full_message = 0;
		return ; //Then we return.
	}
}

int	main(void)
{
	//First we print the server PID to the terminal.
	ft_printf("Server Process ID: %d\n", getpid());
	//Then we prepare the program to receive the signals
	//(SIGUSR1 for 1 and SIGUSR2 for 0).
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	//Then we create a loop to wait for signals with pause().
	while (1)
		pause();
	return (0);
}
