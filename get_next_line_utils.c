/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 08:53:55 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 21:32:42 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char			*str;
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	str = malloc((sizeof(char) * i) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_strlen_modif(const char *s, int carriage)
{
	int i;

	i = 0;
	if (carriage == 0)
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (char*)(s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		size_chains;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen_modif(s1, 0);
	size_chains = i;
	i = ft_strlen_modif(s2, 0);
	size_chains = size_chains + i;
	i = -1;
	if ((str = malloc(sizeof(char) * size_chains + 1)) == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	size_chains = -1;
	while (s2[++size_chains] != '\0')
	{
		str[i] = s2[size_chains];
		i++;
	}
	str[i] = '\0';
	free((char*)s1);
	s1 = NULL;
	return (str);
}

char	*ft_str(char *s)
{
	char	*str;

	str = malloc(sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	free(s);
	s = NULL;
	return (str);
}
