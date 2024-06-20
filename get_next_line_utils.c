/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:06:04 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/06/20 21:48:58 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gstrdup(char	*s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_gstrlen(s1);
	i = 0;
	ptr = (char *) malloc(sizeof(*ptr) * (len + 1));
	if (!ptr)
		return (NULL);
	if (ptr)
	{
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}

char	*ft_gstr_init(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(char));
	str[0] = 0;
	return (str);
}

char	*ft_gstrjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	length1;
	size_t	length2;

	i = 0;
	if (!s1)
		s1 = ft_gstr_init();
	length1 = ft_gstrlen(s1);
	length2 = ft_gstrlen(s2);
	result = (char *)malloc((length1 + length2 + 1) * sizeof(char));
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		result[length1 + i] = s2[i];
		i++;
	}
	result[length1 + length2] = '\0';
	free(s1);
	return (result);
}

size_t	ft_gstrlen( char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_gstrchr(const char *s, char c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
