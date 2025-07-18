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
		else
			this->materia[i] = NULL;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other){
	if (this != &other){
		for (int i = 0; i < 4; i++)
			delete this->materia[i];
		for (int i = 0; i < 4; i++){
			if (other.materia[i] != NULL)
				this->materia[i] = other.materia[i]->clone();
			else
				this->materia[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
		delete materia[i];
}

/*-------------- FUNCTIONS --------------*/

void	MateriaSource::learnMateria(AMateria *m){
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++){
		if (materia[i] == NULL){
			materia[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 4; i++){
		if (this->materia[i] != NULL){
			if (this->materia[i]->getType() == type)
				return (materia[i]->clone());
		}
	}
	return (NULL);
}