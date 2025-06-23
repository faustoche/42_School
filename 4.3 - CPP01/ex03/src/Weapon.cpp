/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:17:27 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/23 21:37:12 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

/*-------------- CONSTRUCTORS --------------*/

Weapon::Weapon(std::string type) : type(type) {
}

Weapon::~Weapon() {
}

/*-------------- FUNCTIONS --------------*/

const std::string &Weapon::getType() {
	return (this->type);
}

void Weapon::setType(std::string type) {
	this->type = type;
}
