/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:24:40 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/07 09:08:27 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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


Zombie* newZombie(std::string name) {
	Zombie	*z = new Zombie(name);
	return z;
}