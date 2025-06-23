/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:04:21 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/23 21:38:05 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HARL_HPP_
#define _HARL_HPP_

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <string>

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