/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 10:04:35 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 23:25:11 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_until_carriage_return(char *s)
{
	char			*str;
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	str = malloc((sizeof(char) * i) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr_modif(char const *s, unsigned int start,
						size_t len, unsigned int i)
{
	char			*str;

	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	if (start + 1 > i)
		return (ft_str((char*)s));
	if (start + len > i)
		len = (len - (len - i) + 1);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (len > 0 && s[start] != '\0')
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	free((char*)s);
	s = NULL;
	return (str);
}

char	*ft_reste(char *reste, char **line)
{
	int len;

	len = ft_strlen_modif(reste, 1);
	*line = ft_strdup_until_carriage_return(reste);
	reste = ft_substr_modif(reste, len + 1, ft_strlen_modif(reste, 0), 0);
	return (reste);
}

char	*ft_free(char *s)
{
	free(s);
	s = NULL;
	return (s);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char *reste;
	int			res;

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	if ((buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (-1);
	res = 1;
	while ((ft_strchr(reste, '\n') == NULL) && (res != 0))
	{
		if ((res = read(fd, buf, BUFFER_SIZE)) < 0)
			ft_free(buf);
		if (res < 0)
			return (-1);
		buf[res] = '\0';
		if (res > 1)
			res = 1;
		reste = (reste == NULL) ? ft_strdup(buf) : ft_strjoin(reste, buf);
	}
	reste = ft_reste(reste, line);
	reste = (res == 0) ? ft_free(reste) : reste;
	ft_free(buf);
	return (res);
}
