/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:40:10 by faustoche         #+#    #+#             */
/*   Updated: 2025/05/08 14:42:44 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int i = 1;
	int j = 0;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else 
	{
		while (i < ac)
		{
			j = 0;
			while (av[i][j])
			{
				std::cout << (char) toupper(av[i][j]);
				j++;
			}
			i++;
		}
		std::cout << std::endl; // ajouter d;un saut a la ligne
	}
	return (0);
}