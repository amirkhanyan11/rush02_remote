/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:41:41 by aamirkha          #+#    #+#             */
/*   Updated: 2023/12/03 00:21:39 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define DEBUG
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "__algorithms__.h"


int	main(void)
{
	int	fd;

	fd = open("numbers.dict", O_RDONLY);
	char	buffer[600];
	read(fd, buffer, 500);
	close(fd);
	chulan(buffer, 9, 7);
	return (0);
}

