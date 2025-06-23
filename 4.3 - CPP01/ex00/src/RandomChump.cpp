/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:24:51 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/23 21:21:09 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

// Zombie z = Zombie(name) : je crée un zombie (et je lui attribue le nom <name>)
// Il s'annonce

void	RandomChump(std::string name) {
	Zombie z = Zombie(name);
	z.announce();
	return;
}