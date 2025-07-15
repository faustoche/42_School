#include "Data.hpp"
#include "Serializer.hpp"

/* */

int main(void){
	Data *data_ptr;
	Data animal("chien", 4);
	uintptr_t ptr_int;

	std::cout << std::endl;
	ptr_int = Serializer::serialize(&animal);
	std::cout << GREEN << "Result for serializer  : " << RESET << ptr_int << std::endl;
	std::cout << GREEN << "Original pointer       : " << RESET << &animal << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	data_ptr = Serializer::deserialize(ptr_int);
	std::cout << PINK << "Result for deserialize : " << RESET << data_ptr << std::endl;
	std::cout << PINK << "Original pointer       : " << RESET << &animal << std::endl;
	std::cout << std::endl;
	return (0);
}