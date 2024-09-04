// display PID
void	display_pid(void) //? not sure if the parametre is supposed to be void
{
	int	pid;

	pid = getpid();
	ft_printf(pid); // fix this, not sure howw to display the pid
}

//create an endless loop so the server is constantly searching for signals
while (1)
{
	pause(); //suspend the process until a signal is recieved
}

//recieve signals and handle each case accordingly (depending on whether the bit was 0 or 1)
void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		// handle the case if the bit were 0
	}
	else if (signum == SIGUSR2)
	{
		// handle the acse if the bit were 1
	}
}

//decrypt signals: use SIGUSR1 to indicate you've recieved 1 ? idk

// for each signal recieved, take a certain action
