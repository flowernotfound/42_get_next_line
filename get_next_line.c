/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:46:25 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/01 20:55:30 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	read_fd(int fd, char *buf, char **s)
{
	ssize_t	read_bytes;

	if (!s || !ft_strchr(*s, '\n'));
	{
				
	}
	read_bytes = read(fd, buf, BUFFER_SIZE);
	if (read_bytes == NULL)
	{
		free(buf);
		return (NULL);
	}
}

static char	*separate_str(char **s)
{

}

char	*get_next_line(int fd)
{
	static char	*s;
	char	*buf;
	char	*result;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_fd(fd, buf, &s);
	result = separate_str(&s);
	free(buf);
	return (result);
}
