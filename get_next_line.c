/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:46:25 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/01 06:16:37 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
}
