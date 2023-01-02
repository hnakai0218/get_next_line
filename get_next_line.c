/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:59:19 by hnakai            #+#    #+#             */
/*   Updated: 2023/01/02 16:51:48 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	static char	line[BUFFER_SIZE + 1];
	char		*arr;
	size_t		i;
	int			read_size;

	if (line[0] == '\0')
	{
		buff = (char *)malloc(sizeof(BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		read_size = read(fd, buff, BUFFER_SIZE);
		ft_strlcpy(line, buff, read_size + 1);
		free(buff);
	}
	i = ft_count(line);
	arr = ft_substr(line, 0, i);
	if (i != ft_strlen(line) || read_size < BUFFER_SIZE)
	{
		ft_strcpy(line, i + 1);
		return (arr);
	}
	else
	{
		ft_strcpy(line, i + 1);
		get_next_line(fd);
	}
	return (NULL);
}

// int	main(int argc, char *argv[])
// {
// 	int	fd;

// 	fd = open(argv[argc - 1], O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	return (0);
// }
