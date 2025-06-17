/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:39:07 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/09 19:36:45 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

int	main() {
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "Memory adress of brain : " << &brain << std::endl;
	std::cout << "Memory adress with PTR : " << stringPTR << std::endl;
	std::cout << "Memory adress with REF : " << &stringREF << std::endl;
	std::cout << "Value of brain : " << brain << std::endl;
	std::cout << "Value pointed by PTR : " << *stringPTR << std::endl;
	std::cout << "Value pointed by REF : " << stringREF << std::endl;
	return (0);
}