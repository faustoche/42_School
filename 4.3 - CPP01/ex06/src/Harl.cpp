/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:05:08 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/24 11:33:07 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

/*-------------- CONSTRUCTORS --------------*/

Harl::Harl() {}
Harl::~Harl() {}

/*-------------- FUNCTIONS --------------*/

void	Harl::debug(void) {
	std::cout << GREEN << "[DEBUG]" << RESET << " I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::info(void) {
	std::cout << YELLOW << "[INFO]" << RESET << " I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::warning(void) {
	std::cout << ORANGE << "[WARNING]" << RESET << " I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
	return ;
}

void	Harl::error(void) {
	std::cout << RED << "[ERROR]" << RESET << " This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}
