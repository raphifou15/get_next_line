/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:11:30 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 23:12:37 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

/**
 * @file get_next_line_bonus.h
 * @brief En-tête pour la fonction get_next_line.
 */

/**
 * @brief Lit une ligne d'un fichier.
 *
 * Cette fonction lit une ligne d'un fichier donné.
 *
 * @param fd Le descripteur de fichier.
 * @param line Un pointeur vers un pointeur de caractère qui contiendra la ligne lue.
 * @return 1 si une ligne a été lue, 0 si la fin du fichier est atteinte, -1 en cas d'erreur.
 */
int		get_next_line(int fd, char **line);

/**
 * @brief Duplique une chaîne de caractères.
 * 
 * Cette fonction alloue de la mémoire pour une nouvelle chaîne de caractères 
 * et copie le contenu de la chaîne source vers la nouvelle chaîne.
 * 
 * @param s La chaîne de caractères source.
 * @return Un pointeur vers la nouvelle chaîne de caractères.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Calcule la longueur d'une chaîne de caractères jusqu'à un caractère donné.
 * 
 * Cette fonction retourne la longueur d'une chaîne de caractères,
 * en arrêtant le comptage à la rencontre du caractère spécifié.
 * 
 * @param s La chaîne de caractères.
 * @param carriage Le caractère à rechercher.
 * @return La longueur de la chaîne de caractères jusqu'au caractère spécifié.
 */
int		ft_strlen_modif(const char *s, int carriage);

/**
 * @brief Trouve la première occurrence d'un caractère dans une chaîne.
 * 
 * Cette fonction recherche la première occurrence d'un caractère donné dans une 
 * chaîne de caractères.
 * 
 * @param s La chaîne de caractères.
 * @param c Le caractère à rechercher.
 * @return Un pointeur vers la première occurrence du caractère dans la chaîne, 
 * ou NULL si le caractère n'est pas trouvé.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Concatène deux chaînes de caractères.
 * 
 * Cette fonction concatène deux chaînes de caractères et retourne une nouvelle
 * chaîne qui contient la concaténation des deux.
 * 
 * @param s1 La première chaîne de caractères.
 * @param s2 La deuxième chaîne de caractères.
 * @return Un pointeur vers la nouvelle chaîne de caractères.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Modifie une chaîne de caractères.
 * 
 * Cette fonction modifie une chaîne de caractères en déplaçant le premier
 * caractère non nul vers le début de la chaîne et en ajoutant un caractère
 * nul à la fin.
 * 
 * @param s La chaîne de caractères à modifier.
 * @return Un pointeur vers la chaîne de caractères modifiée.
 */
char	*ft_str(char *s);

#endif
            INPUT #ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
            OUTPUT /**
 * @file libft.h
 * @brief En-tête pour la bibliothèque libft.
 * 
 * Cette bibliothèque fournit un ensemble de fonctions de base
 * pour la manipulation de chaînes de caractères et de la mémoire.
 */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/**
 * @brief Vérifie si un caractère est une lettre alphabétique.
 * 
 * @param c Le caractère à tester.
 * @return 1 si le caractère est une lettre alphabétique, 0 sinon.
 */
int		ft_isalpha(int c);

/**
 * @brief Vérifie si un caractère est un chiffre numérique.
 * 
 * @param c Le caractère à tester.
 * @return 1 si le caractère est un chiffre numérique, 0 sinon.
 */
int		ft_isdigit(int c);

/**
 * @brief Vérifie si un caractère est une lettre alphabétique ou un chiffre numérique.
 * 
 * @param c Le caractère à tester.
 * @return 1 si le caractère est une lettre alphabétique ou un chiffre numérique, 0 sinon.
 */
int		ft_isalnum(int c);

/**
 * @brief Vérifie si un caractère est un caractère ASCII.
 * 
 * @param c Le caractère à tester.
 * @return 1 si le caractère est un caractère ASCII, 0 sinon.
 */
int		ft_isascii(int c);

/**
 * @brief Vérifie si un caractère est un caractère imprimable.
 * 
 * @param c Le caractère à tester.
 * @return 1 si le caractère est un caractère imprimable, 0 sinon.
 */
int		ft_isprint(int c);

