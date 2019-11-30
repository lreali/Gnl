/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:06:15 by ereali            #+#    #+#             */
/*   Updated: 2019/11/30 20:57:12 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_str(char **str, char **line)
{
	char	*tmp;
	int		n;
	int		k;

	n = 0;
	k = 0;
	if (!str)
	{
		if (!((*str) = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1)))
			return (-1);
	}
	else if ((k = ft_strchr(*str, '\n')) >= 0)
	{
		(*line) = ft_swap(0, k, *str);
		tmp = (*str);
		(*str) = ft_swap(k + 1, -1, *str);
		free(tmp);
		return (1);
	}
	return (0);
}

char	*ft_use_read(char *str, char *str1, int fd, int *i)
{
	ft_bzero(str1, BUFFER_SIZE + 1);
	while (((*i) = (int)(read(fd, str1, BUFFER_SIZE))) > 0)
	{
		str = ft_strjoin(str, str1);
		if (ft_strchr(str1, '\n') >= 0)
			break ;
		ft_bzero(str1, BUFFER_SIZE + 1);
	}
	free(str1);
	return (str);
}

int		ft_line(char **line, char **str, int i)
{
	int		k;
	char	*str1;

	if ((k = ft_strchr((*str), '\n')) >= 0)
	{
		(*line) = ft_swap(0, k, (*str));
		str1 = (*str);
		(*str) = ft_swap(k + 1, -1, (*str));
		free(str1);
	}
	else if ((k = ft_strchr((*str), '\0')) >= 0 && i == 0)
	{
		(*line) = ft_swap(0, k, (*str));
		free(*str);
		(*str) = NULL;
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		*str1;
	int			i;
	int			n;

	i = 0;
	if ((n = ft_check_str(&str, line)) != 0)
		return (n);
	if (!(str1 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	n = 0;
	str = ft_use_read(str, str1, fd, &i);
	if (i == -1)
		return (-1);
	return (ft_line(line, &str, i));
}
