/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:55:50 by faustoche         #+#    #+#             */
/*   Updated: 2025/05/10 15:02:55 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.hpp"
using namespace std;

#define RESET   "\033[0m"
#define WHITE   "\033[97m"
#define FUCHSIA "\033[38;5;201m"
#define BLUE_BRIGHT "\033[94m"
#define RED "\033[91m"
#define YELLOW "\033[93m"



Phonebook::Phonebook() {
	nextIndex = 0;
	nbContact = 0;
}

string	formatLine(const string &line) {
	if (line.length() > 10)
		return (line.substr(0, 9) + ".");
	else
		return (string(10 - line.length(), ' ') + line);
}

void	Phonebook::addContact(Contact newContact) {
	contacts[nextIndex] = newContact;

	if (nbContact < 8) {
		nbContact++;
	} 
	nextIndex = (nextIndex + 1) % 8;
}

void Phonebook::showContacts() {
	cout << BLUE_BRIGHT << "╔═══════════════════════════════════════════════════╗" << RESET << endl;
	cout << BLUE_BRIGHT << "║" << WHITE << "                   CONTACT LIST                    " << BLUE_BRIGHT << "║" << RESET << endl;
	cout << BLUE_BRIGHT << "╠════════════╦════════════╦════════════╦════════════╣" << RESET << endl;
	cout << BLUE_BRIGHT << "║" << WHITE
		<< setw(10) << "Index" << BLUE_BRIGHT << "  ║" << WHITE
		<< setw(10) << "First Name" << BLUE_BRIGHT << "  ║" << WHITE
		<< setw(10) << "Last Name" << BLUE_BRIGHT << "  ║" << WHITE
		<< setw(10) << "Nickname" << BLUE_BRIGHT << "  ║" << RESET << endl;
	cout << BLUE_BRIGHT << "╠════════════╬════════════╬════════════╬════════════╣" << RESET << endl;
	for (int i = 0; i < 8; i++) {
		if (contacts[i].getFirstName() != "") {
			cout << BLUE_BRIGHT << "║" << WHITE
				 << setw(10) << i << BLUE_BRIGHT << "  ║" << WHITE
				 << setw(10) << formatLine(contacts[i].getFirstName()) << BLUE_BRIGHT << "  ║" << WHITE
				 << setw(10) << formatLine(contacts[i].getLastName()) << BLUE_BRIGHT << "  ║" << WHITE
				 << setw(10) << formatLine(contacts[i].getNickname()) << BLUE_BRIGHT << "  ║" << RESET << endl;
		}
	}
	cout << BLUE_BRIGHT << "╚════════════╩════════════╩════════════╩════════════╝" << RESET << endl;
}


void Phonebook::showContact(int index) {
	if (index < 0 || index >= 8 || contacts[index].getFirstName() == "") {
		cout << RED << "Invalid index or empty contact!" << RESET << endl;
		return;
	}

	cout << YELLOW << "╔═══════════════════════════════════════════════════╗" << RESET << endl;
	cout << YELLOW << "║" << WHITE << "               CONTACT INDEX: " << setw(2) << index << "                   " << YELLOW << "║" << RESET << endl;
	cout << YELLOW << "╠═══════════════╦═══════════════════════════════════╣" << RESET << endl;

	cout << YELLOW << "║" << WHITE << setw(12) << "First Name" << YELLOW << "   ║ " << WHITE
		 << contacts[index].getFirstName() << YELLOW << setw(37 - contacts[index].getFirstName().length()) << "║" << RESET << endl;

	cout << YELLOW << "║" << WHITE << setw(12) << "Last Name" << YELLOW << "   ║ " << WHITE
		 << contacts[index].getLastName() << YELLOW << setw(37 - contacts[index].getLastName().length()) << "║" << RESET << endl;

	cout << YELLOW << "║" << WHITE << setw(12) << "Nickname" << YELLOW << "   ║ " << WHITE
		 << contacts[index].getNickname() << YELLOW << setw(37 - contacts[index].getNickname().length()) << "║" << RESET << endl;

	cout << YELLOW << "║" << WHITE << setw(12) << "Phone number" << YELLOW << "   ║ " << WHITE
		 << contacts[index].getPhoneNumber() << YELLOW << setw(37 - to_string(contacts[index].getPhoneNumber()).length()) << "║" << RESET << endl;

	cout << YELLOW << "║" << WHITE << setw(12) << "Darkest secret" << YELLOW << " ║ " << WHITE
		 << contacts[index].getDarkestSecret() << YELLOW << setw(37 - contacts[index].getDarkestSecret().length()) << "║" << RESET << endl;

	cout << YELLOW << "╚═══════════════╩═══════════════════════════════════╝" << RESET << endl;
}


void	Phonebook::showAll() {
	cout << "List of all the contacts:" << endl;
	for (int i = 0; i < 8; i++) {
		if (contacts[i].getFirstName() != "") {
			contacts[i].show();
		}
	}
}
