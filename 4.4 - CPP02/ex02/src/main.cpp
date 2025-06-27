#include "../includes/Fixed.hpp"

int	main(void){
	Fixed a = 5;
	Fixed b = 10;
	std::cout << "\n[FOR A = 5 AND B = 10]" << std::endl << std::endl;
	std::cout << PINK << "1. TESTING COMPARISONS" << RESET << std::endl << std::endl;
	std::cout << "  [1 = true, 0 = false]" << std::endl << std::endl;
	std::cout << "· a > b  = " << (a > b) << std::endl;
	std::cout << "· a < b  = " << (a < b) << std::endl;
	std::cout << "· a <= b = " << (a <= b) << std::endl;
	std::cout << "· a >= b = " << (a >= b) << std::endl;
	std::cout << "· a == b = " << (a == b) << std::endl;
	std::cout << "· a != b = " << (a != b) << std::endl << std::endl;
	std::cout << "· 1.001f == 1.002f = " << (Fixed(1.001f) == Fixed(1.002f)) << std::endl;
	std::cout << "· 1.001f != 1.002f = " << (Fixed(1.001f) != Fixed(1.002f)) << std::endl << std::endl;

	std::cout << TURQUOISE << "2. TESTING CALCULUS\n" << RESET << std::endl;
	std::cout << "· a + b = " << (a + b) << std::endl;
	std::cout << "· a - b = " << (a - b) << std::endl;
	std::cout << "· a * b = " << (a * b) << std::endl;
	std::cout << "· a / b = " << (a / b) << std::endl << std::endl;

	std::cout << YELLOW << "3. TESTING INCREMENT AND DECREMENT\n" << RESET << std::endl;
	std::cout << "  [a = 5 and b = 10]" << std::endl << std::endl;
	std::cout << "· Avant : a++ = " << (a++) << std::endl;
	std::cout << "· Après : a++ = " << a << std::endl;
	std::cout << "· Avant : b-- = " << (b--) << std::endl;
	std::cout << "· Après : b-- = " << b << std::endl;
	Fixed a_a = 5;
	Fixed b_b = 10;
	std::cout << "· ++a = " << (++a_a) << std::endl;
	std::cout << "· --b = " << (--b_b) << std::endl << std::endl;

	Fixed c = 5;
	Fixed d = 10;
	const Fixed const_c = 13;
	const Fixed const_d = 15;
	std::cout << GREEN << "4. TESTING WHO'S GREATER THAN WHO\n" << RESET << std::endl;
	std::cout << "  [c = 5 and d = 10]" << std::endl << std::endl;
	std::cout << "· Who's the smallest ? : " << Fixed::min(c, d) << std::endl;
	std::cout << "· Who's the biggest ?  : " << Fixed::max(c, d) << std::endl << std::endl;
	std::cout << "  [const_c = 13 and const_d = 15]" << std::endl << std::endl;
	std::cout << "· Who's the smallest ? (const version) : " << Fixed::min(const_c, const_d) << std::endl;
	std::cout << "· Who's the biggest ? (const version)  : " << Fixed::max(const_c, const_d) << std::endl << std::endl;
	std::cout << GREEN << "5. TESTING INT <-> FLOAT\n" << RESET << std::endl;
	std::cout << "· Int (5) to int = " << Fixed(5).toInt() << std::endl;
	std::cout << "· Float (5,75) to int = " << Fixed(5.75f).toInt() << std::endl;
	std::cout << "· Negative float (-5,75) = " << Fixed(-5.75f) << std::endl;
	return (0);
}

/* Main du sujet */

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }