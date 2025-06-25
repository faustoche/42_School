/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:04:21 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/24 11:30:55 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HARL_HPP_
#define _HARL_HPP_

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <string>

/*-------------- DEFINES --------------*/

#define RED		"\033[1;31m"
#define YELLOW	"\033[1;33m"
#define GREEN	"\033[1;32m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define ORANGE	"\033[1;38;5;208m"
#define RESET	"\033[0m"

/*-------------- CLASS --------------*/

class Harl
{
public:
	Harl();
	~Harl();
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif