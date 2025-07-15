#include "Serializer.hpp"

/*-------------- CONSTRUCTORS --------------*/

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &other){
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other){
	(void)other;
	return (*this);
}

Serializer::~Serializer(){}

/*-------------- FUNCTIONS --------------*/

/* Transform a pointerr in whole number */

uintptr_t Serializer::serialize(Data *ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

/* Transform the whole number in pointer*/

Data *Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}