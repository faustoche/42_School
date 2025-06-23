/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Automating.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:51:22 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/23 21:37:49 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Automating.hpp"

/*-------------- CONSTRUCTORS --------------*/

Automating::Automating() {}
Automating::~Automating() {}

/*-------------- FUNCTIONS --------------*/

void	Automating::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	return ;
}

void	Automating::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Automating::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
	return ;
}

void	Automating::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

void	Automating::complain(std::string level) {
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Automating::*functions[])() = { &Automating::debug, &Automating::info, &Automating::warning, &Automating::error };
	int i = 0;
	
	while (i < 4) {
		if (levels[i] == level) {
			(this->*functions[i])();
			return ;
		}
		else {
			std::cout << "Wtf are you talking about" << std::endl;
			return ;
		}
		i++;
	}
}