/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:51:22 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/27 18:11:15 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** One or more philosophers sit at a round table. There's a large bowl of food in the middle.
** They alternatively eat, think, sleep. While they are eating, they are not thinking nor sleeping.
** There are as many forks as philosophers
** A philosopher takes their right and their left forks to eat, one in each hand
** When a philosopher has finished eating, they put their forks back on the table and start sleeping
** Once awake they start thinking again. Everything stops when a philosophers dies of starvation
** Every philosophers needs to eat and should never starve
** They don't speak to each other and don't know when another is about to die
** 4 arguments obligatoires : nb of philom, time to die, time to eat, time to sleep
** 1 argument facultatif : nombre de fois où un philo doit manger
*/

/*
** Main
** Initialisation des données : thread, mutex, temps, paramètres
** Vérification de la ligne de commande : 
	- number of philosophers
	- time to die
	- time to eat
	- time to sleep
	- number of times each philosopher must eat (option)
** 
*/

int main(int ac, char *av)
{
	// Le minimum d'argument est de 4 (+ 1) et le maximum est de 5 (+ 1)
	// Si pas le bon nombre d'argument, exit
	// Variable nb de philo = av[1]
	// Appel de la fonction de création des philo
	// 
}

/*
** Init
** Allocation et initialisation des données de chaque philosophe (t_philo)
** Pointeurs vers les fourchettes (mutex)
** Chronomètre pour mesurer time to die
** Compteur de repas
*/

