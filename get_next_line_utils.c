/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:00:52 by ereali            #+#    #+#             */
/*   Updated: 2019/11/30 21:00:53 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_swap(int start, int end, char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (end < 0 || end < start)
		end = ft_strlen(str);
	tmp = str;
	if (!(str = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	while ((start + i) < end)
	{
		str[i] = tmp[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_strlen(char *s1)
{
	int	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
	{
		i++;
	}
	return (i);
}

char	*ft_bzero(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

int		ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;

	i = 0;
	if ((!(s1)) && (!(s2)))
		return (NULL);
	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
			ft_strlen(s2) + 1))))
		return (NULL);
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		if (i >= ft_strlen(s1))
			result[i] = s2[i - ft_strlen(s1)];
		else
			result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	free(s1);
	return (result);
}
