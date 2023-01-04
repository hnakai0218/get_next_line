/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:59:19 by hnakai            #+#    #+#             */
/*   Updated: 2023/01/05 04:59:00 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readbuff(int fd)
{
	char	*buff;
	int		read_size;

	buff = (char *)malloc(sizeof(BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_size = read(fd, buff, BUFFER_SIZE);
	if(read_size < 0)
	{
		free(buff);
		return (NULL);
	}
	if (read_size == 0)
	{
		free(buff);
		return (NULL);
	}
	buff[read_size] = '\0';
	return (buff);
}

size_t	ft_count(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	save[BUFFER_SIZE + 1] = {'\0'};
	char		*line;
	char		*arr;

	if (save[0] == '\0')//no word in string save
		buff = ft_readbuff(fd);
	else
		buff = ft_strdup(save);
	if (!buff)
		return (NULL);
	line = NULL;
	while (ft_count(buff) == ft_strlen(buff)) // exist no newline in string buff //abcd e\nf
	{
		line = ft_strjoin(line, buff);
		free(buff);
		buff = ft_readbuff(fd);
		if(!buff)
		{
			save[0] = '\0';
			return (line);
		}
	}
	arr = ft_substr(buff, 0, ft_count(buff) + 1);
	line = ft_strjoin(line, arr);
	free(arr);
	ft_memmove(save, buff + ft_count(buff) + 1, ft_strlen(buff) - ft_count(buff));
	free(buff);
	return (line);
}

// int	main(int ac, char **av)
// {
// 	size_t	i;
// 	int		fd;
// 	char	*s;

// 	if (ac != 2)
// 		return (printf("ERROR: arg number is invalid.\n"));
// 	fd = open((const char *)av[1], O_RDONLY);
// 	if (fd < 0)
// 		return (printf("ERRPR: fine not found.\n"));
// 	i = 0;
// 	s = "a";
// 	while (s != NULL)
// 	{
// 		s = get_next_line(fd);
// 		printf("line%zu : %s\n", i, s);
// 		i++;
// 	}
// 	return (0);
// }
