/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:42:00 by motroian          #+#    #+#             */
/*   Updated: 2022/11/30 19:59:39 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_new(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_malloc(char *str)
{
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*str;
	static char		*position;
	char			*tmp;
	char			*ret;
	int				reader;

	reader = 1;
	if (BUFFER_SIZE < 1 || fd > 1024 || fd < 0)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (ft_check(position) == 1 && reader > 0)
	{
		reader = read(fd, str, BUFFER_SIZE);
		if (reader == -1)
			return (free(str), NULL);
		tmp = position;
		str[reader] = '\0';
		position = ft_strjoin(tmp, str);
	}
	ret = ft_substr(position, 0, ft_new(position) + 1);
	tmp = position;
	position = ft_substr(tmp, ft_new(tmp) + 1, (ft_strlen(tmp) - ft_new(tmp)));
	return (free(tmp), free(str), ret);
}

// int main ()
// {
// 	int	fd = open("tx.txt", O_RDONLY);
// 	char *str = NULL;//= get_next_line(fd);

// 	while ((str = get_next_line(fd)))
// 	{
// 		printf("%s" , str);
// 		free(str);
// 	}
// 	free(str);
// }
	// str = get_next_line(fd);
	// printf("%s" , str);
	// str = get_next_line(fd);
	// printf("%s" , str);
	// str = get_next_line(fd);
	// printf("%s" , str);
//}