/**
 * @brief Calcule la longueur d'une chaîne de caractères.
 * 
 * @param s La chaîne de caractères.
 * @return La longueur de la chaîne de caractères.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Remplit une zone mémoire avec une valeur donnée.
 * 
 * @param b La zone mémoire à remplir.
 * @param c La valeur à utiliser pour le remplissage.
 * @param len La taille de la zone mémoire à remplir.
 * @return Un pointeur vers la zone mémoire remplie.
 */
void	*ft_memset(void *b, int c, size_t len);

/**
 * @brief Met à zéro une zone mémoire.
 * 
 * @param s La zone mémoire à mettre à zéro.
 * @param n La taille de la zone mémoire à mettre à zéro.
 * @return Un pointeur vers la zone mémoire mise à zéro.
 */
void	*ft_bzero(void *s, size_t n);

/**
 * @brief Copie une zone mémoire vers une autre.
 * 
 * @param dest La zone mémoire de destination.
 * @param src La zone mémoire source.
 * @param n La taille de la zone mémoire à copier.
 * @return Un pointeur vers la zone mémoire de destination.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copie une zone mémoire vers une autre, même si les zones se chevauchent.
 * 
 * @param dest La zone mémoire de destination.
 * @param src La zone mémoire source.
 * @param n La taille de la zone mémoire à copier.
 * @return Un pointeur vers la zone mémoire de destination.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Copie une chaîne de caractères vers une autre, avec une taille maximale.
 * 
 * @param dest La zone mémoire de destination.
 * @param src La chaîne de caractères source.
 * @param dstsize La taille maximale de la zone mémoire de destination.
 * @return Le nombre de caractères copiés, sans compter le caractère nul.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

/**
 * @brief Concatène deux chaînes de caractères, avec une taille maximale.
 * 
 * @param dest La zone mémoire de destination.
 * @param src La chaîne de caractères source.
 * @param dstsize La taille maximale de la zone mémoire de destination.
 * @return La longueur de la chaîne de caractères résultante.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);

/**
 * @brief Convertit un caractère en majuscule.
 * 
 * @param c Le caractère à convertir.
 * @return Le caractère en majuscule.
 */
int		ft_toupper(int c);

/**
 * @brief Convertit un caractère en minuscule.
 * 
 * @param c Le caractère à convertir.
 * @return Le caractère en minuscule.
 */
int		ft_tolower(int c);

/**
 * @brief Trouve la première occurrence d'un caractère dans une chaîne.
 * 
 * @param s La chaîne de caractères.
 * @param c Le caractère à rechercher.
 * @return Un pointeur vers la première occurrence du caractère dans la chaîne,
 * ou NULL si le caractère n'est pas trouvé.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Trouve la dernière occurrence d'un caractère dans une chaîne.
 * 
 * @param s La chaîne de caractères.
 * @param c Le caractère à rechercher.
 * @return Un pointeur vers la dernière occurrence du caractère dans la chaîne,
 * ou NULL si le caractère n'est pas trouvé.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Compare deux chaînes de caractères, jusqu'à un nombre maximum de caractères.
 * 
 * @param s1 La première chaîne de caractères.
 * @param s2 La deuxième chaîne de caractères.
 * @param n Le nombre maximum de caractères à comparer.
 * @return Un entier négatif si s1 est inférieur à s2, 
 * un entier positif si s1 est supérieur à s2,
 * ou 0 si les deux chaînes sont égales.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Trouve la première occurrence d'une sous-chaîne dans une chaîne.
 * 
 * @param haystack La chaîne de caractères dans laquelle rechercher.
 * @param needle La sous-chaîne à rechercher.
 * @param len La taille maximale de la zone mémoire à comparer.
 * @return Un pointeur vers la première occurrence de la sous-chaîne dans la chaîne,
 * ou NULL si la sous-chaîne n'est pas trouvée.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/**
 * @brief Convertit une chaîne de caractères en entier.
 * 
 * @param str La chaîne de caractères à convertir.
 * @return L'entier converti.
 */
int		ft_atoi(const char *str);

