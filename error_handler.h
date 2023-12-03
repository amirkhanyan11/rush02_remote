/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:04:23 by tyavroya          #+#    #+#             */
/*   Updated: 2023/12/03 20:09:16 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	error_handler(int argc, char **argv)
{
	int	count;

	if (argc == 1 || argc > 3)
	{
		write(1, "Error", 5);
		return (0);
	}
	count = 0;
	while (argv[1][count] != '\0')
	{
		if (argv[1][count] < '0' || argv[1][count] > '9')
			return (0);
		++count;
	}
	return (1);
}
