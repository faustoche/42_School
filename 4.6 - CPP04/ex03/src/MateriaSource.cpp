#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

/*-------------- CONSTRUCTORS --------------*/

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other){
	for (int i = 0; i < 4; i++)
		if (other.materia[i] != NULL)
			this->materia[i] = other.materia[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other){
	if (this != &other){
		for (int i = 0; i < 4; i++)
			delete this->materia[i];
		for (int i = 0; i < 4; i++)
			this->materia[i] = other.materia[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
		delete materia[i];
}

/*-------------- FUNCTIONS --------------*/

// trouver le premier emplacement libre
//stocker une copie ->clone

void	MateriaSource::learnMateria(AMateria *m){
	for (int i = 0; i < 4; i++){
		if (materia[i] == NULL){
			materia[i] = m->clone();
			return ;
		}
	}
}

/*
Parcourir les modèles stockés
Si le type correspond, retourner une copie (clone())
Si type inconnu, retourner NULL
*/

AMateria 	*MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 4; i++){
		if (this->materia[i]->getType() == type)
			return (materia[i]->clone());
		else
			return (NULL);
	}
	return (NULL);
}