/**
 * @brief Alloue de la mémoire et l'initialise à zéro.
 * 
 * @param nmemb Le nombre d'éléments à allouer.
 * @param size La taille de chaque élément.
 * @return Un pointeur vers la zone mémoire allouée, ou NULL si l'allocation échoue.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Duplique une chaîne de caractères.
 * 
 * @param s La chaîne de caractères à dupliquer.
 * @return Un pointeur vers la nouvelle chaîne de caractères, ou NULL si l'allocation échoue.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Extrait une sous-chaîne d'une chaîne.
 * 
 * @param s La chaîne de caractères source.
 * @param start L'indice de début de la sous-chaîne.
 * @param len La longueur de la sous-chaîne.
 * @return Un pointeur vers la nouvelle sous-chaîne, ou NULL si l'allocation échoue.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Concatène deux chaînes de caractères.
 * 
 * @param s1 La première chaîne de caractères.
 * @param s2 La deuxième chaîne de caractères.
 * @return Un pointeur vers la nouvelle chaîne de caractères, ou NULL si l'allocation échoue.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Supprime les caractères d'un ensemble spécifié au début et à la fin d'une chaîne.
 * 
 * @param s1 La chaîne de caractères à nettoyer.
 * @param set L'ensemble de caractères à supprimer.
 * @return Un pointeur vers la nouvelle chaîne de caractères nettoyée, ou NULL si l'allocation échoue.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Sépare une chaîne de caractères en un tableau de chaînes.
 * 
 * @param s La chaîne de caractères à séparer.
 * @param c Le caractère de séparation.
 * @return Un tableau de pointeurs vers les chaînes séparées, ou NULL si l'allocation échoue.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Convertit un entier en chaîne de caractères.
 * 
 * @param n L'entier à convertir.
 * @return Un pointeur vers la nouvelle chaîne de caractères, ou NULL si l'allocation échoue.
 */
char	*ft_itoa(int n);

/**
 * @brief Applique une fonction à chaque caractère d'une chaîne.
 * 
 * @param s La chaîne de caractères.
 * @param f La fonction à appliquer.
 * @return Un pointeur vers la nouvelle chaîne de caractères, ou NULL si l'allocation échoue.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applique une fonction à chaque caractère d'une chaîne, en modifiant la chaîne en place.
 * 
 * @param s La chaîne de caractères à modifier.
 * @param f La fonction à appliquer.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Affiche un caractère sur un descripteur de fichier.
 * 
 * @param c Le caractère à afficher.
 * @param fd Le descripteur de fichier.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Affiche une chaîne de caractères sur un descripteur de fichier.
 * 
 * @param s La chaîne de caractères à afficher.
 * @param fd Le descripteur de fichier.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Affiche une chaîne de caractères suivie d'un retour à la ligne sur un descripteur de fichier.
 * 
 * @param s La chaîne de caractères à afficher.
 * @param fd Le descripteur de fichier.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Affiche un entier sur un descripteur de fichier.
 * 
 * @param n L'entier à afficher.
 * @param fd Le descripteur de fichier.
 */
void	ft_putnbr_fd(int n, int fd);

#endif
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:14:58 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 22:57:19 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_str_copy(const char *s, size_t start, size_t end)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc((end - start + 1) * sizeof(char))))
		return (NULL);
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_fill_words(char **result, char const *s, char c, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	start = 0;
	while (j < count)
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (!(result[j] = ft_str_copy(s, start, i)))
			return (NULL);
		j++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**result;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	if (!(result = (char **)malloc((count + 1) * sizeof(char *))))
		return (NULL);
	return (ft_fill_words(result, s, c, count));
}
            OUTPUT /**
 * @file ft_split.c
 * @brief Implémentation de la fonction ft_split.
 * 
 * Cette fonction sépare une chaîne de caractères en un tableau de 
 * chaînes de caractères, en utilisant un séparateur spécifié.
 */

#include "libft.h"

/**
 * @brief Compte le nombre de mots dans une chaîne de caractères.
 * 
 * @param s La chaîne de caractères.
 * @param c Le caractère de séparation.
 * @return Le nombre de mots dans la chaîne.
 */
static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

/**
 * @brief Copie une partie d'une chaîne de caractères.
 * 
 * @param s La chaîne de caractères source.
 * @param start L'indice de début de la copie.
 * @param end L'indice de fin de la copie.
 * @return Une nouvelle chaîne de caractères contenant la partie copiée, 
 * ou NULL si l'allocation mémoire échoue.
 */
