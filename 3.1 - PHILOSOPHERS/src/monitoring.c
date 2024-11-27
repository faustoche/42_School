/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:51:22 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/27 18:10:37 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** TODO : dans t_philo, associer chaque philosophe à une fourchette
** TODO : initialiser les fourchette pthread_mutex_init
** TODO : relier les philosophes et les fourchettes dans les structures
*/

/*
** Affichage du message d'état du philo
** Trouver le timestamp (gettimeoftheday)
** Ajouter une fonction de monitoring qui permet de surveiller si un philosophe dépasse time to die sans manger
** Arrêt de la simulation dès qu'un philo meurt
** Vérification du nombre de fois où chaque philo a mangé selon number of times each philo must eat
*/

void	message_philo(void)
{
	// Affichage du timestamp
	// Affichage de l'état de philo[1]
}

void	monitor_philo(void)
{
	// Prend la variable philo[i] et vérifie si les philo ont le status 1 ou 0
	// Si l'un des philo == 0 alors on arrête la simulation
	// Vérifie la variable du nombre de repas et check si cela correspond à av[5]
}

/*
** Synchronisation des fourchettes
** Mutex sur les fourchettes gauche et droite
** Affichage du message indiquant si le philo a pris une fourchette et laquelle
** Dévérouillage du mutex des fourchettes
** Affichage d'un message indiquand que les fourchettes sont disponibles
*/

void	initialize_forks(void)
{
	// Vérification que chaque philo a une fourchette gauche et une droite
	// Quand le premier philo prend la première fourchette, lock
	// Message FORK
	// Quand il la repose, unlock
	// Message FORKDOWN
}