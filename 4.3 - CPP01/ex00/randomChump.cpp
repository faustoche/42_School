/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:24:51 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/07 08:59:25 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Zombie z = Zombie(name) : je crée un zombie (et je lui attribue le nom <name>)
// Il s'annonce

void	randomChump(std::string name) {
	Zombie z = Zombie(name);
	z.announce();
	return;
}