/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:24:40 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/23 21:20:56 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/* Pourquoi allouer sur la stack ou sur la heap 
* Sur la heap: 
* - Mémoire dynamique (new / delete)
* - Plus flexible mais plus lent
* - Libération manuelle de la mémoire

* Sur la stack
* - Mémoire rapide et automatique
* - Libération automatique
* - Pas besoin de delete
*/


Zombie* NewZombie(std::string name) {
	Zombie	*z = new Zombie(name);
	return z;
}