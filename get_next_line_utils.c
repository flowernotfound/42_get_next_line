/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmitsuyo <yourLogin@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:47:34 by hmitsuyo          #+#    #+#             */
/*   Updated: 2023/10/03 13:14:25 by hmitsuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	char	*str;

	if (s == NULL)
		return (NULL);
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

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	ssize_t	i;
	ssize_t	length;
	char	*result;

	length = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * length + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char *s, unsigned int start, ssize_t length)
{
	char	*result;
	ssize_t	s_length;
	ssize_t	i;

	if (s == NULL)
		return (NULL);
	s_length = ft_strlen(s);
	if (start >= s_length || length == 0)
		return (ft_strdup(""));
	if (length >= s_length - start)
		length = s_length - start;
	result = (char *)malloc(sizeof(char) * length + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < length && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *s, char *buf)
{
	ssize_t	size;
	char	*result;
	size_t	i;
	size_t	j;

	if (s == NULL || buf == NULL)
		return (NULL);
	size = ft_strlen(s) + ft_strlen(buf);
	result = (char *)malloc(sizeof(char) * (size + 1));
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
