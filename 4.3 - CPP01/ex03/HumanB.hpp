/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:16:28 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/10 11:15:10 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMANB_HPP_
#define _HUMANB_HPP_

#include <iostream>
#include <string>
#include "Weapon.hpp"

// 

class HumanB {
	private:
		std::string name;
		Weapon		*weapon;
	
	public:
		HumanB(std::string name);
		~HumanB();
	
		void	setWeapon(Weapon &weapon);
		void	attack(void);
	};

#endif