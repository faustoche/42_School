/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:16:28 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/24 11:03:16 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <string>

/*-------------- DEFINES --------------*/

#define RESET   	"\033[0m"
#define WHITE   	"\033[1;97m"
#define FUCHSIA 	"\033[1;38;5;201m"
#define BLUE_BRIGHT "\033[1;94m"
#define GREEN       "\033[1;32m"
#define MAGENTA     "\033[1;35m"
#define CYAN        "\033[1;36m"
#define RED 		"\033[1;91m"
#define YELLOW 		"\033[1;93m"
#define ORANGE      "\033[1;38;5;208m"
#define PINK        "\033[1;38;5;205m"
#define TURQUOISE   "\033[1;38;5;45m"
#define GOLD        "\033[1;38;5;220m"
#define CORAL       "\033[1;38;5;203m"

/*-------------- CLASS --------------*/

class Weapon {
	private:
		std::string type;
	
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string &getType();
		void setType(std::string type);
	};

#endif