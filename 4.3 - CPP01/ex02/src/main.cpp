/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:39:07 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/24 10:55:14 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

int	main() {
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << GREEN << "Memory adress of brain : " << RESET << &brain << std::endl;
	std::cout << GREEN << "Memory adress with PTR : " << RESET << stringPTR << std::endl;
	std::cout << GREEN << "Memory adress with REF : " << RESET << &stringREF << std::endl;
	std::cout << MAGENTA << "Value of brain         : " << RESET << brain << std::endl;
	std::cout << MAGENTA << "Value pointed by PTR   : " << RESET << *stringPTR << std::endl;
	std::cout << MAGENTA << "Value pointed by REF   : " << RESET << stringREF << std::endl;
	return (0);
}