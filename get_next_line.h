/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhelif <rkhelif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 09:05:23 by rkhelif           #+#    #+#             */
/*   Updated: 2020/06/08 19:13:46 by rkhelif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
 * @file get_next_line.h
 * @brief En-tête pour la fonction get_next_line.
 */

/**
 * @brief Lit une ligne d'un fichier descripteur.
 * 
 * Cette fonction lit une ligne du fichier spécifié par le descripteur de fichier 
 * fd et la stocke dans la chaîne de caractères pointée par *line.
 * 
 * @param[in] fd Le descripteur de fichier du fichier à lire.
 * @param[out] line Un pointeur vers une chaîne de caractères qui contiendra la ligne lue.
 * @return 1 si une ligne a été lue, 0 si la fin du fichier a été atteinte, -1 si une erreur s'est produite.
 */
int		get_next_line(int fd, char **line);

/**
 * @brief Duplique une chaîne de caractères.
 * 
 * Cette fonction crée une copie de la chaîne de caractères pointée par s.
 * 
 * @param[in] s La chaîne de caractères à dupliquer.
 * @return Un pointeur vers la nouvelle chaîne de caractères dupliquée, ou NULL en cas d'erreur.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Calcule la longueur d'une chaîne de caractères avec un caractère de fin de ligne.
 * 
 * Cette fonction calcule la longueur de la chaîne de caractères pointée par s, en incluant le caractère de fin de ligne s'il est spécifié.
 * 
 * @param[in] s La chaîne de caractères.
 * @param[in] carriage Indique s'il faut inclure le caractère de fin de ligne dans le calcul de la longueur (1 si oui, 0 sinon).
 * @return La longueur de la chaîne de caractères, y compris le caractère de fin de ligne si spécifié.
 */
int		ft_strlen_modif(const char *s, int carriage);

/**
 * @brief Trouve la première occurrence d'un caractère dans une chaîne de caractères.
 * 
 * Cette fonction recherche la première occurrence du caractère c dans la chaîne de caractères pointée par s.
 * 
 * @param[in] s La chaîne de caractères à rechercher.
 * @param[in] c Le caractère à rechercher.
 * @return Un pointeur vers la première occurrence du caractère c dans s, ou NULL si le caractère n'est pas trouvé.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Concatène deux chaînes de caractères.
 * 
 * Cette fonction concatène les chaînes de caractères pointées par s1 et s2.
 * 
 * @param[in] s1 La première chaîne de caractères.
 * @param[in] s2 La deuxième chaîne de caractères.
 * @return Un pointeur vers la nouvelle chaîne de caractères concaténée, ou NULL en cas d'erreur.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Supprime le caractère de fin de ligne d'une chaîne de caractères.
 * 
 * Cette fonction supprime le caractère de fin de ligne de la chaîne de caractères pointée par s.
 * 
 * @param[in,out] s La chaîne de caractères.
 * @return Un pointeur vers la chaîne de caractères sans le caractère de fin de ligne.
 */
char	*ft_str(char *s);

#endif
            INPUT #ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

struct s_bin;

typedef struct		s_node
{
	int				value;
	sem_t			*lock_std;
	sem_t			lock;
	sem_t			eat;
	int				end;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	long long		start;
	int				count_eat;
	int				nb_eat;
	pthread_t		thread;
	pthread_t		monitor;
	struct s_node	*next;
	char			str[50];
	struct s_bin	*var;
}					t_node;

typedef struct		s_bin
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				nb;
	int				end;
	t_node			*philo;
	int				count_eat;
	sem_t			lock_std;
	sem_t			sem_die;
	int				nb_philo_eat;
	sem_t			philo_eat;
}					t_bin;

