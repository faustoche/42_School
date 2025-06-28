#include "ICharacter.hpp"

/*-------------- CONSTRUCTORS --------------*/

ICharacter::ICharacter(){
}

ICharacter::ICharacter(const ICharacter &other){
	*this = other;
}

ICharacter &ICharacter::operator=(const ICharacter &other){
	(void)other;
	return (*this);
}

ICharacter::~ICharacter(){
	std::cout << "[ICharacter] Destructor called" << std::endl;
}

/*-------------- GETTER --------------*/

std::string const &getName() const{
	return (this->name)
}


/*-------------- FUNCTIONS --------------*/

void	ICharacter::use(ICharacter &target){

}



class ICharacter
{
public:

	virtual std::string const &getName() const = 0;
	virtual void equip(ICharacter *m) = 0;
	virtual void unequip (int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};