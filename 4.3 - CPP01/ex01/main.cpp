/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 09:19:44 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/07 10:44:47 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie **zombieHorde(int N, std::string name);

int main() {
	int i = 0;
	int	N = 10;

	Zombie **horde = zombieHorde(N, "Serge");
	while (i < N)
	{
		delete horde[i];
		i++;
	}
	delete[] horde;
	return 0;
}