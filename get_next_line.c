/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:59:19 by hnakai            #+#    #+#             */
/*   Updated: 2023/01/02 09:48:18 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	char		*arr;
	static char	*line;
	size_t		i;

	line = (char *)malloc(sizeof(BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	line[0] = '\0';
	printf("%s",line);
	if (line[0] == '\0')
	{
		buff = (char *)malloc(sizeof(BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		read(fd, (void *)buff, BUFFER_SIZE);
		printf("%s",buff);
		ft_strlcpy(line, buff, BUFFER_SIZE + 1);
		free(buff);
	}
	i = ft_count(line);
	printf("%s",line);
	if (i != ft_strlen(line))
	{
		arr = ft_substr(line, 0, i);
		ft_strlcpy(line, line, ft_strlen(line) - i + 1);
		return (arr);
	}
	else
	{
		line[0] = '\0';
		get_next_line(fd);
	}
	return (NULL);
}

// int	main(int argc, char *argv[])
// {
// 	int fd;
// 	fd = open(argv[argc - 1], O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	return (0);
// }
