/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:13:11 by ppinedo-          #+#    #+#             */
/*   Updated: 2023/10/30 11:16:57 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_reading(int fd, char *statik)
{
	char	*buffer;
	int		charsreaded;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free(statik), NULL);
	charsreaded = 1;
	while (!ft_strchr(statik, '\n') && charsreaded != 0)
	{
		charsreaded = read(fd, buffer, BUFFER_SIZE);
		if (charsreaded == -1)
		{
			free(buffer);
			free(statik);
			return (NULL);
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

	if (statik[0] == '\0')
		return (NULL);
	i = 0;
	while (statik[i] != '\n' && statik[i] != '\0')
		i++;
	str = malloc(sizeof(char) * ((i + 1) + (statik[i] == '\n')));
	if (str == NULL)
		return (free(statik), NULL);
	i = 0;
	while (statik[i] != '\n' && statik[i] != '\0')
	{
		str[i] = statik[i];
		i++;
	}
	if (statik[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*ft_leftovers(char	*statik)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	while (statik[i] != '\n' && statik[i] != '\0')
		i++;
	if (statik[i++] == '\0')
		return (free(statik), NULL);
	aux = malloc(ft_strlen(statik + i) + 1);
	if (aux == NULL)
		return (NULL);
	j = 0;
	while (statik[i] != '\0')
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	statik = ft_reading(fd, statik);
	if (statik == NULL)
		return (NULL);
	line = ft_returnedline(statik);
	statik = ft_leftovers(statik);
	return (line);
}

/*
int main(void)
{
	int	fd;
	char	*str;
	
	fd = open("archivo.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	str = get_next_line(fd);
	printf("%s\n", str);
	str = get_next_line(fd);
	printf("%s\n", str);
	str = get_next_line(fd);
	printf("%s\n", str);
	str = get_next_line(fd);
	printf("%s\n", str);
	str = get_next_line(fd);
	printf("%s\n", str);
	str = get_next_line(fd);
	printf("%s\n", str);
	close(fd);
	return (0);
}
*/
/*
int main(void)
{
	fd = open("archivo.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		printf("%s", str);
	}
	close(fd);
	return (0);
}
*/
