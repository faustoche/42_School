/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:24:13 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/28 17:09:31 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HPP
#define _ZOMBIE_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <string>
#include <iomanip>

/*-------------- DEFINES --------------*/

#define RED		"\033[1;31m"
#define YELLOW	"\033[1;33m"
#define GREEN	"\033[1;32m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define RESET	"\033[0m"

/*-------------- CLASS --------------*/

class Zombie {
private:
	std::string	name;

public:
	Zombie(std::string name);
	~Zombie(void);
	void	announce(void);
	Zombie	*newZombie(std::string name);
	void	randomChump(std::string name);
};

#endif