/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:47:34 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/02 09:46:14 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}

ssize_t	ft_strlen(char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, ssize_t start, ssize_t length)
{
	char	*result;
	ssize_t	s_length;
	ssize_t	i;

	if (s == NULL)
		return (NULL);
	s_length = ft_strlen(s);
	if (length >= s_length - start)
		length = s_length - start;
	result = (char *)malloc(sizeof(char) * length + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *s, char *buf)
{
	ssize_t	s_length;
	ssize_t	buf_length;
	char	*result;
	size_t	i;
	size_t	j;

	s_length = ft_strlen(s);
	buf_length = ft_strlen(buf);
	result = (char *)malloc(sizeof(char) * (s_length + buf_length) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	j = 0;
	while (buf[j] != '\0')
	{
		result[i + j] = buf[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}
