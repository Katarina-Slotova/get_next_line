/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslotova <kslotova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:48:09 by kslotova          #+#    #+#             */
/*   Updated: 2022/01/04 19:31:37 by kslotova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_leftover(char *str)
{
	char	*saved_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	saved_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!saved_str)
		return (0);
	i += (str[i] == '\n');
	while (str[i])
	{
		saved_str[j] = str[i];
		i++;
		j++;
	}
	saved_str[j] = '\0';
	free(str);
	return (saved_str);
}

static char	*ft_completed_line(char *str)
{
	char	*str_newline;
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	str_newline = (char *)malloc(sizeof(char) * (i + 1));
	if (!str_newline)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		str_newline[i] = str[i];
		i++;
	}
	str_newline[i] = '\0';
	return (str_newline);
}

static char	*ft_read_file(char **saved_strs, int fd, int *res)
{
	char	*buff;
	int		read_res;
	char	*tmp;

	read_res = 1;
	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		return (NULL);
	while (read_res > 0 && !ft_strchr(saved_strs[fd], '\n'))
	{
		read_res = read(fd, buff, BUFF_SIZE);
		*res = read_res;
		if (read_res == -1)
			return (NULL);
		buff[read_res] = '\0';
		tmp = ft_strjoin(saved_strs[fd], buff);
		free(saved_strs[fd]);
		saved_strs[fd] = tmp;
	}
	free(buff);
	return (saved_strs[fd]);
}

int	get_next_line(const int fd, char **line)
{
	static char	*saved_strs[FD_MAX + 1];
	int			res;

	if (fd < 0 || fd > FD_MAX || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!saved_strs[fd])
	{
		saved_strs[fd] = (char *)malloc(sizeof(char));
		if (!saved_strs[fd])
			return (-1);
		saved_strs[fd][0] = '\0';
	}
	saved_strs[fd] = ft_read_file(saved_strs, fd, &res);
	if (saved_strs[fd] == NULL)
		return (-1);
	if (res == 0 && saved_strs[fd][0] == '\0')
	{
		ft_strdel(&saved_strs[fd]);
		return (0);
	}
	*line = ft_completed_line(saved_strs[fd]);
	saved_strs[fd] = ft_leftover(saved_strs[fd]);
	if (res < 0)
		return (-1);
	return (1);
}
