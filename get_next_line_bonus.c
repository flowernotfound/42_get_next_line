/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:52:28 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/03 14:27:29 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_setnull(char **p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

static char	*sep_line(ssize_t bytes_nl, char **save_fd)
{
	char	*tmp;
	char	*result;

	tmp = NULL;
	if (bytes_nl <= 0)
	{
		if (**save_fd == '\0')
		{
			free(*save_fd);
			*save_fd = NULL;
			return (NULL);
		}
		result = *save_fd;
		*save_fd = NULL;
		return (result);
	}
	tmp = ft_substr(*save_fd, bytes_nl, BUFFER_SIZE);
	result = *save_fd;
	result[bytes_nl] = '\0';
	*save_fd = tmp;
	return (result);
}

static char	*read_fd(int fd, char *buffer, char **save_fd)
{
	ssize_t	bytes;
	char	*new_line;
	char	*tmp;

	bytes = 0;
	new_line = ft_strchr(*save_fd, '\n');
	tmp = NULL;
	while (new_line == NULL)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (sep_line(bytes, save_fd));
		buffer[bytes] = '\0';
		tmp = ft_strjoin(*save_fd, buffer);
		if (tmp == NULL)
			return (NULL);
		free_setnull(save_fd);
		*save_fd = tmp;
		new_line = ft_strchr(*save_fd, '\n');
	}
	return (sep_line(new_line - *save_fd + 1, save_fd));
}

char	*get_next_line(int fd)
{
	static char	*save[FD_MAX + 1];
	char		*buffer;
	char		*result;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (save[fd] == NULL)
	{
		save[fd] = ft_strdup("");
		if (save[fd] == NULL)
		{
			free_setnull(&buffer);
			return (NULL);
		}
	}
	result = read_fd(fd, buffer, &save[fd]);
	free_setnull(&buffer);
	return (result);
}
