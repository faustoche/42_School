/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:24:13 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/07 09:26:18 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HPP
#define _ZOMBIE_HPP

#include <iostream>
#include <string>
#include <iomanip>

// 

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