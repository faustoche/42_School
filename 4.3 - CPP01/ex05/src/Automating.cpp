/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Automating.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:51:22 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/24 11:29:46 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Automating.hpp"

/*-------------- CONSTRUCTORS --------------*/

Automating::Automating() {}
Automating::~Automating() {}

/*-------------- FUNCTIONS --------------*/

void	Automating::debug(void) {
	std::cout << GREEN << "[DEBUG]" << RESET << " I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	return ;
}

void	Automating::info(void) {
	std::cout << YELLOW << "[INFO]" << RESET << " I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Automating::warning(void) {
	std::cout << ORANGE << "[WARNING]" << RESET << " I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
	return ;
}

void	Automating::error(void) {
	std::cout << RED << "[ERROR]" << RESET << " This is unacceptable! I want to speak to the manager now. AND STOP CALLING ME KAREN." << std::endl;
	return ;
}

void	Automating::complain(std::string level) {
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Automating::*functions[])() = { &Automating::debug, &Automating::info, &Automating::warning, &Automating::error };
	
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << RED << "What the fuck are you talking about?" << RESET << std::endl;
}