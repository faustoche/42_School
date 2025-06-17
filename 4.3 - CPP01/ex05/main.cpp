/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:48:09 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/11 12:32:15 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Automating.hpp"

int	main(int ac, char **av) {
	if (ac == 2) {
		Automating bot;
		bot.complain(av[1]);
		return (0);
	}
	else {
		std::cout << "Error : need one argument" << std::endl;
		return (1);
	}
}