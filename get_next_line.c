/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:59:19 by hnakai            #+#    #+#             */
/*   Updated: 2023/01/03 14:22:39 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	if(fd > 256)
		return (NULL);
	static char	line[BUFFER_SIZE + 1] = {'\0'};
	char		*buff;
	size_t		read_size;
	char		*arr;
	static char *save;

	if (line[0] == '\0')
	{
		buff = (char *)malloc(sizeof(BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		read_size = read(fd, buff, BUFFER_SIZE);
		ft_strlcpy(line, buff, read_size + 1);
		free(buff);
	}
	arr = ft_substr(line, 0, ft_count(line));
	save = ft_strjoin(save,arr);
	free(arr);
	if (ft_count(line) != ft_strlen(line))
		ft_memmove(line, line + ft_count(line) + 1, read_size - ft_count(line));
	else if(read_size == BUFFER_SIZE && ft_count(line) == ft_strlen(line))
	{
		ft_memset(line, '\0', 1);
		get_next_line(fd);
	}
	return (save);
}

// int	main(int argc, char *argv[])
// {
// 	int	fd;

// 	fd = open(argv[argc - 1], O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	return (0);
// }
