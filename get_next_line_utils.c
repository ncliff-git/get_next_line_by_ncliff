/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:35:48 by ncliff            #+#    #+#             */
/*   Updated: 2020/11/04 21:35:49 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t n;

	n = 0;
	while (*s != '\0')
	{
		s++;
		n++;
	}
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjn;
	int		i;
	int		n;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	strjn = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (strjn == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		strjn[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n] != '\0')
	{
		strjn[i] = s2[n];
		i++;
		n++;
	}
	strjn[i] = '\0';
	return (strjn);
}

char	*ft_strdup(const char *s1)
{
	char	*s1dup;
	int		i;

	s1dup = malloc((ft_strlen(s1) + 1) * sizeof(char));
	i = 0;
	if (s1dup == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s1dup[i] = s1[i];
		i++;
	}
	s1dup[i] = '\0';
	return (s1dup);
}

char	*ft_strcpy(char *dest, char *src)
{
	int sum;

	sum = 0;
	while (*(src + sum) != '\0')
	{
		*(dest + sum) = *(src + sum);
		sum++;
	}
	*(dest + sum) = '\0';
	return (dest);
}
