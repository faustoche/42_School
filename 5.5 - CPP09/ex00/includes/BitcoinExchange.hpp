#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/*-------------- INCLUDES --------------*/

#include <map>
#include <string>

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

/**************************/
/*    USING STD::MAP      */
/************************ */

class DatesPrices
{
private:
	std::string _database;

public:
	DatesPrices();
	DatesPrices(std::string database);
	DatesPrices(const DatesPrices &other);
	DatesPrices &operator=(const DatesPrices &other);
	~DatesPrices();

	void pricesForDate(); // return the price of 1 unit of currency on a given date 
	void printFees(); // attemps to print the fees for an amount of currency on a given date ---- call pricesForDate()
};

class Date
{
private:

public:
	Date();
	~Date();
};

#endif