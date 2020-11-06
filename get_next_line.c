/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:35:22 by ncliff            #+#    #+#             */
/*   Updated: 2020/11/04 21:35:24 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	Количество четаемых символов за раз = BUFFER_SIZE

*/
#include <stdio.h>
#include "get_next_line.h"

//static int 	get_read(char *s, int *i)
//{
//	while (s[i] != '\0')
//	{
//		if (s[i] == '\n')
//			retutn (1);
//		i++;
//	}
//	return (0);
//}

int			get_next_line(int fd, char **line)
{
	static char		*buf;
	static char		*bufer;
	static size_t	n;
	size_t			i;

	if (fd < 0)
		return (-1);
	if (buf == NULL)
	{
		n = 0;
		bufer = NULL;
	}
	if (!buf)
		buf = malloc(1 + sizeof(char) * BUFFER_SIZE);
	else
		buf = ft_strjoin(bufer, buf, BUFFER_SIZE);
	if (!buf)
		free(buf);
	while (read(fd, buf, BUFFER_SIZE))
	{
		n = BUFFER_SIZE + n;
		i = 0;
		if(bufer)
			buf = ft_strjoin(buf, bufer, BUFFER_SIZE);
		bufer = ft_strdup(buf);
		while (i < n)
		{
//			printf("%d\n", i);
			if (buf[i] == '\n')
			{
				*line = ft_substr(buf, 0, i);
				n++;
				return (1);
			}
//			printf("%d\n", i);
			if (buf[i] == '\0')
			{
				*line = ft_substr(buf, 0, i);
				line[--i] = 0;
				return (0);
			}
//			printf("%d\n", i);
			i++;
		}
//		printf("%d\n", i);
	}
	return (0);
}
