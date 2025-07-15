#include "whatever.hpp"

int main( void )
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << WHITE << "a = " << a << ", b = " << b << RESET << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
	std::cout << std::endl;
	std::string c = "chien";
	std::string d = "chat";
	::swap(c, d);
	std::cout << WHITE << "c = " << c << ", d = " << d << RESET << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
	return 0;
	}