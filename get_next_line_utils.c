/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:02:03 by hnakai            #+#    #+#             */
/*   Updated: 2023/01/05 04:25:36 by hnakai           ###   ########.fr       */
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*udst;
	const unsigned char	*usrc;

	if (dst == src || n == 0)
		return (dst);
	udst = (unsigned char *)dst;
	usrc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		printf("i:%ld\n",i);
		udst[i] = usrc[i];
		i++;
	}
	// printf("%s\n",dst);
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	if (dst == src || len == 0)
		return (dst);
	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (usrc < udst)
	{
		while (len > 0)
		{
			udst[len - 1] = usrc[len - 1];
			len--;
		}
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, len + 1);
	return (s2);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (len_dst >= dstsize)
		return (dstsize + len_src);
	while (i + len_dst + 1 < dstsize && src[i] != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, len_s1 + len_s2 + 1);
	free(s1);
	return (str);
}

