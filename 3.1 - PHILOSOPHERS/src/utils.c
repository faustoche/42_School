/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:51:22 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/27 18:10:49 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** Récupère l'heure actuelle en millisecondes (gettimeoftheday)
** Trouve le sommeil précis en millisecondes pour chaque action
** Libère tout ce qui doit être libéré


4. Synchronisation et gestion des fourchettes
Objectif : Assurer qu’aucun philosophe ne prend plus d’une fourchette et éviter les deadlocks.

Prendre les fourchettes :

Implémentez take_forks pour verrouiller les mutex des fourchettes gauche et droite.
Affichez un message indiquant que les fourchettes sont prises.
Manger :

Implémentez eat dans la routine :
Vérifiez que le philosophe a bien les deux fourchettes.
Mettez à jour le timestamp de son dernier repas.
Utilisez precise_sleep pour simuler le temps de repas.
Poser les fourchettes :

Implémentez put_forks pour déverrouiller les mutex.
Affichez un message indiquant que les fourchettes sont rendues.
Éviter les deadlocks :

Utilisez un algorithme pour éviter les blocages :
Par exemple, faites attendre un philosophe si les deux fourchettes ne sont pas disponibles.
Tests à ce stade :

Vérifiez que les philosophes ne mangent pas avec une seule fourchette.
Assurez-vous que le programme ne se bloque pas lorsque plusieurs philosophes mangent en même temps.
5. Surveillance et gestion des morts
Objectif : Surveiller l’état des philosophes et arrêter la simulation en cas de décès.

Chronométrer les actions :

Implémentez monitor_philosophers dans un thread séparé ou dans la boucle principale.
Vérifiez périodiquement si un philosophe dépasse time_to_die sans manger.
Détecter un décès :

Si un philosophe meurt :
Affichez un message timestamp_in_ms X died.
Arrêtez la simulation.
Arrêter la simulation :

Implémentez une condition d’arrêt :
Si un philosophe meurt.
Si tous les philosophes ont mangé le nombre requis de fois (si cet argument est fourni).
Tests à ce stade :

Simulez des scénarios où un philosophe meurt.
Vérifiez que le programme s’arrête immédiatement après un décès.
6. Finalisation et nettoyage
Objectif : Libérer les ressources et assurer un programme propre.

Libérer la mémoire :

Détruisez les mutex avec pthread_mutex_destroy.
Libérez la mémoire allouée dynamiquement (philosophes, fourchettes).
Assurer la stabilité :

Vérifiez que le programme ne produit pas de fuites de mémoire avec valgrind.
Testez différents scénarios (un philosophe, plusieurs philosophes, timings variés).
7. Tests approfondis
Objectif : Valider que le programme respecte toutes les règles.

Scénarios simples :

1 philosophe : Doit prendre sa fourchette, manger, et mourir (pas de deuxième fourchette).
2 philosophes : Vérifiez l’alternance correcte entre les deux.
5 philosophes : Assurez-vous que les philosophes mangent sans deadlock.
Tests de stress :

Ajoutez beaucoup de philosophes et réduisez les temps (time_to_eat, time_to_sleep).
Vérifiez que les logs restent cohérents.
Tests des arrêts :

Tous les philosophes mangent number_of_times_each_philosopher_must_eat.

*/