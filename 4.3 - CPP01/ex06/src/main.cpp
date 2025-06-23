/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:04:12 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/23 21:34:16 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int	main(int ac, char **av) {
	if (ac == 2) {
		std::string level = av[1];
		Harl harl;
		int index = -1;
		int i = 0;
		std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
		while (i < 4) {
			if (level == levels[i]) {
				index = i;
				break ;
			}
			i++;
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
				std::cout << "[ Prob]" << std::endl;
		}
		return (0);
	}
	else {
		std::cout << "Error : need one argument" << std::endl;
		return (1);
	}
}