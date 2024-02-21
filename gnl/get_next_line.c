/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:48:58 by diahmed           #+#    #+#             */
/*   Updated: 2024/02/08 13:48:13 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join(char *line, char *buf)
{
	char	*tmp;

	tmp = line;
	line = ft_strjoin(tmp, buf);
	free(tmp);
	tmp = NULL;
	return (line);
}

static char	*cp_line(char *str)
{
	char	*line;
	int		i;
	int		len;

	if (!str)
		return (NULL);
	len = line_len(str);
	i = 0;
	line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (line);
		}
		line[i] = str[i];
		i++;
	}
	return (line);
}

static void	read_line(char **line, int fd)
{
	int		cnt;
	char	*buf;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return ;
	while (!ft_strchr(*line, '\n'))
	{
		cnt = read(fd, buf, BUFFER_SIZE);
		if (cnt <= 0)
		{
			if (cnt < 0)
			{
				free(*line);
				*line = NULL;
			}
			break ;
		}
		buf[cnt] = '\0';
		*line = ft_join(*line, buf);
	}
	free(buf);
	buf = NULL;
}

static char	*next_l(char *buffer)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	ptr = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	while (buffer[i])
		ptr[j++] = buffer[i++];
	ptr[j] = '\0';
	free(buffer);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= __INT_MAX__)
		return (NULL);
	read_line(&buffer, fd);
	if (!buffer)
		return (NULL);
	line = cp_line(buffer);
	buffer = next_l(buffer);
	return (line);
}
