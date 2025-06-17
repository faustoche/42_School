/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 09:21:51 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/07 10:37:44 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	**zombieHorde(int N, std::string name) {
	Zombie	**horde = new Zombie*[N];
	int		i = 0;

	while (i < N) {
		horde[i] = new Zombie(name + " " + std::to_string(i));
		horde[i]->announce();
		i++;
	}
	return horde;
}