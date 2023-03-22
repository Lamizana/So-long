/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:39:04 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/17 14:15:41 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_buffer(int fd, char *buffer);
char	*get_line(char *buffer);
char	*save_buffer(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = save_buffer(buffer);
	return (line);
}

char	*read_buffer(int fd, char *buffer)
{
	char	*tmp;
	int		nb_octet;

	buffer = check_buff(buffer);
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	nb_octet = 1;
	while (nb_octet > 0)
	{
		nb_octet = read(fd, tmp, BUFFER_SIZE);
		if (nb_octet == -1)
		{
			free(tmp);
			free(buffer);
			return (NULL);
		}
		tmp[nb_octet] = '\0';
		buffer = ft_strjoin_and_free(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\0';
	return (line);
}

char	*save_buffer(char *buffer)
{
	char	*save_buff;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[len] != '\0' && buffer[len] != '\n')
		len++;
	if (!buffer[len])
	{
		free(buffer);
		return (NULL);
	}
	save_buff = malloc(sizeof(char) * (ft_strlen(buffer) - len + 1));
	if (!save_buff)
		return (NULL);
	len++;
	i = 0;
	while (buffer[len] != '\0')
		save_buff[i++] = buffer[len++];
	save_buff[i] = '\0';
	free(buffer);
	return (save_buff);
}
