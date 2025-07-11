/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:48:46 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/24 11:15:52 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string replaceContent(const std::string &content, const std::string &s1, const std::string &s2) {
	std::string	result;
	size_t		pos = 0;
	size_t		found;

	while ((found = content.find(s1, pos)) != std::string::npos) {
		result += content.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += content.substr(pos);
	return (result);
}

int main(int ac, char **av) {
	if (ac == 4)
	{
		std::string	filename = av[1];
		std::string	s1 = av[2];
		std::string	s2 = av[3];

		if (s1.empty()) {
			std::cout << "Error\ns1 is empty\n";
			return (1);
		}
		std::ifstream infile(filename.c_str());
		if (!infile) {
			std::cout << "Error\nCannot open input file\n";
			return (1);
		}
		std::string content;
		std::string line;
		while (std::getline(infile, line)) {
			content += line;
			content += '\n';
		}
		infile.close();
		std::string replaced = replaceContent(content, s1, s2);
		std::ofstream outfile((filename + ".replace").c_str());
		if (!outfile) {
			std::cout << "Error\nCannot open output file\n";
			return (1);
		}
		outfile << replaced;
		outfile.close();
		return (0);
	}
	else {
		std::cout << "Error\nWrong number of args" << std::endl;
		return (1);
	}
}