/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 09:19:44 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/23 21:25:05 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie **ZombieHorde(int N, std::string name);

int main() {
	int i = 0;
	int	N = 10;

	Zombie **horde = ZombieHorde(N, "Serge");
	while (i < N)
	{
		delete horde[i];
		i++;
	}
	delete[] horde;
	return 0;
}