/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:04:12 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/24 11:34:46 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int	main(int ac, char **av) {
	if (ac == 2) {
		std::string level = av[1];
		Harl harl;
		int index = -1;
		std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
		for (int i = 0; i < 4; i++) {
			if (level == levels[i]) {
				index = i;
				break ;
			}
		}
		switch (index) {
			case 0:
				harl.debug();
			case 1:
				harl.info();
			case 2:
				harl.warning();
			case 3:
				harl.error();
				break ;
			default:
				std::cout << RED << "What the fuck are you talking about?" << RESET << std::endl;
		}
		return (0);
	}
	else {
		std::cout << "Error \nNeed one argument" << std::endl;
		return (1);
	}
}