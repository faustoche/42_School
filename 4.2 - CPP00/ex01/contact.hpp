/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:07:41 by faustoche         #+#    #+#             */
/*   Updated: 2025/05/10 10:55:20 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Contact {
private:
	string	first_name;
	string	last_name;
	string	nickname;
	int		phone_number;
	string	darkest_secret;

public:
	Contact(); // constructeur privé sans définition
	Contact(string fn, string ln, string nick, int num, string ds);

// je déclare mes getter
	string	getFirstName();
	string	getLastName();
	string	getNickname();
	int		getPhoneNumber();
	string	getDarkestSecret();

// je déclare mes setter
	void	setFirstName(string fn);
	void	setLastName(string ln);
	void	setNickname(string nick);
	void	setPhoneNumber(int num);
	void	setDarkestSecret(string ds);

	void	show();
};

#endif
