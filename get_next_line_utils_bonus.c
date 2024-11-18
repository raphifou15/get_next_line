/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:13:14 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 23:15:26 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @file get_next_line_utils_bonus.c
 * @brief Fonctions utilitaires pour la fonction get_next_line_bonus.
 */

/**
 * @brief Duplique une chaîne de caractères.
 * 
 * Cette fonction alloue de la mémoire pour une nouvelle chaîne et copie 
 * le contenu de la chaîne source dans la nouvelle chaîne.
 * 
 * @param s La chaîne de caractères à dupliquer.
 * @return Un pointeur vers la nouvelle chaîne dupliquée, ou NULL si l'allocation 
 * échoue.
 */
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

/**
 * @brief Calcule la longueur d'une chaîne de caractères, avec un caractère de fin optionnel.
 * 
 * Cette fonction retourne la longueur d'une chaîne jusqu'à un caractère 
 * de fin spécifié, ou jusqu'à la fin de la chaîne si aucun caractère 
 * de fin n'est spécifié.
 * 
 * @param s La chaîne de caractères.
 * @param carriage Le caractère de fin, 0 si aucun caractère de fin.
 * @return La longueur de la chaîne jusqu'au caractère de fin.
 */
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

/**
 * @brief Trouve la première occurrence d'un caractère dans une chaîne.
 * 
 * Cette fonction recherche le premier caractère donné dans une chaîne 
 * de caractères. 
 * 
 * @param s La chaîne de caractères.
 * @param c Le caractère à trouver.
 * @return Un pointeur vers la première occurrence du caractère, ou NULL si le 
 * caractère n'est pas trouvé.
 */
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

/**
 * @brief Concatène deux chaînes de caractères.
 * 
 * Cette fonction concatène deux chaînes de caractères et alloue 
 * de la mémoire pour la nouvelle chaîne.
 * 
 * @param s1 La première chaîne de caractères.
 * @param s2 La deuxième chaîne de caractères.
 * @return Un pointeur vers la nouvelle chaîne concaténée, ou NULL si 
 * l'allocation échoue.
 */
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

/**
 * @brief Crée une nouvelle chaîne de caractères vide.
 * 
 * Cette fonction alloue de la mémoire pour une nouvelle chaîne de 
 * caractères vide.
 * 
 * @param s Un pointeur vers la chaîne de caractères à libérer.
 * @return Un pointeur vers la nouvelle chaîne vide, ou NULL si l'allocation 
 * échoue.
 */
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
            

