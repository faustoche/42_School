/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:51:22 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/27 18:10:45 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** Création d'un thread pour chaque philo et assignation de la routine
** pthread_create
*/

void	create_philo(t_philo *philo)
{
	// création d'un thread pour un philo
	// Chaque thread = pointeur vers la structure t_philo
	// quand un thread est créé, incrémentation de la variable left_fork
	// si la création échoue, protection
	// Compteur de repas initialisé à 0
	// Lancement du chronomètre pour son temps de vie
	// Initialisation de son compteur de vie (1 - 0)
}

/*
** Utilisation de pthread join pour attendre la clôture de tous les threads
** pthread_join
*/

void	synchronize_forks()
{
	// take forks (mutex gauche et droite)
	// 
}

void	no_deadlock(void)
{
	// Si les deux fourchettes ne sont pas disponibles : wait
}