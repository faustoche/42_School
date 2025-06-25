/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:21:24 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/24 11:04:12 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

int main()
{
	{
		std::cout << CORAL << "\n*----- TEST 1 - HUMAN A -----*" << RESET << std::endl << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		std::cout << CORAL << "------------------------------" << RESET << std::endl;
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		std::cout << CORAL << "------------------------------" << RESET << std::endl;
		std::cout << "\n";
	}
	{
		std::cout << PINK << "\n*----- TEST 2 - HUMAN B -----*" << RESET << std::endl << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		std::cout << PINK << "------------------------------" << RESET << std::endl;
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		std::cout << PINK << "------------------------------" << RESET << std::endl;
		std::cout << "\n";
	}
	return 0;
}
