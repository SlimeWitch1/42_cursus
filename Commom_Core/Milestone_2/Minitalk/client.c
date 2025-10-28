
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

//We declare a global variable that will manage with the response signal from
	//the Server, so the Client only send another signal for the message when
	//it receives confirmation from the Server.
	//This way we prevent errors, as to not cross signals and lose info.
//Check bellow for detailed info on the variable.
volatile sig_atomic_t	g_ack = 1;

void	server_signal_check(int signal)
{
	//Any time we receive a signal SIGUSR2 from the server, the program changes
		//g_ack to 0 so we can tell the send_signal() function to keep going
		//and send the next signal.
	if (signal == SIGUSR2)
		g_ack = 0;
}

void	send_pid(int server_pid)
{
	//This function runs only once for each time you run the Client program, and
	//sends the Client PID to the server bit by bit, in a loop that runs 32 times.
	//We declare two int variables and a char variable to manage the logic.
	int	client_pid; //This will store the Client PID.
	int	bit_index; //This will control how many times we run the loop, until 32.
	int	bit; //This will be a temporary variable to hold each bit of client_pid.

	bit = 0;
	client_pid = getpid(); //To get the program PID of the Client.
	bit_index = 32;
	while (bit_index > 0) //Run the loop until we have sent 32 signals.
	{
		bit_index--;
		//We move a number of bits on client_pid equal to bit_index, and store that
			//on the bit variable.
		bit = client_pid >> bit_index;
		//We use the bit modulus of 2 (the rest of the division of bit by 2) to
		 	//check if the bit we want to send is 1 or 0.
		if (bit %2 != 0) //This work because we're dealing with binaries.
			kill(server_pid, SIGUSR1); //We send a 1 signal if the bit is 1.
		else //Otherwise we send a 0 signal if the bit is 0.
			kill(server_pid, SIGUSR2);
		//Then we have the program wait a little time to send another signal to not
			//cause it to lose info.
		usleep(200);
	}
}

void	send_signal(int pid, unsigned char character, int bit_index)
{
	//Each time we call this function it will send a character to the Server, bit
		//by bit in a loop that will run 8 times.
	//We declare just a char variable to be a temporary variable to hold each bit
		//of the character..
	unsigned char	bit;

	bit = 0;
	while (bit_index > 0) //Run the loop until we have sent 8 signals.
	{
		bit_index--;
		bit = character >> bit_index;
		//We use the bit modulus of 2 (the rest of the division of bit by 2) to
		 	//check if the bit we want to send is 1 or 0.		
		if (bit % 2 != 0)
			kill(pid, SIGUSR1); //We send a 1 signal if the bit is 1.
		else //Otherwise we send a 0 signal if the bit is 0.
			kill(pid, SIGUSR2);
		//Then we have the program wait until it receives a signal back from the
			//server, and only then it sends another signal, to not cause it to
			// lose info.
		 //We do this with the help of the g_ack global variable. When the Server
		 	//sends a signal, the server_signal_check() function will change g_ack
			//to 0 and break the usleep() loop.
		while (g_ack)
			usleep(10); //Until this loop is broken, we usleep().
		g_ack = 1; //After the loop is broken we reset g_ack to send the next signal.
	}
}

int	main(int argc, char *argv[])
{
	//We declare two variables, one for the Server PID(argv[1]), one as the
		// index for the message (argv[2]).
	int			server_pid;
	int			i;

	//We check if there are only 2 arguments (Server PID and message)
	if (argc != 3)
	{
		//If there isn't, we print an error message and stop the program.
		ft_printf("Syntax: %s <PID> <Message>\n", argv[0]);
		return (1);
	}
	//Then we prepare the program to receive the signal from the Server, for the
		//server_signal_check() funciton.
	signal(SIGUSR2, server_signal_check); //In this case we need only SIGUSR2 for 0.
	server_pid = ft_atoi(argv[1]); //We get the Server PID in argv[1].
	send_pid(server_pid); //Then we send the Client PID to the Server before the message.
	i = 0; //Start the index.
	//While there's still characters in the message string(argv[2]), we call
		// send_signal() to send 8 signals for each character.
	while (argv[2][i] != '\0')
	{
		send_signal(server_pid, (unsigned char) argv[2][i], 8);
		i++;
	}
	//When the message string ends, we send 8 more signals for the '\0' character,
		//so the Server knows the message ended.
	send_signal(server_pid, argv[2][i], 8); //At this point argv[2][i] = '\0'.
	return (0);
}

// volatile: This keyword instructs the compiler not to optimize accesses to the
// variable. When a variable is declared volatile, the compiler will not cache
// its value in registers but will instead always read its value from memory and
// write its value directly to memory. This is crucial for variables shared with
// signal handlers, as the signal handler might modify the variable at any time,
// and the main program needs to see the most up-to-date value.

// sig_atomic_t is an integer type defined in <signal.h>. It is guaranteed by the
// C standard to be an object that can be accessed as an atomic entity, even in the
// presence of asynchronous interrupts (like signals). This means that reading or
// writing a sig_atomic_t variable is an indivisible operation, preventing partial
// updates or inconsistent reads if a signal handler interrupts the main program
// during the access.
