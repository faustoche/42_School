/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:18:18 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/24 11:02:53 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

/*-------------- CONSTRUCTORS --------------*/

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {
}

HumanA::~HumanA() {
	std::cout << "HumanA " << this->name << " destroyed." << std::endl;
}

/*-------------- FUNCTIONS --------------*/

void	HumanA::attack(void) {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
	return ;
}
