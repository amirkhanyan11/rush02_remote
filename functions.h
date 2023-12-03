/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:26:25 by tyavroya          #+#    #+#             */
/*   Updated: 2023/12/03 19:47:23 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*creating_word(char *buffer, int size, int index);

void	print_word(char *str)
{
	write(1, " ", 1);
	while (*str)
	{
		write(1, str, 1);
		++str;
	}
	write(1, " ", 1);
}

int	check_num(char *buffer, char *num, int index)
{
	int	i;

	i = 0;
	while (num[i] != '\0' || buffer[index] != ':')
	{
		if (buffer[index] != num[i])
			return (0);
		++i;
		++index;
	}
	return (1);
}

char	*find_num(char *buffer, char *num, char *dest)
{
	int	i;
	int	needed;
	int	flag;

	i = 0;
	flag = 0;
	while (buffer[++i] != '\0')
	{
		if (buffer[i] >= '0' && buffer[i] <= '9')
			flag = check_num(buffer, num, i);
		if (flag)
		{
			while (buffer[i] != '\n')
			{
				if (buffer[i] == ':')
					needed = i;
				++i;
			}
			dest = creating_word(buffer, i - needed - 1, needed);
			return (dest);
		}
	}
	return (0);
}

int	my_strlen_argv(char *argv)
{
	int	count;

	count = 0;
	while (argv[count] >= '0' && argv[count] <= '9')
	{
		++count;
	}
	return (count);
}

void	print_parts(int len, char *buffer, int stop)
{
	char	*partition;
	char	*res;

	while (len != 0)
	{
		partition = (char *) malloc(sizeof(char) * len + 1);
		partition[0] = '1';
		while (stop < len)
		{
			partition[stop] = '0';
			++stop;
		}
		partition[stop] = '\0';
		res = find_num(buffer, partition, res);
		if (res != 0)
		{
			print_word(res);
			free(partition);
			break ;
		}
		--len;
		stop = 1;
		free(partition);
	}
}