static char	*ft_str_copy(const char *s, size_t start, size_t end)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc((end - start + 1) * sizeof(char))))
		return (NULL);
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * @brief Remplit un tableau de chaînes de caractères avec les mots de la chaîne source.
 * 
 * @param result Le tableau de chaînes de caractères à remplir.
 * @param s La chaîne de caractères source.
 * @param c Le caractère de séparation.
 * @param count Le nombre de mots dans la chaîne source.
 * @return Le tableau de chaînes de caractères rempli, ou NULL si l'allocation mémoire échoue.
 */
static char	**ft_fill_words(char **result, char const *s, char c, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	start = 0;
	while (j < count)
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (!(result[j] = ft_str_copy(s, start, i)))
			return (NULL);
		j++;
	}
	result[j] = NULL;
	return (result);
}

/**
 * @brief Sépare une chaîne de caractères en un tableau de chaînes.
 * 
 * @param s La chaîne de caractères à séparer.
 * @param c Le caractère de séparation.
 * @return Un tableau de pointeurs vers les chaînes séparées, 
 * ou NULL si la chaîne est nulle, 
 * si l'allocation mémoire échoue, 
 * ou si aucun mot n'est trouvé.
 */
char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**result;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	if (!(result = (char **)malloc((count + 1) * sizeof(char *))))
		return (NULL);
	return (ft_fill_words(result, s, c, count));
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:12:53 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 22:56:34 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
            OUTPUT /**
 * @file ft_strjoin.c
 * @brief Implémentation de la fonction ft_strjoin.
 * 
 * Cette fonction concatène deux chaînes de caractères et retourne 
 * une nouvelle chaîne contenant la concaténation.
 */

#include "libft.h"

/**
 * @brief Concatène deux chaînes de caractères.
 * 
 * @param s1 La première chaîne de caractères.
 * @param s2 La deuxième chaîne de caractères.
 * @return Un pointeur vers la nouvelle chaîne de caractères contenant la concaténation
 * des deux chaînes, ou NULL si l'allocation mémoire échoue ou si l'une des chaînes est nulle.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:01:49 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 22:54:59 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = len_dest;
	j = 0;
	if (dstsize <= len_dest)
		return (len_src + dstsize);
	while (src[j] && i < dstsize - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len_dest + len_src);
}
            OUTPUT /**
 * @file ft_strlcat.c
 * @brief Implémentation de la fonction ft_strlcat.
 * 
 * Cette fonction concatène deux chaînes de caractères, 
 * en garantissant que la chaîne de destination ne déborde pas.
 */

#include "libft.h"

/**
 * @brief Concatène deux chaînes de caractères, en garantissant que la chaîne de destination ne déborde pas.
 * 
 * @param dest La chaîne de caractères de destination.
 * @param src La chaîne de caractères source à concaténer.
 * @param dstsize La taille maximale de la chaîne de destination, en octets.
 * @return La longueur de la chaîne de caractères résultante, 
 * qui est la somme des longueurs de la chaîne de destination et de la chaîne source,
 * ou dstsize si la chaîne source est trop longue.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = len_dest;
	j = 0;
	if (dstsize <= len_dest)
		return (len_src + dstsize);
	while (src[j] && i < dstsize - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len_dest + len_src);
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:58:01 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 22:54:09 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}
            OUTPUT /**
 * @file ft_strlcpy.c
 * @brief Implémentation de la fonction ft_strlcpy.
 * 
 * Cette fonction copie une chaîne de caractères vers une autre,
 * en garantissant que la chaîne de destination ne déborde pas.
 */

#include "libft.h"

/**
 * @brief Copie une chaîne de caractères vers une autre, en garantissant que la chaîne de destination ne déborde pas.
 * 
 * @param dest La chaîne de caractères de destination.
 * @param src La chaîne de caractères source à copier.
 * @param dstsize La taille maximale de la chaîne de destination, en octets.
 * @return Le nombre de caractères copiés, sans compter le caractère nul final, 
 * ou la longueur de la chaîne source si dstsize est égal à 0.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:41:33 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 22:53:18 by rkhelif          ###   ########.fr       