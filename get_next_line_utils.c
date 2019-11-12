/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:00:52 by ereali            #+#    #+#             */
/*   Updated: 2019/10/27 19:35:29 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

static char	*ft_cpy(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(result = (char *)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		j++;
		i++;
	}
	result[i] = '\0';
	return (s1);
}

static char		*ft_strjoin(char *s1, char const *s2)
{
	if ((!(s1)) && (!(s2)))
		return (NULL);
	if (!(s1))
		return ((char *)s2);
	if (!(s2))
		return ((char *)s1);
	s1 = ft_cpy(s1, s2);
	return (s1);
}
