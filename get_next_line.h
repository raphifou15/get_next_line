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
 * @brief Fonction de lecture ligne par ligne.
 */
int		get_next_line(int fd, char **line);

/**
 * @brief Duplique une chaîne de caractères.
 * @param s Chaîne à dupliquer.
 * @return Nouvelle chaîne dupliquée.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Calcule la longueur d'une chaîne de caractères.
 * @param s Chaîne à mesurer.
 * @param carriage Indique s'il faut prendre en compte les sauts de ligne.
 * @return Longueur de la chaîne.
 */
int		ft_strlen_modif(const char *s, int carriage);

/**
 * @brief Recherche le premier caractère spécifié dans une chaîne.
 * @param s Chaîne de caractères.
 * @param c Caractère à rechercher.
 * @return Pointeur vers le premier caractère trouvé, NULL sinon.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Concatène deux chaînes de caractères.
 * @param s1 Première chaîne.
 * @param s2 Deuxième chaîne.
 * @return Nouvelle chaîne concaténée.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Alloue une nouvelle chaîne de caractères.
 * @param s Chaîne à allouer.
 * @return Nouvelle chaîne allouée.
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
	pthread_mutex_t	*lock_std;
	pthread_mutex_t	lock;
	pthread_mutex_t	eat;
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
	sem_t			*sem_fork;
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
	pthread_mutex_t	lock_std;
	sem_t			*sem_die;
	sem_t			*sem_fork;
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
void				ft_print_status(t_node *n, char *str, long long time);
int					ft_wait_for_die(t_bin *var);
void				ft_sem_die(sem_t *sem_die, t_bin *var, t_node *n);

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
	pthread_mutex_t	*lock_std; /**< Mutex pour l'affichage standard. */
	pthread_mutex_t	lock; /**< Mutex pour le philosophe. */
	pthread_mutex_t	eat; /**< Mutex pour l'action de manger. */
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
	sem_t			*sem_fork; /**< Sémaphore représentant une fourchette. */
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
	pthread_mutex_t	lock_std; /**< Mutex pour l'affichage standard. */
	sem_t			*sem_die; /**< Sémaphore pour gérer la mort des philosophes. */
	sem_t			*sem_fork; /**< Sémaphore pour gérer les fourchettes. */
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

/**
 * @brief Affiche un message d'état pour un philosophe.
 * 
 * @param n Pointeur vers le philosophe.
 * @param str Le message à afficher.
 * @param time Le timestamp.
 */
void				ft_print_status(t_node *n, char *str, long long time);

/**
 * @brief Attend que tous les philosophes meurent.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @return 0 si tous les philosophes sont morts, -1 sinon.
 */
int					ft_wait_for_die(t_bin *var);

/**
 * @brief Gère la mort d'un philosophe.
 * 
 * @param sem_die Pointeur vers le sémaphore de mort.
 * @param var Pointeur vers la structure contenant les variables globales.
 * @param n Pointeur vers le philosophe.
 */
void				ft_sem_die(sem_t *sem_die, t_bin *var, t_node *n);

#endif
            INPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:31:51 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/07 17:41:11 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
	c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i] != '\0')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
} OUTPUT /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:31:51 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/07 17:41:11 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

/**
 * @file ft_atoi.c
 * @brief Implémentation de la fonction ft_atoi.
 */

/**
 * @brief Vérifie si un caractère est un caractère d'espacement.
 * 
 * @param c Le caractère à vérifier.
 * @return 1 si le caractère est un caractère d'espacement, 0 sinon.
 */
static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
	c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

/**
 * @brief Convertit une chaîne de caractères en entier.
 * 
 * @param str La chaîne de caractères à convertir.
 * @return L'entier converti.
 */
int			ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i] != '\0')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}
            INPUT #ifndef PHILO_TWO_H
# define PHILO_TWO_H

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
	pthread_mutex_t	*lock_std;
	pthread_mutex_t	lock;
	pthread_mutex_t	eat;
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
	sem_t			*sem_fork;
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
	pthread_mutex_t	lock_std;
	sem_t			*sem_die;
	sem_t			*sem_fork;
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
void				ft_print_status(t_node *n, char *str, long long time);
int					ft_wait_for_die(t_bin *var);
void				ft_sem_die(sem_t *sem_die, t_bin *var, t_node *n);

#endif OUTPUT /**
 * @file philo_two.h
 * @brief Contient les déclarations pour le projet Philosophes (philo_two).
 */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

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
	pthread_mutex_t	*lock_std; /**< Mutex pour l'affichage standard. */
	pthread_mutex_t	lock; /**< Mutex pour le philosophe. */
	pthread_mutex_t	eat; /**< Mutex pour l'action de manger. */
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
	sem_t			*sem_fork; /**< Sémaphore représentant une fourchette. */
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
	pthread_mutex_t	lock_std; /**< Mutex pour l'affichage standard. */
	sem_t			*sem_die; /**< Sémaphore pour gérer la mort des philosophes. */
	sem_t			*sem_fork; /**< Sémaphore pour gérer les fourchettes. */
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

/**
 * @brief Affiche un message d'état pour un philosophe.
 * 
 * @param n Pointeur vers le philosophe.
 * @param str Le message à afficher.
 * @param time Le timestamp.
 */
void				ft_print_status(t_node *n, char *str, long long time);

/**
 * @brief Attend que tous les philosophes meurent.
 * 
 * @param var Pointeur vers la structure contenant les variables globales.
 * @return 0 si tous les philosop