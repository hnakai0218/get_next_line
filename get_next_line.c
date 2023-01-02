/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:59:19 by hnakai            #+#    #+#             */
/*   Updated: 2023/01/02 11:01:07 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*line;
	char		*arr;
	size_t		i;
	int			read_size;

	line = (char *)malloc(sizeof(BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	line[0] = '\0';
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
		ft_strlcpy(line, line, ft_strlen(line) - i + 1);
		return (arr);
	}
	else
	{
		line[0] = '\0';
		get_next_line(fd);
		return (arr);
	}
	return (NULL);
}

// int	main(int argc, char *argv[])
// {
// 	int	fd;

// 	fd = open(argv[argc - 1], O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	return (0);
// }
