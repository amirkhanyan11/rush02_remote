/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __algorithms__.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:14:38 by aamirkha          #+#    #+#             */
/*   Updated: 2023/12/02 18:24:36 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int is_alpha(char c)
{
	return (c >= 'a' && c <= 'z');
}

static int	is_empty(char *str)
{
	return (*str == '\0');
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

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	if (is_empty(to_find))
	{
		return (str);
	}
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
				while (!is_alpha(str[i]))
				{
					i++;
				}
				return (str + i);
			}
		}
		i = k + 1;
	}
	return (NULL);
}
