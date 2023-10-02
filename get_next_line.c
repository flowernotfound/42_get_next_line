/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:46:25 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/02 10:18:29 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_join(int fd, char *buf, char **s)
{
	ssize_t	read_bytes;
	char	*tmp;

	read_bytes = read(fd, buf, BUFFER_SIZE);
	if (read_bytes == -1)
		return (-1);
	if (read_bytes == 0)
		return (0);
	buf[read_bytes] = '\0';
	if (*s == NULL)
	{
		*s = ft_substr(buf, 0, read_bytes);
		if (*s == NULL)
			return (-1);
	}
	else
	{
		tmp = *s;
		*s = ft_strjoin(*s, buf);
		if (*s == NULL)
			return (-1);
		free(tmp);
	}
	return (1);
}

static int	read_fd(int fd, char *buf, char **s)
{
	int	read_check;

	if (*s == NULL || !ft_strchr(*s, '\n'))
	{
		while (1)
		{
			read_check = read_join(fd, buf, s);
			if (read_check <= 0 || ft_strchr(*s, '\n'))
				return (read_check);
		}
	}
	return (1);
}

static char	*separate_str(char **s)
{
	char	*result;
	char	*tmp;
	ssize_t	s_length;
	ssize_t	sep_length;

	if (*s == NULL)
		return (NULL);
	if (ft_strchr(*s, '\n') == NULL)
	{
		result = ft_substr(*s, 0, ft_strlen(*s));
		free(*s);
		*s = NULL;
		return (result);
	}
	s_length = ft_strlen(*s);
	sep_length = ft_strlen(ft_strchr(*s, '\n'));
	result = ft_substr(*s, 0, s_length - sep_length + 1);
	tmp = *s;
	*s = ft_substr(ft_strchr(*s, '\n'), 1, sep_length - 1);
	free(tmp);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*buf;
	char		*result;
	int			read_check;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_check = read_fd(fd, buf, &s);
	if (read_check == -1 || read_check == 0)
	{
		free(buf);
		return (NULL);
	}
	result = separate_str(&s);
	free(buf);
	return (result);
}
