/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:48:09 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/24 11:16:33 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Automating.hpp"

int	main(int ac, char **av) {
	if (ac == 2) {
		Automating bot;
		bot.complain(av[1]);
		return (0);
	}
	else {
		std::cout << "Error\nNeed one argument" << std::endl;
		return (1);
	}
}