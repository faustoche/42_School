#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void printHeader(int i, std::string color, std::string reset, std::string testName)
{
	std::cout << color << "\n=======================================================\n" << reset;
	std::cout << WHITE << "   TEST " << i << " : " << testName << RESET << std::endl;
	std::cout << color << "=======================================================\n" << reset << std::endl;
}

Base *generate(void)
{
	int random = std::rand() % 3;
	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
}

/* DYnamic cast will try to cast pointer in A*. If it works (P is pointing toward a A*)
   it returns non-null. If it doesn't work : return nullptr*/

void	identify(Base *p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

/* Casting a reference. If P is not A, then dynamic cast throw an exception. 
   We need to put it in a try and catch because if can brutally fail
   Thus, cannot compile if not in a try and catch */

void	identify(Base &p){
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &e) {}
}

int main()
{
	std::srand(std::time(NULL));
	{
		printHeader(1, GREEN, RESET, "RANDOM IDENTIFICATION (X10)");
		for (int i = 0; i < 10; i++)
		{
			std::cout << PINK << "\n--- TRY " << i + 1 << " ---" << RESET << std::endl;
			Base *instance = generate();
			identify(instance);
			identify(*instance);
			delete (instance);
		}
	}
	{
		printHeader(2, BLUE_BRIGHT, RESET, "MANUAL IDENTIFICATION OF TYPE A, B, C");
		A a;
		B b;
		C c;
		Base *ptrA = &a;
		Base *ptrB = &b;
		Base *ptrC = &c;
		std::cout << TURQUOISE << "\nTEST A:" << RESET << std::endl;
		identify(ptrA);
		identify(*ptrA);
		std::cout << TURQUOISE << "\nTEST B:" << RESET << std::endl;
		identify(ptrB);
		identify(*ptrB);
		std::cout << TURQUOISE << "\nTEST C:" << RESET << std::endl;
		identify(ptrC);
		identify(*ptrC);
	}
	return (0);
}