void				ft_sleep(int n);
size_t				ft_strlen(const char *str);
void				ft_putstr_fd(char *s, int fd);
void				ft_putlnbr_fd(long long n, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_isdigit(int i);
int					ft_atoi(const char *str);
int					ft_arg(t_bin *var, int ac, char **av);
int					ft_create(t_bin *var);
int					ft_clear(t_bin *var, int i, int l);
void				*fn_philo(void *p_data);
void				*fn_monitor_eat(void *p_data);
void				*fn_monitor(void *p_data);
long long			current_timestamp(void);
void				print_value(sem_t *sem_die, int *val);
void				ft_putlnbr_str(long long a, t_node *n);
void				ft_putnbr_str(int a, t_node *n);
void				ft_message(t_node *n, char *str, long long tm,\
unsigned int j);
int					ft_check_arg(int ac, char **av);
int					ft_strisdigit(char *str);
void				ft_message_die(t_node *n, char *str, long long tm,\
unsigned int j);
int					ft_go_thread(t_bin *var);

#endif OUTPUT /**
 * @file philo_three.h
 * @brief Contient les déclarations pour le projet Philosophes (philo_three).
 */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

/**
 * @struct s_bin
 * @brief Structure contenant les variables globales du programme.
 */
struct s_bin;

/**
 * @struct s_node
 * @brief Structure représentant un philosophe.
 */
typedef struct		s_node
{
	int				value; /**< Valeur du philosophe. */
	sem_t			*lock_std; /**< Semaphore pour l'affichage standard. */
	sem_t			lock; /**< Semaphore pour le philosophe. */
	sem_t			eat; /**< Semaphore pour l'action de manger. */
	int				end; /**< Indicateur de fin du programme. */
	int				tt_die; /**< Temps de mourir. */
	int				tt_eat; /**< Temps pour manger. */
	int				tt_sleep; /**< Temps pour dormir. */
	long long		start; /**< Temps de départ. */
	int				count_eat; /**< Nombre de fois que le philosophe a mangé. */
	int				nb_eat; /**< Nombre de fois que le philosophe doit manger. */
	pthread_t		thread; /**< Thread du philosophe. */
	pthread_t		monitor; /**< Thread de surveillance du philosophe. */
	struct s_node	*next; /**< Pointeur vers le philosophe suivant. */
	char			str[50]; /**< Chaîne de caractères pour l'affichage. */
	struct s_bin	*var; /**< Pointeur vers les variables globales. */
}					t_node;

/**
 * @struct s_bin
 * @brief Structure contenant les variables globales du programme.
 */
typedef struct		s_bin
{
	int				time_to_die; /**< Temps de mourir. */
	int				time_to_eat; /**< Temps pour manger. */
	int				time_to_sleep; /**< Temps pour dormir. */
	int				nb_eat; /**< Nombre de fois que chaque philosophe doit manger. */
	int				nb; /**< Nombre de philosophes. */
	int				end; /**< Indicateur de fin du programme. */
	t_node			*philo; /**< Pointeur vers le premier philosophe. */
	int				count_eat; /**< Nombre total de fois que les philosophes ont mangé. */
	sem_t			lock_std; /**< Semaphore pour l'affichage standard. */
	sem_t			sem_die; /**< Semaphore pour la surveillance de la mort. */
	int				nb_philo_eat; /**< Nombre de philosophes qui ont mangé. */
	sem_t			philo_eat; /**< Semaphore pour la surveillance du nombre de repas. */
}					t_bin;

/**
 * @brief Met en pause le programme pendant un temps donné.
 * 
 * @param n Le temps de pause en millisecondes.
 */
void				ft_sleep(int n);

/**
 * @brief Calcule la longueur d'une chaîne de caractères.
 * 
 * @param str La chaîne de caractères.
 * @return La longueur de la chaîne de caractères.
 */
size_t				ft_strlen(const char *str);

/**
 * @brief Affiche une chaîne de caractères sur la sortie standard.
 * 
 * @param s La chaîne de caractères à afficher.
 * @param fd Le descripteur de fichier de la sortie standard (généralement 1).
 */
void				ft_putstr_fd(char *s, int fd);

/**
 * @brief Affiche un nombre long long sur la sortie standard, suivi d'un retour à la ligne.
 * 
 * @param n Le nombre à afficher.
 * @param fd Le descripteur de fichier de la sortie standard (généralement 1).
 */
void				ft_putlnbr_fd(long long n, int fd);

/**
 * @brief Affiche un nombre entier sur la sortie standard.
 * 
 * @param n Le nombre à afficher.
 * @param fd Le descripteur de fichier de la sortie standard (généralement 1).
 */
void				ft_putnbr_fd(int n, int fd);

/**
 * @brief Vérifie si un caractère est un chiffre.
 * 
 * @param i Le caractère à vérifier.
 * @return 1 si le caractère est un chiffre, 0 sinon.
 */
int					ft_isdigit(int i);

/**
 * @brief Convertit une chaîne de caractères en entier.
 * 
 * @param str La chaîne de caractères à convertir.
 * @return L'entier converti, ou 0 si la conversion échoue.
 */
int					ft_atoi(const char *str);

/**
 * @brief Analyse les arguments du programme et initialise les variables globales.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @param ac Nombre d'arguments.
 * @param av Tableau d'arguments.
 * @return 0 si l'analyse se déroule correctement, -1 sinon.
 */
int					ft_arg(t_bin *var, int ac, char **av);

/**
 * @brief Crée les threads des philosophes.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @return 0 si la création des threads se déroule correctement, -1 sinon.
 */
int					ft_create(t_bin *var);

/**
 * @brief Nettoie les ressources allouées pour les philosophes.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @param i Indice du premier philosophe.
 * @param l Indice du dernier philosophe.
 * @return 0.
 */
int					ft_clear(t_bin *var, int i, int l);

/**
 * @brief Fonction exécutée par chaque thread de philosophe.
 * 
 * @param p_data Pointeur vers les données du philosophe.
 * @return NULL.
 */
void				*fn_philo(void *p_data);

/**
 * @brief Fonction de surveillance de l'état de santé d'un philosophe.
 * 
 * @param p_data Pointeur vers les données du philosophe.
 * @return NULL.
 */
void				*fn_monitor_eat(void *p_data);

/**
 * @brief Fonction de surveillance de l'état de santé des philosophes.
 * 
 * @param p_data Pointeur vers les données du programme.
 * @return NULL.
 */
void				*fn_monitor(void *p_data);

/**
 * @brief Retourne le timestamp actuel en millisecondes.
 * 
 * @return Le timestamp actuel.
 */
long long			current_timestamp(void);

/**
 * @brief Affiche la valeur d'un semaphore.
 * 
 * @param sem_die Pointeur vers le semaphore.
 * @param val Pointeur vers la variable qui contiendra la valeur du semaphore.
 */
void				print_value(sem_t *sem_die, int *val);

/**
 * @brief Affiche un message formaté avec le timestamp et l'identifiant du philosophe.
 * 
 * @param a Le timestamp.
 * @param n Pointeur vers le philosophe.
 */
void				ft_putlnbr_str(long long a, t_node *n);

/**
 * @brief Affiche un message formaté avec l'identifiant du philosophe.
 * 
 * @param a L'identifiant du philosophe.
 * @param n Pointeur vers le philosophe.
 */
void				ft_putnbr_str(int a, t_node *n);

/**
 * @brief Affiche un message formaté pour un philosophe.
 * 
 * @param n Pointeur vers le philosophe.
 * @param str Le message à afficher.
 * @param tm Le timestamp.
 * @param j L'identifiant du philosophe.
 */
void				ft_message(t_node *n, char *str, long long tm,\
unsigned int j);

/**
 * @brief Vérifie les arguments du programme.
 * 
 * @param ac Nombre d'arguments.
 * @param av Tableau d'arguments.
 * @return 0 si les arguments sont valides, -1 sinon.
 */
int					ft_check_arg(int ac, char **av);

/**
 * @brief Vérifie si une chaîne de caractères ne contient que des chiffres.
 * 
 * @param str La chaîne de caractères à vérifier.
 * @return 1 si la chaîne ne contient que des chiffres, 0 sinon.
 */
int					ft_strisdigit(char *str);

/**
 * @brief Affiche un message d'erreur formaté pour un philosophe et termine le programme.
 * 
 * @param n Pointeur vers le philosophe.
 * @param str Le message d'erreur à afficher.
 * @param tm Le timestamp.
 * @param j L'identifiant du philosophe.
 */
void				ft_message_die(t_node *n, char *str, long long tm,\
unsigned int j);

/**
 * @brief Lance les threads des philosophes et de surveillance.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @return 0 si le lancement des threads se déroule correctement, -1 sinon.
 */
int					ft_go_thread(t_bin *var);

#endif
            INPUT #include "philo_three.h"

int			ft_clear(t_bin *var, int i, int l)
{
	int j;

	j = 1;
	while (j < i + 1)
	{
		sem_destroy(&(var->philo[i].lock));
		if (l == 0 && j == i)
			break ;
		sem_destroy(&(var->philo[i].eat));
		j++;
	}
	sem_destroy(&(var->lock_std));
	sem_destroy(&(var->sem_die));
	sem_destroy(&(var->philo_eat));
	free(var->philo);
	return (1);
}

static int	ft_create_philo(t_bin *var, int i)
{
	while (i < var->nb + 1)
	{
		if (i == var->nb)
			var->philo[i].next = &(var->philo[1]);
		else
			var->philo[i].next = &(var->philo[i + 1]);
		var->philo[i].value = i;
		var->philo[i].tt_die = var->time_to_die;
		var->philo[i].tt_eat = var->time_to_eat;
		var->philo[i].tt_sleep = var->time_to_sleep;
		var->philo[i].count_eat = 0;
		var->philo[i].end = 0;
		var->philo[i].nb_eat = var->nb_eat;
		var->philo[i].str[0] = '\0';
		var->philo[i].var = var;
		var->philo[i].lock_std = &(var->lock_std);
		if (sem_init(&(var->philo[i].lock), 0, 1) == -1)
			return ((!(ft_clear(var, i, 0))));
		if (sem_init(&(var->philo[i].eat), 0, 1) == -1)
			return ((!(ft_clear(var, i, 1))));
		i++;
	}
	return (0);
}

int			ft_create(t_bin *var)
{
	if (sem_init(&(var->lock_std), 0, 1) == -1)
		return (1);
	if (sem_init(&(var->sem_die), 0, 1) == -1)
		return (1);
	if (sem_init(&(var->philo_eat), 0, 0) == -1)
		return (1);
	if (!(var->philo = malloc((var->nb + 1) * sizeof(t_node))))
	{
		sem_destroy(&(var->lock_std));
		sem_destroy(&(var->sem_die));
		sem_destroy(&(var->philo_eat));
		return (1);
	}
	if (ft_create_philo(var, 1))
		return (1);
	return (0);
} OUTPUT /**
 * @file struct.c
 * @brief Gestion des structures et des mutex pour les philosophes.
 * 
 * Ce fichier contient les fonctions nécessaires pour créer, initialiser
 * et nettoyer les structures utilisées dans le programme, notamment
 * les philosophes et leurs mutex.
 */

#include "philo_three.h"

/**
 * @brief Libère la mémoire et détruit les sémaphores.
 * 
 * Cette fonction détruit les sémaphores associés à chaque philosophe et
 * libère la mémoire allouée à la structure `philo`. Elle détruit également
 * les sémaphores globaux `lock_std`, `sem_die` et `philo_eat`.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @param i Indice du premier philosophe.
 * @param l Indice du dernier philosophe (0 si c'est le dernier, sinon 1).
 * @return Toujours retourne 1 (indique que l'opération a été effectuée).
 */
int ft_clear(t_bin *var, int i, int l)
{
    int j;

    j = 1;
    while (j < i + 1)
    {
        sem_destroy(&(var->philo[i].lock)); /**< Destruction du sémaphore de verrouillage. */
        if (l == 0 && j == i)
            break;
        sem_destroy(&(var->philo[i].eat)); /**< Destruction du sémaphore de temps de repas. */
        j++;
    }
    sem_destroy(&(var->lock_std)); /**< Destruction du sémaphore global. */
    sem_destroy(&(var->sem_die)); /**< Destruction du sémaphore de surveillance de la mort. */
    sem_destroy(&(var->philo_eat)); /**< Destruction du sémaphore de surveillance du nombre de repas. */
    free(var->philo); /**< Libération de la mémoire allouée aux philosophes. */
    return (1);
}

/**
 * @brief Crée et initialise les structures des philosophes.
 * 
 * Cette fonction configure les structures de chaque philosophe, lie les sémaphores,
 * et initialise leurs valeurs par défaut. Chaque philosophe est relié
 * à un suivant pour former une liste circulaire.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @param i Indice du premier philosophe.
 * @return Retourne 0 si la création est réussie, sinon une valeur différente de 0.
 */
static int ft_create_philo(t_bin *var, int i)
{
    while (i < var->nb + 1)
    {
        if (i == var->nb)
            var->philo[i].next = &(var->philo[1]); /**< Liaison au premier philosophe (liste circulaire). */
        else
            var->philo[i].next = &(var->philo[i + 1]); /**< Liaison au philosophe suivant. */

        var->philo[i].value = i; /**< Affectation de l'identifiant du philosophe. */
        var->philo[i].tt_die = var->time_to_die; /**< Temps avant de mourir sans manger. */
        var->philo[i].tt_eat = var->time_to_eat; /**< Temps nécessaire pour manger. */
        var->philo[i].tt_sleep = var->time_to_sleep; /**< Temps nécessaire pour dormir. */
        var->philo[i].count_eat = 0; /**< Compteur initialisé à 0. */
        var->philo[i].end = 0; /**< Indicateur de fin initialisé à 0. */
        var->philo[i].nb_eat = var->nb_eat; /**< Nombre de repas nécessaires. */
        var->philo[i].str[0] = '\0'; /**< Chaîne initialisée à vide. */
        var->philo[i].var = var; /**< Pointeur vers la structure globale. */
        var->philo[i].lock_std = &(var->lock_std); /**< Pointeur vers le sémaphore global. */

        if (sem_init(&(var->philo[i].lock), 0, 1) == -1) /**< Initialisation du sémaphore de verrouillage. */
            return ((!(ft_clear(var, i, 0))));
        if (sem_init(&(var->philo[i].eat), 0, 1) == -1) /**< Initialisation du sémaphore de repas. */
            return ((!(ft_clear(var, i, 1))));
        i++;
    }
    return (0);
}

/**
 * @brief Crée et initialise les structures principales du programme.
 * 
 * Cette fonction alloue la mémoire nécessaire pour les philosophes et
 * initialise les sémaphores globaux ainsi que les structures individuelles.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @return Retourne 0 si la création est réussie, sinon 1.
 */
int ft_create(t_bin *var)
{
    if (sem_init(&(var->lock_std), 0, 1) == -1) /**< Initialisation du sémaphore global. */
        return (1);
    if (sem_init(&(var->sem_die), 0, 1) == -1) /**< Initialisation du sémaphore de surveillance de la mort. */
        return (1);
    if (sem_init(&(var->philo_eat), 0, 0) == -1) /**< Initialisation du sémaphore de surveillance du nombre de repas. */
        return (1);
    if (!(var->philo = malloc((var->nb + 1) * sizeof(t_node)))) /**< Allocation mémoire pour les philosophes. */
    {
        sem_destroy(&(var->lock_std)); /**< Destruction du sémaphore global en cas d'échec. */
        sem_destroy(&(var->sem_die)); /**< Destruction du sémaphore de surveillance de la mort. */
        sem_destroy(&(var->philo_eat)); /**< Destruction du sémaphore de surveillance du nombre de repas. */
        return (1);
    }
    if (ft_create_philo(var, 1)) /**< Appel de la fonction pour initialiser les philosophes. */
        return (1);
    return (0);
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:32:37 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/07 17:36:41 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
		return (1);
	return (0);
} OUTPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:32:37 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/07 17:36:41 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

/**
 * @file ft_isdigit.c
 * @brief Implémentation de la fonction ft_isdigit.
 */

/**
 * @brief Vérifie si un caractère est un chiffre.
 * 
 * @param i Le caractère à vérifier.
 * @return 1 si le caractère est un chiffre, 0 sinon.
 */
int			ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
		return (1);
	return (0);
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:34:16 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/07 17:37:40 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
} OUTPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:34:16 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/07 17:37:40 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

/**
 * @file ft_putnbr_fd.c
 * @brief Implémentation de la fonction ft_putnbr_fd.
 */

/**
 * @brief Affiche un nombre entier sur un descripteur de fichier.
 * 
 * @param n Le nombre à afficher.
 * @param fd Le descripteur de fichier.
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:34:16 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/07 17:38:21 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_putlnbr_fd(long long n, int fd)
{
	if (n == -9223372036854775808)
	{
		ft_putstr_fd("-9223372036854775808", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putlnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putlnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
	ft_putchar_fd('\n', fd);
} OUTPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:34:16 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/07 17:38:21 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

/**
 * @file ft_putln