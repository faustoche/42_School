/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 09:21:27 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/23 21:35:50 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/*-------------- CONSTRUCTORS --------------*/

Zombie::Zombie() {
	this->name = "Default";
}

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << this->name << " destroyed" << std::endl;
}

/*-------------- FUNCTIONS --------------*/

Zombie* NewZombie(std::string name) {
	Zombie	*z = new Zombie(name);
	return z;
}

void	Zombie::announce() {
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}
