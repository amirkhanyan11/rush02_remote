/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __string_manip__.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:47:05 by aamirkha          #+#    #+#             */
/*   Updated: 2023/12/03 00:21:20 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Stringify
static char	*stringify_power(int exp)
{
	char	*nb;
	char	*t_nb;

	if (exp < 0)
	{
		return (0);
	}
	nb = (char *) malloc (exp + 1);
	t_nb = nb + 1;
	nb[0] = '1';
	while (exp >= 1)
	{
		*t_nb = '0';
		t_nb++;
		exp--;
	}
	return (nb);
}
/*
static char	*stringify_digit(int nb)
{
	char	*dg;

	dg = (char *) malloc (2 * sizeof(char));
	dg[0] = (nb + '0');
	dg[1] = '\0';
	return (dg);
}
*/
