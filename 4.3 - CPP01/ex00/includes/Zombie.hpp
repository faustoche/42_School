/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:24:13 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/23 21:20:29 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HPP
#define _ZOMBIE_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <string>
#include <iomanip>

/*-------------- CLASS --------------*/

class Zombie {
private:
	std::string	name;

public:
	Zombie(std::string name);
	void	announce(void);
	Zombie	*newZombie(std::string name);
	void	randomChump(std::string name);
	~Zombie(void);
};

#endif