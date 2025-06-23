/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:16:28 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/23 21:36:17 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMANA_HPP_
#define _HUMANA_HPP_

/*-------------- INCLUDES --------------*/

#include "Weapon.hpp"

/*-------------- CLASS --------------*/

class HumanA {
private:
	std::string name;
	Weapon		&weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();

	void	attack(void);
};

#endif