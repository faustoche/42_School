/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Automating.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:52:17 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/23 21:37:26 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AUTOMATING_HPP_
#define _AUTOMATING_HPP_

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>

/*-------------- class --------------*/

class Automating
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	Automating();
	~Automating();
	void	complain(std::string level);
};

#endif