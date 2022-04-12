/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter- <mwinter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:24 by mwinter-          #+#    #+#             */
/*   Updated: 2022/04/12 18:09:21 by mwinter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static int	res;
	static char	buff[1 / 1 + 1];
	char		*str;

	str = NULL;
	if (res == 0)
	{
		res = read(fd, buff, 1);
		buff[res] = '\0';
	}
	if (res > 0 && buff[0] != '\0')
		str = ft_read(fd, buff, str, res);
	else
		return (NULL);
	return (str);
}

char	*ft_read( int fd, char *buff, char *str, int res)
{
	while (res > 0 && ftG_strchr(str, '\n'))
	{
		str = ftG_strjoin(str, buff);
		res = read(fd, buff, 1);
		buff[res] = '\0';
	}
	return (str);
}
