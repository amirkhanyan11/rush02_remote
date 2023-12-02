/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __helper_functions__.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:23:35 by aamirkha          #+#    #+#             */
/*   Updated: 2023/12/03 00:21:15 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
int ft_pow(int dg, int exp)
{
	if(exp == 0)
	{
		return 1;
	}
	return (dg * ft_pow(dg, exp - 1));
}
*/
static int	is_alpha(char c)
{
	return (c >= 'a' && c <= 'z');
}

static int	my_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str)
	{
		length++;
		str++;
	}
	return (length);
}

char	*ft_strstr_partition(char *str, int *i)
{
	while (!is_alpha(str[*i]))
	{
		(*i)++;
	}
	return (str + *i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (str[i])
	{
		j = 0;
		k = i;
		while (str[i] == to_find[j])
		{
			i++;
			j++;
			if (j == my_strlen(to_find))
			{
				i -= j;
				return (ft_strstr_partition(str, &i));
			}
		}
		i = k + 1;
	}
	return (NULL);
}
