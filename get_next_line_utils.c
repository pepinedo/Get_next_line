/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:06:53 by ppinedo-          #+#    #+#             */
/*   Updated: 2023/10/24 17:11:08 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*as;

	a = (char)c;
	i = 0;
	as = (char *)s;
	while (as[i])
	{
		if (as[i] == a)
			return (&as[i]);
		i++;
	}
	if (a == '\0')
		return (&as[i]);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;
	size_t	i;
	size_t	j;

	len = strlen(s1) + strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (len + 1));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[len + 1] = '\0';
	return (s3);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = (void *)malloc(count * size);
	if (str == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
