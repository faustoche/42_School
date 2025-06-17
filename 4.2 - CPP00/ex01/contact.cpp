/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:57:55 by faustoche         #+#    #+#             */
/*   Updated: 2025/05/10 14:53:02 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = 0;
	darkest_secret = "";
}

Contact::Contact(string fn, string ln, string nick, int num, string ds) {
	first_name = fn;
	last_name = ln;
	nickname = nick;
	phone_number = num;
	darkest_secret = ds;
}

//getter
string	Contact::getFirstName() {
	return (first_name);
}

string	Contact::getLastName() {
	return (last_name);
}

string	Contact::getNickname() {
	return (nickname);
}

int	Contact::getPhoneNumber() {
	return (phone_number);
}

string	Contact::getDarkestSecret() {
	return (darkest_secret);
}

//setter
void	Contact::setFirstName(string fn) {
	first_name = fn;
}

void	Contact::setLastName(string ln) {
	last_name = ln;
}

void	Contact::setNickname(string nick) {
	nickname = nick;
}

void	Contact::setPhoneNumber(int num) {
	phone_number = num;
}

void	Contact::setDarkestSecret(string ds) {
	darkest_secret = ds;
}

void Contact::show() {
	cout << "First name: " << first_name << endl;
	cout << "Last name: " << last_name << endl;
	cout << "Nickname: " << nickname << endl;
	cout << "Phone number: " << phone_number << endl;
	cout << "Darkest secret: " << darkest_secret << endl;
	cout << "---------------------" << endl;
}


