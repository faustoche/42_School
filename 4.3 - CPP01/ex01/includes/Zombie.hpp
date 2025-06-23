/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 09:20:12 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/23 21:35:31 by faustoche        ###   ########.fr       */
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
	std::string name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie(void);
	void	announce(void);
};

Zombie	*NewZombie(std::string name);
Zombie	**ZombieHorde(int N, std::string name);

#endif