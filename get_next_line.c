/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:06:15 by ereali            #+#    #+#             */
/*   Updated: 2019/11/12 17:49:22 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 32

/*
1) faire un get_next_line qui met simplement line a NULL
2) faire la meme choses uniquement si le FD est bon sinon return -1
3) Faire le return : Si le read a lu qqch, renvoyer 1, sinon 0
4) Ajouter dans un buffer le contenu lu de read et print le buffer 
5) repeter le 4 jusqu'a trouver un \n
6) faire une fonction char *ft_strcut(char **src, char delim)
7) faire un printf de la ligne decoupee et du buffer pour verifier
8) mettre la ligne decoupee dans line
9) Rajouter dans le return le test suivant : si buffer pas vide -> return 1
*/


char    *ft_strchr(const char *s, int c)
{
	size_t  i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return (i);
	return (NULL);
}


int get_next_line(int fd, char **line)
{
	char *str;
	int i;
	int j;
	int k;
	int n;

	n = 0;
	i = 0;
	j = 0;
	if (!fd)
		return (-1);
	while ((i = read(fd, str, BUFFER_SIZE)) > 0 && ft_strchr((const char)str, '\n') == NULL)
	{
		j++;
	}
	if (j > 0 && (k = strchr(str , '\n')) >= 0)
	{
		if (!(line = (char *)malloc((sizeof(char) * k) + 1))
			return (-1);
		while (k > n)
		{
			line[n] = str[n];
			n++;
		}
		line[k] = '\0';
	}	
	if (strchr(line, '\0') == -1)
		return (-1)
	if (i == -1)
		return (-1);
	return (1);
	
}

int main()
{
	int fd = open ("test.txt", O_RDONLY);
	char *line = NULL;

	int i = 0;

	while (get_next_line(fd, &line) > 0)
	{
		printf("Line [%d] = {%s}\n", i, line);	
		i++;
	}
	
	return (0);
}
