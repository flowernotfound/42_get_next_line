/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:46:25 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/01 17:44:37 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	read_fd(int fd, char *buf, char **s)
{

}

static char	*sepalate_str(char **s)
{

}

char	*get_next_line(int fd)
{
	static char	*s;
	ssize_t	read_bytes;
	char	*buf;
	char	*result;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_bytes = read(fd, buf, BUFFER_SIZE);
	if (read_bytes == -1)
	{
		free(buf);
		return (NULL);
	}
	read_fd(fd, buf, &s);
	result = sepalate_str(&s)
	return (result);
}
