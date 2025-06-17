/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:51:50 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/10 11:28:09 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

#define RESET   "\033[0m"
#define WHITE   "\033[97m"
#define FUCHSIA "\033[38;5;201m"

int main() {
	Phonebook myBook;
	string choice;

	while (true) {
        cout << FUCHSIA << "\n╔══════════════════════════════╗" << RESET << endl;
        cout << FUCHSIA << "║" << WHITE << "         MY PHONEBOOK         " << FUCHSIA << "║" << RESET << endl;
        cout << FUCHSIA << "╠══════════════════════════════╣" << RESET << endl;
        cout << FUCHSIA << "║" << WHITE << " 1. ADD a contact             " << FUCHSIA << "║" << RESET << endl;
        cout << FUCHSIA << "║" << WHITE << " 2. SEARCH for a contact      " << FUCHSIA << "║" << RESET << endl;
        cout << FUCHSIA << "║" << WHITE << " 3. EXIT                      " << FUCHSIA << "║" << RESET << endl;
        cout << FUCHSIA << "╚══════════════════════════════╝" << RESET << endl;
		cout << WHITE << endl << RESET;
		cout << WHITE << "Your choice : " << RESET;
		cin >> choice;

		if (choice == "ADD" || choice == "1") {
			string last_name;
			string first_name;
			string nickname;
			int phone_number;
			string darkest_secret;
			cout << WHITE << endl << RESET;
			cout << "First name : ";
			cin >> first_name;
			cout << "Last name : ";
			cin >> last_name;
			cout << "Nickname : ";
			cin >> nickname;
			cout << "Phone number : ";
			cin >> phone_number;
			cout << "Darkest secret : ";
			cin >> darkest_secret;

			if (cin.fail()) {
				cin.clear(); // reset erreur
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vide input
				cout << "Invalid phone number. Cannot add contact." << endl;
				continue;
			}

			if (last_name.empty() || first_name.empty() || phone_number <= 0) {
				cout << "Invalid entry. Cannot add contact." << endl;
			} else {
				Contact newContact(first_name, last_name, nickname, phone_number, darkest_secret);
				myBook.addContact(newContact);
			}
		}
		else if (choice == "SEARCH" || choice == "2") {
			int index;
			cout << WHITE << endl << RESET;
			myBook.showContacts();
			cout << WHITE << endl << RESET;
			cout << "Entrez l'index du contact (0 à 7) : ";
			cin >> index;
			cout << WHITE << endl << RESET;
			myBook.showContact(index);
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid index." << endl;
				continue;
			}
		}
		else if (choice == "EXIT" || choice == "3") {
			cout << "See ya !" << endl;
			break;
		}
		else {
			cout << "Invalid choice. Try again." << endl;
		}
		// else if eof 
			// exit
	}
	return 0;
}
