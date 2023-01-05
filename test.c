#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	char	*buff;

// 	buff = (char *)malloc(sizeof(BUFFER_SIZE + 1));
// 	if (!buff)
// 		return (NULL);
// 	read(fd, buff, BUFFER_SIZE);
// 	if (buff == NULL)
// 		return (NULL);
// 	buff = NULL;
// 	return (buff);
// }

// char	*ft_readbuff(int fd)
// {
// 	char	*buff;

// 	// size_t	read_size;
// 	buff = (char *)malloc(sizeof(BUFFER_SIZE + 1));
// 	if (!buff)
// 		return (NULL);
// 	read(fd, buff, BUFFER_SIZE);
// 	if (buff[0] == '\0')
// 		return (NULL);
// 	return (buff);
// }

// size_t	ft_count(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == '\n')
// 			return (i);
// 		i++;
// 	}
// 	return (i);
// }

// char	*get_next_line(int fd)
// {
// 	int i;
// 	char		*buff;
// 	char		*line;

// 	i = 0;
// 	line = NULL;
// 	buff = ft_readbuff(fd);
// 	printf("%c\n",buff[4]);
// 	while (i < 5) // exist no newline in string buff
// 	{
// 		if(i == 0)
// 			ft_strlen(buff);
// 		line = ft_strjoin(line, buff);
// 		free(buff);
// 		buff = ft_readbuff(fd);
// 		if(!buff)
// 			return (line);
// 		i++;
// 	}
// 	return ("42");
// }
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
// 	while (i < 4)
// 	{
// 		s = get_next_line(fd);
// 		printf("line%zu : %s\n", i, s);
// 		i++;
// 	}
// 	return (0);
// }

int main(void)
{
	char buff[5] = {'\0'};
	free(buff);
	return (0);
}