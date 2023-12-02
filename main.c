/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:41:41 by aamirkha          #+#    #+#             */
/*   Updated: 2023/12/02 18:25:45 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "__algorithms__.h"
//#define DEBUG

char	*stringify(int exp)
{
	char	*nb;
	char	*t_nb;

	nb = (char*)malloc (exp + 1);
	nb[0] = '1';
	t_nb = nb + 1;
	while (exp >= 1)
	{
		*t_nb = '0';
		t_nb++;
		exp--;
	}
#ifdef DEBUG
	printf("%s\n", nb);
#endif
	return (nb);
}

void get_it(char* buffer, int exp)
{
	char	*needle;
	char	*needle_print;

	needle = stringify(exp);
	needle_print = ft_strstr(buffer, needle);
	while (is_alpha(*needle_print))
	{
		write(1, needle_print, 1);
		needle_print++;
	}
#ifdef DEBUG
	printf("%s\n", needle_print);
#endif
	write(1, "\n", 1);
	free(needle);
}

int main()
{
	
	int fd = open("numbers.dict", O_RDONLY);
	char buffer[600];
	read(fd, buffer, 500);
	//printf("%s\n", buffer);
	close(fd);
	
	get_it(buffer, 4);	
	return 0;
}
