/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:13:11 by ppinedo-          #+#    #+#             */
/*   Updated: 2023/10/19 15:43:14 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <libc.h>
#include <unistd.h>

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
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (0);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
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

static char	*ft_reading(int fd, char *statik)
{
	char	*buffer;
	int		charsreaded;
	
	buffer = ft_calloc(1, BUFFER_SIZE);
	if(!statik)
		statik = ft_calloc(1,1);
	while (!ft_strchr(buffer, '\n'))
	{
		charsreaded = read(fd, buffer, BUFFER_SIZE);
		if(charsreaded == -1)
		{
			free(buffer);
			free(statik);
			return (0);
		}
		buffer[charsreaded] = '\0';
		statik = ft_strjoin(statik, buffer);
	}
	free(buffer);
	return (statik);
}

static char	*ft_returnedline(char	*statik)
{
	char	*str;
	int		i;
	int		j;

	if (statik == 0)
		return (0);
	i = 0;
	while (statik[i] != '\n' || statik[i] != '\0')
		i++;
	str = (char*)malloc(sizeof(char) * (i + 1));
	if(str == 0)
		return (0);
	j = 0;
	while (j <= i)
	{
		str[i] = statik[i];
		i++;
	}
	str[i] = '\0';
	free(statik);
	return (str);
}

static char	*ft_leftovers(char	*statik)
{
	char	*aux;
	int		i;
	int		j;

	aux = ft_calloc(1, 1);
	while(statik[i] != '\n')
		i++;
	j = 0;
	while(statik[i] != '\0')
	{
		aux[j] = statik[i];
		i++;
		j++;
	}
	aux[j] = '\0';
	free(statik);
	return (aux);	
}

char	*get_next_line(int fd)
{
	static char	*statik;
	char		*line;
	
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	statik = ft_reading(fd, statik);
	if(statik == 0)
		return (0);
	line = ft_returnedline(statik);
	statik = ft_leftovers(statik);
	return (line);
}

int main(void)
{
	int	fd;
	
	fd = open("archivo.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("\n%s", get_next_line(fd));
	close(fd);
}
