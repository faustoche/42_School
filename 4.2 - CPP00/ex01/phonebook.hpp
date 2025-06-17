/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:07:41 by faustoche         #+#    #+#             */
/*   Updated: 2025/05/10 11:09:01 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "contact.hpp"

class Phonebook {
private:
	Contact	contacts[8];
	int		nextIndex;
	int		nbContact;

public:
	Phonebook();

	void	addContact(Contact newContact);
	void	showContacts();
	void	showContact(int index);
	void	showAll();
};

#endif