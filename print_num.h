/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:04:46 by tyavroya          #+#    #+#             */
/*   Updated: 2023/12/03 19:51:43 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_one(char *buffer, char *str, int strlen)
{
	int	i;

	i = -1;
	while (buffer[++i] != '\0')
	{
		if (buffer[i] == *str)
		{
			i += 3;
			while (buffer[i] != '\n')
			{
				write(1, buffer + i, 1);
				++i;
			}
			break ;
		}
	}
	if (strlen > 3)
		print_parts(strlen, buffer, 1);
}

void	print_two(char *buffer, char *str, int strlen)
{
	char	*ptr;
	char	*dest;

	dest = 0;
	ptr = (char *) malloc(sizeof(char) * 2);
	if (str[0] < '2')
	{
		print_word(find_num(buffer, str, ptr));
		return ;
	}
	ptr[0] = str[0];
	ptr[1] = '0';
	print_word(find_num(buffer, ptr, dest));
	if (str[1] != '0')
		print_one(buffer, str + 1, 0);
	if (strlen > 3)
	{
		print_parts(strlen, buffer, 1);
	}
	free(ptr);
	free(dest);
}

void	print_three(char *buffer, char *str, int strlen)
{
	char	*dest;

	dest = 0;
	if (str[0] != '1')
	{
		print_one(buffer, str, 0);
		write(1, " ", 1);
	}
	print_word(find_num(buffer, "100", dest));
	if (str[1] != '0')
		print_two(buffer, str + 1, 0);
	if (strlen > 3)
		print_parts(strlen, buffer, 1);
	free(dest);
}

void	print_num(char *buffer, char *str, int strlen)
{
	if (strlen <= 0)
		return ;
	else if (strlen % 3 == 0)
	{
		print_three(buffer, str, strlen);
		print_num(buffer, str + 3, strlen - 3);
	}
	else if (strlen % 3 == 2)
	{
		print_two(buffer, str, strlen);
		print_num(buffer, str + 2, strlen - 2);
	}
	else if (strlen % 3 == 1)
	{
		print_one(buffer, str, strlen);
		print_num(buffer, str + 1, strlen - 1);
	}
}

static char	*creating_word(char *buffer, int size, int index)
{
	char	*dest;
	char	*t_dest;

	dest = (char *) malloc(sizeof(char) * size);
	t_dest = dest;
	index += 2;
	while (buffer[index] != '\n')
	{
		*dest = buffer[index];
		++dest;
		++index;
	}
	*dest = '\0';
	return (t_dest);
}
