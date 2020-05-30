/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 11:02:16 by cchieko           #+#    #+#             */
/*   Updated: 2019/06/29 12:55:52 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		fill_line(char **arr_fd, char **line, int fd)
{
	char		*temp;
	int			length;

	length = 0;
	while (arr_fd[fd][length] != '\n' && arr_fd[fd][length] != '\0')
		length++;
	if (arr_fd[fd][length] == '\n')
	{
		*line = ft_strsub(arr_fd[fd], 0, length);
		temp = ft_strdup(arr_fd[fd] + length + 1);
		ft_strdel(&arr_fd[fd]);
		arr_fd[fd] = temp;
		if (arr_fd[fd][0] == '\0')
			ft_strdel(&arr_fd[fd]);
	}
	else if (arr_fd[fd][length] == '\0')
	{
		*line = ft_strdup(arr_fd[fd]);
		ft_strdel(&arr_fd[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*arr_fd[_POSIX_OPEN_MAX];
	char		buf[GNL_BUFF_SIZE + 1];
	char		*temp;
	int			r_bytes;

	if (fd < 0 || fd > _POSIX_OPEN_MAX || !line)
		return (-1);
	while ((r_bytes = read(fd, buf, GNL_BUFF_SIZE)) > 0)
	{
		buf[r_bytes] = '\0';
		if (arr_fd[fd] == NULL)
			arr_fd[fd] = ft_strnew(0);
		temp = ft_strjoin(arr_fd[fd], buf);
		ft_strdel(&arr_fd[fd]);
		arr_fd[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (r_bytes < 0)
		return (-1);
	else if (r_bytes == 0 && (!(arr_fd[fd]) || arr_fd[fd][0] == '\0'))
		return (0);
	return (fill_line(arr_fd, line, fd));
}
