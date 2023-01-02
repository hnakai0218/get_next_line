/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:02:03 by hnakai            #+#    #+#             */
/*   Updated: 2023/01/02 16:49:25 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (src == NULL)
		return (0);
	while (count + 1 < dstsize && src[count] != '\0')
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		a = malloc(sizeof(char) * 1);
		if (!a)
			return (NULL);
		a[0] = '\0';
		return (a);
	}
	if (len > len_s - start)
		len = len_s - start;
	a = malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	ft_strlcpy(a, s + start, len + 1);
	return (a);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	ft_count(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *s, size_t start)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[start + i] != '\0')
	{
		s[i] = s[start + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
