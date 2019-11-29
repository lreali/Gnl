/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:23:20 by ereali            #+#    #+#             */
/*   Updated: 2019/11/29 17:24:03 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
	int fd = open ("test.txt", O_RDONLY);
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
