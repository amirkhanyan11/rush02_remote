/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __algorithms__.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:14:38 by aamirkha          #+#    #+#             */
/*   Updated: 2023/12/03 00:21:35 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__helper_functions__.h"
#include "__string_manip__.h"

static void	execute_printing(char *str, char *free_me)
{
	while (is_alpha(*str))
	{
		write(1, str, 1);
		str++;
	}
	write(1, " ", 1);
	free(free_me);
}

//     Get_it
static void	get_it_exp(char *buffer, int dg, int *exp)
{
	char	*ptr;
	char	*_needle;

	dg = 0;
	if (*exp == 0)
	{
		return ;	
	}/*
	ptr = stringify_digit(dg);
	_needle = ft_strstr(buffer, ptr);
	execute_printing(_needle, ptr);*/
	ptr = stringify_power(*exp);
	_needle = ft_strstr(buffer, ptr);
	execute_printing(_needle, ptr);
	(*exp)--; // maybe
}

static void	get_it_uniq(char *buffer, int dg, int *exp, int i)
{
	char	*ptr;
	char	*t_ptr;

	ptr = (char *) malloc (*exp + 2);
	ptr[0] = (dg + '0');
	t_ptr = ptr + 1;
	ptr[*exp + 1] = '\0';
	while (i-- > 0)
		*t_ptr = '0';
	t_ptr = ft_strstr(buffer, ptr);
	execute_printing(t_ptr, ptr);
	get_it_exp(buffer, 1, exp);
}

static void	chulan(char *buffer, int dg, int exp)
{
	while(exp > 1)
	{
		if ((exp - 1) % 3 == 0)
		{
			exp--;
			get_it_uniq(buffer, dg, &exp, exp);
		}
		exp--;
	}
}
