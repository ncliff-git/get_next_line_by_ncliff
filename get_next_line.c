/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:35:22 by ncliff            #+#    #+#             */
/*   Updated: 2020/11/07 20:50:46 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

char		*ft_strnew(size_t n)
{
	char	*str;

	if (!(str = (char*)malloc(n * sizeof(char) + 1)))
		return (NULL);
	str[n] = 0;
	while (n--)
		str[n] = 0;
	return (str);
}

void		ft_strclr(char *s)
{
	int	i;

	i = 0;
	while (s && *(s + i))
	{
		*(s + i) = '\0';
		i++;
	}
}

char		*chk_buf(char *s_buf, char **line)
{
	char	*n;

	n = NULL;
	if (s_buf)
		if ((n = ft_strchr(s_buf, '\n')))
		{
			*n = 0;
			*line = ft_strdup(s_buf);
			ft_strcpy(s_buf, ++n);
		}
		else
		{
			*line = ft_strdup(s_buf);
			ft_strclr(s_buf);
		}
	else
		*line = ft_strnew(1);
	return (n);
}

int			get_next_line(int fd, char **line)
{
	static char		*s_buf;
	char			*buf;
	int				b_read;
	char			*n;

	if (BUFFER_SIZE < 0
		|| !(buf = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1)))
		return (-1);
	n = chk_buf(s_buf, line);
	while (!n && (b_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (b_read < 0)
			return (-1);
		buf[b_read] = 0;
		if ((n = ft_strchr(buf, '\n')))
		{
			*n = 0;
			s_buf = ft_strdup(++n);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (b_read || ft_strlen(s_buf) || ft_strlen(*line) ? 1 : 0);
}
