/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:13:11 by ppinedo-          #+#    #+#             */
/*   Updated: 2023/10/24 18:29:46 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_reading(int fd, char *statik)
{
	char	*buffer;
	int		charsreaded;
	char	*aux;

	if (!statik)
	{
		statik = malloc(1);
		if(statik == NULL)
			return (NULL);
	}
	buffer = ft_calloc(1, BUFFER_SIZE);
	if (buffer == 0)
	{
		free(statik);
		return (0);
	}
	charsreaded = 1;
	while (!ft_strchr(buffer, '\n') && charsreaded > 0)
	{
		charsreaded = read(fd, buffer, BUFFER_SIZE);
		if ((charsreaded < 0) || (charsreaded == 0 && ft_strlen(statik) == 0))
		{
			free(buffer);
			free(statik);
			return (NULL);
		}
		buffer[charsreaded] = '\0';
		aux = ft_strjoin(statik, buffer);
		free(statik);
		statik = aux;
	}
	free(buffer);
	return (statik);
}

static char	*ft_returnedline(char	*statik)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (statik[i] != '\n' && statik[i] != '\0')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
	{
		free(statik);
		return (NULL);
	}
	j = 0;
	while (j <= i)
	{
		str[j] = statik[j];
		j++;
	}
	str[i + 1] = '\0';
	return (str);
}

static char	*ft_leftovers(char	*statik)
{
	char	*aux;
	int		i;
	int		j;

	aux = malloc(1);
	if (aux == NULL)
		return (NULL);
	i = 0;
	if (statik[0] == '\n')
		i++;
	while (statik[i] != '\n' && statik[i] != '\0' && i != 1)
		i++;
	j = 0;
	while (statik[i] != '\0')
	{
		aux[j] = statik[i + 1];
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
	if (line == NULL)
		return (NULL);
	statik = ft_leftovers(statik);
	if (statik == NULL)
	{
		free(line);
		free(statik);
		return (NULL);
	}
	return (line);
}


int main(void)
{
	int	fd;
	char	*str;
	
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
}
