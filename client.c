
void	send_signals(int pid, char *message)
{
	int	i; //to iterate through the char
	int	bit_index; //to iterate over each bit index

	bit_index = 7;
	while (message[i] != '\0')
	{
		i = 0;
		while (bit_index >= 0)
		{
      //shift what's in index 7 (MSB) to be in index 0 (LSB), then check if it's & 1. if it is 1, the condition is true, and the if condition executes
			if ((c >> bit_index) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			bit_index--; //decrement bit_index by 1 to analyse the next bit. 7->6, 6->5, and so on
		}
		i++;
	}
	return (0);
}
