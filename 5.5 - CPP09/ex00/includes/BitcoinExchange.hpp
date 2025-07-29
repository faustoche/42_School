#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/*-------------- INCLUDES --------------*/

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>


/*-------------- CLASS --------------*/

/*
** La map stock les éléments dans un arbre binaire équilibré
** 		- une structure de données
**		- chaque noeud contient une clé et une valeur
**		- chaque noeud a max 2 enfants
**		- à gauche : des clés plus petites
**		- à droite des clés plus grandes
** 		Si on ajoute pas les données dans un ordre équilibré, on se retrouve avec une liste chainée ce qui n'est pas le but

** Pour chaque insertion, la clé est comparée et placée au bon endroit
** Pour chaque recherche, l'arbre est parcouru en O(log n) selon la comparaison des clés
**		- O(log n) = notation mathématique pour mesurer le temps d'exécution d'une opération selon le nombre d'éléments n
**		- Pour un arbre équilibré avec n elements 
**			- chaque fois qu'on descend d'un niveau dans l'arbre, on divise l'espace de recherche en 2
			- niveau 0 = tout l'arbre / niveau 1 = moitié gauche ou droite / niveau 2 : moitié d'une moitié
** L'ordre des éléments est toujours trié par clé
** Les clés sont uniques
*/

class BitcoinExchange
{
private:
	std::string _csvPath; // chemin du fichier CSV à charger
	std::map<std::string, float> _rateByDate; // map triée des taux : key = date, value = taux

public:
	BitcoinExchange();
	BitcoinExchange(const std::string database_path);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void chargingDatabase();
	std::string getCSVPath(void) const;
	float getRate(std::string date);

	class CSVOpenException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

bool isValidDate(std::string str);
bool isValidValue(std::string str);
float strToFloat(std::string str);
void processInputFile(const std::string& filename, BitcoinExchange& btc);


#endif