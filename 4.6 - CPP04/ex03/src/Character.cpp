#include "Character.hpp"

/*-------------- CONSTRUCTORS --------------*/

/* Je sette le name et l'inventaire à rien pour le moment */

Character::Character(void) : name("no name yet"){
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const std::string name) : name(name){
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character &other){
	*this = other;
}



/*-------------- CONSTRUCTORS --------------*/
