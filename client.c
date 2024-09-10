/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btehrani <btehrani@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:57:57 by btehrani          #+#    #+#             */
/*   Updated: 2024/09/09 15:42:48 by btehrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(int pid, char *message)
{
	int		i;
	int		bit_index;
	unsigned char	c;

	i = 0;
	while (message[i])
	{
		c = message[i];
		bit_index = 7;
		while (bit_index >= 0)
		{
			if ((c >> bit_index) & 1) //c >> bit_index shifts bits of char c by 'bit_index' positions. &1 isolates LSB and checks if it is 1
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			bit_index--;
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	int	server_pid;
	char	*message;

// error handling because the program can only run if there are 3 args
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]); //acquire server PID
		if (!server_pid) //error handling in case there is no PID
		{
			ft_printf("ERROR: Wrong PID");
			return (0);
		}
		message = argv[2]; //acquire message
		send_signals(server_pid, message);
		send_signals(server_pid, "\n"); //signal the end of the str and mark it with a new line
	}
	else
	{
		ft_printf("ERROR: Too many or too few arguments.\n Enter arguments");
		ft_printf("as follows: ./client <PID> <message>");
		return (1);
	}
	return (0);
}
