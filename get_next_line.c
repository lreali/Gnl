/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:06:15 by ereali            #+#    #+#             */
/*   Updated: 2019/11/29 16:03:34 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *s1)
{
	int i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
	{
		i++;
	}
	return (i);
}


char	*ft_swap(int k, char *str)
{
	char	*tmp;
	int		i;

	tmp = str;
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(str) - k + 1))))
		return (NULL);
	while (tmp[k + i])
	{
		str[i] = tmp[k + i];
		i++;
	}
	str[i] = '\0';
	free(tmp);
	return (str);
}

int		ft_strchr(const char *s, int c)
{
	size_t  i;

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
	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
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

/*	if (!str)
	{
		if (!(str = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1)))
			return (-1);
	}
	else if ((k = ft_strchr(str, '\n')) >= 0)
	{
		if (!(*line = (char *)malloc((sizeof(char) * k) + 1)))
			return (-1);
		while (n < k)
		{
			(*line)[n] = str[n];
			n++;
		}
		(*line)[n] = '\0';
		n = 0;
		str = ft_swap(k + 1, str);
		return (1);
	}
	if (!(str1 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);*/

int	ft_check_str(char **str, char **line)
{
	int	n;
	int	k;

	n = 0;
	k = 0;
	if (!str)
	{
		if (!((*str) = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1)))
			return (-1);
	}
	else if ((k = ft_strchr(*str, '\n')) >= 0)
	{
		if (!(*line = (char *)malloc((sizeof(char) * k) + 1)))
			return (-1);
		while (n < k)
		{
			(*line)[n] = (*str)[n];
			n++;
		}
		(*line)[n] = '\0';
		n = 0;
		(*str) = ft_swap(k + 1, *str);
		return (1);
	}
	return (0);
}

char *ft_use_read(char *str, char *str1, int fd,int *i)
{
	ft_bzero(str1, BUFFER_SIZE + 1);
	while (((*i) = (int)(read(fd, str1, BUFFER_SIZE))) > 0) 
	{
		str = ft_strjoin(str , str1);
		if (ft_strchr(str1, '\n') >= 0)
			break;
		ft_bzero(str1, BUFFER_SIZE + 1);
	}
	free(str1);
	return (str);
}

int get_next_line(int fd, char **line)
{
	static char *str;
	char *str1;
	int i;
	int k;
	int n;

	i = 0;
	if ((n = ft_check_str(&str, line)) != 0)
		return (n);
	if (!(str1 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	n = 0;
	str = ft_use_read(str, str1, fd, &i);
	if (i == -1)
		return (-1);
	if ((k = ft_strchr(str, '\n')) >= 0)
	{
		if (!((*line) = (char *)malloc((sizeof(char) * k) + 1)))
			return (-1);
		while (n < k)
		{
			(*line)[n] = str[n];
			n++;
		}
		(*line)[n] = '\0'; 
		str = ft_swap(k + 1, str);
	}
	else if ((k = ft_strchr(str, '\0')) >= 0 && i == 0)
	{
		n = 0;
		if (!(*line = (char *)malloc((sizeof(char) * k) + 1)))
			return (-1);
		while (n < k)
		{
			(*line)[n] = str[n];
			n++;
		}
		(*line)[n] = '\0';
		if (k == 0)
			(*line) = NULL;
		free(str);
		str = NULL;
		return (0);
	}
	return (1);
}

int main()
{
	int fd = open ("newfile", O_RDONLY);
	char *line = NULL;
	int i = 0;
	int j = 0;

	while ((j = get_next_line(fd, &line)) > 0)
	{
		printf("%d - Line [%d] = {%s}\n", j, i, line);
		free(line);
		i++;
	}
	printf("%d - Line [%d] = {%s}\n",j , i, line);
	free(line);
	i = 0;
	while (1)
		i = 1;
	return (0);
}
