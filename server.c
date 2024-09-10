/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btehrani <btehrani@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:10:23 by btehrani          #+#    #+#             */
/*   Updated: 2024/09/10 16:50:11 by btehrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_reciever = 0;

//function to append recieved char to message string
char	*append_char_to_str(char **result, unsigned char character)
{
	char	*temp;
	int	len;

	if (*result)
		len = ft_strlen(*result);
	else
		len = 0;
	temp = malloc(len + 2);
	if (!temp)
		return (NULL);
	if (*result)
		ft_strcpy(temp, *result);
	temp[len] = character;
	temp[len + 1] = '\0';
	free(*result);
	*result = temp;
	return (*result);
}

//recieve signals and handle the case for each signal/decrypt signal
void	signal_handler(int signum)
{
	static unsigned char	character = 0;
	static int		bit_count = 0; //for counting bits
	static char		*result; //to hold the result message and print it as an str instead of printing chars one by one

	if (!result)
		result = ft_strdup(""); //create an empty str to add chars to
	if (signum == SIGUSR1)
		character = (character << 1) | 1; // shift left and add 1
	else if (signum == SIGUSR2)
		character = (character << 1); // shift left and add 0
	bit_count++;
	if (bit_count == 8) //once you've recieved enough bits, make sense of the char
	{
		result = append_char_to_str(&result, character);
		if (character == '\0')
		{
			ft_printf("%s\n", result);
			free(result);
			result = NULL;
		}
		character = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Welcome to btehrani's server ! ^_^\n");
	ft_printf("The server's PID: %d\n", getpid()); // display the PID
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1) // create an endless loop so the server keeps checking for signals
		pause();
}
