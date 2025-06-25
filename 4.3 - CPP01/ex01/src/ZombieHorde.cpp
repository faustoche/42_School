/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 09:21:51 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/24 10:24:22 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

std::string	to_string(int n){
	std::ostringstream oss;
	oss << n;
	return (oss.str());
}

Zombie	**ZombieHorde(int N, std::string name) {
	Zombie	**horde = new Zombie*[N];
	int		i = 0;

	while (i < N) {
		horde[i] = new Zombie(name + " " + to_string(i));
		horde[i]->announce();
		i++;
	}
	return horde;
}