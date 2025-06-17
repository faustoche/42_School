/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:19:18 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/10 14:34:56 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
}

HumanB::~HumanB() {
	std::cout << "HumanB " << this->name << "destroyed" << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
	return ;
}

void	HumanB::attack(void) {
	if (this->weapon)
		std::cout << this->name << "attacks with their " << this->weapon->getType() << std::endl;
	return ;
}
